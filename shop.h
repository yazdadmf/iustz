#ifndef SHOP_H
#define SHOP_H
#include<memory>

#include"character.h"
class Party;
    class Shop {
    
public:
		
    vector<unique_ptr<Item>> inventory;
    // Shop attributes and methods...
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
        inventory.push_back(move(make_unique<Weapon>(randomWeaponID)));
  
    }

    for (int i = 0; i < numMeds; ++i) {
        string randomMedsID = medsIDs[rand() % medsIDs.size()];
        inventory.push_back(move(make_unique<Meds>(randomMedsID)));
       
    }

    for (int i = 0; i < numArmor; ++i) {
        string randomArmorID = armorIDs[rand() % armorIDs.size()];
        inventory.push_back(move(make_unique<Armor>(randomArmorID)));
       
    }

    for (int i = 0; i < numThrowables; ++i) {
        string randomThrowablesID = throwablesIDs[rand() % throwablesIDs.size()];
        inventory.push_back(move(make_unique<Throwables>(randomThrowablesID)));
       
    }
}

    void buyItem(Party& party, int itemIndex) ;
    void sellItem(Party& party, int itemIndex) ;

void scrollThroughBuyInventory(Party& party) {
    const int itemsPerPage = 5;
    size_t currentPage = 0;

    while (true) {
        system("cls");
        cout<<inventory.size();

        cout << "Shop Inventory (Page " << currentPage + 1 << "):" << endl;
        for (size_t i = currentPage * itemsPerPage; i < min((currentPage + 1) * itemsPerPage, inventory.size()); ++i) {
           color("┌───────┬─────────────────────┬───────────────────┐" ,"cyan");
		   cout<< endl;
            color("│ ","cyan"); 
			cout<< setw(6) <<left<< i + 1;
			 color("│ ","cyan");
			cout<<setw(20) << left << inventory[i]->id ;
			 color("│ ","cyan");
            // Type casting and getting the price
            if (dynamic_cast<Meds*>(inventory[i].get())) {
            	
                cout << "Price: " << setw(10) << dynamic_cast<Meds*>(inventory[i].get())->getPrice();
				 color(" │ ","cyan"); 
				 cout<< endl;
            } else if (dynamic_cast<Weapon*>(inventory[i].get())) {
                cout << "Price: " << setw(10) << dynamic_cast<Weapon*>(inventory[i].get())->getPrice();
				color(" │ ","cyan");
				cout<< endl;
            } else if (dynamic_cast<Throwables*>(inventory[i].get())) {
                cout << "Price: " << setw(10) << dynamic_cast<Throwables*>(inventory[i].get())->getPrice();
				 color(" │ ","cyan");
				 cout << endl;
            } else if (dynamic_cast<Armor*>(inventory[i].get())) {
                cout << "Price: " << setw(10) << dynamic_cast<Armor*>(inventory[i].get())->getPrice();
                color(" │ ","cyan");
				 cout << endl;
            }
             color("└───────┴─────────────────────┴───────────────────┘","cyan");
			 cout << endl;
        }
        cout << "Enter 'next' to see next page, 'prev' to see previous page, or type 'back' to return to main menu: ";
        string inputStr;
        cin >> inputStr;
        if (inputStr == "back") {
            break;
        } else if (inputStr == "next") {
            ++currentPage;
            if (currentPage * itemsPerPage >= inventory.size()) {
                currentPage = 0;
            }
        } else if (inputStr == "prev") {
            if (currentPage == 0) {
                currentPage = (inventory.size() - 1) / itemsPerPage;
            } else {
                --currentPage;
            }
        }else{
            buyItem(party,stoi(inputStr)-1);
        }
    }
}
     void removeItemFromInventory(unique_ptr<Item>& item) {
        auto it = find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
        }
    }
     void addItemToInventory(unique_ptr<Item> item) {
        inventory.push_back(move(item));
    }
    void scrollThroughSellInventory(Party& party) ;
};


#endif 