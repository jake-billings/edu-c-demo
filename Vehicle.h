/**
 * Name: Jake Billings
 * Date:  08/02/2017
 * Class: CSCI 1411-001
 * Description: Header file for the Vehicle class from PA3
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#ifndef EDU_C_DEMO_VEHICLE_H
#define EDU_C_DEMO_VEHICLE_H

//Include strings and io for the purpose of implementing methods later
#include <string>
#include <iostream>
#include "Dealer.h"

/**
 * Define the Vehicle class to hold all of the data needed to represent a vehicle
 */
class Vehicle {
private:
    /**
     * VIN - the string vin of vehicle
     */
    std::string VIN;

    /**
     * make - the string make of vehicle
     */
    std::string make;

    /**
     * model - the string model of vehicle
     */
    std::string model;

    /**
     * year - the unsigned int year of vehicle
     */
    unsigned int year;

    /**
     * price - the double vin of vehicle
     */
    double price;
public:
    /**
     * DealerPtr - a public pointer to the vehicle's dealer
     */
    Dealer* DealerPtr;

    /**
     * Define a default constructor
     */
    Vehicle();
    /**
     * Define a complete constructor
     * @param iVin The vin of the vehicle
     * @param iMake The make of the vehicle
     * @param iYear The year of the vehicle
     * @param iPrice The price of the vehicle
     */
    Vehicle(std::string iVin, std::string iMake, unsigned int iYear, double iPrice);

    //Define setters
    void setVIN(std::string input);
    void setMake(std::string input);
    void setModel(std::string input);
    void setYear(unsigned int input);
    void setPrice(double price);

    //Define getters
    std::string getVIN();
    std::string getMake();
    std::string getModel();
    unsigned int getYear();
    double getPrice();

    /**
     * Define the << operator as a method to serialize this object
     *
     * Contains cout/cin specific content for the purpose of user input.
     *
     * @param out The output stream to serialize to
     * @param car1 The vehicle to serialize to out
     * @return out
     */
    friend std::ostream& operator<<(std::ostream &out, Vehicle &car1);
    /**
     * Define the >> operator as a method to deserialize this object
     *
     * Contains cout/cin specific content for the purpose of user input.
     *
     * @param out The input stream to read from
     * @param car1 The vehicle to dump the incoming data to
     * @return out (input)
     */
    friend std::istream& operator>>(std::istream &out, Vehicle &car1);


    /**
     * Define a method to serialize this object without console output
     *
     * @param out The output stream to serialize to
     */
    void serialize(std::ostream &out);
    /**
     * Define a method to deserialize this object without console output
     *
     * @param in The input stream to serialize to
     */
    void deserialize(std::istream &in);
};


#endif //EDU_C_DEMO_VEHICLE_H
