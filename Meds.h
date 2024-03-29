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
        if (ID == "stamina1") {
    onUse = {20, "stamina"};
    boosts = {};
    detail = "A basic stamina-boosting medication that restores energy and vitality.";
}
if (ID == "health1" || ID == "weedweed") {
    id = "health1";
    onUse = {20, "health"};
    boosts = {};
    detail = "A common health potion that heals wounds and restores vitality.";
}
if (ID == "strenght1") {
    onUse = {};
    boosts = {{3,"strenght+"}};
    detail = "A simple potion that enhances physical strength, making the user stronger in combat.";
}
if (ID == "knowledge") {
    onUse = {};
    boosts = {{3,"knowledge+"}};
    detail = "A potion that enhances mental clarity and knowledge, improving cognitive abilities.";
}
if (ID == "health1stamina1" || ID == "lean") {
    id = "lean";
    onUse = {50, "stamina"};
    boosts = {{10, "poisend1"}};
    detail = "A combination medication that boosts stamina and provides resistance against poison.";
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
