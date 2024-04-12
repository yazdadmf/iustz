#ifndef FISHING_MINIGAME_H
#define FISHING_MINIGAME_H


#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h> // For console color and cursor manipulation
#include <conio.h>   // For _kbhit and _getch

class FishingMinigame {
public:
	int fishCount;
    FishingMinigame() : fishCount(0) {}

    void play() {
    	#ifdef MY_SYSTEM
        std::string filePath =  "C:\\Users\\me1382\\Desktop\\dalgh 8\\music\\fishing.wav";
	    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
	    #endif
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

        // Display fish count
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

private:

    // Wait for the user to press Enter to continue
    void waitForEnter() {
        while (true) {
            if (_kbhit()) {
                if (_getch() == 13) // 13 is the Enter key
                    break;
            }
        }
    }

    // Simulate casting the fishing line with cool visual effects
    void simulateCasting() {
        std::string castingLine = "|";
        std::cout << castingLine;

        for (int i = 0; i < 20; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause for visual effect
            std::cout << "\b/"; // Move cursor back and overwrite previous character
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "\b-";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "\b\\"; // Move cursor back and overwrite previous character
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "\b|";
        }

        std::cout << "\n"; // Move to the next line
    }

    // Wait for the user to reel in the fishing line by pressing Spacebar
    int waitForReel() {
        int reelCount = 0;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // Define colors for visual feedback
        const int GREEN = 10;
        const int RED = 12;
        const int YELLOW = 14;

        while (reelCount < 50) { // Maximum 50 reel attempts allowed
            if (_kbhit()) {
                if (_getch() == 32) { // 32 is the Spacebar key
                    SetConsoleTextAttribute(hConsole, GREEN); // Set text color to green
                    std::cout << "*"; // Show visual feedback for reeling in
                    SetConsoleTextAttribute(hConsole, 15); // Set text color back to white
                    reelCount++;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause for visual effect
        }

        // Additional visual effect after reeling is done
        for (int i = 0; i < 5; ++i) {
            SetConsoleTextAttribute(hConsole, RED); // Set text color to red
            std::cout << "!"; // Show visual effect
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Pause for visual effect
            SetConsoleTextAttribute(hConsole, YELLOW); // Set text color to yellow
            std::cout << "!"; // Show visual effect
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Pause for visual effect
            SetConsoleTextAttribute(hConsole, 15); // Set text color back to white
        }

        SetConsoleTextAttribute(hConsole, 15); // Set text color back to white
        std::cout << "\n"; // Move to the next line after reeling is done
        return reelCount;
    }
};
#endif // FISHING_MINIGAME_H
