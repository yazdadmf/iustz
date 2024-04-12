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
    onUse = {15, "stamina"};
    boosts = {};
    detail = "A basic stamina-boosting medication that restores energy and vitality.";
}
if (ID == "health1" || ID == "weedweed") {
    id = "health1";
    onUse = {40, "health"};
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
if (ID == "weed") {
    onUse = {30, "health"};
    boosts = {};
    detail = "A medicinal herb known for its healing properties, providing a mild boost to health.";
}
if (ID == "health1health1" || ID == "health2") {
    id = "health2";
    onUse = {100, "health"};
    boosts = {};
    detail = "A potent health potion that restores a significant amount of health and vitality.";
}
if (ID == "stamina1stamina1" || ID == "stamina2") {
    id = "stamina2";
    onUse = {40, "stamina"};
    boosts = {};
    detail = "A powerful stamina-boosting medication that replenishes energy reserves and enhances endurance.";
}
if (ID == "strenght2" || ID == "strength1strength1") {
    id = "strength2";
    onUse = {};
    boosts = {{3, "strength+"},{3, "strength+"},{3, "strength+"},{3, "strength+"}};
    detail = "A potent potion that greatly enhances physical strength, allowing the user to perform extraordinary feats of power.";
}
if (ID == "energydrink") {
    onUse = {30, "stamina"};
    boosts = {{5, "strength+"}};
    detail = "An energy drink that provides a quick boost of energy, enhancing strength and speed.";
}
if (ID == "adrenalineshot") {
    onUse = {-15, "stamina"};
    boosts = {{3, "strength+"},{3,"Aim+"},{3,"Aim+"}};
    detail = "An adrenaline shot that increases adrenaline levels, boosting strength, agility, and awareness.";
}
// aim bost monde
    }

    void displayInfo() {
    std::cout << "Meds ID: " << id << std::endl;
    if (!detail.empty()) {
        std::cout << "Description: " << detail << std::endl;
    }
    if (!boosts.empty()) {
        std::cout << "Boosts:" << std::endl;
        for (const auto &boost : boosts) {
            std::cout << "- " << boost.first << " " << boost.second << std::endl;
        }
    } else {
        std::cout << "No boosts." << std::endl;
    }
    if (!onUse.second.empty()) {
        std::cout << "On Use: " << onUse.first << " " << onUse.second << std::endl;
    } else {
        std::cout << "No on-use effects." << std::endl;
    }
}


    int getPrice() {
    int totalBoosts = 0;
    for (const auto &boost : boosts) {
        totalBoosts += boost.first;
    }
    int price = 10 + totalBoosts * 5; // Adjusting price based on total boost amount
    if (!onUse.second.empty()) {
        price += 20; // Additional price for having an on-use effect
    }
    return price;
}
};
vector<std::string> MedsIDs = {
    "stamina1", "health1", "weedweed", "strenght1", "knowledge", "health1stamina1", 
    "lean", "weed", "health1health1", "health2", "stamina1stamina1", "stamina2", 
    "strenght2", "strength1strength1", "energydrink", "adrenalineshot"
};

#endif // MEDS_H