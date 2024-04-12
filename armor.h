#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h" // Include the Item header file
#include <iostream>
#include <vector>

using namespace std;

class Armor : public Item {
public:
 
    int defense;
    int bodypart;
     // Copy constructor
    Armor(const Armor& other) {
        this->id = other.id;
        this->type = other.type;
        this->detail = other.detail;
        this->defense = other.defense;
        this->bodypart = other.bodypart;
    }
     
    Armor(string ID="non");
       void displayInfo() {
        cout << "Armor ID: " << id << ", Defense: " << defense << endl;
    }
    
    // calculating the price of each armor by bodypart and defense
    int getPrice() {
	    return (240 / bodypart) + (defense * 5);
	}
	
    int getDefense() const {
        return defense;
    }
};

// Definition of the Armor class methods
Armor::Armor(string ID) {
    if (ID == "naked1") {
        id = ID;
        type = "armor";
        detail = "";
        defense = 0;
        bodypart = 1;
    }
    else if (ID == "naked2") {
        id = ID;
        type = "armor";
        detail = "";
        defense = 0;
        bodypart = 2;
    }
    else if (ID == "naked3") {
        id = ID;
        type = "armor";
        detail = "";
        defense = 0;
        bodypart = 3;
    }
    else if (ID == "clownShoes") {
        id = ID;
        type = "armor";
        detail = "Oversized shoes that squeak with every step, completing the clown ensemble.";
        defense = 5; // Assuming clown shoes offer low defense 
        bodypart = 3; // Feet
    }
    else if (ID == "clownJumpsuit") {
        id = ID;
        type = "armor";
        detail = "A polka-dotted and brightly colored jumpsuit, the staple of any clown's wardrobe.";
        defense = 10; // Assuming clown jumpsuit offers some defense
        bodypart = 2; // Middle
    }
    else if (ID == "clownHat") {
        id = ID;
        type = "armor";
        detail = "A wacky and extravagant hat, complete with spinning propellers and attached balloons.";
        defense = 5; // Assuming clown hat offers some defense
        bodypart = 1; // Head
    }
    else  if (ID == "samuraiHelmet") {
        id = ID;
        type = "armor";
        detail = "An ornate helmet adorned with elaborate designs, worn by samurai warriors for protection and intimidation.";
        defense = 15; // Assuming samurai helmet offers good defense
        bodypart = 1; // Head
    }
    else if (ID == "samuraiChestplate") {
        id = ID;
        type = "armor";
        detail = "A sturdy chestplate crafted from high-quality materials, offering exceptional protection in battle.";
        defense = 15; // Assuming samurai chestplate offers good defense
        bodypart = 2; // Middle
    }
    else if (ID == "samuraiLegGuards") {
        id = ID;
        type = "armor";
        detail = "Leg guards designed to withstand powerful blows and keep the wearer agile in combat.";
        defense = 20; // Assuming samurai leg guards offer good defense
        bodypart = 3; // Feet
    }
    else  if (ID == "trashBin") {
        id = ID;
        type = "armor";
        detail = "A makeshift armor fashioned from a repurposed trash bin, offering unconventional but surprisingly effective protection.";
        defense = 15; // Assuming trash bin armor offers good defense
        bodypart = 2; // Middle
    }
        else if (ID == "wheelchair") {
        id = ID;
        type = "armor";
        detail = "A wheelchair equipped with armor plating, providing mobility and protection in equal measure.";
        defense = 20; // Assuming wheelchair armor offers good defense
        bodypart = 2; // Middle
    }
    else if (ID == "flowerSkirt") {
        id = ID;
        type = "armor";
        detail = "A skirt adorned with a delicate flower pattern, offering style and protection on the battlefield.";
        defense = 5 ; // Assuming flower skirt offers low defense
        bodypart = 3; // feet
    }
    else if (ID == "shrekTShirt") {
        id = ID;
        type = "armor";
        detail = "A green t-shirt emblazoned with the face of everyone's favorite ogre, Shrek.";
        defense = 20; // Assuming Shrek t-shirt offers good defense
        bodypart = 2; // Middle
    }
    else if (ID == "bush") {
        id = ID;
        type = "armor";
        detail = "A dense bush costume, perfect for blending into the environment and surprising your foes.";
        defense = 15; // Assuming bush armor offers excelent defense
        bodypart = 2; // Middle
    }
    else if (ID == "militaryHelmet") {
        id = ID;
        type = "armor";
        detail = "A rugged military helmet designed to protect the wearer's head from shrapnel and projectiles.";
        defense = 20 ; // Assuming military helmet offers excelent defense
        bodypart = 1; // Head
    }
    else if (ID == "tacticalVest") {
        id = ID;
        type = "armor";
        detail = "A versatile tactical vest equipped with pouches and compartments for storing ammunition and gear.";
        defense = 25; // Assuming tactical vest offers excellent defense
        bodypart = 2; // Middle
    }
    else if (ID == "combatBoots") {
        id = ID;
        type = "armor";
        detail = "Sturdy combat boots designed to withstand rugged terrain and provide ankle support during extended missions.";
        defense = 15; // Assuming combat boots offer good defense
        bodypart = 3; // Feet
    }
        // Scrap Armor
    else if (ID == "scrapHelmet") {
        id = ID;
        type = "armor";
        detail = "A makeshift helmet crafted from welded metal pieces and salvaged materials.";
        defense = 15; // Assuming scrap helmet offers decent head protection
        bodypart = 1; // Head
    }
    else if (ID == "scrapChestplate") {
        id = ID;
        type = "armor";
        detail = "A chest armor piece constructed from repurposed metal sheets and reinforced with leather straps.";
        defense = 20; // Assuming scrap chestplate provides good torso protection
        bodypart = 2; // Middle
    }
    else if (ID == "scrapGreaves") {
        id = ID;
        type = "armor";
        detail = "Leg armor made from welded metal scraps and reinforced with sturdy fabric.";
        defense = 15; // Assuming scrap greaves offer decent leg protection
        bodypart = 3; // Feet
    }
 
    // Medieval Armor
    else if (ID == "chainmailCoif") {
        id = ID;
        type = "armor";
        detail = "A hood-like headpiece made from interlocking metal rings.";
        defense = 10; // Assuming chainmail coif offers good head and neck protection
        bodypart = 1; // Head
    }
    else if (ID == "plateArmor") {
        id = ID;
        type = "armor";
        detail = "Heavy armor consisting of metal plates worn over a padded underlayer.";
        defense = 25; // Assuming plate armor provides excellent torso protection
        bodypart = 2; // Middle
    }
    else if (ID == "greavesSabatons") {
        id = ID;
        type = "armor";
        detail = "Leg armor comprising metal shin guards (greaves) and foot armor (sabatons).";
        defense = 20; // Assuming greaves and sabatons offer solid leg protection
        bodypart = 3; // Feet
    }
   


    else {
        // Default values if ID doesn't match known armor types
        id = "non";
        type = "armor";
        detail = "";
        defense = 0;
        bodypart = 0;
    }
	
}
vector<string> validArmorIDs = {
    "clownShoes", "clownJumpsuit", "clownHat", "samuraiHelmet", "samuraiChestplate", 
    "samuraiLegGuards", "trashBin", "wheelchair", "flowerSkirt", "shrekTShirt", 
    "bush", "militaryHelmet", "tacticalVest", "combatBoots", "scrapHelmet", 
    "scrapChestplate", "scrapGreaves", "chainmailCoif", "plateArmor", "greavesSabatons"
};
#endif // ARMOR_H
// Definition of the Meds class