//
// Created by Jake Billings on 8/2/17.
//
#include <iostream>
#include "functions.h"

bool userInterfaceLoop(std::vector<Vehicle>& inventory) {
    //Print menu
    std::cout << "1.\tDisplay Inventory" << std::endl;
    std::cout << "2.\tAdd a vehicle" << std::endl;
    std::cout << "3.\tUpdate a vehicle" << std::endl;
    std::cout << "4.\tDelete a vehicle" << std::endl;
    std::cout << "5.\tSort inventory by VIN" << std::endl;
    std::cout << "6.\tSearch inventory by Model" << std::endl;
    std::cout << "7.\tRead inventory from file" << std::endl;
    std::cout << "8.\tWrite inventory to file" << std::endl;

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
//            updateVehicle(inventory);
            break;
        case 4:
//            deleteVehicle(inventory);
            break;
        case 5:
//            sortInventoryByVIN(inventory);
            break;
        case 6:
//            sortInventoryByModel(inventory);
            break;
        case 7:
//            readInventoryFromFile(inventory);
            break;
        case 8:
//            writeInventoryFromFile(inventory);
            break;
        default:
            unknownOption();
            break;
    }

    return false;
}

void displayInventory(std::vector<Vehicle>& inventory) {
    if (inventory.size()<1) {
        std::cout<<"Inventory is empty."<<std::endl;
        return;
    }
    for (unsigned int i=0; i<inventory.size();i++) {
        std::cout<<inventory[i]<<std::endl<<std::endl;
    }
}

void addVehicle(std::vector<Vehicle>& inventory) {
    Vehicle v;
    std::cin >> v;
    inventory.push_back(v);
    std::cout << "Added new vehicle to inventory." << std::endl;
}

void unknownOption() {
    std::cout << "Unknown Option" << std::endl;
}