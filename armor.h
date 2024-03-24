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
    else {
        // Default values if ID doesn't match known armor types
        id = "non";
        type = "armor";
        detail = "";
        defense = 0;
        bodypart = 0;
    }
}
#endif // ARMOR_H
// Definition of the Meds class