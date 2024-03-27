#ifndef MEDS_H
#define MEDS_H

#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

class Meds : public Item {
public:
    std::vector<std::pair<int, std::string>> boosts;
    std::pair<int, std::string> onUse;


    Meds() {}
    Meds(std::string ID) {
        id = ID;
        type = "Meds";
        if (ID == "stamina1") {
            onUse = {20, "stamina"};
            boosts = {};
        }
        if (ID == "healthi") {
            onUse = {20, "health"};
            boosts = {};
        }
    }

    void displayInfo() {
        std::cout << "Meds ID: " << id << std::endl;
        std::cout << "Boosts: ";
        for (const auto &boost : boosts) {
            std::cout << boost.first << " " << boost.second << " ";
        }
        std::cout << std::endl;
        std::cout << "On Use: " << onUse.first << " " << onUse.second << std::endl;
    }

    int getPrice() {
        // Calculating price
        return 10;
    }
};

#endif // MEDS_H