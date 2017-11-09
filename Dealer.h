/**
 * Name: Jake Billings
 * Date:  08/02/2017
 * Class: CSCI 1411-001
 * Description: Header file for the Dealer class from PA3
 * Status: compiles and runs on VS, Clion, and csegrid
 */

#ifndef EDU_C_DEMO_DEALER_H
#define EDU_C_DEMO_DEALER_H

// Include strings so we can use them as properties
#include <string>

class Dealer {
private:
    /**
     * string DealerName the name of the dealer
     */
    std::string DealerName;
    /**
     * string DealerAddress the address of the dealer
     */
    std::string DealerAddress;
public:
    /**
     * setName() sets the DealerName attribute of a given Dealer object.
     *
     * @param input std::string value to set the DealerName to
     */
    void setName(std::string input);

    /**
     * setAddress() sets the DealerAddress attribute of a given Dealer object.
     *
     * @param input std::string value to set the DealerAddress to
     */
    void setAddress(std::string input);

    /**
     * getName() returns the DealerName attribute of a given Dealer object.
     */
    std::string getName();

    /**
     * getAddress() returns the DealerName attribute of a given Dealer object.
     */
    std::string getAddress();


    /**
     * Define a default constructor to init an empty Dealer object
     */
    Dealer();

    /**
     * Define a constructor that sets the name of a Dealer using the setName() method
     * @param iName The name to set the dealer to
     */
    Dealer(std::string iName);
};


#endif //EDU_C_DEMO_DEALER_H
