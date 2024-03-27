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
  Weapon(const Weapon& other) {
        this->id = other.id;
        this->type = other.type;
        this->detail = other.detail;
        this->DurabilityUsage = other.DurabilityUsage;
        this->damage = other.damage;
        this->durability = other.durability;
        this->LongRange = other.LongRange;
    }
    Weapon(){}
    Weapon(string ID){
	      id = ID;
     if (ID == "AK-47") {
        LongRange = true;
        damage = 20;
        DurabilityUsage = 4;
        type = "weapon"; 
        durability = rand() % 32; 
        detail = "An iconic assault rifle known for its reliability and durability. It packs a punch with its high damage output.";
    } else if (ID == "shocker") {
        LongRange = false;
        damage = 5;
        DurabilityUsage = 1;
        type = "weapon"; 
        durability = 50; 
        detail = "A handheld electric shock device, great for stunning enemies but not effective for lethal damage.";
    } else if (ID == "bow") {
        LongRange = true;
        damage = 70;
        DurabilityUsage = 1;
        type = "weapon"; 
        durability = rand() % 8; 
        detail = "A traditional bow and arrow, surprisingly effective even in modern times. Silent and deadly.";
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
