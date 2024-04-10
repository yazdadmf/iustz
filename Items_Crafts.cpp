#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<algorithm>
#include <utility>
#include<iomanip>
#include<windows.h>
#include "Item.h" 
#include "Armor.h"
#include "weapon.h"

#include "Meds.h"
#include "printstuff.h"
#include "character.h"
#include"nonfreindly.h"
#include"zombie.h"

using namespace std;

Item* craft(Item* item1, Item* item2) {
// Check the type of one of the items (assuming both have the same type) 
string itemType = item1->type; 

// Combine IDs of item1 and item2 
string combinedId = item1->id + item2->id; 

// Vector to store the craftable IDs 
vector<string> craftableIds;   

// Check if the combined ID exists in the craftable IDs 
auto it = find(craftableIds.begin(), craftableIds.end(), combinedId);   
if (it != craftableIds.end()) {   
    // Remove item1 and item2 from inventory and memory   
    // Implement removal from inventory 

    // Create a new item with the combined ID and type 
    Item* craftedItem = nullptr; 
    if (itemType == "Weapon") { 
        Weapon* weapon = new Weapon(combinedId); 
        craftedItem = weapon; 
    } else if (itemType == "Armor") { 
        Armor* armor = new Armor(combinedId); 
        craftedItem = armor; 
    } else if (itemType == "Meds") { 
        Meds* meds = new Meds(combinedId); 
        craftedItem = meds; 
    } else if (itemType == "Throwables") { 
        Throwables* throwables = new Throwables(combinedId); 
        craftedItem = throwables; 
    } 

    // Add the crafted item to inventory 
    // Implement addition to inventory 

    cout << "Crafted item with ID: " << combinedId << " and type: " << itemType << endl;   

    // Return the crafted item   
    return craftedItem;   
} else {   
    cout << "Crafting failed. No matching recipe found." << endl;   
    return nullptr;   
}  }