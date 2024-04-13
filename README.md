# iustz
# Game story:
As the music blared and the lights flashed, a group of friends crowded into a small apartment, ready to party. Beer cans littered the floor and a cloud of smoke hung in the air. But little did they know, their night was about to take a drastic turn. 
 
As the clock struck midnight, everything suddenly went black. Confused and disoriented, the friends stumbled around in the dark, trying to figure out what was happening. Suddenly, a bright light appeared, and a booming voice echoed in their heads. 
 
'I am the Almighty, the Creator of all worlds,' the voice said. 'You have been summoned here for a purpose.' 
 
The friends looked at each other in shock, unsure of what was happening. The voice continued. 
 
'In your world, you have been indulging in drugs and alcohol, poisoning your bodies and minds. But in this world, things are different. You have been brought here to learn and grow, to make amends for your past actions.' 
 
The friends were suddenly transported to a vast, otherworldly land. The sky was a surreal lavender color and the ground was made of sparkling crystals. In front of them stood a majestic figure, their true form radiating with a divine glow. 
 
'You must now face the consequences of your choices,' the deity said. 'But fear not, for I offer you a chance at redemption. Will you accept the challenge?' 
 
The friends looked at each other, and with a sense of determination, they nodded. They knew this was their chance to make things right. 
 
And so, their journey in this new world began. They faced challenges and obstacles, but they also found joy and purpose. As they learned and grew, they realized that this was the true party they had been searching for all along - a party of self-discovery and enlightenment. And they would never go back to their old ways again.


**Description:**
Welcome to our text-based survival game implemented in C++! This game offers a thrilling adventure where you must navigate through a post-apocalyptic world filled with dangers, challenges, and opportunities. Explore various locations, engage in strategic combat encounters, manage your party, and make crucial decisions to survive against all odds.

### Requirements:
To compile and run this project, ensure you have the following:

* C++ compiler
* Standard C++ libraries
* Windows or Linux environment
### Compilation and Execution:
Follow these steps to compile and run the game:

##### 1.Compile the source code using your preferred C++ compiler. For example:
g++ main.cpp -o dalgh
##### 2.Run the compiled executable:

| Operating System | Command     |
|------------------|-------------|
| Windows          | `dalgh.exe` |
| Linux            | `./sdalgh`  |

### Features:
Dive into the immersive world of our survival game and enjoy these exciting features:

**Exploration:** Embark on a journey across diverse landscapes, from abandoned cities to desolate wilderness areas. Encounter hidden treasures, mysterious ruins, and unexpected dangers.

![main menu1](https://github.com/yazdadmf/iustz/assets/154887581/6e006d5b-cd04-46e9-8a30-f8cf6ad6b8e0)

**Combat:** Engage in tactical combat encounters with various adversaries, including hordes of zombies, hostile survivors, and otherworldly creatures. Strategize your attacks, utilize items, and defend your party to emerge victorious.

![attack1](https://github.com/yazdadmf/iustz/assets/154887581/36d130a1-18bb-46e6-95f2-8e6b05d99091)
![health bar1](https://github.com/yazdadmf/iustz/assets/154887581/672b9ac7-3f36-40bd-b829-e92807d2fd09)

**Item Management:** Collect and manage a wide array of items, including weapons, armor, medical supplies, and throwable objects. Equip your party members with the best gear to enhance their combat prowess and survival chances.

![stats1](https://github.com/yazdadmf/iustz/assets/154887581/97a2cc0e-8b09-4cfd-8466-b98378b38cbd)

**Party Management:** Lead and manage a group of diverse characters, each with unique abilities, strengths, and weaknesses. Customize your party composition, assign roles, and develop relationships among party members to strengthen teamwork and resilience.

![managing the party1](https://github.com/yazdadmf/iustz/assets/154887581/e38fe006-1047-4a63-94d8-1ae44fa5ffde)

**Interactive Events:** Encounter dynamic events and challenges during your exploration, such as encounters with friendly or hostile NPCs, random encounters, environmental hazards, and moral dilemmas. Your choices and actions will shape the outcome of your adventure.

**Economy and Trading:** Visit trade hubs, settlements, and makeshift markets to buy and sell goods. Negotiate prices, barter with merchants, and trade valuable resources to acquire essential supplies and equipment for your journey.

![shop menu1](https://github.com/yazdadmf/iustz/assets/154887581/56c1e4e9-addf-4759-b16a-45c0df0cb203)

![shop 1](https://github.com/yazdadmf/iustz/assets/154887581/40ffab43-f220-45b7-886e-38d822a7f3da)

### File Structure:
Understand the organization of our project's files:

* Item.h: Define the base Item class and its subclasses, including Armor, Weapon, and Meds.
* printstuff.h: Contains utility functions for printing formatted text and colored output.
* character.h: Define the Character class representing playable characters in the game.
* nonfriendly.h: Define the NonFriendly class representing non-playable characters and enemies.
* zombie.h: Define the Zombie class, a subtype of NonFriendly representing undead enemies.
* shop.h: Define the Shop class representing in-game shops where players can buy and sell items.
* fishing.h: Define the FishingMinigame class, representing a mini-game for fishing activities.
* main.cpp: Implement the game's main logic, including menus, gameplay mechanics, and user interactions.
  
* save.h: This code provides functions to save and load party data to and from JSON files. It includes functionalities to serialize and deserialize party information, including character attributes, inventory items, and wallet data.
To use these functions, follow these steps:
Ensure that the json.hpp file is included and properly linked to your project.
Define your party data structure (Party and Character) with attributes such as name, stamina, vigor, etc.
Use the saveParty function to save your party data to a JSON file

* printstuff.h: Contains utility functions for printing formatted text and colored output.
Simulates typing effect for a given text, Displays a progress bar with customizable colors and increments, Flashes the specified text on the screen for a specified duration, effect by flashing red background with the text, Animates flying underscores across the console screen, Displays an introductory animation with flying underscores, and ......

* human enemy.h: The Human_enemy class allows for the creation of human enemy characters with distinct attributes such as health, stamina, weapons, and throwables.
Features
Character Attributes: Each human enemy character has attributes such as health points
(HP), maximum HP, stamina, and damage dealt.

* Weapon and Throwables: Human enemies are equipped with weapons and throwable items that affect combat outcomes.
Description: Each human enemy has a detailed description, providing context and flavor to their role within the game.
Effects: Human enemies can apply and receive various effects during combat, affecting their performance and behavior.
View and Controller Classes: The class includes nested View and Controller classes for managing display and logic related to human enemy characters.

* throwables.h: The Throwables class is designed to represent a variety of throwable items that can be used within a game or simulation environment. Throwables may cause instant damage upon impact with a target. Some throwables have special effects that affect the target, such as fire, stun, freeze, confusion, or slip. The class provides a method to display detailed information about each throwable, including its ID, effects, and instant damage.
  
### Gameplay Instructions:
Here's how to start your adventure in our survival game:

1. Launch the game and navigate the main menu to explore available options.
2. Choose "Explore" to begin your journey into the unknown. Traverse different locations, encounter diverse challenges, and collect valuable resources.
3. Prepare for combat encounters by equipping your party members with weapons, armor, and healing items. Engage in strategic battles against enemies, using a variety of tactics to overcome tough opponents.
4. Utilize the "Manage Party" option to view and customize your party composition, upgrade character abilities, and foster camaraderie among party members.
5. Make wise decisions as you explore, interact with NPCs, and confront moral dilemmas. Your choices will influence the outcome of your adventure and shape the destiny of your party.
6. Visit shops to trade goods, acquire essential supplies, and upgrade your equipment. Spend currency wisely and seek out rare items to gain an edge in your quest for survival.
7. Keep exploring, battling enemies, and overcoming challenges to uncover the secrets of the post-apocalyptic world and emerge as a resilient survivor.

# Fishing Minigame
**Description:**
The Fishing Minigame is a simple console-based game where players can experience the excitement of fishing in a virtual environment. Players cast their fishing line into the water and reel it in, aiming to catch as many fish as possible.

![fishing game](https://github.com/yazdadmf/iustz/assets/154887581/f80ac6b3-6f44-4d32-aced-d2161329a36e)

## How to Play:

### 1.Starting the Game:

* Run the executable file to start the fishing minigame.
* Follow the on-screen instructions to proceed.
### 2.Gameplay:

* Press Enter to cast the fishing line into the water.
* Repeatedly press the Spacebar to reel in the fishing line.
* Catch a fish by reeling in enough times.
* The game keeps track of the total number of fish caught.
### 3.Objective:

* The main objective is to catch as many fish as possible within the allotted time.
* Enjoy the relaxing atmosphere and immersive experience of virtual fishing.
### 4.Controls:

* Press Enter to cast the fishing line.
* Press Spacebar repeatedly to reel in the line.
* Follow on-screen prompts for additional actions.
### 5.Features:

* Realistic casting and reeling mechanics.
* Visual feedback for casting and reeling actions.
* Random events to add variety to the gameplay.
* Simple and intuitive controls for an enjoyable experience.

### 6.Requirements:

* This game requires a C++ compiler to build and run.
* Compatible with Windows operating systems.

<p>Enjoy your adventure!</p>
