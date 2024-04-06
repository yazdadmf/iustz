#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h> // For console color and cursor manipulation
#include <conio.h>   // For _kbhit and _getch

class FishingMinigame {
public:
    FishingMinigame() : fishCount(0) {}

    void play() {
        std::cout << "Welcome to the Fishing Minigame!\n";
        std::cout << "Press Enter to start casting your fishing line...\n";
        std::cin.ignore(); // Wait for user to press Enter

        // Press Enter to cast the fishing line
        waitForEnter();

        // Simulate casting the fishing line with visual effects
        std::cout << "Casting the fishing line...\n";
        simulateCasting();

        // Prompt user to reel in the fishing line
        std::cout << "Press Spacebar repeatedly to reel in the fishing line...\n";
        int reelCount = waitForReel(); // Wait for user to reel in the line
// Check if the player caught a fish based on reeling effort
        if (reelCount > 20) {
            // Player caught a fish
            fishCount++;
            std::cout << "You caught a fish!\n";
        } else {
            // Player didn't catch a fish
            std::cout << "You didn't catch anything...\n";
        }
        / Display fish count
        std::cout << "Total Fish Caught: " << fishCount << "\n";

        // Introduce a random event (e.g., sudden heavy rain)
        if (rand() % 5 == 0) {
            std::cout << "Uh oh! Sudden heavy rain makes fishing more challenging!\n";
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate delay
        }

        // Ask if player wants to continue fishing
        char choice;
        std::cout << "Do you want to continue fishing? (Y/N): ";
        std::cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            play(); // Recursive call to continue fishing
        } else {
            std::cout << "Exiting Fishing Minigame...\n";
        }
    }
        
};
#endif // FISHING_MINIGAME_H
