#ifndef PRINTSUTFF_H
#define PRINTSUTFF_H

#include <iostream>
#include <string>
#include <windows.h> // Include for Windows API
#include <chrono>
#include <thread>
string input(vector<string> choices) {
    string ans;

    do {
        cout << "Enter your choice: ";
        cin >> ans;

        for (const string& choice : choices) {
            if (choice == ans) {
                return ans;
            }
        }

        cout << "Invalid input. Please try again." << endl;

    } while (true);
}
// Function to simulate typing effect
void typeText(const string& text) {
    for (char c : text) {
        cout << c << flush;
        // Sleep for a short duration to simulate typing effect
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}

void color(const std::string& a, const std::string& b) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD originalAttributes;

    // Save current console attributes
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    originalAttributes = consoleInfo.wAttributes;

    if (b == "red") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    } else if (b == "green") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    } else if (b == "blue") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    } else if (b == "yellow") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    } else if (b == "cyan") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    } else if (b == "magenta") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    } else if (b == "white") {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    } else {
        // No color specified
        std::cerr << "Invalid color specified!" << std::endl;
        return;
    }

    // Print the colored string
    std::cout << a;

    // Reset color to default
    SetConsoleTextAttribute(hConsole, originalAttributes);
}

void barandnumber(int current, int max, const std::string& color1, int increment) {
    std::string ret = "[";
    std::string bar = "";
    for (int i = 0; i < (max / increment); i++) {
        if (current > 0) {
            bar += "●";
        } else {
            bar += ".";
        }
        current -= increment;
    }
    
    // Print the colored bar and numbers
    std::cout << ret;
    color(bar, color1);
    std::cout << "] " << current + max << "/" << max;
}


#include <thread>
#include <chrono>

void clearScreen() {
    system("cls");
}

void flashText(const std::string& text, int duration_ms) {
    std::cout << text;
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
}

void death() {
	SetConsoleOutputCP(65001); // Set console output code page to UTF-8
    const int FLASH_DURATION_MS = 200; // Duration of each flash in milliseconds
    const int NUM_FLASHES = 5; // Number of times to flash
    const int BACKGROUND_COLOR = BACKGROUND_RED; // Background color to flash (RED in this case)
    const std::string YOU_DIED_TEXT =
R"(
                                 ▓██   ██▓ ▒█████   █    ██    ▓█████▄  ██▓▓█████ ▓█████▄ 
                                  ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▒██▀ ██▌▓██▒▓█   ▀ ▒██▀ ██▌
                                   ▒██ ██░▒██░  ██▒▓██  ▒██░   ░██   █▌▒██▒▒███   ░██   █▌
                                   ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░▓█▄   ▌░██░▒▓█  ▄ ░▓█▄   ▌
                                   ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░▒████▓ ░██░░▒████▒░▒████▓ 
                                    ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒     ▒▒▓  ▒ ░▓  ░░ ▒░ ░ ▒▒▓  ▒ 
                                  ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░     ░ ▒  ▒  ▒ ░ ░ ░  ░ ░ ▒  ▒ 
                                  ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░     ░ ░  ░  ▒ ░   ░    ░ ░  ░ 
                                  ░ ░         ░ ░     ░           ░     ░     ░  ░   ░    
                                  ░ ░                           ░                  ░      )";

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo);

    // Save the original attributes
    WORD originalAttributes = bufferInfo.wAttributes;

    for (int i = 0; i < NUM_FLASHES; ++i) {
        // Flash "You Died" text with red background
        SetConsoleTextAttribute(consoleHandle, BACKGROUND_COLOR | FOREGROUND_INTENSITY);
        clearScreen();
        flashText(YOU_DIED_TEXT, FLASH_DURATION_MS / 2);

        // Flash blank screen with black background
        SetConsoleTextAttribute(consoleHandle, 0);
        clearScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(FLASH_DURATION_MS / 2));
    }

    // Restore original attributes before exiting
    SetConsoleTextAttribute(consoleHandle, originalAttributes);

    exit(0);
}


// Function to set cursor position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to print centered text
void printCenteredText(const std::string& text, int y) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int padding = (consoleWidth - text.length()) / 2;
    gotoxy(padding, y);
    std::cout << text;
}

// Function to change the second text every 10 seconds
std::string getAlternateText(int secondsElapsed) {
    int option = (secondsElapsed /10) % 4;
    switch (option) {
        case 0:
            return "Mehrab AmirLOO";
        case 1:
            return "Yazdad MastaRy FarAHanI";
        case 2:
            return "Mohammad Emami";
        case 3:
            return "MarYam AzimIrad";
        default:
            return "Unknown";
    }
}

// Function to create moving underscores
void animateFlyingUnderscores(int numUnderscores, int delay) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int secondsElapsed = 0;

    while (secondsElapsed<300) {
        // Clear the console and set background color to blue
        system("cls");
        system("color 1F"); // Set background color to blue and text color to white

        // Calculate padding for ASCII art
        int artPadding = (consoleWidth - 45) / 2;
		std::cout<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
        // Print the fancy ASCII text
        std::cout << std::endl; // Add a line break
        std::cout << std::string(artPadding, ' ') << " ██████ ██       ██████  ██     ██ ███    ██ ███████      ██" << std::endl; // Center vertically
        std::cout << std::string(artPadding, ' ') << "██      ██      ██    ██ ██     ██ ████   ██    ███      ███" << std::endl; // Center vertically
        std::cout << std::string(artPadding, ' ') << "██      ██      ██    ██ ██  █  ██ ██ ██  ██   ███        ██" << std::endl; // Center vertically
        std::cout << std::string(artPadding, ' ') << "██      ██      ██    ██ ██ ███ ██ ██  ██ ██  ███         ██" << std::endl; // Center vertically
        std::cout << std::string(artPadding, ' ') << " ██████ ███████  ██████   ███ ███  ██   ████ ███████      ██" << std::endl; // Center vertically

        // Print the second text
        printCenteredText(getAlternateText(secondsElapsed), consoleHeight / 2 + 4);

        // Print the third text


        // Print the moving underscores
        for (int i = 0; i < numUnderscores; ++i) {
            int x = rand() % consoleWidth;
            int y = rand() % consoleHeight;

            // Check if the underscore hits the main texts
            if ((y == consoleHeight / 2) || (y == consoleHeight / 2 + 2)) {
                continue; // Skip printing the underscore
            }

            gotoxy(x, y);
            std::cout << "_";
        }

        // Sleep to control the animation speed
        Sleep(delay);

        // Update seconds elapsed
        secondsElapsed +=1;
    }
}

void intro() {
    // Set console output to UTF-8 encoding
    SetConsoleOutputCP(CP_UTF8);

    // Specify font
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    wcscpy(fontInfo.FaceName, L"Consolas");
    fontInfo.dwFontSize.X = 10;
    fontInfo.dwFontSize.Y = 18;
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));


    animateFlyingUnderscores(8, 100); // Number of underscores and delay in milliseconds
    system("color 0F");
    system("cls");
    return ;
}














#endif // PRINTSUTFF_H
