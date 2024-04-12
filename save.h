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

#include <fstream>
#include <cstdlib>
// Assuming you have the JsonCpp library installed

// Include all item headers

#include <typeinfo> // For typeid operator
using json = nlohmann::json;
void saveParty(const Party &party, const std::string &filename)
{
    // Begin saving party data
    std::cout << "Saving party data to file: " << filename << std::endl;

    json partyData;

    // Save party wallet
    partyData["wallet"] = party.wallet;

    // Save party characters
    json charactersData;
    for (const auto &character : party.group)
    {
        json characterData;

        // Save character attributes
        characterData["name"]=character.name;
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
    for (const auto &item : party.inventory)
    {
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

    // Saving complete
    std::cout << "Party data saved successfully!" << std::endl;
}

Party loadParty(const std::string filename)
{
    // Begin loading party data
    std::cout << "Loading party data from file: " << filename << std::endl;

    Party party;

    // Read JSON data from file
    std::ifstream inputFile(filename);
    json partyData;
    inputFile >> partyData;

    // Load party wallet
    party.wallet = partyData["wallet"];

    // Load party characters
    for (const auto &characterData : partyData["group"])
    {
        Character character;
        character.name=characterData["name"].get<string>();
        // Fill the Character object with data from the JSON object
        character.stamina = characterData["stamina"].get<int>();
        character.vigor = characterData["vigor"].get<int>();
        character.Aim = characterData["Aim"].get<int>();

        character.Strength = characterData["Strength"].get<int>();
        character.Knowledge = characterData["Knowledge"].get<int>();
        character.level = characterData["level"].get<int>();
        character.defending = characterData["defending"].get<bool>(); // Assuming defending is stored as a boolean in JSON
        character.HP = characterData["HP"].get<int>();
        character.Health = characterData["Health"].get<int>();
        // Load weapon and armor data from the JSON object

        character.selah = Weapon(characterData["selah"]);
        character.head = Armor(characterData["head"]);
        character.middle = Armor(characterData["middle"]);
        character.lower = Armor(characterData["lower"]);

        // Add character to the party
        party.group.push_back(character);
    }

    // Load party inventory
    for (const auto& itemData : partyData["inventory"]) {
        std::string itemType = itemData.second.at("type");
        std::string itemId = itemData.second.at("id");

        std::unique_ptr<Item> item;

        if (itemType == "weapon") {
            item = std::make_unique<Weapon>(itemId);
        } else if (itemType == "armor") {
            item = std::make_unique<Armor>(itemId);
        } else if (itemType == "Meds") {
            item = std::make_unique<Meds>(itemId);
        } else if (itemType == "Throwables") {
            item = std::make_unique<Throwables>(itemId);
        }

        if (item) {
            party.inventory.push_back(std::move(item));
        }
    }
    // Loading complete
    std::cout << "Party data loaded successfully!" << std::endl;

    return party;
}
