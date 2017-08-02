//
// Created by Jake Billings on 8/2/17.
//

#ifndef EDU_C_DEMO_FUNCTIONS_H
#define EDU_C_DEMO_FUNCTIONS_H
#include <vector>
#include "Vehicle.h"

bool userInterfaceLoop(std::vector<Vehicle>& inventory);

void displayInventory(std::vector<Vehicle>& inventory);
void addVehicle(std::vector<Vehicle>& inventory);
void updateVehicle(std::vector<Vehicle>& inventory);
void deleteVehicle(std::vector<Vehicle>& inventory);
void sortInventoryByVIN(std::vector<Vehicle>& inventory);
void searchInventoryByModel(std::vector<Vehicle>& inventory);
//void readInventoryFromFile(std::vector<Vehicle>& inventory);
//void writeInventoryFromFile(std::vector<Vehicle>& inventory);
void unknownOption();

#endif //EDU_C_DEMO_FUNCTIONS_H
