#ifndef THROWABLESR_H
#define THROWABLES_H

#include "Item.h" // Include the Item header file
#include<string>


class Throwables : public Item {
public:
   
    vector<pair<int, string>> effects;
    int instantDamage;

    Throwables() {}
    Throwables(string ID) {
		id=ID;
    	type="Throwables";
        if(ID=="molotov"){
            instantDamage=50;
            effects.push_back({3,"fire"});
            }
        if(ID=="granade"){
            instantDamage=50;
            effects={};
        }
    }
    void displayInfo() {
        cout << "Throwables ID: " << id << endl;
        cout << "Effects: ";
        for (const auto& effect : effects) {
            cout << effect.first << " " << effect.second << " ";
        }
        cout << endl;
        cout << "Instant Damage: " << instantDamage << endl;
    }
 
    
    int getPrice() {
        // calculating price
        return 15; // example
    }
    
};

#endif 
// Definition of the Meds class