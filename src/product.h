#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_PRODUCTS 100

// Product structure to store item details
struct Product {
    int id;
    string name;
    string category;
    string supplier;
    int quantity;
    double purchasePrice;
    double sellingPrice;
};

// Admin structure for login credentials
struct Admin {
    string username;
    string password;
};

extern Product products[MAX_PRODUCTS];
extern int productCount;

#endif
