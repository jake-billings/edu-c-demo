#include <iostream>
#include "functions.h"

int main() {
    std::vector<Vehicle> inventory;
    while (true) {
        if (!userInterfaceLoop(inventory)) break;
    }

    return 0;
}