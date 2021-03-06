/**
 * Name: Jake Billings
 * Date: 08/02/2017
 * Class: CSCI 1411-001
 * Description: Function headers for the car dealership functions
 * Status: compiles and runs on VS, Clion, and csegrid
 */

#ifndef EDU_C_DEMO_FUNCTIONS_H
#define EDU_C_DEMO_FUNCTIONS_H

//Include vectors and vehicles
#include <vector>
#include "Vehicle.h"

//Declare all the function headers
bool userInterfaceLoop(std::vector<Vehicle>& inventory);

void displayInventory(std::vector<Vehicle>& inventory);
void addVehicle(std::vector<Vehicle>& inventory);
void updateVehicle(std::vector<Vehicle>& inventory);
void deleteVehicle(std::vector<Vehicle>& inventory);
void sortInventoryByVIN(std::vector<Vehicle>& inventory);
void searchInventoryByModel(std::vector<Vehicle>& inventory);
void readInventoryFromFile(std::vector<Vehicle>& inventory);
void writeInventoryToFile(std::vector<Vehicle>& inventory);
void unknownOption();

#endif //EDU_C_DEMO_FUNCTIONS_H
