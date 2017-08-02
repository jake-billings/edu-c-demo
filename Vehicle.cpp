//
// Created by Jake Billings on 8/2/17.
//

#include "Vehicle.h"

Vehicle::Vehicle(){
    Dealer* d = new Dealer();
    this->DealerPtr=d;
}
Vehicle::Vehicle(std::string iVin, std::string iMake, unsigned int iYear, double iPrice) {
    this->setVIN(iVin);
    this->setMake(iMake);
    this->setYear(iYear);
    this->setPrice(iPrice);
    Vehicle();
}

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
    out << "VIN:\t\t" << car1.getVIN() << std::endl;
    out << "Make:\t\t" << car1.getMake() << std::endl;
    out << "Model:\t\t" << car1.getModel() << std::endl;
    out << "Year:\t\t" << car1.getYear() << std::endl;
    out << "Price:\t\t$" << car1.getPrice() << std::endl;
    Dealer dealer = *car1.DealerPtr;
    out << "Dealer Name:\t\t" << dealer.getName() << std::endl;
    out << "Dealer Address:\t\t" << dealer.getAddress() << std::endl;
    return out;
}
std::istream& operator>>(std::istream &in, Vehicle &car1) {
    std::cout << "Make:\t\t";
    in >> car1.make;
    std::cout << "Model:\t\t";
    in >> car1.model;
    std::cout << "VIN:\t\t";
    in >> car1.VIN;
    std::cout << "Year:\t\t";
    in >> car1.year;
    std::cout << "Price:\t\t";
    in >> car1.price;

    Dealer* d = new Dealer(); //Allocate on the heap
    car1.DealerPtr = d; //Assign the pointer
    //Read strings then call setters
    std::string DealerName;
    std::string DealerAddress;
    std::cout << "Dealer Name:\t\t";
    in >> DealerName;
    std::cout << "Dealer Address:\t\t";
    in >> DealerAddress;
    d->setName(DealerName);
    d->setAddress(DealerAddress);

    return in;
}

void Vehicle::serialize(std::ostream &out) {
    out << this->getVIN() << std::endl;
    out << this->getMake() << std::endl;
    out << this->getModel() << std::endl;
    out << this->getYear() << std::endl;
    out << this->getPrice() << std::endl;
    Dealer dealer = *this->DealerPtr;
    out << dealer.getName() << std::endl;
    out << dealer.getAddress();
}

void Vehicle::deserialize(std::istream &in) {
    in >> this->make;
    in >> this->model;
    in >> this->VIN;
    in >> this->year;
    in >> this->price;

    //Read strings then call setters
    std::string DealerName;
    std::string DealerAddress;
    in >> DealerName;
    in >> DealerAddress;
    this->DealerPtr->setName(DealerName);
    this->DealerPtr->setAddress(DealerAddress);
}