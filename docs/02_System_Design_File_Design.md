# PHASE 2: System Design & File Design
## Inventory Management System (IMS)
### Programming Fundamentals (PF) Project - Roman Urdu Documentation

---

## 1. System Architecture

Humara system ek **menu-driven console application** hai:
- Program start par menu dikhega
- User number press karke option select karega
- Operation perform hoga
- Menu dobara dikhega (jab tak exit na kare)

---

## 2. Data Storage Design

### Parallel Arrays (Struct ki jagah)

Humne **struct** ki jagah **parallel arrays** use ki hain. Yeh zyada basic approach hai:

```cpp
const int MAX_PRODUCTS = 100;

int ids[MAX_PRODUCTS];                  // Product IDs
string names[MAX_PRODUCTS];             // Product names
string categories[MAX_PRODUCTS];        // Categories
string suppliers[MAX_PRODUCTS];         // Suppliers
int quantities[MAX_PRODUCTS];           // Stock quantities
double purchasePrices[MAX_PRODUCTS];    // Purchase prices
double sellingPrices[MAX_PRODUCTS];     // Selling prices
int productCount = 0;                   // Current count
```

**Kyun Parallel Arrays?**
- Struct se zyada basic concept hai
- Har field ki apni alag array hai
- Index `i` par saari 7 arrays mil kar ek product banati hain
- Sorting mein 7 arrays ek saath swap hoti hain
- Delete mein 7 arrays ek saath shift hoti hain

**Example - Product at Index 2:**
```
ids[2] = 103
names[2] = "USB Cable"
categories[2] = "Accessories"
suppliers[2] = "CableWorld"
quantities[2] = 150
purchasePrices[2] = 100.0
sellingPrices[2] = 250.0
```

### Admin Data (Simple Variables)

```cpp
string adminUser = "";
string adminPass = "";
```

Koi struct nahi, sirf 2 simple string variables.

---

## 3. File Design

### 3.1 products.dat
**Purpose:** Saare products ka data store karna
**Format:** Text file (one field per line)

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

### 3.2 admin.dat
**Format:** Text file - pehli line username, doosri password
```
admin
admin123
```

### 3.3 reports.txt
Generated reports text format mein save hoti hain.

### 3.4 logs.txt
Har activity ka record (append mode - purana data delete nahi hota).

### 3.5 backup.dat
products.dat ki exact copy.

---

## 4. Module Design

| Module | Functions | Purpose |
|--------|-----------|---------|
| **Auth** | login(), createDefaultAdmin() | Login check |
| **Menu** | showMenu(), getMenuChoice() | Menu dikhana |
| **CRUD** | addProduct(), viewProducts(), searchProduct(), updateProduct(), deleteProduct() | Product manage |
| **Stock** | stockIn(), stockOut() | Stock in/out |
| **Reports** | generateReport(), lowStockAlert() | Reports |
| **Sort** | sortProducts() | Bubble sort |
| **Files** | saveData(), loadData(), backupData(), writeLog() | File I/O |
| **Utils** | clearScreen(), pause(), printLine() | Helpers |

---

## 5. Libraries Used

| Library | Purpose |
|---------|---------|
| `<iostream>` | cout, cin (input/output) |
| `<fstream>` | ifstream, ofstream (file handling) |
| `<string>` | string class (text) |

**Note:** Humne `<iomanip>`, `<ctime>`, `<cstdlib>` use NAHI kiye. Sirf 3 basic libraries.

---

## 6. Key Algorithms

### Linear Search (findProductIndex, isDuplicateID)
- Har element ko one by one check karo
- Time: O(n)

### Bubble Sort (sortProducts)
- Adjacent elements compare aur swap karo
- 7 parallel arrays ek saath swap hoti hain
- Time: O(n²)

---

**Phase 2 Complete!**
