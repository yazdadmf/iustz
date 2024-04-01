#ifndef SHOP_H
#define SHOP_H

#include"party.h"
#include"character.h"
class Party;
class Shop{

vector<Item*> inventory;
void generateShopInventory(int numWeapons, int numMeds, int numArmor, int numThrowables) {
    vector<string> weaponIDs =  {"AK-47", "shocker", "bow", "Katana", "pistol", "Frying pan", "Rocket launcher",
    "Mike Tyson Gloves", "Witcher steel sword", "Sniper rifle", "Machine gun", "stapler",
    "Lucille", "Cane", "Axe", "Shotgun", "Electric Guitar", "Dagger", "Revolver",
     "MTs-108", "Wrench", "Whip"};
    vector<string> medsIDs = { "stamina1", "health1", "weedweed", "strenght1", "knowledge", "health1stamina1", 
    "lean", "weed", "health1health1", "health2", "stamina1stamina1", "stamina2", 
    "strenght2", "strength1strength1", "energydrink", "adrenalineshot"};
    vector<string> armorIDs = {
    "clownShoes", "clownJumpsuit", "clownHat", "samuraiHelmet", "samuraiChestplate", 
    "samuraiLegGuards", "trashBin", "wheelchair", "flowerSkirt", "shrekTShirt", 
    "bush", "militaryHelmet", "tacticalVest", "combatBoots", "scrapHelmet", 
    "scrapChestplate", "scrapGreaves", "chainmailCoif", "plateArmor", "greavesSabatons"};
    vector<string> throwablesIDs = { "molotov","grenade","kitty","batrang","slippers",
        "snowball","rock","oxford dictionary","peel of banana","shuriken","smoke bomb"};

    srand(time(NULL));

    for (int i = 0; i < numWeapons; ++i) {
        string randomWeaponID = weaponIDs[rand() % weaponIDs.size()];
        inventory.push_back(new Weapon(randomWeaponID));
  
    }

    for (int i = 0; i < numMeds; ++i) {
        string randomMedsID = medsIDs[rand() % medsIDs.size()];
        inventory.push_back(new Meds(randomMedsID));
       
    }

    for (int i = 0; i < numArmor; ++i) {
        string randomArmorID = armorIDs[rand() % armorIDs.size()];
        inventory.push_back(new Armor(randomArmorID));
       
    }

    for (int i = 0; i < numThrowables; ++i) {
        string randomThrowablesID = throwablesIDs[rand() % throwablesIDs.size()];
        inventory.push_back(new Throwables(randomThrowablesID));
       
    }
}

 void buyItem(Party& party, int itemIndex) ;
    void sellItem(Party& party, int itemIndex) ;

void scrollThroughBuyInventory(Party& party)

     void removeItemFromInventory(Item* item) {
        auto it = find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
        }
    }
     void addItemToInventory(Item* item) {
        inventory.push_back(item);
    }
    void scrollThroughSellInventory(Party& party) ;
};



void Shop::sellItem(Party& party, int itemIndex) {
        if (itemIndex >= 0 && itemIndex < party.inventory.size()) {
            Item* item = party.inventory[itemIndex];
            // Add item to shop inventory
            inventory.push_back(item);
            party.inventory.erase(party.inventory.begin() + itemIndex);
            party.increaseWallet(item->price); // Implement increaseWallet function in Party class
            cout << "You sold: " << item->id << endl;
        } else {
            cout << "Invalid item index." << endl;
        }
    }








#endif 


