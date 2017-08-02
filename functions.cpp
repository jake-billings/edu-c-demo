//
// Created by Jake Billings on 8/2/17.
//
#include <iostream>
#include "functions.h"

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
//            readInventoryFromFile(inventory);
            break;
        case 8:
//            writeInventoryFromFile(inventory);
            break;
        case 9:
            return false;
        default:
            unknownOption();
            break;
    }

    return true;
}

void displayInventory(std::vector<Vehicle>& inventory) {
    if (inventory.size()<1) {
        std::cout<<"Inventory is empty."<<std::endl;
        return;
    }
    for (unsigned int i=0; i<inventory.size();i++) {
        std::cout<<"Vehicle:\t"<<i<<std::endl;
        std::cout<<inventory[i]<<std::endl<<std::endl;
    }
}

void addVehicle(std::vector<Vehicle>& inventory) {
    Vehicle v;
    std::cin >> v;
    inventory.push_back(v);
    std::cout << std::endl << "Added new vehicle to inventory." << std::endl;
}

void updateVehicle(std::vector<Vehicle>& inventory) {
    std::cout<<"Pick a vehicle by its #: ";
    int i;
    std::cin >> i;
    std::cout<<"Now updating vehicle "<<i<<std::endl;
    std::cin >> inventory[i];
    std::cout << std::endl << "Updated vehicle in inventory." << std::endl;
}

void deleteVehicle(std::vector<Vehicle>& inventory) {
    std::cout<<"Pick a vehicle by its #: ";
    int i;
    std::cin >> i;
    inventory.erase(inventory.begin() + i);
    std::cout << std::endl << "Deleted vehicle from inventory." << std::endl;
}

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
    std::cout << std::endl << "Sorted vehicles." << std::endl;
}

void searchInventoryByModel(std::vector<Vehicle>& inventory) {
    std::cout<<"Search for Model: ";
    std::string searchText;
    std::cin >> searchText;

    std::vector<Vehicle> results;
    for (unsigned long i = 0; i<inventory.size(); i++) {
        if (inventory[i].getModel()==searchText) {
            results.push_back(inventory[i]);
        }
    }

    if (results.size()>0) {
        std::cout<<"Found the following vehicles: "<<std::endl<<std::endl;
    } else {
        std::cout<<"No vehicles were found matching that model."<<std::endl;
    }

    for (unsigned long i = 0; i<results.size(); i++) {
        std::cout<<"Result #: "<<i<<std::endl;
        std::cout<<results[i]<<std::endl;
    }

}


void unknownOption() {
    std::cout << "Unknown Option" << std::endl;
}