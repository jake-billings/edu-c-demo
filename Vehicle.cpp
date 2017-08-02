//
// Created by Jake Billings on 8/2/17.
//

#include "Vehicle.h"

void Vehicle::setVIN(std::string input) {
    this->VIN = input;
}
void Vehicle::setMake(std::string input) {
    this->make = input;
}
void Vehicle::setModel(std::string input) {
    this->model = input;
}
void Vehicle::setYear(unsigned int input) {
    this->year = input;
}
void Vehicle::setPrice(double price) {
    this->price = price;
}

std::string Vehicle::getVIN() {
    return this->VIN;
}
std::string Vehicle::getMake() {
    return this->make;
}
std::string Vehicle::getModel() {
    return this->model;
}
unsigned int Vehicle::getYear() {
    return this->year;
}
double Vehicle::getPrice() {
    return this->price;
}
std::ostream& operator<<(std::ostream &out, Vehicle &car1) {
    out << "VIN: " << car1.getVIN() << std::endl;
    out << "Make: " << car1.getMake() << std::endl;
    out << "Model: " << car1.getModel() << std::endl;
    out << "Year: " << car1.getYear() << std::endl;
    out << "Price: $" << car1.getPrice() << std::endl;
    Dealer dealer = *car1.DealerPtr;
    out << "Dealer Name: " << dealer.getName() << std::endl;
    out << "Dealer Address: " << dealer.getAddress() << std::endl;
    return out;
}
std::istream& operator>>(std::istream &in, Vehicle &car1) {
    std::cout << "Make:\t";
    in >> car1.make;
    std::cout << "Model:\t";
    in >> car1.model;
    std::cout << "Year:\t";
    in >> car1.year;
    std::cout << "Price:\t";
    in >> car1.price;

    Dealer* d = new Dealer(); //Allocate on the heap
    car1.DealerPtr = d; //Assign the pointer
    //Read strings then call setters
    std::string DealerName;
    std::string DealerAddress;
    std::cout << "Dealer Name:\t";
    in >> DealerName;
    std::cout << "Dealer Address:\t";
    in >> DealerAddress;
    d->setName(DealerName);
    d->setAddress(DealerAddress);

    return in;
}