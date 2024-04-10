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

void addItemToInventory(Item* a){
    inventory.push_back(a);
     cout << "Added item to inventory: " << a->type << endl;
    delete a;
}
// Function to add items from loot to the party inventory
void addLootToInventory(vector<Item*> loot) {
    for (Item* item : loot) {
      addItemToInventory(item);
    
  }