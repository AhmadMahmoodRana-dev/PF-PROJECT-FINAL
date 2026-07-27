# PHASE 8: Code Explanation (Roman Urdu)
## Inventory Management System (IMS)
### Programming Fundamentals (PF) Project - Line by Line Explanation

---

## Is Document Mein Kya Hai?

Is document mein hum apne poore project ka code line by line samjhenge Roman Urdu mein. Saara code **ek hi file** (main.cpp) mein hai. Koi header file, struct ya complex library use nahi ki hai - **sirf basics**.

---

## 1. Includes - Libraries

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
```

**Explanation:**
- `iostream` - `cout` (output) aur `cin` (input) ke liye
- `fstream` - File handling ke liye (`ofstream` likhne ke liye, `ifstream` parhne ke liye)
- `string` - C++ ki string class ke liye (text store karne ke liye)
- `using namespace std;` - Taake baar baar `std::` na likhna pare

**Note:** Humne `<iomanip>`, `<ctime>`, aur koi aur library use NAHI ki. Sirf yeh 3 basic libraries kaafi hain.

---

## 2. Constants aur Parallel Arrays

```cpp
const int MAX_PRODUCTS = 100;
```
**Explanation:** `const int` ka matlab hai yeh value change nahi ho sakti. Maximum 100 products store ho sakte hain.

---

```cpp
int ids[MAX_PRODUCTS];
string names[MAX_PRODUCTS];
string categories[MAX_PRODUCTS];
string suppliers[MAX_PRODUCTS];
int quantities[MAX_PRODUCTS];
double purchasePrices[MAX_PRODUCTS];
double sellingPrices[MAX_PRODUCTS];
int productCount = 0;
```

**Explanation:** Yeh **Parallel Arrays** hain. Ek struct ki jagah humne 7 alag arrays banayi hain. Har index `i` par saari 7 arrays mil kar ek product banati hain.

**Example:** Product at index 0:
| Array | Index 0 | Matlab |
|-------|---------|--------|
| `ids[0]` | 101 | Product ID |
| `names[0]` | "Dell Laptop" | Naam |
| `categories[0]` | "Electronics" | Category |
| `suppliers[0]` | "TechWorld" | Supplier |
| `quantities[0]` | 25 | Stock mein kitne |
| `purchasePrices[0]` | 45000 | Kharidne ki qeemat |
| `sellingPrices[0]` | 55000 | Bechne ki qeemat |

- `productCount` batata hai ke abhi kitne products add hue hain (shuru mein 0)

---

```cpp
string adminUser = "";
string adminPass = "";
```
**Explanation:** Admin ke login credentials. Simple string variables, koi struct nahi.

---

```cpp
const string PRODUCTS_FILE = "data/products.dat";
const string ADMIN_FILE = "data/admin.dat";
const string LOGS_FILE = "data/logs.txt";
const string REPORTS_FILE = "data/reports.txt";
const string BACKUP_FILE = "data/backup.dat";
```
**Explanation:** File paths. `const string` matlab yeh change nahi hongi.

---

## 3. Function Declarations (Forward Declarations)

```cpp
void showMenu();
int getMenuChoice();
void addProduct();
void viewProducts();
// ... etc
```

**Explanation:** Compiler ko pehle bata rahe hain ke yeh functions baad mein defined hain. Isse `main()` mein kisi bhi order mein call kar sakte hain.

---

## 4. Helper Functions

### clearScreen()
```cpp
void clearScreen() {
    for (int i = 0; i < 25; i++) {
        cout << endl;
    }
}
```
**Explanation:** 25 blank lines print karke screen "clear" karta hai. `system("cls")` ki jagah yeh simple tarika hai.

---

### pause()
```cpp
void pause() {
    cout << "\nPress Enter to continue...";
    cin.get();
}
```
**Explanation:** Program rok deta hai jab tak user Enter na dabaye. `cin.get()` Enter key wait karta hai.

---

### printLine()
```cpp
void printLine(int length) {
    for (int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
}
```
**Explanation:** `=` signs ki line draw karta hai. Default 50 characters lambi.

---

### getDateTime()
```cpp
string getDateTime() {
    return "---";
}
```
**Explanation:** Simple placeholder text return karta hai. `ctime` library ki zaroorat nahi.

---

## 5. main() Function - Program Start

```cpp
int main() {
    clearScreen();
    // Welcome screen
    printLine(50);
    cout << "   INVENTORY MANAGEMENT SYSTEM (IMS)" << endl;
    // ...
    pause();
```
**Explanation:** Program yahan se start hota hai. Pehle welcome screen dikhate hain.

---

```cpp
    loadData();
    createDefaultAdmin();
    loadAdmin();
```
**Explanation:** Startup pe 3 kaam:
1. `loadData()` - Agar pehle se products hain toh file se load karo
2. `createDefaultAdmin()` - Pehli baar admin account banao
3. `loadAdmin()` - Admin credentials file se parho

---

```cpp
    if (!login()) {
        cout << "   Login failed! Maximum attempts exceeded." << endl;
        pause();
        return 0;
    }
```
**Explanation:** `login()` true return kare toh aage badho, false toh program exit. `!` ka matlab "NOT".

---

```cpp
    int choice;
    do {
        showMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            // ... cases 3-11
            case 12: /* save and exit */ break;
            default: /* invalid */ break;
        }
    } while (choice != 12);
```

**Explanation:** **do-while loop** + **switch statement** ka combination:
- `do-while` - Pehle menu dikhao, phir condition check karo (kam az kam ek baar chalta hai)
- `switch` - User ki choice ke hisaab se sahi function call karo
- `break` - Zaroori hai warna neeche ke cases bhi chal jayenge
- `default` - Agar 1-12 ke ilawa koi number dale
- `while (choice != 12)` - Jab tak Exit na dabaye, loop chalta rahe

---

## 6. login() - Authentication

```cpp
bool login() {
    int attempts = 3;
    string username, password;

    while (attempts > 0) {
        // ... input lete hain
        if (username == adminUser && password == adminPass) {
            return true;
        } else {
            attempts--;
        }
    }
    return false;
}
```

**Explanation:**
- `bool` return type - `true` ya `false` return karta hai
- `while (attempts > 0)` - 3 mauke milenge
- `getline(cin, username)` - Spaces ke saath input leta hai
- `==` - String comparison. C++ mein `string` ke saath `==` direct use hota hai
- `&&` - AND operator. Dono conditions true honi chahiye
- `attempts--` - Ek attempt kam (3→2→1→0)

---

## 7. File Handling Functions

### saveAdmin() / loadAdmin()

```cpp
void saveAdmin() {
    ofstream file(ADMIN_FILE);
    if (file.is_open()) {
        file << adminUser << endl;
        file << adminPass << endl;
        file.close();
    }
}
```

**Explanation:**
- `ofstream` - Output File Stream (file mein likhne ke liye)
- `file.is_open()` - Check karta hai file successfully khuli ya nahi
- `file << adminUser` - `<<` operator se file mein likhte hain
- `file.close()` - File band karo (important!)

---

### saveData() - Products Save

```cpp
void saveData() {
    ofstream file(PRODUCTS_FILE);
    if (file.is_open()) {
        file << productCount << endl;
        for (int i = 0; i < productCount; i++) {
            file << ids[i] << endl;
            file << names[i] << endl;
            file << categories[i] << endl;
            file << suppliers[i] << endl;
            file << quantities[i] << endl;
            file << purchasePrices[i] << endl;
            file << sellingPrices[i] << endl;
        }
        file.close();
    }
}
```

**Explanation:**
- Pehle `productCount` save karte hain (kitne products hain)
- Phir loop mein har product ke 7 fields line by line likhte hain
- **For loop** se har product iterate hota hai
- **Array indexing** - `ids[i]`, `names[i]`, etc. se ith product ka data milta hai

---

### loadData() - Products Load

```cpp
void loadData() {
    ifstream file(PRODUCTS_FILE);
    if (file.is_open()) {
        file >> productCount;
        if (productCount > 0 && productCount <= MAX_PRODUCTS) {
            for (int i = 0; i < productCount; i++) {
                file >> ids[i];
                file.ignore();
                getline(file, names[i]);
                // ... baaki fields
            }
        }
        file.close();
    }
}
```

**Explanation:**
- `ifstream` - Input File Stream (file se parhne ke liye)
- `file >> productCount` - `>>` operator se number parhte hain
- `file.ignore()` - Newline character skip karta hai (`>>` ke baad `getline` se pehle zaroori)
- `getline(file, names[i])` - String parhta hai (spaces ke saath)
- Safety check: `productCount > 0 && productCount <= MAX_PRODUCTS`

---

### writeLog() - Activity Logger

```cpp
void writeLog(const string& message) {
    ofstream file(LOGS_FILE, ios::app);
    if (file.is_open()) {
        file << "[" << getDateTime() << "] " << message << endl;
        file.close();
    }
}
```

**Explanation:**
- `const string& message` - String ka reference leta hai (copy nahi hoti, fast hai)
- `ios::app` - **Append mode** - file ke end mein likhta hai, purana data delete nahi hota
- Har log entry: `[---] PRODUCT ADDED - ID: 101, Name: Dell Laptop`

---

## 8. Search Functions

### isDuplicateID()

```cpp
bool isDuplicateID(int id) {
    for (int i = 0; i < productCount; i++) {
        if (ids[i] == id) {
            return true;
        }
    }
    return false;
}
```

**Explanation:** **Linear Search** - pehle se last tak check karta hai ke yeh ID pehle se hai ya nahi.
- Loop se har `ids[i]` check karo
- Match mile → `true` (duplicate hai)
- Loop khatam, match nahi → `false` (unique hai)

---

### findProductIndex()

```cpp
int findProductIndex(int id) {
    for (int i = 0; i < productCount; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}
```

**Explanation:** Product ka **index** dhundta hai. Agar mil gaya toh uska position return karo (0, 1, 2...). Agar nahi mila toh `-1` return karo (kyunki valid index kabhi negative nahi hota).

---

## 9. addProduct() - Naya Product Add

```cpp
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "   ERROR: Product limit reached!" << endl;
        pause();
        return;
    }
```

**Explanation:** Pehle check karo ke 100 ki limit toh nahi aa gayi. `return` se function khatam ho jata hai.

---

```cpp
    int newId;
    cout << "   Enter Product ID: ";
    cin >> newId;

    if (isDuplicateID(newId)) {
        cout << "   ERROR: Product ID already exists!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        pause();
        return;
    }
```

**Explanation:**
- User se ID lo
- `isDuplicateID()` check karta hai duplicate toh nahi
- `cin.clear()` - Input errors clear karta hai
- `cin.ignore(10000, '\n')` - Buffer mein extra characters hata deta hai

---

```cpp
    int pos = productCount;
    ids[pos] = newId;

    cout << "   Enter Product Name: ";
    getline(cin, names[pos]);
    // ... baaki fields
```

**Explanation:** `pos` nayi position hai (jaise agar 5 products hain toh pos = 5). Har array ke `pos` index par data store karo.

---

```cpp
    while (quantities[pos] < 0) {
        cout << "   Quantity cannot be negative. Enter again: ";
        cin >> quantities[pos];
    }
```

**Explanation:** **Input Validation** - While loop se baar baar poocho jab tak valid input na mile. Negative quantity allowed nahi hai.

---

```cpp
    productCount++;
    saveData();
    writeLog("PRODUCT ADDED - ID: " + to_string(ids[pos]) + ", Name: " + names[pos]);
```

**Explanation:**
- `productCount++` - Ek product barh gaya
- `saveData()` - File mein save karo
- `to_string()` - Integer ko string mein convert karta hai (jaise 101 → "101")
- `+` operator - Strings jodta hai (concatenation)

---

## 10. viewProducts() - Products Dikhana

```cpp
void viewProducts() {
    if (productCount == 0) {
        cout << "   No products in inventory." << endl;
        pause();
        return;
    }

    cout << "   ID\t\tName\t\t\tCategory\tQty\tPurch.Price\tSell.Price" << endl;
    printLine(85);

    for (int i = 0; i < productCount; i++) {
        cout << "   " << ids[i]
             << "\t\t" << names[i]
             << "\t\t" << categories[i]
             << "\t" << quantities[i]
             << "\tRs." << purchasePrices[i]
             << "\t\tRs." << sellingPrices[i] << endl;
    }
}
```

**Explanation:**
- Pehle empty check
- `\t` (tab character) se columns align karte hain (iomanip ki zaroorat nahi)
- **For loop** se har product print hota hai
- `cout <<` chain se ek hi line mein saara data print hota hai

---

## 11. searchProduct() - Search

```cpp
    if (names[i].find(searchName) != string::npos) {
```

**Explanation:** `string::find()` - String ke andar string dhundta hai.
- Agar "Laptop" search karo aur product "Dell Laptop" hai → match milega
- `string::npos` = "not found" (match nahi mili)
- Yeh **partial matching** hai

---

## 12. updateProduct() - Update

```cpp
    switch (field) {
        case 1:
            getline(cin, names[index]);
            break;
        case 2:
            getline(cin, categories[index]);
            break;
        // ... etc
    }
```

**Explanation:** **Switch statement** se user ka chosen field update karte hain. Sirf wo ek array change hoti hai jo user ne select ki.

---

## 13. deleteProduct() - Delete with Shifting

```cpp
    if (confirm == 'y' || confirm == 'Y') {
        for (int i = index; i < productCount - 1; i++) {
            ids[i] = ids[i + 1];
            names[i] = names[i + 1];
            categories[i] = categories[i + 1];
            suppliers[i] = suppliers[i + 1];
            quantities[i] = quantities[i + 1];
            purchasePrices[i] = purchasePrices[i + 1];
            sellingPrices[i] = sellingPrices[i + 1];
        }
        productCount--;
    }
```

**Explanation:** **Array element deletion with shifting** - PF ka important concept:
- Deleted product ke baad wale saare products ek position peeche shift hote hain
- `[A, B, C, D, E]` mein C delete → `[A, B, D, E]`
- **7 arrays** shift hoti hain (parallel arrays mein har field alag array mein hai)
- `productCount--` - Ek product kam
- `confirm == 'y' || confirm == 'Y'` - OR operator, lowercase ya uppercase dono chalein

---

## 14. stockIn() aur stockOut()

```cpp
    quantities[index] += qty;   // stockIn - add
    quantities[index] -= qty;   // stockOut - subtract
```

**Explanation:**
- `+=` means `quantities[index] = quantities[index] + qty`
- `-=` means `quantities[index] = quantities[index] - qty`
- stockOut mein pehle check: `if (qty > quantities[index])` - itna stock hai ya nahi

---

## 15. generateReport() - Reports

```cpp
    int totalItems = 0;
    double totalValue = 0;
    for (int i = 0; i < productCount; i++) {
        totalItems += quantities[i];
        totalValue += quantities[i] * sellingPrices[i];
    }
```

**Explanation:**
- `totalItems` - Saare products ki total quantity (accumulator pattern)
- `totalValue` - Har product ki (quantity × selling price) ka sum = total inventory value
- `+=` se running total banta hai

---

## 16. sortProducts() - Bubble Sort

```cpp
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = 0; j < productCount - i - 1; j++) {
            if (names[j] > names[j + 1]) {
                int t1 = ids[j]; ids[j] = ids[j+1]; ids[j+1] = t1;
                string t2 = names[j]; names[j] = names[j+1]; names[j+1] = t2;
                // ... 5 aur arrays swap
            }
        }
    }
```

**Explanation:** **Bubble Sort** - PF ka sabse basic sorting algorithm:

1. **Outer loop** (`i`) - Kitne passes karne hain
2. **Inner loop** (`j`) - Adjacent (bagal bagal wale) elements compare
3. Agar pehla bada hai → **swap** (jagah badlo)
4. `productCount - i - 1` - Har pass mein ek element sahi jagah aa jata hai, toh usko dobara check nahi karte

**Swap karne ka tarika (3 steps):**
```
temp = A[j];      // pehla element temp mein save
A[j] = A[j+1];    // doosra pehle ki jagah
A[j+1] = temp;    // temp (pehla) doosre ki jagah
```

**Parallel arrays mein:** 7 arrays ko ek saath swap karna padta hai taake product ka data bikhre nahi.

**String comparison:** `names[j] > names[j+1]` - C++ string alphabetically compare hoti hai ("Apple" < "Dell")

**Time Complexity:** O(n²) - do nested loops hain

---

## 17. backupData() - File Copy

```cpp
    string line;
    while (getline(source, line)) {
        dest << line << endl;
    }
```

**Explanation:**
- `source` products.dat kholti hai read ke liye
- `dest` backup.dat kholti hai write ke liye
- `while (getline(source, line))` - Har line parho jab tak file khatam na ho
- `dest << line` - Doosri file mein likho
- Yeh **line-by-line file copy** hai

---

## PF Concepts Summary

| Concept | Kahan Use Hua |
|---------|--------------|
| **Variables** | productCount, choice, id, qty |
| **Data Types** | int, string, double, bool, char |
| **Arrays** | 7 parallel arrays (ids, names, categories, etc.) |
| **Constants** | `const int MAX_PRODUCTS = 100` |
| **Functions** | 20+ functions |
| **For Loop** | Arrays iterate, sorting, table print |
| **While Loop** | Input validation, file reading |
| **Do-While Loop** | Main menu (kam az kam ek baar chale) |
| **If-Else** | Login check, conditions, search |
| **Switch** | Menu choice, update field |
| **File I/O** | ofstream (write), ifstream (read), append mode |
| **Linear Search** | findProductIndex, isDuplicateID |
| **Bubble Sort** | sortProducts |
| **Input Validation** | Negative numbers, duplicate IDs |
| **String Operations** | ==, +, .find(), string::npos, to_string() |
| **Boolean Logic** | &&, !, == |
| **Character Comparison** | 'y' == 'Y' \|\| confirm |
| **Accumulator Pattern** | totalItems +=, totalValue += |

---

**Code Explanation Complete!**
**Ab aap har line samajh sakte hain ke kyun likhi gayi hai!**
