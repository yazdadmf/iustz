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
        if (ID == "molotov") {
    instantDamage = 50;
    effects.push_back({3, "fire"});
    detail = "A bottle of liquid courage that makes things uncomfortably toasty.";
} else if (ID == "grenade") {
    instantDamage = 50;
    effects = {};
    detail = "A pocket-sized surprise that says 'Boom!' in 50 different languages.";
} else if (ID == "kitty") {
    instantDamage = 40;
    effects.push_back({4, "stun"});
    detail= "A furry projectile guaranteed to leave your enemy purr-alyzed for 4 turns.";
}
else if (ID == "batrang") {
    instantDamage = 30; // Assuming lower damage for a batrang
    effects = {};
    detail = "The ultimate tool for caped crusaders, designed to knock sense into evildoers.";
}
else if (ID == "slippers") {
    instantDamage = 10; // Slippers may not deal much damage
    effects = {};
    detail = "The perfect weapon for a cozy night in, guaranteed to make your enemy slip up.";
}
 else if (ID == "snowball") {
    instantDamage = 20; // Snowballs are not that deadly, but they're fun!
    effects.push_back({2, "freeze"}); // Freeze effect for 2 turns
   detail = "A frosty surprise straight from the heavens, bringing joy and a cold reality check.";
}
else if (ID == "rock") {
    instantDamage = 35; // Rocks are solid, so they pack a punch
    effects = {};
    detail = "The original weapon of choice for Mother Nature, now in a throwable format. Guaranteed to rock your enemy's world! Can you smell what The Rock is cooking?";
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
