#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

inline void pause() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

inline void printLine(int length = 50) {
    for (int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
}

inline void printBorder() {
    cout << "\n";
    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}

inline string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string dateTime = dt;
    dateTime = dateTime.substr(0, dateTime.length() - 1);
    return dateTime;
}

#endif
