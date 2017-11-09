/**
 * Name: Jake Billings
 * Date:  08/02/2017
 * Class: CSCI 1411-001
 * Description: Implementation of getters/setters for the dealer class from PA3
 * Status: compiles and runs on VS, Clion, and csegrid
 */

//Include the dealer header file
#include "Dealer.h"

/**
 * setName() sets the DealerName attribute of a given Dealer object.
 *
 * @param input std::string value to set the DealerName to
 */
void Dealer::setName(std::string input) {
    this->DealerName = input;
}

/**
 * setAddress() sets the DealerAddress attribute of a given Dealer object.
 *
 * @param input std::string value to set the DealerAddress to
 */
void Dealer::setAddress(std::string input) {
    this->DealerAddress = input;
}

/**
 * getName() returns the DealerName attribute of a given Dealer object.
 */
std::string Dealer::getName() {
    return this->DealerName;
}

/**
 * getAddress() returns the DealerName attribute of a given Dealer object.
 */
std::string Dealer::getAddress() {
    return this->DealerAddress;
}

/**
 * Define a default constructor to init an empty Dealer object
 */
Dealer::Dealer() {}

/**
 * Define a constructor that sets the name of a Dealer using the setName() method
 * @param iName The name to set the dealer to
 */
Dealer::Dealer(std::string iName) {
    this->setName(iName);
}