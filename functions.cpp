/**
 * Name: Jake Billings
 * Date: 08/02/2017
 * Class: CSCI 1411-001
 * Description: Function implementations for the car dealership functions
 * Status: compiles and runs on VS, Clion, and csegrid
 */

//Include cout, cin, fileout, filein, and function headers
#include <iostream>
#include <fstream>
#include "functions.h"

/**
 * Implement the user interface loop for the menu system. Called my main() in main.cpp
 *
 * @param inventory - A vector reference to the inventory we are managing
 * @return bool - False if the program should exit. True for another loop.
 */
bool userInterfaceLoop(std::vector<Vehicle>& inventory) {
    //Print menu
    std::cout << std::endl;
    std::cout << "1.\tDisplay Inventory" << std::endl;
    std::cout << "2.\tAdd a vehicle" << std::endl;
    std::cout << "3.\tUpdate a vehicle" << std::endl;
    std::cout << "4.\tDelete a vehicle" << std::endl;
    std::cout << "5.\tSort inventory by VIN" << std::endl;
    std::cout << "6.\tSearch inventory by Model" << std::endl;
    std::cout << "7.\tRead inventory from file" << std::endl;
    std::cout << "8.\tWrite inventory to file" << std::endl;
    std::cout << "9.\tExit" << std::endl;

    //Read the user's choice
    std::cout << "Select a number: ";
    int input;
    std::cin >> input;
    std::cout << std::endl;

    //Select the correct function for a given choice
    switch (input) {
        case 1:
            displayInventory(inventory);
            break;
        case 2:
            addVehicle(inventory);
            break;
        case 3:
            updateVehicle(inventory);
            break;
        case 4:
            deleteVehicle(inventory);
            break;
        case 5:
            sortInventoryByVIN(inventory);
            break;
        case 6:
            searchInventoryByModel(inventory);
            break;
        case 7:
            readInventoryFromFile(inventory);
            break;
        case 8:
            writeInventoryToFile(inventory);
            break;
        case 9:
            return false;
        default:
            unknownOption();
            break;
    }

    return true;
}

/**
 * Implement the display inventory function
 *
 * @param inventory The inventory we are managing
 */
void displayInventory(std::vector<Vehicle>& inventory) {
    //If there aren't any vehicles, tell the user.
    if (inventory.size()<1) {
        std::cout<<"Inventory is empty."<<std::endl;
        return;
    }

    //Print vehicle information for each vehicle
    for (unsigned int i=0; i<inventory.size();i++) {
        std::cout<<"Vehicle:\t"<<i+1<<std::endl;
        std::cout<<inventory[i]<<std::endl<<std::endl;
    }
}

/**
 * Implement the add inventory function
 *
 * @param inventory The inventory we are managing
 */
void addVehicle(std::vector<Vehicle>& inventory) {
    //Create an empty vehicle
    Vehicle v;

    // Use the >> operator to read the vehicle from cin
    std::cin >> v;

    //Append the vehicle to the inventory
    inventory.push_back(v);

    //Notify the user of our success
    std::cout << std::endl << "Added new vehicle to inventory." << std::endl;
}

/**
 * Implement the update inventory function
 *
 * @param inventory The inventory we are managing
 */
void updateVehicle(std::vector<Vehicle>& inventory) {
    //First, display the inventory
    displayInventory(inventory);

    //Ask the user which vehicle they want to edit
    std::cout<<"Pick a vehicle by its #: ";
    int i;
    std::cin >> i;

    //Tell the user we're starting
    std::cout<<"Now updating vehicle "<<i<<std::endl;

    //Take the new info
    std::cin >> inventory[i-1];

    //Tell the user we updated
    std::cout << std::endl << "Updated vehicle in inventory." << std::endl;
}

/**
 * Implement the delete inventory function
 *
 * @param inventory The inventory we are managing
 */
void deleteVehicle(std::vector<Vehicle>& inventory) {
    //First, display the inventory
    displayInventory(inventory);

    //Have the user pick a vehicle
    std::cout<<"Pick a vehicle by its #: ";
    int i;
    std::cin >> i;

    //Erase the vehicle by id
    inventory.erase(inventory.begin() + i - 1);

    //Tell the user what we did
    std::cout << std::endl << "Deleted vehicle from inventory." << std::endl;
}

/**
 * Implement the sort inventory function
 *
 * @param inventory The inventory we are managing
 */
void sortInventoryByVIN(std::vector<Vehicle>& inventory) {
    //Using bubble sort, arrange Vehicle from tallest to shortest in the inventory vector.
    for (unsigned long i = 0; i<inventory.size(); i++) {
        for (unsigned long j = 0; j<inventory.size()-1; j++) {
            Vehicle v = inventory[j];
            if (v.getVIN() > inventory[j+1].getVIN()) {
                inventory[j] = inventory[j+1];
                inventory[j+1] = v;
            }
        }
    }

    //Tell the user we're done
    std::cout << std::endl << "Sorted vehicles." << std::endl;
}

/**
 * Implement the search inventory function
 *
 * @param inventory The inventory we are managing
 */
void searchInventoryByModel(std::vector<Vehicle>& inventory) {
    //Ask the user what model to search for
    std::cout<<"Search for Model: ";
    std::string searchText;
    std::cin >> searchText;

    //Iterate through the inventory and add matches to a new vector
    std::vector<Vehicle> results;
    for (unsigned long i = 0; i<inventory.size(); i++) {
        if (inventory[i].getModel()==searchText) {
            results.push_back(inventory[i]);
        }
    }

    //If no results are found, tell the user. If they are, print them out.
    if (results.size()>0) {
        std::cout<<"Found the following vehicles: "<<std::endl<<std::endl;
    } else {
        std::cout<<"No vehicles were found matching that model."<<std::endl;
    }

    for (unsigned long i = 0; i<results.size(); i++) {
        std::cout<<"Result #: "<<i+1<<std::endl;
        std::cout<<results[i]<<std::endl;
    }

}

/**
 * Implement the read inventory from file function
 *
 * @param inventory The inventory we are managing
 */
void readInventoryFromFile(std::vector<Vehicle>& inventory) {
    //Open a file input stream
    std::ifstream input;
    input.open("main.dealership");

    //Keep count
    unsigned int count = 0;

    //Until we reach the end of the file, deserialize vehicles and add them to inventory
    while (input.peek()!=EOF) {
        Vehicle v;
        v.deserialize(input);
        inventory.push_back(v);
        count++;
    }

    //Tell the user we're done
    std::cout << std::endl << "Loaded "<< count << " vehicles." << std::endl;
}

/**
 * Implement the write inventory to file function
 *
 * @param inventory The inventory we are managing
 */
void writeInventoryToFile(std::vector<Vehicle>& inventory) {
    //Open an output stream
    std::ofstream output;
    output.open("main.dealership");

    //For each vehicle, write it to the file
    for (unsigned long i = 0; i<inventory.size(); i++) {
        if (i!=0) output<<std::endl;
        inventory[i].serialize(output);
    }

    //Flush the output
    output.flush();

    //Close the output stream
    output.close();

    //Tell the user we're done
    std::cout << std::endl << "Saved "<< inventory.size() << " vehicles." << std::endl;
}


/**
 * Implement the unknown option function
 *
 * @param inventory The inventory we are managing
 */
void unknownOption() {
    //Print a message stating we don't know the option
    std::cout << "Unknown Option" << std::endl;
}