#ifndef PRINTSUTFF_H
#define PRINTSUTFF_H

#include <iostream>
#include <string>
#include <windows.h> // Include for Windows API

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
#endif