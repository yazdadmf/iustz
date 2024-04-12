


#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <windows.h>
#include <memory>
#ifdef MY_SYSTEM
#include "save.h"
#include <nlohmann/json.hpp>
 using json = nlohmann::json;
#endif
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Fishing.h" // Include the fishing minigame header file
#include <conio.h>
#include "Meds.h"
#include "PrintStuff.h"
#include "Character.h"
#include "NonFreindly.h"
#include "Zombie.h"
#include "Shop.h"
#include "human_enemy.h"
#include <cstdlib>



using namespace std;

vector<string> playlist = {"C:\\Users\\me1382\\Desktop\\dalgh 4.3\\dalgh 4.3\\dalgh 5\\music\\Ost1.wav",
                           "C:\\Users\\me1382\\Desktop\\dalgh 4.3\\dalgh 4.3\\dalgh 5\\music\\Ost2.wav"};

// Function to create a non-friendly entity based on the given level
nonfreindly *factory(int level)
{
    vector<string> zombie_ids = {"zombie.", "fast zombie", "smart zombie", "screamer zombie", "body builder zombie", "explosive zombie",
                                 "A zombie who didn't eat breakfast",
                                 "Nigger zombie", "zombie succubus", "Zombie batman"};
    vector<string> human_ids = {"police officer", "handicap old man", "vladimir putin",
                                "kazem forghani", "Mr.X", "Soilder guy", "THE shop keeper", "Drunk teenager", "guardian of hell", "banana man", "spartan soldier"};
    if (level < 44)
    {
        return new Zombie(zombie_ids[rand() % zombie_ids.size()]);
    }
    else
    {
        if ((rand() % 2))
        {
            return new Human_enemy(human_ids[rand() % human_ids.size()]);
        }
        return new Zombie(zombie_ids[rand() % zombie_ids.size()]);
    }
}

// Function to simulate an encounter between the player party and a non-friendly entity
void encounter(Party &party, nonfreindly *Enemy)
{
#ifdef MY_SYSTEM
    PlaySound(NULL, NULL, SND_PURGE);
    std::string filePath = "C:\\Users\\me1382\\Desktop\\dalgh 4.3\\dalgh 4.3\\dalgh 5\\music\\battle.wav";
    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
#endif
    int target = 4; // Default target for defending
    bool m;
	cout<<Enemy->discription<<endl;
    if (party.hintroll())
    {
        cout <<party.group[rand() % party.group.size()].name << ": " << Enemy->hint << endl;
    }
    while (true)
    {
        // Display status of party and zombie
        party.displaystatus();
        Enemy->displaystatus();

        // Display options for each character in the party
        for (int i = 0; i < party.group.size(); i++)
        {
        move:
            if (!(party.group[i].HP > 0))
            {
                if (party.lose())
                {
                    break;
                }
            }
            else
            {
                // Print available actions for the character
                cout << "\n------------------------\n"
                     << setw(10) << left << "1. Attack"
                     << "| " << setw(10) << "2. Use item"
                     << "| " << setw(10) << "3. Defend\n"
                     << "------------------------\n";

                // Check for user input
                char key = _getch(); // Get the pressed key
                switch (key)
                {
                case '1':
                    // Perform attack action
                    cout << party.group[i].name << " is attacking." << endl;
                    party.group[i].attack(Enemy);
                    break;
                case '2':
                {
                    // Perform use item action
                    auto item = party.chooseusableitem();
                    if (item == nullptr)
                    {
                        goto move;
                    }
                    if (item->type == "Meds")
                    {
                        cout << party.group[i].name << " is using meds." << endl;
                        unique_ptr<Meds> meds=make_unique<Meds>(*static_cast<Meds *>(item.get()));
                        party.group[i].useMeds(move(meds));
                    }
                    else
                    {
                        cout << party.group[i].name << " is using throwables." << endl;
                        unique_ptr<Throwables> thrown=make_unique<Throwables>(static_cast<Throwables *>(item.get()));
                        Enemy->gethit1(thrown);
                    }
                    break;
                }
                case '3':
                    // Perform defend action
                    if (target != 4)
                    {
                        cout << party.group[target].name << " is already defending." << endl;
                        goto move;
                    }
                    else
                    {
                        cout << party.group[i].name << " is defending." << endl;
                        party.group[i].defending = true;
                        target = i;
                    }
                    break;
                default:
                    cout << "Invalid input. Please try again." << endl;
                    goto move;
                    break;
                }
            }
        }
    m = party.lose();
if (m)
{
    death();
    cout << "Game over!!!" << endl;
    break;
}
else if (Enemy->health <= 0)
{

    cout << "YOU WON!!!" << endl;
    break;
}

// Zombie attacks
if (target == 4)
{
    int adad = rand() % party.group.size();
    cout << Enemy->id << " is attacking " << party.group[adad].name << endl;
    Enemy->attack(party.group[adad]);
}
else
{
    cout << Enemy->id << " is attacking " << party.group[target].name << endl;
    Enemy->attack(party.group[target]);
    party.group[target].defending = false;
    target = 4;
}

// Check if the fight should end
m = party.lose();

if (m)
{
    death();
    cout << "Game over!!!" << endl;
    break;
}
else if (Enemy->health <= 0)
{

    cout << "YOU WON!!!" << endl;
    break;
}

// Apply effects
party.applyEffects();
Enemy->applyeffects();

// Check if the fight should end again
m = party.lose();
if (m)
{
    death();
    cout << "Game over!!!" << endl;
    break;
}
else if (Enemy->health <= 0)
{

    cout << "YOU WON!!!" << endl;
    break;
}

// Delay to control loop iteration rate
Sleep(2000);

// Clear screen for next iteration
system("cls");
}
#ifdef MY_SYSTEM
PlaySound(NULL, NULL, SND_PURGE);
#endif
}
	

// Check if the fight should end again



template<typename T>
unique_ptr<T>& findUniquePtr(vector<unique_ptr<T>>& inventory, T* itemPtr) {
    auto it = find_if(inventory.begin(), inventory.end(), [itemPtr](const unique_ptr<T>& ptr) {
        return ptr.get() == itemPtr;
    });

    if (it != inventory.end()) {
        return *it;
    } else {
        // Handle the case where the item pointer is not found in the inventory
        // For simplicity, let's return a reference to the first element
        return inventory.front();
    }
}

void Party::useSelectedItem(Item* selectedItem)

{
	
    cout << "You selected item: " << selectedItem->id << endl;
    cout << "Now select a character from your party:" << endl;
    for (int i = 0; i < group.size(); ++i)
    {
        cout << i + 1 << ". " << group[i].name << endl;
    }
    int characterIndex;
    cout << "Enter the number of the character: ";
    cin >> characterIndex;
    if (characterIndex < 1 || characterIndex > group.size())
    {
        cout << "Invalid character selection." << endl;
        return;
    }

    Character &selectedCharacter = group[characterIndex - 1];

    if (selectedItem->type == "Meds")
    {
        cout << "Item Info: " << selectedItem->detail << endl;
        cout << "Do you want to use " << selectedItem->id << "? (Y/N): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y')
        {
           unique_ptr<Meds> meds=make_unique<Meds>(*static_cast<Meds *>(selectedItem));
            selectedCharacter.useMeds(move(meds));
            eraseUniquePtr(inventory,selectedItem);
        }
        else
        {
            cout << "Operation canceled. Returning to item selection." << endl;
        }
    }
    else if (selectedItem->type == "armor")
    {
        unique_ptr<Armor> selectedArmor=make_unique<Armor>(*static_cast<Armor *>(selectedItem));
        int selectedDefense = selectedArmor->defense;

        int currentDefense = 0;
        int currentDurability = 0;
        string bodypart;
        switch (selectedArmor->bodypart)
        {
        case 1:
            currentDefense = selectedCharacter.head.defense;

            bodypart = "head";
            break;
        case 2:
            currentDefense = selectedCharacter.middle.defense;

            bodypart = "middle";
            break;
        case 3:
            currentDefense = selectedCharacter.lower.defense;

            bodypart = "lower";
            break;
        default:
            cout << "Invalid body part." << endl;
            break;
        }

        cout << "Character's Current Armor (Body Part " << bodypart << "):" << endl;
        cout << "Defense: " << currentDefense << endl;
        cout << selectedArmor->id << endl;
        cout << "Defense:";
        color(to_string(selectedDefense), selectedDefense > currentDefense ? "green" : (selectedDefense < currentDefense ? "red" : "white"));

        // Prompt for confirmation
        cout << "Do you want to equip " << selectedItem->id << "? (Y/N): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y')
        {

            selectedCharacter.equipArmor(move(selectedArmor), *this);
            eraseUniquePtr(inventory,selectedItem);
        }
        else
        {
            cout << "Operation canceled. Returning to item selection." << endl;
        }
    }
    else if (selectedItem->type == "weapon")
    {
        unique_ptr<Weapon> selectedWeapon=make_unique<Weapon>(*static_cast<Weapon *>(selectedItem));
        int selectedDamage = selectedWeapon->damage;
        int currentDamage = selectedCharacter.selah.damage;

        cout << "Character's Current Weapon: " << selectedCharacter.selah.id << "Damage:" << currentDamage << endl;
        cout << "Selected Weapon: " << selectedItem->id << endl;

        // Display the comparison result with color coding
        cout << "Damage: ";
        color(to_string(selectedDamage), selectedDamage > currentDamage ? "green" : (selectedDamage < currentDamage ? "red" : "white"));
        cout << endl;

        // Prompt for confirmation
        cout << "Do you want to equip " << selectedItem->id << "? (Y/N): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y')
        {
            selectedCharacter.equipWeapon(move(selectedWeapon), *this);
             eraseUniquePtr(inventory,selectedItem);
        }
        else
        {
            cout << "Operation canceled. Returning to item selection." << endl;
        }
    }
    else
    {
        cout << "Invalid item type." << endl;
    }
}

void Party::displayCharacterInfo()
{
    // Display character selection menu
    cout << "Select a character to view their information:" << endl;
    for (int i = 0; i < group.size(); ++i)
    {
        cout << i + 1 << ". " << group[i].name << endl;
    }
    int characterIndex;
    cout << "Enter the number of the character: ";
    cin >> characterIndex;
    if (characterIndex < 1 || characterIndex > group.size())
    {
        cout << "Invalid character selection." << endl;
        return;
    }

    // Display selected character's information
    Character &selectedCharacter = group[characterIndex - 1];
    selectedCharacter.displayStatus1();
    // Add more information as needed
}

vector<unique_ptr<Item>> generateRandomLoot(int numWeapons, int numMeds, int numArmor, int numThrowables)
{
    vector<unique_ptr<Item>> loot;

    vector<string> weaponIDs = {"AK-47", "shocker", "bow", "Katana", "pistol", "Frying pan", "Rocket launcher",
                                "Mike Tyson Gloves", "Witcher steel sword", "Sniper rifle", "Machine gun", "stapler",
                                "Lucille", "Cane", "Axe", "Shotgun", "Electric Guitar", "Dagger", "Revolver",
                                "MTs-108", "Wrench", "Whip"};

    vector<string> medsIDs = {"stamina1", "health1", "weedweed", "strenght1", "knowledge", "health1stamina1",
                              "lean", "weed", "health1health1", "health2", "stamina1stamina1", "stamina2",
                              "strenght2", "strength1strength1", "energydrink", "adrenalineshot"};
    vector<string> armorIDs = {
        "clownShoes", "clownJumpsuit", "clownHat", "samuraiHelmet", "samuraiChestplate",
        "samuraiLegGuards", "trashBin", "wheelchair", "flowerSkirt", "shrekTShirt",
        "bush", "militaryHelmet", "tacticalVest", "combatBoots", "scrapHelmet",
        "scrapChestplate", "scrapGreaves", "chainmailCoif", "plateArmor", "greavesSabatons"};

    vector<string> throwablesIDs = {"molotov", "grenade", "kitty", "batrang", "slippers",
                                    "snowball", "rock", "oxford dictionary", "peel of banana", "shuriken", "smoke bomb"};

    srand(time(NULL));
    for (int i = 0; i < numWeapons; ++i)
    {
        string randomWeaponID = weaponIDs[rand() % weaponIDs.size()];
        loot.push_back(move(make_unique<Weapon>(randomWeaponID)));
    }

    for (int i = 0; i < numMeds; ++i)
    {
        string randomMedsID = medsIDs[rand() % medsIDs.size()];
        loot.push_back(move(make_unique<Meds>(randomMedsID)));
    }

    for (int i = 0; i < numArmor; ++i)
    {
        string randomArmorID = armorIDs[rand() % armorIDs.size()];
        loot.push_back(move(make_unique<Armor>(randomArmorID)));
    }

    for (int i = 0; i < numThrowables; ++i)
    {
        string randomThrowablesID = throwablesIDs[rand() % throwablesIDs.size()];
        loot.push_back(move(make_unique<Throwables>(randomThrowablesID)));
    }

    return loot;
}
void Character::equipArmor(std::unique_ptr<Armor> armor, Party& party) {
    // Equip the armor to the appropriate body part
    if (armor->bodypart == 1) {
        // Head armor
        if (head.id != "naked1") {
            // If there was already armor equipped, add it back to the inventory
            cout << "You're equipping " << armor->id << " to your head, replacing your previous head armor." << endl;
            party.inventory.push_back(std::move(unique_ptr<Armor>(&head)));
        }
        
        head=*armor;
        armor.reset();
    } else if (armor->bodypart == 2) {
        // Middle armor
        if (middle.id != "naked2") {
            // If there was already armor equipped, add it back to the inventory
            cout << "You're equipping " << armor->id << " to your middle, replacing your previous middle armor." << endl;
            party.inventory.push_back(std::move(unique_ptr<Armor>(&middle)));
        }
        middle=*armor;
        armor.reset();
    } else if (armor->bodypart == 3) {
        // Lower armor
        if (lower.id != "naked3") {
            // If there was already armor equipped, add it back to the inventory
            cout << "You're equipping " << armor->id << " to your lower part, replacing your previous lower armor." << endl;
            party.inventory.push_back(std::move(unique_ptr<Armor>(&lower)));
        }
        lower=*armor;
        armor.reset();
    }
}


void Character::equipWeapon(std::unique_ptr<Weapon> weapon, Party& party) {
    // Create a copy of the current weapon
    std::unique_ptr<Weapon> currentWeapon = std::make_unique<Weapon>(&selah);

    // Check if the weapon is part of the "naked" set
    if (currentWeapon->id.find("naked") == string::npos) {
        // Add the currently equipped weapon to the inventory
        cout << "You're unequipping " << currentWeapon->id << " and adding it to your inventory." << endl;
        party.inventory.push_back(std::move(currentWeapon));
    }

    // Equip the weapon
    selah = *weapon;
    weapon.reset();
}

void shopInteraction(Party &party)
{
    // Enter the shop
    Shop shop;
    cout << "Entering the shop..." << endl;
    cout << "Shop Menu:" << endl;
    cout << "1. Buy Item" << endl;
    cout << "2. Sell Item" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";

    int shopChoice;
    cin >> shopChoice;

    switch (shopChoice)
    {
    case 1:
        cout << "Entering Buy Menu..." << endl;
        shop.scrollThroughBuyInventory(party); // Enter the shop to buy items
        break;
    case 2:
        cout << "Entering Sell Menu..." << endl;
        shop.scrollThroughSellInventory(party); // Enter the shop to sell items
        break;
    case 3:
        cout << "Exiting shop..." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}
Party partyconstructor()
{ system("cls");
typeText("As the music blared and the lights flashed, a group of friends crowded into a small apartment, ready to party.\n");
    typeText("Beer cans littered the floor and a cloud of smoke hung in the air.\n");
    typeText("But little did they know, their night was about to take a drastic turn.\n\n");

   
    typeText("As the clock struck midnight, everything suddenly went black.\n");
    typeText("Confused and disoriented, the friends stumbled around in the dark, trying to figure out what was happening.\n");
    typeText("Suddenly, a bright light appeared, and a booming voice echoed in their heads.\n\n");


    typeText("'I am the Almighty, the Creator of all worlds,' the voice said.\n");
    typeText("'You have been summoned here for a purpose.'\n\n");


    typeText("The friends looked at each other in shock, unsure of what was happening.\n");
    typeText("The voice continued.\n\n");
    typeText("'In your world, you have been indulging in drugs and alcohol, poisoning your bodies and minds.\n");
    typeText("But in this world, things are different.\n");
    typeText("You have been brought here to learn and grow, to make amends for your past actions.'\n\n");


    typeText("The friends were suddenly transported to a vast, otherworldly land.\n");
    typeText("The sky was a surreal lavender color and the ground was made of sparkling crystals.\n");
    typeText("In front of them stood a majestic figure, their true form radiating with a divine glow.\n\n");


    typeText("'You must now face the consequences of your choices,' the deity said.\n");
    typeText("'But fear not, for I offer you a chance at redemption.\n");
    typeText("Will you accept the challenge?'\n\n");


    typeText("The friends looked at each other, and with a sense of determination, they nodded.\n");
    typeText("They knew this was their chance to make things right.\n\n");


    typeText("And so, their journey in this new world began.\n");
    typeText("They faced challenges and obstacles, but they also found joy and purpose.\n");
    typeText("As they learned and grew.\n");
    typeText("Press Enter to begin your adventure.");
   
    while (true) {
            if (_kbhit()) {
                if (_getch() == 13) // 13 is the Enter key
                    break;
            }
        }
    #ifdef MY_SYSTEM
    PlaySound(NULL, NULL, SND_PURGE);
    std::string filePath = "C:\\Users\\me1382\\Desktop\\dalgh 8\\music\\intro.wav";
    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
#endif
    intro(); 
    system("cls"); 
	Party party;
	 SetConsoleOutputCP(CP_UTF8);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Specify the font name
    wcscpy(fontInfo.FaceName, L"Segoepr");

    // Set the font size
    fontInfo.dwFontSize.X = 12;
    fontInfo.dwFontSize.Y = 16; // Font size in pixels

    // Set the console font
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    cout << "Enter the number of players (1 or 2): ";
    int numPlayers;
    cin >> numPlayers;

    if (numPlayers == 1)
    {
        // Single player mode
        cout << "Welcome to single player mode." << endl;
        cout << "Enter your character's name: ";
        string playerName;
        cin.ignore(); // Clear the input buffer
        getline(cin, playerName);

        // Replace spaces with hyphens
        for (char &ch : playerName)
        {
            if (ch == ' ')
                ch = '-';
        }

        vector<string> characterClasses = {"tank", "scout", "survivor", "medic", "berserker"};
        cout << "Choose a character class: tank, scout, survivor, medic, berserker" << endl;
        string characterClass = input(characterClasses);

        party.group.push_back(Character(playerName, characterClass));
    }
    else if (numPlayers == 2)
    {
        // Multiplayer mode
        cout << "Welcome to multiplayer mode." << endl;
        cout << "Enter first player's character name: ";
        string playerName1;
        cin.ignore(); // Clear the input buffer
        getline(cin, playerName1);

        // Replace spaces with hyphens
        for (char &ch : playerName1)
        {
            if (ch == ' ')
                ch = '-';
        }

        vector<string> characterClasses = {"tank", "scout", "survivor", "medic", "berserker"};
        cout << "Choose a character class for player 1: tank, scout, survivor, medic, berserker" << endl;
        string characterClass1 = input(characterClasses);

        party.group.push_back(Character(playerName1, characterClass1));

        cout << "Enter second player's character name: ";
        string playerName2;
        getline(cin, playerName2);

        // Replace spaces with hyphens
        for (char &ch : playerName2)
        {
            if (ch == ' ')
                ch = '-';
        }

        cout << "Choose a character class for player 2: tank, scout, survivor, medic, berserker" << endl;
        string characterClass2 = input(characterClasses);
        party.group.push_back(Character(playerName2, characterClass2));
    }

    return party;
}
void fishingintraction(Party &party){
    // Ask player for help with fishing
        cout << "Hey there! I could really use some help with fishing. Would you like to assist me? (Y/N): ";
        char response;
        cin >> response;

        if (response == 'Y' || response == 'y') {
            cout << "Fantastic! Fishing pays well, and I'll split the rewards with you." << endl;
            
            srand(time(0)); // Seed the random number generator
            FishingMinigame fishingMinigame;
            fishingMinigame.play();
            cout<<"Thanks for the help heres your reward pal.";
            party.wallet+=fishingMinigame.fishCount*50;
            cout<<"+ "<<fishingMinigame.fishCount*50<<"coins";

         
        } else {
            cout << "No worries! Maybe next time." << endl;
            cout << "Fishing can be quite lucrative, so feel free to join me whenever you're ready." << endl;
}}
void explore(Party &party, int &fight, int &empty, int &shop, int &fishing, int &round)
{
    while (round != 6)
    {
        int randomChoice = rand() % 10 + 1; // Generate a random number between 1 and 10

        if ((randomChoice <= 4 && fight != 3) || round == 0)
        {
            cout << "You encountered an enemy! Prepare for battle." << endl;
            int partylevel = party.lvlsum();
            encounter(party, factory(partylevel));
            int ranW =rand()%2,ranA=rand()%2,ranM=rand()%4,ranT=rand()%3;
            auto loot=generateRandomLoot(ranW, ranA, ranA, ranT);
            party.addLootToInventory(loot);
            party.levelup();
            fight++;
            return;
        }
        else if (randomChoice <= 7 && shop != 1)
        {
            cout << "You stumbled upon a shop. Let's see what they have to offer." << endl;
            shopInteraction(party);
            shop++;
            return;
        }
        else if (randomChoice <= 9 && fishing != 1)
        {
            cout << "You found a fishing spot. Time to catch some fish!" << endl;
            fishingintraction(party);
            fishing++;
            return;
        }
        else if (randomChoice == 10 && empty != 1)
        {	if(party.endingcond()){
        	typeText("As you lie on the ground, the pain in your foot throbbing, you feel a sense of disorientation wash over you.\n");
    		typeText("The world around you seems to shift and blur, almost as if you were looking through a distorted lens.\n");
    		typeText("You can hear the sounds of chaos all around you - people shouting, glass breaking, and the loud bursts of gunfire.\n");
    		typeText("\n");
    		typeText("It takes a moment for your brain to fully register what is happening - the police are shooting at you.\n");
    		typeText("Panic sets in as you try to crawl away, but your injured foot hinders your movements.\n");
    		typeText("You can see the officers advancing towards you, their guns trained on your trembling body.\n");
   			typeText("\n");
    		typeText("In a flash, memories of earlier events come rushing back to you.\n");
        	death();
		}
            cout << "Finally, a quiet place where you can rest." << endl;
            #ifdef MY_SYSTEM
            cout << "Would you like to save? (y/n): ";
            char saveResponse;
            cin >> saveResponse;
            if (saveResponse == 'y' || saveResponse == 'Y')
            {
                cout << "Your progress has been saved." << endl;
            }
            else
            {
                cout << "Alright, no problem. Let's continue." << endl;
            }

            cout << "Heads or tails? ";
            if (rand() % 2)
            {
                cout << "It's heads!" << endl;
            }
            else
            {
                cout << "It's tails!" << endl;
            }
            return;
            #endif
        }

        round++;
    }

    fight = 0;
    shop = 0;
    fishing = 0;
    empty = 0;
    round = 0;
}

void mainmenu(Party &party, int &fight, int &empty, int &shop, int &fishing, int &round)
{
    system("cls");
#ifdef MY_SYSTEM
    PlaySound(playlist[rand() % playlist.size()].c_str(), NULL, SND_FILENAME | SND_ASYNC);
#endif

    cout << "Main Menu:" << endl;
    cout << "1. Explore" << endl;
    cout << "2. Manage Party" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You've chosen to explore." << endl;
        explore(party, fight, empty, shop, fishing, round);
        break;
    case 2:
        cout << "You've chosen to manage your party." << endl;
        party.manageParty(); // Call the function to manage the party
        break;
    case 3:
        cout << "Exiting program..." << endl;
        exit(0);
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}
int main()
{
    // Set console output to UTF-8 encoding
    SetConsoleOutputCP(CP_UTF8);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Specify the font name
    wcscpy(fontInfo.FaceName, L"Segoepr");

    // Set the font size
    fontInfo.dwFontSize.X = 12;
    fontInfo.dwFontSize.Y = 16; // Font size in pixels

    // Set the console font
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Welcome message and menu options
    cout << "Welcome to the Adventure Game!\n";
    cout << "1. Start New Game\n";
    cout << "2. Load Game\n";
    cout << "3. Exit\n";

    // Player chooses an option
 
    int choice = stoi(input({"1", "2", "3"}));

    Party party;

    // Perform actions based on player's choice
    if (choice == 1)
    {
        cout << "Starting a new game...\n";
        party = partyconstructor();
    }
    else if (choice == 2)
    {
#ifdef MY_SYSTEM
        cout << "Loading saved game...\n";
        party = loadParty("C:\\Users\\me1382\\Desktop\\dalgh 4.3\\dalgh 4.3\\dalgh 5\\save\\save.json");
#else
        cout << "No saved game found. Starting a new game...\n";
        party = partyconstructor();
#endif
    }
    else if (choice == 3)
    {
        cout << "Exiting the game...\n";
        exit(0);
    }
    else
    {
        cout << "Invalid choice. Exiting the game...\n";
        exit(0);
    }

    int fight, empty, shop, fishing, round = 0;

    while (true)
    {
        // Display main menu and handle player's choice
        mainmenu(party, fight, empty, shop, fishing, round);
    }

    return 0;
}
