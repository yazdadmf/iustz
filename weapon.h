#ifndef WEAPON_H
#define WEAPON_H

#include<vector>
#include "Item.h" 
#include <iostream>

#include<string>
using namespace std;
class Weapon : public Item {
public:
    
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
    Weapon(){
	}
	#ifdef MY_SYSTEM
	using json = nlohmann::json;
   json toJson()  const {
        json weaponData;
        weaponData["id"] = id;
        weaponData["damage"] = damage;
        weaponData["durability"] = durability;
        weaponData["DurabilityUsage"] = DurabilityUsage;
        weaponData["LongRange"] = LongRange;
        weaponData["detail"] = detail;
        return weaponData;
    }
     Weapon(const json& data) {
        id = data["id"];
        damage = data["damage"];
        DurabilityUsage = data["DurabilityUsage"];
        durability = data["durability"];
        LongRange = data["LongRange"];
        detail = data["detail"];
    }
    #endif
   Weapon(const Weapon* other) {
    if(other) {
        this->id = other->id;
        this->type = other->type;
        this->detail = other->detail;
        this->DurabilityUsage = other->DurabilityUsage;
        this->damage = other->damage;
        this->durability = other->durability;
        this->LongRange = other->LongRange;
    }
}
    Weapon(const string& ID){
  id = ID;
     if (ID == "AK-47") {
        LongRange = true;
        damage = 40;
        DurabilityUsage = 4;
        type = "weapon"; 
        durability = 40; 
        detail = "An iconic assault rifle known for its reliability and durability. It packs a punch with its high damage output.";
    } else if (ID == "shocker") {
        LongRange = false;
        damage = 15;
        DurabilityUsage = 2;
        type = "weapon"; 
        durability = 24; 
        detail = "A handheld electric shock device, great for stunning enemies but not effective for lethal damage.";
    } else if (ID == "bow") {
        LongRange = true;
        damage = 30;
        DurabilityUsage = 1;
        type = "weapon"; 
        durability = 10; 
        detail = "A traditional bow and arrow, surprisingly effective even in modern times. Silent and deadly.";
    } else if (ID == "Katana") {
        LongRange = false;
        damage = 25;
        DurabilityUsage = 2;
        type = "weapon"; 
        durability = 24; 
        detail = "A traditional Japanese sword, forged with precision and sharpness. Its elegance in combat is unmatched.";
    }
	if (ID == "pistol") {
    LongRange = true; // Assuming pistols are generally short to mid-range
    damage = 30;
    DurabilityUsage = 2;
    type = "weapon"; 
    durability = 30; // Random durability between 0 and 19
    detail = "A standard-issue sidearm, reliable and easy to handle. What do you want to know? It shoots.";
}

if (ID == "Frying pan") {
    LongRange = false; // Melee weapon
    damage = 15;
    DurabilityUsage = 1;
    type = "weapon"; 
    durability = 9; // Assuming the frying pan's durability is fixed
    detail = "Transformed from a kitchen utensil into a formidable weapon. Still, some sausages left on it if you're hungry.";
}

if (ID == "Rocket launcher") {
    LongRange = true; // Typically long-range due to the nature of rockets
    damage = 60;
    DurabilityUsage = 5;
    type = "weapon"; 
    durability = 2; // Random durability between 0 and 3
    detail = "High damage, low durability. Unleash destruction with this powerful rocket launcher.";
}

if (ID == "Mike Tyson Gloves") {
    LongRange = false; // Melee weapon
    damage = 15;
    DurabilityUsage = 1; // Assuming no durability usage
    type = "weapon"; 
    durability = 25; // Random durability between 0 and 99
    detail = "Once worn by the legendary boxer Mike Tyson, these gloves hold a special significance. Use them wisely.";
}
	if (ID == "Witcher steel sword") {
    LongRange = false; // Melee weapon
    damage = 30;
    DurabilityUsage = 2; // Moderate durability usage
    type = "weapon"; 
    durability = 20; // Random durability between 0 and 109
    detail = "Forged by skilled craftsmen in the tradition of witcher weaponry, the steel sword carries the legacy of monster hunters. Its keen edge is honed to perfection, capable of cleaving through even the toughest adversaries. A relic of a bygone era, it stands as a symbol of courage and determination in the face of darkness.";
}
	
	
	if (ID == "Sniper rifle") {
    LongRange = true; // Typically long-range weapon
    damage = 55;
    DurabilityUsage = 5; // Moderate durability usage
    type = "weapon"; 
    durability = 25; // Random durability between 0 and 39
    detail = "A precision firearm designed for long-range engagements. With its high-powered scope and exceptional accuracy, the sniper rifle is a formidable tool in the hands of a skilled marksman. Its lethal efficiency makes it a preferred choice for eliminating targets from a distance with surgical precision.";
}
	
	
	if (ID == "Machine gun") {
    LongRange = false; // Typically used for short to mid-range combat
    damage = 45;
    DurabilityUsage = 5; // Moderate durability usage
    type = "weapon"; 
    durability = 50; // Random durability between 0 and 89
    detail = "A heavy-duty automatic firearm capable of sustained rapid fire. While it lacks precision, its high rate of fire and substantial damage output make it devastating in close-quarters combat. The machine gun excels at suppressing enemy positions and laying down a barrage of bullets to overwhelm adversaries.";
}
	
	if (ID == "stapler") {
    LongRange = false; // Melee weapon
    damage = 10;
    DurabilityUsage = 1; // Moderate durability usage
    type = "weapon"; 
    durability = 20; // Random durability between 0 and 59
    detail = "An office stapler repurposed into an unconventional but surprisingly effective melee weapon. Its sturdy build and sharp edges make it capable of delivering painful blows to adversaries. Perfect for those who prefer unconventional combat tactics or find themselves in need of a makeshift weapon.";
}
if (ID == "Lucille") {
    LongRange = false; // Melee weapon
    damage = 30;
    DurabilityUsage = 3; // Moderate durability usage
    type = "weapon"; 
    durability = 30; // Random durability between 0 and 34
    detail = "A baseball bat wrapped in barbed wire, inspired by the weapon wielded by the character Negan in 'The Walking Dead.' It's as brutal as it is iconic, capable of delivering devastating blows to enemies.";
}

if (ID == "Cane") {
    LongRange = false; // Melee weapon
    damage = 15;
    DurabilityUsage = 1; // Low durability usage
    type = "weapon"; 
    durability = 12; // Random durability between 0 and 39
    detail = "An ordinary walking cane repurposed as a makeshift weapon. Despite its humble appearance, it's surprisingly effective in close-quarters combat, offering both reach and blunt force to incapacitate foes.";
}

if (ID == "Axe") {
    LongRange = false; // Melee weapon
    damage = 35;
    DurabilityUsage = 2; // Moderate durability usage
    type = "weapon"; 
    durability = 30; // Random durability between 0 and 59
    detail = "A traditional woodcutter's axe, honed to a razor-sharp edge. Its weight and cutting power make it a formidable choice for hacking through obstacles and enemies alike. With each swing, it cleaves through flesh and bone with brutal efficiency.";
}
if (ID == "Shotgun") {
    LongRange = true; // Typically short to mid-range weapon
    damage = 60;
    DurabilityUsage = 4; // Moderate durability usage
    type = "weapon"; 
    durability = 20; // Random durability between 0 and 69
    detail = "A classic scattergun favored for its devastating close-range firepower. With its wide spread of pellets, the shotgun delivers bone-crushing damage to anything in its path. Perfect for clearing rooms or stopping charging adversaries in their tracks.";
}

if (ID == "Electric Guitar") {
    LongRange = false; // Melee weapon
    damage = 25;
    DurabilityUsage = 2; // Low durability usage
    type = "weapon"; 
    durability = 12; // Random durability between 0 and 44
    detail = "An electric guitar repurposed as an improvised melee weapon. Its solid body and reinforced neck make it surprisingly effective for smashing skulls or delivering electrifying performances on the battlefield.";
}

if (ID == "Dagger") {
    LongRange = false; // Melee weapon
    damage = 25;
    DurabilityUsage = 1; // Low durability usage
    type = "weapon"; 
    durability = 10; // Random durability between 0 and 49
    detail = "A compact and deadly blade designed for swift and silent kills. The dagger's sharp edge and lightweight design make it ideal for concealed carry and close-quarters combat. With a flick of the wrist, it can slip past defenses and strike with lethal precision.";
}

if (ID == "Revolver") {
    LongRange = true; // Short to mid-range firearm
    damage = 40;
    DurabilityUsage = 3; // Moderate durability usage
    type = "weapon"; 
    durability = 21; // Random durability between 0 and 69
    detail = "A classic six-shooter revolver, known for its reliability and stopping power. With its timeless design and rugged construction, the revolver is a trusty sidearm in any situation. Whether fending off bandits or engaging in a duel at high noon, it's a firearm you can count on.";
}

        if(ID=="gun"){
        type="weapon";
        id=ID;
        detail="";
        DurabilityUsage=1;
        damage=25;
        durability=8;
        LongRange=true;
    }
    
    if(ID=="sword"){
        type="weapon";
        id=ID;
        detail="";
        DurabilityUsage=2;
        damage=20;
        durability=16;
        LongRange=false;
    }
    if (ID == "MTs-108") {
    LongRange = true; // Typically long-range weapon
    damage = 55;
    DurabilityUsage = 4; // Moderate durability usage
    type = "weapon"; 
    durability = 24; // Random durability between 0 and 89
    detail = "An antique rifle with a storied history. Despite its age, the MTs-108 boasts impressive accuracy and stopping power. Its timeless design and rugged construction make it a valuable asset in any arsenal.";
}

if (ID == "Wrench") {
    LongRange = false; // Melee weapon
    damage = 20;
    DurabilityUsage = 1; // Low to moderate durability usage
    type = "weapon"; 
    durability = 8; // Random durability between 0 and 59
    detail = "A versatile tool turned makeshift weapon. The wrench's solid construction and hefty weight make it effective for bashing skulls or tightening bolts. Whether repairing machinery or fending off adversaries, it gets the job done.";
}

if (ID == "Whip") {
    LongRange = false; // Melee weapon with some range
    damage = 30;
    DurabilityUsage = 1; // Low to moderate durability usage
    type = "weapon"; 
    durability = 10; // Random durability between 0 and 69
    detail = "A flexible weapon with a long history of use. The whip's long reach and swift strikes make it ideal for keeping enemies at bay or delivering punishing blows from a distance. Its crack echoes through the battlefield, striking fear into the hearts of adversaries.";
}

    }
   void displayInfo() {
    cout << "Weapon ID: " << id << endl;
    cout << "Type: " << type << endl;
    cout << "Damage: " << damage << endl;
    cout << "Durability: " << durability << endl;
    cout << "Durability Usage: " << DurabilityUsage << endl;
    cout << "Long Range: " << (LongRange ? "Yes" : "No") << endl;
    cout << "Description: " << detail << endl;
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
    return (damage * 10) + (durability * 5) - (DurabilityUsage * 60);
}
};
vector<std::string> weaponIDs = {
    "AK-47", "shocker", "bow", "Katana", "pistol", "Frying pan", "Rocket launcher",
    "Mike Tyson Gloves", "Witcher steel sword", "Sniper rifle", "Machine gun", "stapler",
    "Lucille", "Cane", "Axe", "Shotgun", "Electric Guitar", "Dagger", "Revolver",
     "MTs-108", "Wrench", "Whip"
};
#endif 
