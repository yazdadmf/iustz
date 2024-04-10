#ifndef PRINTSUTFF_H
#define PRINTSUTFF_H

#include <iostream>
#include <string>
#include <windows.h> // Include for Windows API

void barandnumber(int current, int max, const std::string& color1, int increment) {
    std::string ret = "[";
    std::string bar = "";
    for (int i = 0; i < (max / increment); i++) {
        if (current > 0) {
            bar += "?";
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

#endif // PRINTSUTFF_H
