/**
 * Name: Jake Billings
 * Date: 08/02/2017
 * Class: CSCI 1411-001
 * Description: Data system for a car dealership
 * Status: compiles and runs on VS, Clion, and csegrid
 */

//Include cout, cin, and functions
#include <iostream>
#include "functions.h"

/**
 * Implement main() as a while(true) loop that calls userInterfaceLoop until exit
 *
 * @return int 0 - Everything executed without error
 */
int main() {
    //Declare a vector to hold our inventory
    std::vector<Vehicle> inventory;

    //Iterate forever on the user interface loop unless, it sends us an exit signal
    // by returning false
    while (true) {
        if (!userInterfaceLoop(inventory)) break;
    }

    //Return 0 because everything went okay
    return 0;
}