# PHASE 2: System Design & File Design
## Inventory Management System (IMS)
### Programming Fundamentals (PF) Project - Roman Urdu Documentation

---

## Phase Objective

**Roman Urdu:**
Is phase mein hum decide karte hain ke project ka structure kaisa hoga, different modules kis tarah kaam karenge, aur data files mein kis format mein save aur retrieve hoga.

**English:**
In this phase, we design the system architecture, module structure, flowcharts, and file formats.

---

## 1. System Architecture

**Roman Urdu:**
Humara system ek **menu-driven console application** hai. Iska matlab hai:
- Program start hone par ek menu dikhega
- User number press karke option select karega
- Wo operation perform hoga
- Phir menu dobara dikhega (jab tak user exit na kare)

### System Structure:

```
┌─────────────────────────────────────────────────────────┐
│                   IMS Application                        │
├─────────────────────────────────────────────────────────┤
│                                                          │
│  ┌─────────────┐                                        │
│  │   Login     │ ──────► Admin Authentication           │
│  │   Module    │                                        │
│  └──────┬──────┘                                        │
│         │                                                │
│         ▼                                                │
│  ┌─────────────┐                                        │
│  │    Main     │ ──────► User selects option (1-12)     │
│  │    Menu     │                                        │
│  └──────┬──────┘                                        │
│         │                                                │
│         ▼                                                │
│  ┌─────────────────────────────────────────────────┐    │
│  │              MODULES                             │    │
│  ├─────────────────────────────────────────────────┤    │
│  │  1. Add Product Module                           │    │
│  │  2. View Products Module                         │    │
│  │  3. Search Product Module                        │    │
│  │  4. Update Product Module                        │    │
│  │  5. Delete Product Module                        │    │
│  │  6. Stock In Module                              │    │
│  │  7. Stock Out Module                             │    │
│  │  8. Generate Reports Module                      │    │
│  │  9. Sort Products Module                         │    │
│  │ 10. Low Stock Alert Module                       │    │
│  │ 11. Backup Data Module                           │    │
│  │ 12. Exit                                         │    │
│  └─────────────────────────────────────────────────┘    │
│         │                                                │
│         ▼                                                │
│  ┌─────────────┐                                        │
│  │    File     │ ──────► Data save/load from files      │
│  │  Handling   │                                        │
│  └─────────────┘                                        │
│                                                          │
└─────────────────────────────────────────────────────────┘
```

---

## 2. Data Flow Diagram

**Roman Urdu:**
Data Flow Diagram dikhata hai ke data system mein kis tarah move karta hai.

### Simple Data Flow:

```
                    ┌──────────────┐
                    │    USER      │
                    └──────┬───────┘
                           │
                    Input (username, password)
                           │
                           ▼
                    ┌──────────────┐
                    │    Login     │──── Read admin.dat
                    │   Module     │──── Write logs.txt
                    └──────┬───────┘
                           │
                    Login Successful
                           │
                           ▼
                    ┌──────────────┐
                    │  Main Menu   │
                    └──────┬───────┘
                           │
            ┌──────────────┼──────────────┐
            │              │              │
            ▼              ▼              ▼
    ┌──────────────┐ ┌──────────┐ ┌──────────┐
    │ Add Product  │ │  View    │ │  Search  │  ... (other modules)
    └──────┬───────┘ └──────────┘ └──────────┘
           │
           │ Product Data
           │
           ▼
    ┌──────────────┐
    │ File Handler │
    └──────┬───────┘
           │
           ├──► Write products.dat
           ├──► Write logs.txt
           └──► Write backup.dat
```

**Roman Urdu Explanation:**
- User login karta hai → admin.dat se verify hota hai
- Login ke baad menu dikhta hai
- User option select karta hai → related module chalta hai
- Module apna kaam karta hai → file handler data save karta hai
- Har activity logs.txt mein save hoti hai

---

## 3. Flowcharts

### 3.1 Main Program Flowchart

```
         ┌─────────┐
         │  START  │
         └────┬────┘
              │
              ▼
      ┌───────────────┐
      │ Load Data     │
      │ from Files    │
      └───────┬───────┘
              │
              ▼
      ┌───────────────┐         ┌──────────────┐
      │   Login       │◄────────│ Login Failed │
      │   Screen      │         │ (Show Error) │
      └───────┬───────┘         └──────────────┘
              │                          ▲
              │ Valid?                   │
         ┌────┴────┐                     │
         │         │                     │
        YES       NO ────────────────────┘
         │
         ▼
      ┌───────────────┐
      │  Show Main    │
      │    Menu       │
      └───────┬───────┘
              │
              ▼
      ┌───────────────┐
      │ User enters   │
      │   choice      │
      └───────┬───────┘
              │
     ┌────────┼────────┬────────┬────────┐
     │        │        │        │        │
     ▼        ▼        ▼        ▼        ▼
   Opt 1    Opt 2    Opt 3   Opt 11   Opt 12
   (Add)   (View)  (Search) (Backup) (Exit)
     │        │        │        │        │
     └────────┴────────┴────────┘        │
              │                          │
              ▼                          ▼
      ┌───────────────┐          ┌──────────────┐
      │  Save Data    │          │  Save & Exit │
      │  Show Menu    │          └──────┬───────┘
      └───────┬───────┘                 │
              │                         │
              └────────► Loop ◄─────────┘
                            │
                            ▼
                      ┌─────────┐
                      │   END   │
                      └─────────┘
```

### 3.2 Add Product Flowchart

```
      ┌──────────────────┐
      │  Start addProduct │
      └────────┬─────────┘
               │
               ▼
      ┌──────────────────┐
      │ Enter Product ID │
      └────────┬─────────┘
               │
               ▼
      ┌──────────────────┐         ┌──────────────┐
      │ Check if ID      │────YES─►│ Show Error:  │
      │ already exists   │         │ "ID exists!" │
      └────────┬─────────┘         └──────────────┘
               │ NO
               ▼
      ┌──────────────────┐
      │ Enter Name       │
      │ Enter Category   │
      │ Enter Supplier   │
      │ Enter Quantity   │
      │ Enter Prices     │
      └────────┬─────────┘
               │
               ▼
      ┌──────────────────┐
      │ Validate Input   │
      │ (no negatives)   │
      └────────┬─────────┘
               │ Valid?
          ┌────┴────┐
         YES       NO ──► Show Error, Ask Again
          │
          ▼
      ┌──────────────────┐
      │ Add to Array     │
      └────────┬─────────┘
               │
               ▼
      ┌──────────────────┐
      │ Save to File     │
      └────────┬─────────┘
               │
               ▼
      ┌──────────────────┐
      │ Write Log        │
      └────────┬─────────┘
               │
               ▼
      ┌──────────────────┐
      │ Show Success     │
      │ "Product Added!" │
      └──────────────────┘
```

---

## 4. Menu Design

**Roman Urdu:**
Menu simple text-based hai jo console par dikhega.

### Main Menu Display:

```
╔══════════════════════════════════════════╗
║                                          ║
║      INVENTORY MANAGEMENT SYSTEM         ║
║                                          ║
╠══════════════════════════════════════════╣
║                                          ║
║   1.  Add Product                        ║
║   2.  View Products                      ║
║   3.  Search Product                     ║
║   4.  Update Product                     ║
║   5.  Delete Product                     ║
║   6.  Stock In                           ║
║   7.  Stock Out                          ║
║   8.  Generate Reports                   ║
║   9.  Sort Products                      ║
║  10.  Low Stock Alert                    ║
║  11.  Backup Data                        ║
║  12.  Exit                               ║
║                                          ║
╚══════════════════════════════════════════╝

Enter your choice (1-12): 
```

### Login Screen Display:

```
╔══════════════════════════════════════════╗
║                                          ║
║          ADMIN LOGIN                     ║
║                                          ║
╠══════════════════════════════════════════╣
║                                          ║
║   Username: _______________              ║
║   Password: _______________              ║
║                                          ║
║   Attempts Remaining: 3                  ║
║                                          ║
╚══════════════════════════════════════════╝
```

---

## 5. Module Planning

**Roman Urdu:**
System ko modules mein divide karte hain taake code organized rahe.

| Module Name | Purpose (Roman Urdu) | Functions |
|-------------|---------------------|-----------|
| **Authentication** | Login check karna | `login()`, `checkCredentials()` |
| **Menu** | Main menu dikhana | `showMenu()`, `getChoice()` |
| **Product Management** | Product add/view/search/update/delete | `addProduct()`, `viewProducts()`, `searchProduct()`, `updateProduct()`, `deleteProduct()` |
| **Stock Management** | Stock in/out karna | `stockIn()`, `stockOut()` |
| **Reports** | Reports generate karna | `generateReport()`, `lowStockReport()` |
| **Sorting** | Products sort karna | `sortByName()`, `sortByPrice()`, `sortByQuantity()` |
| **File Handling** | Data save/load karna | `saveData()`, `loadData()`, `backupData()`, `writeLog()` |
| **Validation** | Input check karna | `isValidInput()`, `isDuplicateID()` |
| **Utils** | Helper functions | `clearScreen()`, `pause()`, `getDate()` |

---

## 6. File Design

**Roman Urdu:**
Is section mein hum decide karte hain ke har file mein kya data hoga aur kis format mein.

### 6.1 products.dat

**Purpose:** Saare products ka data store karna

**Format:** Text file (one field per line)

**Structure:**
```cpp
struct Product {
    int id;                 // Product ID (unique)
    string name;            // Product name
    string category;        // Product category (e.g., Electronics, Grocery)
    string supplier;        // Supplier name
    int quantity;           // Current stock quantity
    double purchasePrice;   // Price we buy at
    double sellingPrice;    // Price we sell at
};
```

**Example File Content:**
```
2
101
Dell Laptop
Electronics
TechWorld Pvt Ltd
25
45000
55000
102
Mouse
Accessories
Logitech
50
500
800
```

**Roman Urdu:** 
- Text file use karte hain - har field ek nayi line par
- Pehli line mein total products ka count hota hai
- Phir har product ke 7 fields line by line likhe hote hain
- Array mein maximum 100 products rakh sakte hain

---

### 6.2 admin.dat

**Purpose:** Admin login credentials store karna

**Format:** Text file (one value per line)

**Structure:**
```cpp
struct Admin {
    string username;        // Admin username
    string password;        // Admin password
};
```

**Default Values:**
```
admin
admin123
```

**Roman Urdu:**
- Program first time chale toh default admin create hoga
- Admin file se credentials read karke login check hota hai

---

### 6.3 reports.txt

**Purpose:** Generated reports store karna

**Format:** Text file (human readable)

**Structure:**
```
==============================================
        INVENTORY REPORT
        Generated: 15-Jul-2026
==============================================

Total Products: 45
Total Items in Stock: 1250
Total Value: Rs. 2,500,000.00

--- LOW STOCK ITEMS ---
ID: 1005 | USB Cable | Qty: 2
ID: 1012 | Mouse Pad | Qty: 1

--- OUT OF STOCK ITEMS ---
ID: 1008 | HDMI Cable | Qty: 0

==============================================
         END OF REPORT
==============================================
```

**Roman Urdu:**
- Text file hai taake easily padh saken
- Har baar report generate karne par file overwrite hoti hai

---

### 6.4 logs.txt

**Purpose:** System activities record karna

**Format:** Text file (append mode)

**Structure:**
```
[2026-07-15 10:30:45] LOGIN SUCCESS - User: admin
[2026-07-15 10:31:20] PRODUCT ADDED - ID: 1001, Name: Dell Laptop
[2026-07-15 10:35:10] STOCK IN - ID: 1001, Quantity Added: 10
[2026-07-15 10:40:00] PRODUCT UPDATED - ID: 1001, New Price: 56000
[2026-07-15 10:45:30] PRODUCT DELETED - ID: 1003
[2026-07-15 11:00:00] BACKUP CREATED
[2026-07-15 11:05:00] LOGOUT - User: admin
```

**Roman Urdu:**
- Har activity ka log banta hai
- File append mode mein khulti hai (purana data delete nahi hota)
- Timestamp ke saath har entry likhi jati hai

---

### 6.5 backup.dat

**Purpose:** Products data ka backup lena

**Format:** Text file (same format as products.dat)

**Roman Urdu:**
- products.dat ki exact copy (text format mein)
- User jab "Backup Data" option select karta hai toh products.dat copy ho kar backup.dat ban jata hai
- Har line ko parh kar doosri file mein likha jata hai

---

## 7. Product Structure (Final Design)

```cpp
// Product structure definition
struct Product {
    int id;                 // Unique Product ID
    string name;            // Product name
    string category;        // Product category
    string supplier;        // Supplier company name
    int quantity;           // Current stock quantity
    double purchasePrice;   // Cost price (we buy at)
    double sellingPrice;    // Selling price (we sell at)
};

// Admin structure definition
struct Admin {
    string username;        // Admin username
    string password;        // Admin password
};
```

**Roman Urdu Explanation:**
- `int id` - Har product ka unique number, do products ka same ID nahi ho sakta
- `string name` - Product ka naam (C++ string - koi character limit nahi)
- `string category` - Product kis category mein hai (Electronics, Grocery, etc.)
- `string supplier` - Supplier company ka naam
- `int quantity` - Abhi kitne products stock mein hain
- `double purchasePrice` - Humne kis price par kharida
- `double sellingPrice` - Hum kis price par bechenge

---

## 8. Array Design

**Roman Urdu:**
Products ko memory mein rakhne ke liye array use karenge.

```cpp
#define MAX_PRODUCTS 100    // Maximum 100 products

Product products[MAX_PRODUCTS];   // Array to store products
int productCount = 0;             // Current number of products
```

**Why Array?**
- Simple hai aur PF mein padha hai
- Fixed size (100 products) - chote business ke liye kaafi hai
- Index se access fast hai

---

## 9. Module Communication Diagram

```
                    ┌─────────────┐
                    │   main()    │
                    └──────┬──────┘
                           │
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
   ┌────────────┐   ┌────────────┐   ┌────────────┐
   │   login    │   │  showMenu  │   │   exit     │
   │  module    │   │  module    │   │  module    │
   └─────┬──────┘   └─────┬──────┘   └────────────┘
         │                │
         ▼                ▼
   ┌────────────┐   ┌────────────────────────────┐
   │ checkCred  │   │      Action Modules        │
   └─────┬──────┘   ├────────────────────────────┤
         │          │ addProduct()               │
         ▼          │ viewProducts()             │
   ┌────────────┐   │ searchProduct()            │
   │ admin.dat  │   │ updateProduct()            │
   └────────────┘   │ deleteProduct()            │
                    │ stockIn() / stockOut()     │
                    │ generateReport()           │
                    │ sortProducts()             │
                    │ backupData()               │
                    └─────────────┬──────────────┘
                                  │
                                  ▼
                    ┌────────────────────────────┐
                    │     File Handler Module    │
                    ├────────────────────────────┤
                    │ saveData()                 │
                    │ loadData()                 │
                    │ writeLog()                 │
                    └─────────────┬──────────────┘
                                  │
          ┌───────────┬───────────┼───────────┬───────────┐
          │           │           │           │           │
          ▼           ▼           ▼           ▼           ▼
    products.dat  admin.dat  reports.txt  logs.txt  backup.dat
```

---

## 10. Summary (Roman Urdu)

> "Is phase mein humne system ka design banaya. Humne decide kiya ke:
> - System menu-driven hoga
> - 12 modules honge jo alag alag kaam karenge
> - 5 files use hongi (products.dat, admin.dat, reports.txt, logs.txt, backup.dat)
> - Product structure mein 7 fields honge (string use karte hain char[] ki jagah)
> - Maximum 100 products store kar sakte hain
> - Flowcharts banaye taake program flow samajh aaye
> 
> Agle phase mein hum code likhna shuru karenge - pehle project setup karenge!"

---

## 10. Summary (English)

> "In this phase, we designed the system architecture:
> - Menu-driven console application with 12 options
> - 9 modules handling different responsibilities
> - 5 files for data storage (products, admin, reports, logs, backup)
> - Product structure with 7 fields
> - Maximum capacity of 100 products using arrays
> - Created flowcharts for program flow
> 
> In the next phase, we will start coding - first setting up the project structure!"

---

## Problems & Solutions (This Phase)

| Problem | Solution |
|---------|----------|
| Kitne products store kar sakte hain? | Array size 100 set kiya - chote business ke liye kaafi |
| Binary ya text file? | Text for all files (readable, beginner-friendly, works with string) |
| Password encrypt karein? | PF level par simple store karte hain (security advanced topic hai) |

---

**Phase 2 Complete!**
**Review and approve to proceed to Phase 3: Project Setup & Core Structure (Code)**
