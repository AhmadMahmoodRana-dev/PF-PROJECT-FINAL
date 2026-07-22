#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    char category[30];
    char supplier[50];
    int quantity;
    double purchasePrice;
    double sellingPrice;
};

struct Admin {
    char username[30];
    char password[30];
};

extern Product products[MAX_PRODUCTS];
extern int productCount;

#endif
