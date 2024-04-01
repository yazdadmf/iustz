#ifndef SHOP_H
#define SHOP_H

#include"party.h"
#include"character.h"
class Party;
class Shop{

vector<Item*> inventory;
void generateShopInventory(int numWeapons, int numMeds, int numArmor, int numThrowables);
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


#endif 

}
