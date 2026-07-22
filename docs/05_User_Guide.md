# PHASE 9: User Guide - How to Use IMS
## Inventory Management System (IMS)
### Step-by-Step Operating Guide for New Users

---

## Is Guide Mein Kya Hai?

Yeh guide un logon ke liye hai jo pehli baar IMS use kar rahe hain. Hum step by step batayenge ke:
- Program kaise start karna hai
- Login kaise karna hai
- Har feature kaise use karna hai
- Data kahan save hota hai

---

## 1. Program Start Karna

### Red Panda Dev-C++ Mein:
1. Red Panda Dev-C++ open karein
2. Apna IMS project open karein
3. **F9** press karein (Compile and Run)
4. Ek black console window khulegi - yeh IMS hai

### Command Line Se:
```
g++ -o ims main.cpp
./ims
```

---

## 2. Welcome Screen

Jab program start hoga toh yeh screen dikhega:

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

**Kya Karein:** Enter press karein aage badhne ke liye.

---

## 3. Login Screen

Welcome screen ke baad login screen aayega:

```
==================================================
          ADMIN LOGIN
==================================================

   Attempts Remaining: 3

   Username: _
   Password: _
```

### Default Login Credentials:

| Field | Value |
|-------|-------|
| **Username** | `admin` |
| **Password** | `admin123` |

### Steps:
1. `admin` type karein aur Enter press karein
2. `admin123` type karein aur Enter press karein
3. Agar sahi hai toh "Login Successful!" message aayega

### Important Rules:
- Aapko **3 attempts** milte hain
- Agar 3 baar galat password dala toh **program band** ho jayega
- Har login attempt ka record `data/logs.txt` mein save hota hai

---

## 4. Main Menu

Login ke baad yeh menu dikhega:

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
   Enter your choice (1-12): _
```

Number type karein aur Enter press karein. Neeche har option detail mein explained hai.

---

## 5. Add Product (Option 1)

Naya product add karne ke liye.

### Step-by-Step:

```
==================================================
      ADD NEW PRODUCT
==================================================

   Enter Product ID: 1001
   Enter Product Name: Dell Laptop
   Enter Category (e.g., Electronics, Grocery): Electronics
   Enter Supplier Name: TechWorld Pvt Ltd
   Enter Quantity: 25
   Enter Purchase Price (Rs.): 45000
   Enter Selling Price (Rs.): 55000

   Product added successfully!
==================================================

Press Enter to continue...
```

### Fields Explanation:

| Field | Kya Dalna Hai | Example |
|-------|--------------|---------|
| **Product ID** | Unique number (kisi aur product ka same nahi ho sakta) | 1001 |
| **Product Name** | Product ka naam | Dell Laptop |
| **Category** | Product kis type ka hai | Electronics, Grocery, Stationery |
| **Supplier** | Supplier company ka naam | TechWorld Pvt Ltd |
| **Quantity** | Kitne products stock mein hain (0 ya usse zyada) | 25 |
| **Purchase Price** | Kharidne ki price (0 ya usse zyada) | 45000 |
| **Selling Price** | Bechne ki price (0 ya usse zyada) | 55000 |

### Rules:
- ID **unique** hona chahiye - agar same ID pehle se hai toh error aayega
- Quantity aur prices **negative** nahi ho sakte - agar negative daale toh dobara poochega
- Zyada se zyada **100 products** add kar sakte hain

---

## 6. View Products (Option 2)

Saare products table format mein dekhne ke liye.

### Example Output:

```
==================================================
      VIEW ALL PRODUCTS
==================================================

   ID    Name                Category       Qty       Purch.Price Sell.Price
   ============================================================================
   1001  Dell Laptop         Electronics    25        Rs.45000     Rs.55000
   1002  USB Cable           Accessories    150       Rs.50        Rs.150
   1003  Mouse Pad           Accessories    3         Rs.20        Rs.80
   ============================================================================
   Total Products: 3

Press Enter to continue...
```

### Kya Dikhata Hai:
- Har product ki complete details ek row mein
- **Total Products** count neeche
- Agar koi product nahi hai toh "No products in inventory" message aayega

---

## 7. Search Product (Option 3)

Kisi specific product ko dhundne ke liye.

### Step 1: Search Method Choose Karein

```
   Search by:
   1. Product ID
   2. Product Name
   Enter choice: _
```

### Option A: Search by ID (Choice 1)

```
   Enter Product ID to search: 1001

   Product Found!
   ========================================
   ID:            1001
   Name:          Dell Laptop
   Category:      Electronics
   Supplier:      TechWorld Pvt Ltd
   Quantity:      25
   Purchase Price: Rs.45000
   Selling Price:  Rs.55000
   ========================================
```

- Exact ID dalni padti hai
- Agar ID nahi milti toh "not found" message aayega

### Option B: Search by Name (Choice 2)

```
   Enter Product Name to search: Lap

   Matching Products:
   ============================================================================
   ID    Name                Category       Qty       Purch.Price Sell.Price
   ============================================================================
   1001  Dell Laptop         Electronics    25        Rs.45000     Rs.55000
   1005  Laptop Bag          Accessories    50        Rs.200       Rs.500
   ============================================================================
```

- **Partial name** se bhi search ho jata hai
- "Lap" likhne se "Dell **Lap**top" aur "**Lap**top Bag" dono milenge
- Saare matching products table mein dikhenge

---

## 8. Update Product (Option 4)

Kisi product ki details change karne ke liye.

### Step 1: Product ID Dalein

```
   Enter Product ID to update: 1001
```

### Step 2: Current Details Dikhenge

```
   Current Product Details:
   ========================================
   ID:            1001
   Name:          Dell Laptop
   Category:      Electronics
   Supplier:      TechWorld Pvt Ltd
   Quantity:      25
   Purchase Price: Rs.45000
   Selling Price:  Rs.55000
   ========================================
```

### Step 3: Kaunsa Field Change Karna Hai

```
   Which field do you want to update?
   1. Name
   2. Category
   3. Supplier
   4. Quantity
   5. Purchase Price
   6. Selling Price
   Enter choice: _
```

### Step 4: New Value Dalein

Example - agar aapne 6 (Selling Price) choose kiya:
```
   Enter new Selling Price: 56000

   Product updated successfully!
```

### Rules:
- Sirf existing products update ho sakte hain
- ID change nahi ho sakta (sirf baaki fields)

---

## 9. Delete Product (Option 5)

Kisi product ko system se remove karne ke liye.

### Step 1: Product ID Dalein

```
   Enter Product ID to delete: 1003
```

### Step 2: Product Details Dikhenge

```
   Product Details:
   ========================================
   ID:            1003
   Name:          Mouse Pad
   Category:      Accessories
   ...
   ========================================
```

### Step 3: Confirmation

```
   Are you sure you want to delete this product? (y/n): y

   Product deleted successfully!
```

### Rules:
- `y` press karein confirm karne ke liye
- `n` press karein cancel karne ke liye
- Delete hone ke baad wapas nahi aa sakta!

---

## 10. Stock In (Option 6)

Naya stock add karne ke liye (quantity barhane ke liye).

### Example:

```
==================================================
      STOCK IN (Add Stock)
==================================================

   Enter Product ID: 1001
   Current Stock of 'Dell Laptop': 25
   Enter quantity to add: 10

   Stock updated successfully!
   New Stock of 'Dell Laptop': 35
```

### Steps:
1. Product ID dalein
2. Current stock dikhega
3. Kitna add karna hai woh dalein (positive number)
4. New stock dikhega

### Rules:
- Quantity **positive** honi chahiye (0 se zyada)
- Sirf existing products ka stock add ho sakta hai

---

## 11. Stock Out (Option 7)

Stock nikalne ke liye (quantity kam karne ke liye).

### Example:

```
==================================================
      STOCK OUT (Remove Stock)
==================================================

   Enter Product ID: 1001
   Current Stock of 'Dell Laptop': 35
   Enter quantity to remove: 5

   Stock updated successfully!
   Remaining Stock of 'Dell Laptop': 30
```

### Rules:
- Quantity **positive** honi chahiye
- Itna stock nikalne ko nahi de sakte jitna available nahi hai
- Example: Agar 5 products hain toh 10 nahi nikal sakte - error aayega

```
   ERROR: Not enough stock! Available: 5
```

---

## 12. Generate Reports (Option 8)

Reports banane ke liye. 3 types ki reports hain.

### Step 1: Report Type Choose Karein

```
   Select Report Type:
   1. Full Inventory Report
   2. Low Stock Report (Qty < 5)
   3. Out of Stock Report (Qty = 0)
   Enter choice: _
```

### Report 1: Full Inventory Report

Sabse complete report - saare products, total items, aur total value.

```
==================================================
      FULL INVENTORY REPORT
==================================================

   Date: Thu Jul 16 10:30:45 2026
   Total Products: 5
   Total Items in Stock: 253
   Total Inventory Value: Rs.2500000

   Products:
   ID    Name                Category       Qty       Purch.Price Sell.Price
   ============================================================================
   1001  Dell Laptop         Electronics    25        Rs.45000     Rs.55000
   1002  USB Cable           Accessories    150       Rs.50        Rs.150
   ...
   ============================================================================
```

**Kya Dikhata Hai:**
- Total kitne products hain
- Total kitne items stock mein hain
- Total inventory ki value (quantity × selling price ka sum)
- Saare products ki list

### Report 2: Low Stock Report

Sirf woh products dikhata hai jinki quantity 5 se kam hai (lekin 0 nahi).

```
==================================================
      LOW STOCK REPORT (Qty < 5)
==================================================

   Date: Thu Jul 16 10:30:45 2026
   [!] ID: 1003 | Mouse Pad | Qty: 3
   [!] ID: 1007 | Pen | Qty: 2

   Total Low Stock Items: 2
```

### Report 3: Out of Stock Report

Sirf woh products jo bilkul khatam ho gaye hain (quantity = 0).

```
==================================================
      OUT OF STOCK REPORT (Qty = 0)
==================================================

   Date: Thu Jul 16 10:30:45 2026
   [X] ID: 1008 | HDMI Cable | Qty: 0

   Total Out of Stock Items: 1
```

### Note:
- Har report **screen par bhi dikhti hai** aur **`data/reports.txt` file mein bhi save** hoti hai
- Reports file ko Notepad++ ya kisi bhi text editor mein khol kar dekh sakte hain

---

## 13. Sort Products (Option 9)

Products ko kisi order mein arrange karne ke liye.

### Step 1: Sort Method Choose Karein

```
   Sort by:
   1. Name (A-Z)
   2. Selling Price (Low to High)
   3. Quantity (Low to High)
   Enter choice: _
```

### Option 1: Sort by Name (A-Z)
Products ko naam ke hisaab se alphabetically arrange karta hai.

**Example:**
```
Before: Dell Laptop, Apple iPhone, Samsung Phone
After:  Apple iPhone, Dell Laptop, Samsung Phone
```

### Option 2: Sort by Selling Price (Low to High)
Sasti cheez pehle, mehngi baad mein.

**Example:**
```
Before: Rs.55000, Rs.150, Rs.500
After:  Rs.150, Rs.500, Rs.55000
```

### Option 3: Sort by Quantity (Low to High)
Kam stock pehle, zyada stock baad mein.

**Example:**
```
Before: 25, 3, 150
After:  3, 25, 150
```

### Note:
- Sorting **permanent** hai - file mein bhi sorted order save hota hai
- Sort karne ke baad products table sorted order mein dikhega

---

## 14. Low Stock Alert (Option 10)

Turant dekhne ke liye ke kaunse products kam ho rahe hain.

### Example Output:

```
==================================================
      LOW STOCK ALERT
==================================================

   Products with LOW STOCK (Quantity < 5):

   [OUT OF STOCK] ID: 1008 | HDMI Cable | Qty: 0
   [LOW STOCK]    ID: 1003 | Mouse Pad | Qty: 3
   [LOW STOCK]    ID: 1007 | Pen | Qty: 2

   Total Alerts: 3 product(s) need attention.
```

### Kya Dikhata Hai:
- **[OUT OF STOCK]** - Product bilkul khatam (Qty = 0)
- **[LOW STOCK]** - Product kam ho raha hai (Qty 1-4)
- Total kitne products ko attention chahiye

### Agar Sab Sahi Hai:
```
   All products have sufficient stock!
```

---

## 15. Backup Data (Option 11)

Data ka backup lene ke liye. Agar kabhi `products.dat` corrupt ho jaye toh backup se restore kar sakte hain.

### Example Output:

```
==================================================
      BACKUP DATA
==================================================

   Backup created successfully!
   Data backed up to: data/backup.dat
   Backup Date: Thu Jul 16 10:30:45 2026
   Products Backed Up: 5
```

### Rules:
- Backup mein us waqt ke saare products ki copy hoti hai
- Har baar backup lene se purani backup **overwrite** ho jati hai
- Backup regularly lena chahiye (especially zyada products hone par)

---

## 16. Exit (Option 12)

Program se bahar aane ke liye.

```
==================================================
   Thank you for using IMS!
   Goodbye!
==================================================
```

### Kya Hota Hai:
1. Saara data automatically `data/products.dat` mein save hota hai
2. Logout ka log entry `data/logs.txt` mein save hota hai
3. Program band ho jata hai

---

## 17. Data Files

Program yeh files `data/` folder mein banata hai:

| File | Format | Kya Store Hota Hai |
|------|--------|-------------------|
| `products.dat` | Binary | Saare products ka data (ID, naam, category, etc.) |
| `admin.dat` | Binary | Admin username aur password |
| `logs.txt` | Text | Har activity ka record (login, add, delete, etc.) |
| `reports.txt` | Text | Last generated report |
| `backup.dat` | Binary | Products data ka backup copy |

### logs.txt Example:

```
[Thu Jul 16 10:30:00 2026] LOGIN SUCCESS - User: admin
[Thu Jul 16 10:31:20 2026] PRODUCT ADDED - ID: 1001, Name: Dell Laptop
[Thu Jul 16 10:35:10 2026] STOCK IN - ID: 1001, Name: Dell Laptop, Quantity Added: 10, New Stock: 35
[Thu Jul 16 10:40:00 2026] PRODUCT UPDATED - ID: 1001, Field: 6
[Thu Jul 16 10:45:30 2026] PRODUCT DELETED - ID: 1003, Name: Mouse Pad
[Thu Jul 16 11:00:00 2026] REPORT GENERATED
[Thu Jul 16 11:05:00 2026] BACKUP CREATED
[Thu Jul 16 11:10:00 2026] LOGOUT - User exited the system
```

### Important:
- `data/` folder **delete mat karein** warna saara data kho jayega
- `.dat` files binary hain - Notepad mein nahi khulengi (garbage dikhega)
- `.txt` files Notepad++ ya kisi bhi text editor mein khul sakti hain

---

## 18. Common Issues & Solutions

### Problem: "No products in inventory"
**Solution:** Pehle kuch products add karein (Option 1).

### Problem: "Product ID already exists"
**Solution:** Different ID use karein. Har product ka ID unique hona chahiye.

### Problem: "Product not found"
**Solution:** Sahi ID dalein. View Products (Option 2) se sahi ID dekh lein.

### Problem: "Not enough stock"
**Solution:** Stock Out mein utna mat nikalo jitna available nahi hai.

### Problem: "Product limit reached"
**Solution:** Maximum 100 products ho sakte hain. Purane products delete karein.

### Problem: Program crash ho gaya
**Solution:** `data/` folder check karein. Agar corrupt hai toh delete karein aur program dobara start karein.

### Problem: Data show nahi ho raha
**Solution:** Check karein ke program `src/` folder se run ho raha hai jahan `data/` folder hai.

---

## 19. Quick Reference Card

```
┌─────────────────────────────────────────────────┐
│            IMS QUICK REFERENCE                    │
├─────────────────────────────────────────────────┤
│                                                   │
│  Login:      admin / admin123                     │
│                                                   │
│  Option 1:   Add new product                      │
│  Option 2:   View all products                    │
│  Option 3:   Search by ID or Name                 │
│  Option 4:   Update product details               │
│  Option 5:   Delete a product                     │
│  Option 6:   Add stock (quantity increase)        │
│  Option 7:   Remove stock (quantity decrease)     │
│  Option 8:   Generate reports                     │
│  Option 9:   Sort products                        │
│  Option 10:  See low stock alerts                 │
│  Option 11:  Create data backup                   │
│  Option 12:  Exit (auto-saves data)               │
│                                                   │
│  Max Products: 100                                │
│  Low Stock:    Quantity < 5                       │
│  Login Tries:  3 attempts                         │
│                                                   │
│  Data Folder:  src/data/                          │
│                                                   │
└─────────────────────────────────────────────────┘
```

---

## 20. Complete Workflow Example

Naye user ke liye ek complete example - pehli baar IMS use karna:

### Step 1: Program Start
```
F9 press karein → Welcome Screen → Enter press
```

### Step 2: Login
```
Username: admin
Password: admin123
Enter press
```

### Step 3: Pehle Products Add Karein (Option 1)
```
ID: 1001
Name: Dell Laptop
Category: Electronics
Supplier: TechWorld Pvt Ltd
Quantity: 25
Purchase Price: 45000
Selling Price: 55000
```

```
ID: 1002
Name: USB Cable
Category: Accessories
Supplier: CableMart
Quantity: 150
Purchase Price: 50
Selling Price: 150
```

```
ID: 1003
Name: Mouse Pad
Category: Accessories
Supplier: CableMart
Quantity: 3
Purchase Price: 20
Selling Price: 80
```

### Step 4: Saare Products Dekhein (Option 2)
```
Choice: 2
→ Table mein 3 products dikhenge
```

### Step 5: Kisi Product Ko Search Karein (Option 3)
```
Choice: 3
Search by: 1 (ID)
ID: 1001
→ Dell Laptop ki complete details dikhenge
```

### Step 6: Stock Add Karein (Option 6)
```
Choice: 6
ID: 1001
Quantity to add: 10
→ Dell Laptop ka stock 25 se 35 ho jayega
```

### Step 7: Stock Nikalein (Option 7)
```
Choice: 7
ID: 1002
Quantity to remove: 20
→ USB Cable ka stock 150 se 130 ho jayega
```

### Step 8: Low Stock Check Karein (Option 10)
```
Choice: 10
→ Mouse Pad [LOW STOCK] dikhega (Qty: 3)
```

### Step 9: Report Generate Karein (Option 8)
```
Choice: 8
Report Type: 1 (Full Inventory)
→ Complete report screen par aur file mein save
```

### Step 10: Products Sort Karein (Option 9)
```
Choice: 9
Sort by: 1 (Name)
→ Products A-Z order mein arrange ho jayenge
```

### Step 11: Backup Lein (Option 11)
```
Choice: 11
→ Backup ban jayega
```

### Step 12: Exit (Option 12)
```
Choice: 12
→ Data auto-save hoga, program band
```

### Next Time:
Jab dobara program kholenge toh saare products waise ke waise milenge kyunki data file mein save tha!

---

**User Guide Complete!**
**Ab aap IMS ko confidently use kar sakte hain!**
