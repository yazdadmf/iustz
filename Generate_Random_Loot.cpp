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
 
 vector<Item *> generateRandomLoot(int numWeapons, int numMeds, int numArmor, int numThrowables) {
 vector<Item *> loot;

    vector<string> weaponIDs = {"sword"};
    vector<string> medsIDs = {"health1"};
    vector<string> armorIDs = {"naked1"};
    vector<string> throwablesIDs = {"grenade"};

    srand(time(NULL)); 

    for (int i = 0; i < numWeapons; ++i) {
        string randomWeaponID = weaponIDs[rand() % weaponIDs.size()];
        loot.push_back(new Weapon(randomWeaponID));
    }

    for (int i = 0; i < numMeds; ++i) {
        string randomMedsID = medsIDs[rand() % medsIDs.size()];
        loot.push_back(new Meds(randomMedsID));
    }

    for (int i = 0; i < numArmor; ++i) {
        string randomArmorID = armorIDs[rand() % armorIDs.size()];
        loot.push_back(new Armor(randomArmorID));
    }

    for (int i = 0; i < numThrowables; ++i) {
        string randomThrowablesID = throwablesIDs[rand() % throwablesIDs.size()];
        loot.push_back(new Throwables(randomThrowablesID));
    }

    return loot;
}