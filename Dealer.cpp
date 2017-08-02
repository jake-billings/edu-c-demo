//
// Created by Jake Billings on 8/2/17.
//

#include "Dealer.h"

void Dealer::setName(std::string input) {
    this->DealerName = input;
}
void Dealer::setAddress(std::string input) {
    this->DealerAddress = input;
}
std::string Dealer::getName() {
    return this->DealerName;
}
std::string Dealer::getAddress() {
    return this->DealerAddress;
}
Dealer::Dealer() {}
Dealer::Dealer(std::string iName) {
    this->setName(iName);
}