//
// Created by Jake Billings on 8/2/17.
//

#ifndef EDU_C_DEMO_DEALER_H
#define EDU_C_DEMO_DEALER_H

#include <string>

class Dealer {
private:
    std::string DealerName;
    std::string DealerAddress;
public:
    void setName(std::string input);
    void setAddress(std::string input);
    std::string getName();
    std::string getAddress();

    Dealer();
    Dealer(std::string iName);
};


#endif //EDU_C_DEMO_DEALER_H
