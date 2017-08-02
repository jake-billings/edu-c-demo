//
// Created by Jake Billings on 8/2/17.
//

#ifndef EDU_C_DEMO_VEHICLE_H
#define EDU_C_DEMO_VEHICLE_H

#include <string>
#include <iostream>
#include "Dealer.h"

class Vehicle {
private:
    std::string VIN;
    std::string make;
    std::string model;
    unsigned int year;
    double price;
public:
    Dealer* DealerPtr;

    void setVIN(std::string input);
    void setMake(std::string input);
    void setModel(std::string input);
    void setYear(unsigned int input);
    void setPrice(double price);

    std::string getVIN();
    std::string getMake();
    std::string getModel();
    unsigned int getYear();
    double getPrice();

    friend std::ostream& operator<<(std::ostream &out, Vehicle &car1);
    friend std::istream& operator>>(std::istream &out, Vehicle &car1);
};


#endif //EDU_C_DEMO_VEHICLE_H
