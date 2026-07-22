# PHASE 3: Project Setup & Core Structure
## Inventory Management System (IMS)
### Programming Fundamentals (PF) Project - Roman Urdu Documentation

---

## Phase Objective

**Roman Urdu:**
Is phase mein hum project ki foundation ready karte hain. Hum source files banate hain, Product structure define karte hain, aur main menu dashboard create karte hain.

**English:**
In this phase, we set up the project foundation by creating source files, defining the Product structure, and building the main menu dashboard.

---

## Tasks Completed

### Task 1: Project Structure Created

```
InventoryManagementSystem/
├── docs/                          (documentation files)
│   ├── 01_Requirement_Analysis.md
│   ├── 02_System_Design_File_Design.md
│   └── 03_Project_Setup.md
├── src/                           (source code files)
│   ├── main.cpp                   (main program)
│   ├── product.h                  (Product structure)
│   └── utils.h                    (helper functions)
└── data/                          (data files - created later)
```

---

## Files Created

### 1. product.h (Header File)

**Roman Urdu:**
Yeh header file mein Product aur Admin structures define hain. Structures woh jagah hain jahan hum related data ek saath rakhte hain.

**English:**
This header file defines the Product and Admin structures. Structures allow us to group related data together.

**Key Concepts:**
- `struct Product` - Har product ka data store karta hai (id, name, category, supplier, quantity, prices)
- `struct Admin` - Login credentials store karta hai (username, password)
- `#define MAX_PRODUCTS 100` - Maximum 100 products store kar sakte hain

**Variables Explained:**

| Variable | Type | Purpose |
|----------|------|---------|
| `id` | int | Unique product ID |
| `name` | char[50] | Product ka naam (50 characters tak) |
| `category` | char[30] | Product category (Electronics, Grocery, etc.) |
| `supplier` | char[50] | Supplier company ka naam |
| `quantity` | int | Kitne products stock mein hain |
| `purchasePrice` | double | Kharidne ki price |
| `sellingPrice` | double | Bechne ki price |

---

### 2. utils.h (Helper Functions)

**Roman Urdu:**
Yeh file mein helper functions hain jo program mein baar baar use hote hain.

**Functions Explained:**

| Function | Purpose (Roman Urdu) | Purpose (English) |
|----------|---------------------|-------------------|
| `clearScreen()` | Screen clear karta hai | Clears the console screen |
| `pause()` | User ko enter press karne deta hai | Waits for user to press Enter |
| `printLine()` | Ek line print karta hai (= signs) | Prints a separator line |
| `printBorder()` | Border print karta hai (* signs) | Prints a decorative border |
| `getCurrentDateTime()` | Current date/time return karta hai | Returns current date and time |

---

### 3. main.cpp (Main Program)

**Roman Urdu:**
Yeh program ki main file hai. Ismein:
- `main()` function hai jahan se program start hota hai
- `showMenu()` function menu dikhata hai
- `getMenuChoice()` function user ki choice leta hai
- Sabhi module functions ke stubs hain (abhi placeholder hain, baad mein implement honge)

**English:**
This is the main program file containing:
- `main()` function - program entry point
- `showMenu()` function - displays the menu
- `getMenuChoice()` function - gets user's choice
- Stub functions for all modules (to be implemented in later phases)

---

## Main Function Flow

```
main()
  │
  ├── Show welcome message
  │
  └── do-while loop (jab tak user exit na kare)
        │
        ├── showMenu() - Menu dikhao
        │
        ├── getMenuChoice() - User ki choice lo
        │
        └── switch (choice)
              ├── case 1: addProduct()
              ├── case 2: viewProducts()
              ├── case 3: searchProduct()
              ├── case 4: updateProduct()
              ├── case 5: deleteProduct()
              ├── case 6: stockIn()
              ├── case 7: stockOut()
              ├── case 8: generateReport()
              ├── case 9: sortProducts()
              ├── case 10: lowStockAlert()
              ├── case 11: backupData()
              └── case 12: Exit (goodbye message)
```

---

## Key Code Concepts Used

### 1. do-while Loop

**Roman Urdu:**
do-while loop use kiya hai kyunki humein menu kam se kam ek baar dikhana hai, aur phir user jab tak exit na kare tab tak dikhate rehna hai.

**English:**
We use a do-while loop because we want to show the menu at least once, and keep showing it until the user chooses to exit.

```cpp
do {
    showMenu();
    choice = getMenuChoice();
    // ... process choice
} while (choice != 12);
```

### 2. switch Statement

**Roman Urdu:**
switch statement use kiya hai menu choice ke liye kyunki yeh if-else se clean aur readable hai jab options zyada hon.

**English:**
We use a switch statement for menu selection because it's cleaner and more readable than multiple if-else statements when there are many options.

### 3. cin.clear() and cin.ignore()

**Roman Urdu:**
Jab user number enter karta hai, toh kabhi kabhi extra characters buffer mein reh jate hain. `cin.clear()` errors clear karta hai aur `cin.ignore()` extra characters hata deta hai.

**English:**
After reading integer input, we clear any errors with `cin.clear()` and remove extra characters with `cin.ignore()` to prevent input problems.

---

## How to Compile (Dev C++)

### Roman Urdu Instructions:

1. Dev C++ open karein
2. File → New → Project select karein
3. "Console Application" choose karein
4. Project ko naam dein (e.g., "IMS")
5. `product.h`, `utils.h`, aur `main.cpp` files ko project mein add karein
6. F9 press karein ya Execute → Compile and Run select karein

### Simple Compilation (Command Line):

```bash
g++ -o ims main.cpp
./ims
```

---

## Expected Output

When you run the program, you should see:

```
==================================================
   INVENTORY MANAGEMENT SYSTEM (IMS)
   Programming Fundamentals Project
==================================================

   Welcome to IMS!
   This system helps you manage your products.

   Starting the system...

Press Enter to continue...
```

Then the main menu:

```
==================================================
      INVENTORY MANAGEMENT SYSTEM
==================================================

   1.  Add Product
   2.  View Products
   3.  Search Product
   4.  Update Product
   5.  Delete Product
   6.  Stock In
   7.  Stock Out
   8.  Generate Reports
   9.  Sort Products
  10.  Low Stock Alert
  11.  Backup Data
  12.  Exit

==================================================
   Enter your choice (1-12): 
```

---

## Problems & Solutions

| Problem | Solution |
|---------|----------|
| Dev C++ mein multiple files kaise compile karein? | Project bana kar sab files add karein |
| Screen clear nahi ho rahi? | `system("cls")` Windows par kaam karta hai |
| cin input problems? | `cin.clear()` aur `cin.ignore()` use kiya |

---

## Summary (Roman Urdu)

> "Is phase mein humne project ki foundation banayi. Teen files create ki:
> - product.h - Structures define kiye (Product, Admin)
> - utils.h - Helper functions banaye (clearScreen, pause, etc.)
> - main.cpp - Main program with menu system
> 
> Abhi sab modules ke stubs hain (placeholder functions). Agle phases mein hum inhe implement karenge.
> Program compile aur run ho raha hai - menu dikhta hai aur user choice leta hai."

---

## Summary (English)

> "In this phase, we set up the project foundation with three files:
> - product.h - Defined Product and Admin structures
> - utils.h - Created helper functions
> - main.cpp - Built main program with menu system
> 
> All module functions are currently stubs (placeholders). We will implement them in the following phases. The program compiles and runs - showing the menu and accepting user choices."

---

**Phase 3 Complete!**
**Next: Phase 4 - Authentication Module (Login System)**
