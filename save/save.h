#ifndef SAVE_H
#define SAVE_H
#include <nlohmann/json.hpp>

#include "C:\Users\me1382\Downloads\json-develop\json-develop\include\nlohmann\json.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <windows.h>
 // Include the fishing minigame header file
#include <conio.h>

#include<fstream>
#include <cstdlib>
// Assuming you have the JsonCpp library installed

// Include all item headers




#include <typeinfo> // For typeid operator
using json = nlohmann::json;
void saveParty(const Party& party, const std::string& filename) {
    json partyData;

    // Save party wallet
    partyData["wallet"] = party.wallet;

    // Save party characters
    json charactersData;
    for (const auto& character : party.group) {
        json characterData;

        // Save character attributes
        characterData["stamina"] = character.stamina;
        characterData["vigor"] = character.vigor;
        characterData["Aim"] = character.Aim;
        characterData["Strength"] = character.Strength;
        characterData["Knowledge"] = character.Knowledge;
        characterData["level"] = character.level;
        characterData["defending"] = character.defending;
        characterData["HP"] = character.HP;
        characterData["Health"] = character.Health;

        // Save character weapons and armors
   		 characterData["selah"] = character.selah.toJson();
		characterData["head"] = character.head.toJson();
		characterData["middle"] = character.middle.toJson();
		characterData["lower"] = character.lower.toJson();
        // Save character effects
        characterData["effects"] = character.effects;

        // Add character data to characters array
        charactersData.push_back(characterData);
    }
    partyData["group"] = charactersData;

    // Save party inventory
    json inventoryData;
    for (const auto& item : party.inventory) {
        // Save item type and ID
        json itemData;
        itemData["type"] = item->type;
        itemData["id"] = item->id;

        // Add item data to inventory array
        inventoryData.push_back(itemData);
    }
    partyData["inventory"] = inventoryData;

    // Write party data to file
    std::ofstream outputFile(filename);
    outputFile << std::setw(4) << partyData << std::endl;
}
#endif
