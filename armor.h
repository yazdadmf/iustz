#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h" // Include the Item header file

using namespace std;

class Armor : public Item {
public:
    string id;
    int defense;
    int bodypart;
    
    Armor(string ID="non");
       void displayInfo() {
        cout << "Armor ID: " << id << ", Defense: " << defense << endl;
    }

    int getPrice() {
        // Placeholder for price calculation
        return defense * 10; // Example price calculation
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
        defense = 15; // Assuming clown shoes offer some defense 
        bodypart = 3; // Feet 
    } 
    else if (ID == "clownJumpsuit") { 
        id = ID; 
        type = "armor"; 
        detail = "A polka-dotted and brightly colored jumpsuit, the staple of any clown's wardrobe."; 
        defense = 30; // Assuming clown jumpsuit offers good defense 
        bodypart = 2; // Middle 
    } 
    else if (ID == "clownHat") { 
        id = ID; 
        type = "armor"; 
        detail = "A wacky and extravagant hat, complete with spinning propellers and attached balloons."; 
        defense = 20; // Assuming clown hat offers moderate defense 
        bodypart = 1; // Head 
    }
        else  if (ID == "samuraiHelmet") { 
        id = ID; 
        type = "armor"; 
        detail = "An ornate helmet adorned with elaborate designs, worn by samurai warriors for protection and intimidation."; 
        defense = 25; // Assuming samurai helmet offers good defense 
        bodypart = 1; // Head 
    } 
    else if (ID == "samuraiChestplate") { 
        id = ID; 
        type = "armor"; 
        detail = "A sturdy chestplate crafted from high-quality materials, offering exceptional protection in battle."; 
        defense = 40; // Assuming samurai chestplate offers excellent defense 
        bodypart = 2; // Middle 
    } 
    else if (ID == "samuraiLegGuards") { 
        id = ID; 
        type = "armor"; 
        detail = "Leg guards designed to withstand powerful blows and keep the wearer agile in combat."; 
        defense = 30; // Assuming samurai leg guards offer good defense 
        bodypart = 3; // Feet 
    }
        else  if (ID == "samuraiHelmet") { 
        id = ID; 
        type = "armor"; 
        detail = "An ornate helmet adorned with elaborate designs, worn by samurai warriors for protection and intimidation."; 
        defense = 25; // Assuming samurai helmet offers good defense 
        bodypart = 1; // Head 
    } 
    else if (ID == "samuraiChestplate") { 
        id = ID; 
        type = "armor"; 
        detail = "A sturdy chestplate crafted from high-quality materials, offering exceptional protection in battle."; 
        defense = 40; // Assuming samurai chestplate offers excellent defense 
        bodypart = 2; // Middle 
    } 
    else if (ID == "samuraiLegGuards") { 
        id = ID; 
        type = "armor"; 
        detail = "Leg guards designed to withstand powerful blows and keep the wearer agile in combat."; 
        defense = 30; // Assuming samurai leg guards offer good defense 
        bodypart = 3; // Feet 
    }
        else if (ID == "shrekTShirt") { 
        id = ID; 
        type = "armor"; 
        detail = "A green t-shirt emblazoned with the face of everyone's favorite ogre, Shrek."; 
        defense = 25; // Assuming Shrek t-shirt offers good defense 
        bodypart = 2; // Middle 
    } 
    else if (ID == "bush") { 
        id = ID; 
        type = "armor"; 
        detail = "A dense bush costume, perfect for blending into the environment and surprising your foes."; 
        defense = 30; // Assuming bush armor offers good defense 
        bodypart = 2; // Middle 
    } 
    else if (ID == "militaryHelmet") { 
        id = ID; 
        type = "armor"; 
        detail = "A rugged military helmet designed to protect the wearer's head from shrapnel and projectiles."; 
        defense = 30; // Assuming military helmet offers good defense 
        bodypart = 1; // Head 
    } 
    else if (ID == "tacticalVest") { 
        id = ID; 
        type = "armor"; 
        detail = "A versatile tactical vest equipped with pouches and compartments for storing ammunition and gear."; 
        defense = 40; // Assuming tactical vest offers excellent defense 
        bodypart = 2; // Middle 
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
