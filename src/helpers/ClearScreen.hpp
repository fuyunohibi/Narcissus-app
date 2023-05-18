#ifndef CLEAR_SCREEN_H
#define CLEAR_SCREEN_H

#include <iostream>
#include <cstdlib> // for std::system

// USAGE: clearScreen();

// Function to clear console screen based on OS
void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

#endif // CLEAR_SCREEN_H
