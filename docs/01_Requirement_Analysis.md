# PHASE 1: Requirement Analysis
## Inventory Management System (IMS)
### Programming Fundamentals (PF) Project - Roman Urdu Documentation

---

## Phase Objective

Is phase mein hum project ki requirements samajhte hain - yani yeh decide karte hain ke system kya karega, user ki kya zaroorat hai, aur project ka scope kya hoga.

In this phase, we understand what the system will do, what the user needs, and what the scope of the project is.

---

## 1. Project Introduction

**Roman Urdu:**
Inventory Management System (IMS) ek C++ console application hai jo businesses ko unke products manage karne mein madad karti hai. Pehle businesses apna inventory haath se registers ya diaries mein likhte the. Yeh tarika purana hai aur usmein galtiyan hoti hain - product kho jata hai, quantity galat likhi jati hai, aur reports banana mushkil hota hai.

Humara computerized system yeh sab masle hal karta hai. Ab user apne computer se:
- Products add kar sakta hai
- Products dekh sakta hai
- Products search kar sakta hai
- Products update kar sakta hai
- Products delete kar sakta hai
- Stock manage kar sakta hai (aaya kitna, gaya kitna)
- Reports nikal sakta hai
- Data permanently save kar sakta hai

**English:**
The Inventory Management System (IMS) is a C++ console application that helps businesses manage their products efficiently. Traditionally, businesses maintained inventory manually in registers. This method is outdated and error-prone - products get misplaced, quantities are recorded incorrectly, and generating reports is difficult.

Our computerized system solves all these problems by allowing users to manage products digitally from their computer.

---

## 2. Problem Statement

**Roman Urdu:**
Bohat se chote businesses aaj bhi paper-based inventory system use karte hain. Ismein yeh masle hain:

1. **Galtiyan (Errors):** Haath se likhne mein numbers galat ho sakte hain
2. **Waqt Zaya Hota Hai (Time Consuming):** Ek product dhundne mein bohat waqt lagta hai jab data paper par ho
3. **Reports Mushkil Hain:** Monthly ya weekly report banana mushkil aur slow hai
4. **Data Safe Nahi Rehta:** Register kho sakta hai, phat sakta hai, ya purana ho sakta hai
5. **Stock Track Nahi Hota:** Kab product khatam hone wala hai, yeh pata nahi chalta

Humara system yeh sab problems solve karega.

**English:**
Many small businesses still use paper-based inventory systems. These have several problems:

1. **Errors:** Manual data entry leads to mistakes
2. **Time Consuming:** Finding product information takes too long on paper
3. **Difficult Reports:** Generating reports is slow and error-prone
4. **Data Security:** Paper records can be lost, damaged, or deteriorate
5. **No Stock Tracking:** Hard to know when a product is running low

Our system will solve all these problems.

---

## 3. Objectives

**Roman Urdu:**
Is project ka maqsad hai:

1. Ek computerized system banana jo manual inventory ki jagah le
2. Products ko add, view, search, update, aur delete karne ki facility dena
3. Stock management karna (kitna aaya, kitna gaya)
4. Reports generate karna (inventory summary, low stock, out of stock)
5. Data ko permanently files mein save karna
6. Programming Fundamentals ke concepts practically implement karna

**English:**
The objectives of this project are:

1. Create a computerized system to replace manual inventory records
2. Provide facilities to add, view, search, update, and delete products
3. Manage stock (in and out)
4. Generate reports (inventory summary, low stock, out of stock)
5. Save data permanently in files
6. Practically implement Programming Fundamentals concepts

---

## 4. Scope

**Roman Urdu:**
Is project ka scope yeh hai:

### Kya Karenge (In Scope):
- C++ console application banana
- Admin login system (username + password)
- Product management (CRUD operations)
- Stock management (in and out)
- File handling se data save aur load karna
- Reports generate karna
- Sorting features (naam se, price se, quantity se)
- Low stock alert dena
- Backup system
- Activity logging

### Kya Nahi Karenge (Out of Scope):
- Graphical User Interface (GUI) - sirf console use karenge
- Online/Network features - sirf ek computer par chalega
- Barcode scanner ya printer integration
- Database (MySQL, SQLite) use nahi karenge
- Web application nahi banayenge

**English:**
### In Scope:
- C++ console application
- Admin login system
- Product CRUD operations
- Stock management
- File-based data storage
- Report generation
- Sorting features
- Low stock alerts
- Backup system
- Activity logging

### Out of Scope:
- Graphical User Interface (GUI)
- Online/Network features
- Barcode scanner or printer integration
- Database (MySQL, SQLite)
- Web application

---

## 5. User Requirements

**Roman Urdu:**
User ko yeh features chahiye:

### Functional Requirements (Jo System Karega):

| # | Requirement | Description (Roman Urdu) |
|---|-------------|--------------------------|
| 1 | Login System | User ko username aur password se login karna hoga |
| 2 | Add Product | Naya product add kar sake (ID, naam, category, supplier, quantity, prices) |
| 3 | View Products | Saare products table format mein dekh sake |
| 4 | Search Product | ID ya naam se product dhund sake |
| 5 | Update Product | Product ki information change kar sake |
| 6 | Delete Product | Product ko system se remove kar sake |
| 7 | Stock In | Naya stock add kare (quantity barhaye) |
| 8 | Stock Out | Stock nikale (quantity kam kare) |
| 9 | Generate Reports | Inventory summary, low stock, out of stock reports |
| 10 | Sort Products | Products ko naam, price, ya quantity se sort kare |
| 11 | Low Stock Alert | Jab koi product kam ho jaye toh alert de |
| 12 | Backup | Data ka backup le sake |
| 13 | Exit | Safely program se bahar aaye |

### Non-Functional Requirements (System Kaisa Hoga):

| # | Requirement | Description |
|---|-------------|-------------|
| 1 | Simple Interface | Console menu clear aur samajhne mein asaan ho |
| 2 | Data Security | Login ke bina koi data access na kar sake |
| 3 | Data Persistence | Program band hone ke baad bhi data save rahe |
| 4 | Error Handling | Galat input par crash na ho, user ko bataye |
| 5 | Fast Response | Operations jaldi complete hon |

---

## 6. Programming Concepts Used

**Roman Urdu:**
Is project mein yeh PF concepts use honge:

| Concept | Kahan Use Hoga |
|---------|----------------|
| **Variables** | Product ID, naam, quantity, price store karne ke liye |
| **Data Types** | int (ID, quantity), string (naam), double (price) |
| **Arrays** | Multiple products store karne ke liye |
| **Structures** | Product ka complete data ek jagah rakhne ke liye |
| **Functions** | Har kaam ke liye alag function (addProduct, viewProducts, etc.) |
| **Loops** | Menu repeatedly dikhane ke liye, products iterate karne ke liye |
| **If-Else** | Menu choice check karne ke liye, conditions ke liye |
| **File Handling** | Data save aur load karne ke liye |
| **Searching** | Linear search - ID ya naam se product dhundne ke liye |
| **Sorting** | Bubble sort, Selection sort - products sort karne ke liye |

---

## 7. Team Members

| Name | Roll No | Role |
|------|---------|------|
| Ahmad Mahmood Rana | 007 | Team Lead, Developer |
| Muhammad Suleman | 020 | Developer, Tester |
| Syed Usman Ahmad | 055 | Developer, Documenter |
| Ashar Yar | 320 | Developer, Tester |
| Arslan Ali | 017 | Developer, Documenter |

---

## 8. Tools & Technologies

**Roman Urdu:**
- **Language:** C++ (C++11 standard)
- **IDE:** Dev C++
- **Data Storage:** Files (.txt aur .dat)
  - products.dat (products ka data)
  - admin.dat (admin login credentials)
  - reports.txt (generated reports)
  - logs.txt (activity logs)
  - backup.dat (data backup)

---

## 9. Expected Output

**Roman Urdu:**
Jab program chalega toh yeh flow hoga:

1. Program start hoga
2. Login screen aayega
3. Username aur password enter karna hoga
4. Agar correct hai toh Main Menu dikhega
5. User apni choice select karega (1-12)
6. Operation perform hoga
7. Data file mein save hoga
8. User dobara menu dekh sakta hai ya exit kar sakta hai

---

## 10. Problems & Solutions (Is Phase Ke)

| Problem | Solution |
|---------|----------|
| Pehli baar itna bada project kar rahe hain | Chote modules mein divide kiya hai |
| Requirements clear nahi thi | Is document mein sab clearly likha hai |
| Kya features include karein confuse the | Reference PDF se guide liya |

---

## Phase 1 Summary (Roman Urdu)

> "Is phase mein humne decide kiya ke humara Inventory Management System kya karega. Humne problem statement likhi, objectives define kiye, scope set kiya, aur user requirements list kiye. Ab humein pata hai ke system ko kya features chahiye aur programming concepts kahan use honge. Agle phase mein hum system design karenge."

---

## Phase 1 Summary (English)

> "In this phase, we defined what our Inventory Management System will do. We wrote the problem statement, defined objectives, set the scope, and listed user requirements. Now we know what features the system needs and where programming concepts will be used. In the next phase, we will design the system."

---

**Phase 1 Complete!**
**Review and approve to proceed to Phase 2: System Design & File Design**
