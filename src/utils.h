#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

// Clears the console screen
inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Pauses the program until user presses Enter
inline void pause() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

// Prints a line of '=' characters for visual separation
inline void printLine(int length = 50) {
    for (int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
}

// Prints a border line of '*' characters
inline void printBorder() {
    cout << "\n";
    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}

// Returns current date and time as a formatted string
inline string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string dateTime = dt;
    // Remove trailing newline added by ctime
    dateTime = dateTime.substr(0, dateTime.length() - 1);
    return dateTime;
}

#endif
