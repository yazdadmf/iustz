#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "nonfreindly.h"
#include "Item.h"
#include "Armor.h"
#include "weapon.h"
#include "Throwables.h"
#include "Meds.h"
#include "printstuff.h"
#include "zombie.h"
#include "shop.h"
#include "human_enemy.h"
template<typename T>
void eraseUniquePtr(std::vector<std::unique_ptr<T>>& inventory, T* itemPtr) {
    inventory.erase(std::remove_if(inventory.begin(), inventory.end(), [itemPtr](const std::unique_ptr<T>& ptr) {
        return ptr.get() == itemPtr;
    }), inventory.end());
}
class Party;
class Shop;
class Character
{
public:
    int stamina;
    int vigor, Aim, Strength, Knowledge;
    int level;
    bool defending = false;
    Weapon selah;
    Armor head, middle, lower;
    vector<pair<int, string>> effects;
    int HP;
    int Health;
    string displayFightInfo()
    {
        // heelth stamina damage armor per part
        return "";
    }

    string name;
    Character(){};

    Character(string namee, string characterClass)
    {
        name = namee;
        if (characterClass == "tank")
        {
            Health = 7;
            vigor = 5;
            Strength = 7;
            Aim = 1;
            Knowledge = 0;
            level=20;
            HP=140;
            stamina=100;
            string g="Axe";
            string armor1="militaryHelmet";
    	    string armor2="tacticalVest";
    	    string armor3="combatBoots";

            selah = Weapon(g);
            head = Armor(armor1);
            middle = Armor(armor2);
            lower = Armor(armor3);
        }
        else if (characterClass == "scout")
        {
            Health = 4;
            vigor = 3;
            Strength = 0;
            Aim = 9;
            Knowledge = 4;
            level = 20;
            HP = 4 * 20;
            stamina = 3 * 20;
            string g = "Sniper rifle";
            string armor1 = "naked3";
            string armor2 = "shrekTShirt";
            string armor3 = "flowerSkirt";
            selah = Weapon(g);
            head = Armor(armor1);
            middle = Armor(armor2);
            lower = Armor(armor3);
        }
        else if (characterClass == "survivor")
        {
            Health = 5;
            vigor = 5;
            Strength = 5;
            Aim = 1;
            Knowledge = 4;
            level = 20;
            HP = 5 * 20;
            stamina = 5 * 20;
            string g = "bow";
            string armor1 = "scrapHelmet";
            string armor2 = "scrapChestplate";
            string armor3 = "scrapGreaves";
            selah = Weapon(g);
            head = Armor(armor1);
            middle = Armor(armor2);
            lower = Armor(armor3);
        }
        else if (characterClass == "medic")
        {
            Health = 4;
            vigor = 4;
            Strength = 3;
            Aim = 3;
            Knowledge = 6;
            level = 29;
            HP = 4 * 20;
            stamina = 4 * 20;
            string g = "Lucille";
            string armor1 = "naked3";
            string armor2 = "tacticalVest";
            string armor3 = "wheelchair";
            selah = Weapon(g);
            head = Armor(armor1);
            middle = Armor(armor2);
            lower = Armor(armor3);
        }
        else if (characterClass == "berserker")
        {
            Health = 5;
            vigor = 4;
            Strength = 9;
            Aim = 0;
            Knowledge = 1;
            level = 20;
            HP = 5 * 20;
            stamina = 4 * 20;
            string g = "Frying pan";
            string armor1 = "samuraiHelmet";
            string armor2 = "samuraiChestplate";
            string armor3 = "samuraiLegGuards";
            selah = Weapon(g);
            head = Armor(armor1);
            middle = Armor(armor2);
            lower = Armor(armor3);
        }
    };
    Character(int god)
    {
        if (god == 1)
        {
            name = "jeff1";

            Health = 7;
            vigor = 5;
            Strength = 7;
            Aim = 1;
            Knowledge = 0;
            level = 20;
            HP = 7 * 20;
            stamina = 5 * 20;
        }
        else
        {
            name = "jeff2";

            Health = 7;
            vigor = 5;
            Strength = 7;
            Aim = 1;
            Knowledge = 0;
            level = 20;
            HP = 7 * 20;
            stamina = 5 * 20;
            string wep = "sword";
            string armor1 = "naked3";
            string armor2 = "naked2";
            string armor3 = "naked1";
            selah = Weapon(wep);
            head = Armor(armor1);
            middle = Armor(armor2);
            lower = Armor(armor3);
        }
    };
    void displayStatus()
    {
        cout << "Name: " << name << endl;
        cout << "HP: ";
        barandnumber(HP, Health * 20, "red", 10);
        cout << " | Stamina: ";
        barandnumber(stamina, vigor * 20, "cyan", 10);
        cout << endl;
        effectsstring();
    }
    void displayStatus1()
    {
        cout << "Name: " << name << endl;

        // Display HP and Stamina bars
        cout << "HP: ";
        barandnumber(HP, Health * 20, "red", 10);
        cout << " | Stamina: ";
        barandnumber(stamina, vigor * 20, "cyan", 10);
        cout << endl;

        // Display stats
        cout << "Stats:" << endl;
        cout << "Health: ";
        barandnumber(Health, 10, "red", 1);
        cout << "  \nVigor: ";
        barandnumber(vigor, 10, "green", 1);
        cout << " \nStrength: ";
        barandnumber(Strength, 10, "yellow", 1);
        cout << "  \nAim: ";
        barandnumber(Aim, 10, "magenta", 1);
        cout << "  \nKnowledge: ";
        barandnumber(Knowledge, 10, "blue", 1);
        cout <<"  "<<endl;

        // Display level
        cout << "Level: " << level << endl;

        // Display effects
        cout << "Active Effects: ";
        effectsstring();
        cout << endl;
    }
    void effectsstring()
    {

        for (int i = 0; i < effects.size(); i++)
        {
            if (effects[i].second.back() == '-')
            {
                cout << "|";
                color(effects[i].second, "red");
            }
            else if (effects[i].second.back() == '+')
            {
                cout << "|";
                color(effects[i].second, "green");
            }
            else
            {
                cout

 << "|";
                color(effects[i].second, "yellow");
            }
        }
        cout << endl;
    }

    void applyEffects()
    {
        int damage = 0;
        for (int i = 0; i < effects.size(); i++)
        {
            if (effects[i].first > 1)
            {
                string effectName = effects[i].second;

                if (effectName == "fire")
                {
                    damage += 5;
                }
                else if (effectName == "PoisonDamage")
                {
                    damage += 4;
                }
                effects[i].first -= 1;

                if (effects[i].first == 0)
                {
                    effects.erase(effects.begin() + i);
                    i--; // Adjust index after erasing element
                }
            }
        }
        HP -= damage;
        if (HP < 0)
        {
            HP = 0;
        }
    }
    void getHit(int DAM, int bodypart)
    {
        int damageTaken = DAM;

        // Apply defense reduction based on the body part being hit
        switch (bodypart)
        {
        case 1:

            damageTaken -= head.getDefense();
            break;
        case 2:
            damageTaken -= middle.getDefense();
            break;
        case 3:
            damageTaken -= lower.getDefense();

            break;
        }

        // Apply additional reductions if the character is defending
        if (defending)
        {
            damageTaken *= 0.8;
        }

        // Ensure that damage taken is not negative
        damageTaken = max(0, damageTaken);

        // Deduct the damage from the character's health
        HP -= damageTaken;

        // Ensure that HP doesn't go below 0
        HP = max(0, HP);
        string bodyParts[] = {"head", "middle", "lower"};
        cout << endl
             << "-" << name << " Took ";
        color(to_string(DAM), "red");
        cout << " Damage to ";
        color(bodyParts[bodypart - 1], (bodypart == 1) ? "red" : (bodypart == 2) ? "yellow"
                                                                                 : "blue");
    }


    //****************be careful that aim must be under 10 range****************
    int generateRandomNumber(int aim) {random_device rd;mt19937 gen(rd()); uniform_int_distribution<> distrib(aim, 10); return distrib(gen);}
    void addeffects(vector<pair<int, string>> neew){effects.insert(effects.end(), neew.begin(), neew.end());}
    void levelup(){
    	bool Check = false;
    	if(level < 50){
    		level++;
    		cout << "\nCongratulation! " << name << " level increased to " <<level << ".\nPlease select the ability you want to enhance." << endl ;
    		while(!Check){
				// Display stats
    			cout << "Stats:" << endl;
    			cout << "\n1.Strength: ";
   				barandnumber(Strength, 10, "yellow", 1);
   				cout << "\n2.Health: ";
   				barandnumber(Health, 10, "red", 1);
    			cout << "\n3.Vigor: ";
    			barandnumber(vigor, 10, "green", 1);
    			cout << "\n4.Aim: ";
    			barandnumber(Aim, 10, "magenta", 1);
    			cout << "\n5.Knowledge: ";
    			barandnumber(Knowledge, 10, "blue", 1);
    			cout << endl;

    			// Display level
    			cout << "Level: " << level << endl;
    			int choice=stoi(input({"1", "2", "3", "4", "5"}));
	    		switch (choice){
	    			case 1:
	    				
	    				if(Strength<10){
	    					Strength++;
	    					cout << "strength level increased successfully to: " << Strength << endl;
	    					Check = true;
						}
						else{
							cout << "Your strength level is 10.(MAX) \nPlease choose another option!";}
						break;
                    case 2:
	    				if(Health<10){
	    					Health++;
	    					cout << "Health level increased successfully to: " << Health << endl;
	    					Check = true;
					}
						else{	cout << "Your Health level is 10.(MAX) \nPlease choose another option!";}
						
						break;
	    			case 3:
	    				if(vigor<10){
	    					vigor++;
	    					cout << "Vigor level increased successfully to: " << vigor << endl;
	    					Check = true;
						}
						else{
							cout << "Your vigor level is 10.(MAX) \nPlease choose another option!";
						}
						break;
	    			case 4:
	    				if(Aim<10){
	    					Aim++;
	    					cout << "Aim level increased successfully to: " << Aim << endl;
	    					Check = true;
						}
						else{
							cout << "Your Aim level is 10.(MAX) \nPlease choose another option!";
						}
						break;
	    			case 5:
	    				if(Knowledge!=10){
	    					Knowledge++;
	    					cout << "Knowledge level increased successfully to: " << Knowledge << endl;
	    					Check = true;
						}
						else{
							cout << "Your Knowledge level is 10.(MAX) \nPlease choose another option!";
						}
						break;
					
				}
			}
		}
		else{
			cout << "Your level is maximum, which means it is 50!" << endl;
			cout << "You can't upgrade it anymore." << endl;
		}
	}
	

    
   void attack(nonfreindly* enemy){
		int DAM=selah.use();
        int Aim1=Aim;
        Aim1*=moddifier("Aim");
    	int aim_chance = generateRandomNumber(Aim1);
        int bodypart;
        stamina = stamina - selah.damage / 10;
        if(stamina<0){
                        stamina=0;
        }
        else{
	        if(selah.durability>0){
	        	if (aim_chance==0) { //miss
	        	cout<<"-"<<name;
                color(" missed","yellow");
                cout<<endl;
	           	bodypart = 0;
	           	return ;
				}
		        else if (aim_chance < 4){ //feet
		           	bodypart = 3;
		           	//effect
				}
		        else if (aim_chance < 10){ //body
		            bodypart = 2;
		            //effect
				}
				else if (aim_chance == 10){ //head
					bodypart = 1;
					//effect
				}
		        
				if(selah.LongRange){
                    
					
		            DAM=DAM+DAM*(bodypart*0.2);
		            if(enemy->type=="zombie"){
                    Zombie* enemy1=dynamic_cast<Zombie*>(enemy);
                    cout<<"-"<<name<< " Delt:";
                    color(to_string(DAM),"green");
                    cout<<" Damage"<<endl;
		            enemy1->gethit(DAM,bodypart);}
                    else{
                         Human_enemy* enemy1=dynamic_cast<Human_enemy*>(enemy);
                        cout<<"-"<<name<< " Delt:";
                        color(to_string(DAM),"green");
                        cout<<" Damage"<<endl;
                        enemy1->gethit(DAM,bodypart);
                    }
	        	}
		        
		        else{
                    //nesfe
                    DAM*=moddifier("streght");
		        	//effect
		            DAM=DAM+(Strength*0.1)*DAM+(bodypart*0.05)*DAM;
		            if(rand()%4){
                        //counter zombie
                    }
                   if(enemy->type=="zombie"){
                    Zombie* enemy1=dynamic_cast<Zombie*>(enemy);
                    cout<<"-"<<name<< " Delt:";
                    color(to_string(DAM),"green");
                    cout<<" Damage"<<endl;
		            enemy1->gethit(DAM,bodypart);}
                    else{
                         Human_enemy* enemy1=dynamic_cast<Human_enemy*>(enemy);
                        cout<<"-"<<name<< " Delt:";
                        color(to_string(DAM),"green");
                        cout<<" Damage"<<endl;
                    }
	        	}
		  
	        }
	        else{
	        	DAM=10;
	        if(enemy->type=="zombie"){
                    Zombie* enemy1=dynamic_cast<Zombie*>(enemy);
                    cout<<"-"<<name<< " Delt:";
                    color(to_string(DAM),"green");
                    cout<<" Damage"<<endl;
		            enemy1->gethit(DAM,bodypart);}
                    else{
                         Human_enemy* enemy1=dynamic_cast<Human_enemy*>(enemy);
                        cout<<"-"<<name<< " Delt:";
                        color(to_string(DAM),"green");
                        cout<<" Damage"<<endl;
                    }
                    cout<<"-"<<name<< " Delt";
                    color(to_string(DAM),"green");
                    cout<<" Damage"<<endl;
	        	}
	        		
			}}
		
    	
	
  void useMeds(unique_ptr<Meds>  meds)
{
    vector<pair<int, string>> eff = meds->boosts;
    addeffects(eff);
    if (meds->onUse.second == "stamina")
    {
        stamina += meds->onUse.first;
        if (stamina > vigor * 20)
        {
            stamina = vigor * 20;
        }
    }
    if (meds->onUse.second == "health")
    {
        HP += meds->onUse.first;
        if (HP > Health * 20)
        {
            HP = Health * 20;
        }
    }
    // Release the memory allocated for meds

}




int moddifier(string stat)
{
    int ret = 1;

    for (int i = 0; i < effects.size(); i++)
    {
        if (effects[i].second == stat + "+")
        {
            cout << "Applied strength modifier." << endl;
            ret *= 1.2;
        }
        else if ((effects[i].second == stat + "-"))
        {
            ret *= 0.9;
        }
        else if ((effects[i].second == "stun"))
        {
            cout << "Zombie is stunned." << endl;
            ret = 0;
        }
        else if ((effects[i].second == "slip"))
        {
            if (!(rand() % 4))
            {
                cout << name << " slipped." << endl;
                ret = 0;
            }
        }
        else if ((effects[i].second == "confusion"))
        {
            if (!(rand() % 2))
            {
                cout << name << " is confused." << endl;
                ret = 0.5;
            }
        }
    }

    return ret;
}

string getStaminaCostAttack()
{
    return "";
}

string getStaminaCostDefend()
{
    return "";
}

void equipArmor(unique_ptr<Armor> armor, Party &party);

void equipWeapon(unique_ptr<Weapon> weapon, Party &party);

void checkforlevelup() {}

void gethit1(Throwables *thrown)
{
    getHit(thrown->instantDamage, 2);
    vector<pair<int, string>> effectsh = thrown->effects;
    addeffects(effectsh);
   
}};

void Zombie::Controller::attack(Character &char1, std::vector<std::pair<int, std::string>> attackeffects, Zombie &zombie, std::vector<std::pair<int, std::string>> effects)
{
    int damage = zombie.damagee * moddifier("strength", effects);
    int player_bodypart = rand() % 3 + 1;
    int specialAttack_Chance = rand() % 10;

    if (specialAttack_Chance == 0)
    {
        if (attackeffects.empty())
        {
            damage *= 2;
            std::cout << "Special attack: ";
            std::cout << "- " << zombie.id << " used a special attack!" << std::endl;
        }
        else
        {
            char1.addeffects(attackeffects);
            std::cout << "- " << zombie.id << " applied special effects to the target!" << std::endl;
            return;
        }
    }

    std::cout << "- " << zombie.id << " attacked with ";
    std::cout << "damage: ";
    color(to_string(damage), "red");
    cout << std::endl;
    char1.getHit(damage, player_bodypart);
}

class Party
{
public:
    int wallet = 10;
    vector<Character> group;
    vector<unique_ptr<Item>> inventory;
    void useSelectedItem(Item* selectedItem);
    Party(int god)
    {
        group.push_back(Character(1));
        group.push_back(Character(2));
    }
    bool endingcond(){
        for(int i=0;i<group.size();i++){
            if(group[i].level>49){
                return true;
            }
        }
        return false;
    }
    void buy(unique_ptr<Item> item, Shop &shop)
    {
        if (wallet < item->price)
        {
            cout << "Not enough money to buy " << item->id << endl;
            return;
        }
        wallet -= item->price;
        cout << "Bought " << item->id << " for " << item->price << " coins." << endl;
        addItemToInventory(move(item));
        shop.removeItemFromInventory(item);
        
    }
    void increaseWallet(int amount)
    {
        wallet += amount;
    }
    void removeItemFromInventory(unique_ptr<Item> item)
    {
        auto it = find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end())
        {
            inventory.erase(it);
        }
    }
    void levelup()
    {
        for (int i = 0; i < group.size(); i++)
        {
            group[i].levelup();
        }
    }
    Party(){};
    void sell(unique_ptr<Item> item, Shop &shop)
    {
        wallet += item->price;
        inventory.erase(remove(inventory.begin(), inventory.end(), item), inventory.end());
        shop.addItemToInventory(move(item));
        cout << "Sold " << item->id << " for " << item->price << " coins." << endl;
    }

    void addItemToInventory(unique_ptr<Item> a)
    {   cout << "Added item to inventory: " << a->id << " " << a->type << endl;
        inventory.push_back(move(a));
        
    }

    void addLootToInventory(vector<unique_ptr<Item>>& loot)
    {
        for(int i=0;i<loot.size();i++){
		
            addItemToInventory(move(loot[i]));
        }
    }

    void displaystatus()
    {
        for (int i = 0; i < group.size(); i++)
        {
            group[i].displayStatus();
        }
    }

    bool lose()
    {

        bool ret = true;
        for (int i = 0; i < group.size(); i++)
        {
            if (group[i].HP <= 0)
            {
                cout << group[i].name << " has been defeated." << endl;
            }
            else
            {
                ret = false;
            }
        }
        return ret;
    }

    int lvlsum()
    {

        int ret = 0;
        for (int i = 0; i < group.size(); i++)
        {
            ret += group[i].level;
        }
        return ret;
    }
    bool hintroll()
    {
        for (int i = 0; i < group.size(); i++)
        {
            if (rand() % (11 - group[i].Knowledge) == 0)
            {
                return true;
            }
        }
        return false;
    }
    void applyEffects()
    {
        for (int i = 0; i < group.size(); i++)
        {

            group[i].applyEffects();
        }
    }

    void scrollInventory();
    void manageParty()
    {
        while (true)
        {
            cout << "Manage Party:" << endl;
            cout << "1. Scroll Through Inventory" << endl;
            cout << "2. View Character Status" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                scrollInventory();
                break;
            case 2:
                displayCharacterInfo();
                break;
            case 3:
                return; // Exit the function
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    unique_ptr<Item>craft(Item* item1, Item* item2)
    {
        // Check the type of one of the items (assuming both have the same type)
        string itemType = item1->type;

        // Combine IDs of item1 and item2
        string combinedId = item1->id + item2->id;

        // Vector to store the craftable IDs
        vector<string> craftableIds = {
            "weedweed", "health1stamina1", "health1health1", "stamina1stamina1", "strength1strength1"};

        // Check if the combined ID exists in the craftable IDs
        auto it = find(craftableIds.begin(), craftableIds.end(), combinedId);
        if (it != craftableIds.end())
        {
            // Remove item1 and item2 from inventory and memory
            // Implement removal from inventory

            // Create a new item with the combined ID and type
            unique_ptr<Item> craftedItem = nullptr;
            if (itemType == "Meds")
            {
                unique_ptr<Meds>  meds = make_unique<Meds>(combinedId);
                craftedItem = move(meds);
            }

            // Add the crafted item to inventory
            // Implement addition to inventory

            cout << "Crafted item with ID: " << combinedId << " and type: " << itemType << endl;
           eraseUniquePtr(inventory,item1);
           eraseUniquePtr(inventory,item2);
            // Return the crafted item
            return craftedItem;
        }
        else
        {
            if (!(item1->type == item2->type))
            {
                cout << "Crafting failed. No matching recipe found." << endl;
                return nullptr;
            }
            // repair
            if (item1->type == "weapon")
            {
        		auto weaponPtr = dynamic_cast<Weapon*>(item1);
        		auto weapon2Ptr = dynamic_cast<Weapon*>(item2);
                unique_ptr<Weapon> item11(weaponPtr);
				 unique_ptr<Weapon> item22(weapon2Ptr);
                item22->durability += item11->durability;
                unique_ptr<Item> craftedItem = move(item22);
                eraseUniquePtr(inventory,item1);
           eraseUniquePtr(inventory,item2);
                return craftedItem;
            }
            cout << "Crafting failed. No matching recipe found." << endl;
            return nullptr;
        }
    }
    void displayCraftingOptions(Item* selectedItem, int currentPage, int itemsPerPage);
    void displayInventoryPage(int currentPage, int itemsPerPage);
    void displayNavigationOptions();
    void navigatePreviousPage(int &currentPage);
    void navigateNextPage(int &currentPage, int itemsPerPage);
    void selectItemAction(const std::string &choice, int currentPage, int itemsPerPage);
    void displayItemOptions(Item* selectedItem);
    void displayInventoryPageWithCrossedOut(Item* selectedItem, int currentPage, int itemsPerPage);

unique_ptr<Item> chooseusableitem()
{
    while (true)
    {
        cout << "-------------------------------------------------------" << endl;
        int row = 0;
        cout << "Select an item to use:" << endl;
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i]->type == "Meds" || inventory[i]->type == "Throwables")
            {
                cout << i + 1 << ". " << setw(18) << left << inventory[i]->id;
                row++;
                if (row % 4 == 0)
                {
                    cout << endl;
                }
            }
        }
        cout << endl
             << "-------------------------------------------------------" << endl;

        int choice;
        cout << "Enter the number of the item you want to use (0 to cancel): ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Operation canceled." << endl;
            return nullptr; // Cancel operation
        }

        if (choice < 1 || choice > inventory.size())
        {
            cout << "Invalid choice. Please try again." << endl;
            continue; // Restart the loop
        }

        // Adjust index to match vector indexing
        int index = choice - 1;

        cout << "You selected:" << endl;
        cout << "Item ID: " << inventory[index]->id << endl;
        cout << "Item Details: " << inventory[index]->detail << endl;

        // Confirm the selection

        cout << "Are you sure you want to use this item? (Y/N)\n ";
        char confirm = _getch();
        if (confirm == 'Y' || confirm == 'y')
        {
             unique_ptr<Item> selected =move(inventory[index]);
            inventory.erase(inventory.begin() + index);
            return selected;
        }
        else
        {
            cout << "Operation canceled." << endl;
            continue;       // Restart the loop
            return nullptr; // Cancel operation
        }
    }
}

void displayCharacterInfo();
};
// Class representing a shop
void	 Shop::scrollThroughSellInventory(Party& party) {
         const int itemsPerPage = 5;
    size_t currentPage = 0;

  while (true) {
    system("cls");
    cout << "Your Inventory (Page " << currentPage + 1 << "):" << endl;
    for (size_t i = currentPage * itemsPerPage; i < min((currentPage + 1) * itemsPerPage, party.inventory.size()); ++i) {
        color("┌───────┬─────────────────────┬───────────────────┐" ,"cyan");
        cout << endl;
        color("│ ","cyan"); 
        cout << setw(6) << left << i + 1;
        color("│ ","cyan");
        cout << setw(20) << left << party.inventory[i]->id;
        color("│ ","cyan");

        // Type casting and getting the price
        if (const auto& meds = dynamic_cast<Meds*>(party.inventory[i].get())) {
            cout << "Price: " << setw(10) << meds->getPrice();
        } else if (const auto& weapon = dynamic_cast<Weapon*>(party.inventory[i].get())) {
            cout << "Price: " << setw(10) << weapon->getPrice();
        } else if (const auto& throwables = dynamic_cast<Throwables*>(party.inventory[i].get())) {
            cout << "Price: " << setw(10) << throwables->getPrice();
        } else if (const auto& armor = dynamic_cast<Armor*>(party.inventory[i].get())) {
            cout << "Price: " << setw(10) << armor->getPrice();
        }
        color(" │ ","cyan"); 
        cout << endl;
        color("└───────┴─────────────────────┴───────────────────┘","cyan");
        cout << endl;
    }

    cout << "Enter 'next' to see the next page, 'prev' to see the previous page, or type 'back' to return to the main menu: ";
    string inputStr;
    cin >> inputStr;

    if (inputStr == "back") {
        break;
    } else if (inputStr == "next") {
        ++currentPage;
        if (currentPage * itemsPerPage >= party.inventory.size()) {
            currentPage = 0;
        }
    } else if (inputStr == "prev") {
        if (currentPage == 0) {
            currentPage = (party.inventory.size() - 1) / itemsPerPage;
        } else {
            --currentPage;
        }
    } else {
        // Check if the input is a valid item index
        int itemIndex = stoi(inputStr) - 1;
        if (itemIndex >= 0 && itemIndex < party.inventory.size()) {
            sellItem(party, itemIndex);
        } else {
            cout << "Invalid input! Please enter a valid item index." << endl;
        }
    }
}}
 void Shop::sellItem(Party& party, int itemIndex) {
        if (itemIndex >= 0 && itemIndex < party.inventory.size()) {
            party.increaseWallet(party.inventory[itemIndex]->price); // Implement increaseWallet function in Party class
            cout << "You sold: " << party.inventory[itemIndex]->id << endl;
            // Add item to shop inventory
            inventory.push_back(move(party.inventory[itemIndex]));
            party.inventory.erase(party.inventory.begin() + itemIndex);
            sleep(5);
           
        } else {
            cout << "Invalid item index." << endl;
            sleep(1);
        }
    }

void Shop::buyItem(Party &party, int itemIndex)
{
    if (itemIndex >= 0 && itemIndex < inventory.size())
    {
        Item* itemToBuy =inventory[itemIndex].get();
        if (party.wallet < itemToBuy->price)
        {
            cout << "You don't have enough coins to buy " << itemToBuy->id << "." << endl;
            return;
        }
        party.wallet -= itemToBuy->price;
        cout << "You bought " << itemToBuy->id << " for " << itemToBuy->price << " coins." << endl;
        party.addItemToInventory(move(inventory[itemIndex]));
        inventory.erase(inventory.begin() + itemIndex);
        sleep(5);
       
    }
    else
    {
        cout << "Invalid item index." << endl;
        sleep(1);
    }
}

void Party::scrollInventory()
{
    const int itemsPerPage = 9; // 3x3 table = 9 items per page
    int currentPage = 0;

    while (true)
    {
        // Display inventory page
        displayInventoryPage(currentPage, itemsPerPage);

        // Display page navigation options
        displayNavigationOptions();

        // Get user input for page navigation or item selection
        std::string choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Process user choice
        if (choice == "P" || choice == "p")
        {
            navigatePreviousPage(currentPage);
        }
        else if (choice == "N" || choice == "n")
        {
            navigateNextPage(currentPage, itemsPerPage);
        }
        else if (choice == "Q" || choice == "q")
        {
            break; // Quit
        }
        else
        {
            selectItemAction(choice, currentPage, itemsPerPage);
        }
    }
}

void Party::displayInventoryPage(int currentPage, int itemsPerPage)
{
    std::cout << "Inventory Page " << currentPage + 1 << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    int startIndex = currentPage * itemsPerPage;
    int endIndex = std::min(startIndex + itemsPerPage, static_cast<int>(inventory.size()));

    // Print items in a 3x3 table
    for (int i = startIndex; i < endIndex; i += 3)
    {
        for (int j = 0; j < 3 && i + j < endIndex; ++j)
        {
            std::cout << "[" << i + j + 1 << "] " << inventory[i + j]->id << " (" << inventory[i + j]->type << ")\t";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}

void Party::displayNavigationOptions()
{
    std::cout << "Page Navigation: [P]revious | [N]ext | [Q]uit" << std::endl;
}

void Party::navigatePreviousPage(int &currentPage)
{
    if (currentPage > 0)
    {
        --currentPage;
        std::cout << "Navigated to previous page." << std::endl;
    }
    else
    {
        std::cout << "You are already on the first page." << std::endl;
    }
}

void Party::navigateNextPage(int &currentPage, int itemsPerPage)
{
    int startIndex = currentPage * itemsPerPage;
    int endIndex = std::min(startIndex + itemsPerPage, static_cast<int>(inventory.size()));
    if (endIndex < static_cast<int>(inventory.size()))
    {
        ++currentPage;
        std::cout << "Navigated to next page." << std::endl;
    }
    else
    {
        std::cout << "You are already on the last page." << std::endl;
    }
}

void Party::selectItemAction(const std::string &choice, int currentPage, int itemsPerPage)
{
    int itemIndex = std::stoi(choice) - 1;
    int startIndex = currentPage * itemsPerPage;
    int endIndex = std::min(startIndex + itemsPerPage, static_cast<int>(inventory.size()));

    if (itemIndex >= startIndex && itemIndex < endIndex)
    {
       auto selecteditem=inventory[itemIndex].get();
        displayItemOptions(selecteditem);
    }
    else
    {
        std::cout << "Invalid item index. Please try again." << std::endl;
    }
}

void Party::displayItemOptions(Item* selectedItem)
{
    std::cout << "Item Info: " << selectedItem->detail << std::endl;
    std::cout << "1. Appraise" << std::endl;
    std::cout << "2. Use Item" << std::endl;
    std::cout << "3. Craft" << std::endl;
    std::cout << "4. Discard Item" << std::endl;
    std::cout << "5. Go Back" << std::endl;
    std::cout << "Enter your choice: ";

    int option;
    std::cin >> option;

    switch (option) {
        case 1: {
            // Appraise item
            if (selectedItem->type == "weapon") {
                Weapon* weaponItem = dynamic_cast<Weapon*>(selectedItem);
                if (weaponItem != nullptr) {
                    weaponItem->displayInfo();
                }
            } else if (selectedItem->type == "armor") {
                Armor* armorItem = dynamic_cast<Armor*>(selectedItem);
                if (armorItem != nullptr) {
                    armorItem->displayInfo();
                }
            } else if (selectedItem->type == "Meds") {
                Meds* medsItem = dynamic_cast<Meds*>(selectedItem);
                if (medsItem != nullptr) {
                    medsItem->displayInfo();
                }
            } else if (selectedItem->type == "Throwables") {
                Throwables* throwablesItem = dynamic_cast<Throwables*>(selectedItem);
                if (throwablesItem != nullptr) {
                    throwablesItem->displayInfo();
                }
            } else {
                std::cout << "Unknown item type." << std::endl;
            }
            break;
        }
            break;
        case 2:
            // Use item
            if (selectedItem->type == "Throwables") {
                std::cout << "Cannot use throwables outside of combat." << std::endl;
            } else {
                useSelectedItem(selectedItem);
            }
            break;
        case 3:
            // Craft option
            displayCraftingOptions(selectedItem,0,9);
            break;
        case 4:{
		
	
        
           eraseUniquePtr(inventory,selectedItem);
			break;}
		case 5:
			break;    
        
        // Add cases for other options if needed
    }
}

void Party::displayCraftingOptions(Item* selectedItem, int currentPage, int itemsPerPage)
{
    std::cout << "Select another item to craft with " << selectedItem->id << ":" << std::endl;

    // Display inventory again with crossed out previously selected item
    displayInventoryPageWithCrossedOut(selectedItem, currentPage, itemsPerPage);

    // Display page navigation options
    displayNavigationOptions();

    std::string input;
    std::cout << "Enter the index of the second item or 'Q' to cancel: ";
    std::cin >> input;

    if (input == "Q" || input == "q")
    {
        std::cout << "Crafting canceled." << std::endl;
    }
    else if (input == "P" || input == "p")
    {
        displayCraftingOptions(selectedItem, currentPage - 1, itemsPerPage);
    }
    else if (input == "N" || input == "n")
    {
        displayCraftingOptions(selectedItem, currentPage + 1, itemsPerPage);
    }
    else
    {
        int secondItemIndex = std::stoi(input) - 1;
        int startIndex = currentPage * itemsPerPage;
        int endIndex = std::min(startIndex + itemsPerPage

, static_cast<int>(inventory.size()));

        if (secondItemIndex >= startIndex && secondItemIndex < endIndex)
        {
            auto secondItem =inventory[secondItemIndex].get();

            // Now you have both selected items (selectedItem and secondItem)
            // Perform crafting operations here
            std::cout << "Crafting " << selectedItem->id << " with " << secondItem->id << "..." << std::endl;
            auto crafted=craft(selectedItem,secondItem);
            if(crafted==nullptr){
			}
			else{
			
            inventory.push_back(move(crafted));}
        }
        else
        {
            std::cout << "Invalid item index. Please try again." << std::endl;
        }
    }
}

void Party::displayInventoryPageWithCrossedOut(Item* selectedItem, int currentPage, int itemsPerPage)
{
    int totalPages = (inventory.size() + itemsPerPage - 1) / itemsPerPage; // Calculate total pages
    if (currentPage < 0 || currentPage >= totalPages)
    {
        // Adjust currentPage to the closest valid page
        currentPage = std::max(0, std::min(currentPage, totalPages - 1));
        std::cout << "Page number out of bounds. Displaying closest valid page: " << currentPage + 1 << std::endl;
    }


    std::cout << "Inventory Page " << currentPage + 1 << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    int startIndex = currentPage * itemsPerPage;
    int endIndex = std::min(startIndex + itemsPerPage, static_cast<int>(inventory.size()));

    // Print items in a 3x3 table
    for (int i = startIndex; i < endIndex; i += 3)
    {
        for (int j = 0; j < 3 && i + j < endIndex; ++j)
        {	Item* check=inventory[i + j].get();
            if (check == selectedItem)
            {
                std::cout << "[X] ";
            }
            else
            {
                std::cout << "[" << i + j + 1 << "] ";
            }
            std::cout << inventory[i + j]->id << " (" << inventory[i + j]->type << ")\t";
        }
        std::cout << std::endl;
    }



}

void Human_enemy::Controller::attack(Character& Character, std::vector<std::pair<int, std::string>> effects, Human_enemy& zombie) {
  	int bodypart = rand() % 3 + 1;
  			int mod=moddifier("strenght",effects);
			
	        if (zombie.getstate() == 3 || zombie.HP == zombie.maxHP){
	        	if(zombie.maxHP/zombie.HP <= 2){
	        		Character.getHit(zombie.weapon.damage*(0.4)*mod*(zombie.stamina/100),bodypart);
	        		zombie.stamina -= 10;
              cout << "The enemy strikes with great force!" << endl;
				}
				else if(zombie.maxHP/zombie.HP <= 4 && zombie.maxHP/zombie.HP > 2){
					Character.getHit(zombie.weapon.damage*(0.6)*mod*(zombie.stamina/100),bodypart - 1);
					zombie.stamina -= 20;
          cout << "The enemy delivers a powerful blow!" << endl;
				}
				else if(zombie.maxHP/zombie.HP > 4){
					Character.getHit(zombie.weapon.damage*(1.1)*mod*(zombie.stamina/100),bodypart-2);
					zombie.stamina -= 40;
          cout << "The enemy unleashes an overwhelming attack!" << endl;
				}
	        }

	        else if (zombie.getstate() == 2 ){
	            zombie.HP += 20;
                if(zombie.HP > zombie.maxHP){zombie.HP=zombie.maxHP;}
              cout << "The enemy is healing itself!" << endl;
			}
	
	        else if (zombie.getstate() == 1){
	        	Character.gethit1(&zombie.throwables);
            cout << "The enemy throws something at you!" << endl;
	            }
	        
	    }



#endif // CHARACTER_H
