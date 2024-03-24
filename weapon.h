#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h" 

#include<string>
using namespace std;
class Weapon : public Item {
public:
    
	string id;
    int damage;
    int DurabilityUsage;
	int durability;
    bool LongRange;
    Weapon(){}
    Weapon(string ID){
        if(ID=="gun"){
        type="weapon";
        id=ID;
        detail="";
        DurabilityUsage=1;
        damage=10;
        durability=5;
        LongRange=true;
    }
    if(ID=="sword"){
        type="weapon";
        id=ID;
        detail="";
        DurabilityUsage=1;
        damage=10;
        durability=5;
        LongRange=false;
    }
    }
    void displayInfo() {
        cout << "Weapon ID: " << id << ", Damage: " << damage << ", Durability: " << durability << endl;
    }

    int use() {
        if (durability > 0) {
            durability -= DurabilityUsage;
            return damage;
        } else {
            return 0; // Weapon is broken, returns 0 damage
        }
    }

    int getPrice() {
        // calculating price
        return damage * 20; // example
    }
};
#endif 