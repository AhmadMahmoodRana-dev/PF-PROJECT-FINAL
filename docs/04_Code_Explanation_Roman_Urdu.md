# PHASE 8: Code Explanation (Roman Urdu)
## Inventory Management System (IMS)
### Programming Fundamentals (PF) Project - Line by Line Explanation

---

## Is Document Mein Kya Hai?

Is document mein hum apne poore project ka code line by line samjhenge Roman Urdu mein. Har file, har function, aur har important line ko explain karenge taake aap easily samajh sakein ke code kaise kaam karta hai.

---

## 1. product.h - Header File (Product Structure)

Yeh file humare project ki **foundation** hai. Ismein humne data structures define kiye hain.

```cpp
#ifndef PRODUCT_H
#define PRODUCT_H
```
**Explanation:** Yeh **header guards** hain. Agar yeh file ek se zyada baar include ho jaye toh compiler dobara isse read nahi karega. `PRODUCT_H` ek unique naam hai jo compiler ko batata hai ke yeh file already include ho chuki hai.

---

```cpp
#include <iostream>
```
**Explanation:** `iostream` library include ki hai. Ismein `cout` (output print karne ke liye) aur `cin` (user se input lene ke liye) hain.

---

```cpp
#include <fstream>
```
**Explanation:** `fstream` library file handling ke liye hai. Ismein `ofstream` (file mein likhne ke liye) aur `ifstream` (file se parhne ke liye) hain.

---

```cpp
#include <cstring>
```
**Explanation:** `cstring` library C-style string functions ke liye hai. Hum `strcmp()` (do strings compare karna), `strcpy()` (string copy karna), aur `strstr()` (string ke andar string dhundna) use karenge.

---

```cpp
#include <string>
```
**Explanation:** `string` library C++ ki string class ke liye hai. Hum log messages aur date/time ke liye `string` type use karenge.

---

```cpp
#include <iomanip>
```
**Explanation:** `iomanip` library formatted output ke liye hai. `setw()` function se hum table mein columns ki width set karte hain taake products ki list achi dikhe.

---

```cpp
#include <ctime>
```
**Explanation:** `ctime` library se current date aur time milta hai. Jab log likhna ho ya report generate karna ho toh timestamp ke liye use hota hai.

---

```cpp
using namespace std;
```
**Explanation:** Is line se humein baar baar `std::` likhne ki zaroorat nahi padti. `cout` likh sakte hain instead of `std::cout`. Yeh beginners ke liye asaan hai.

---

```cpp
#define MAX_PRODUCTS 100
```
**Explanation:** Yeh ek **constant** define kiya hai. `MAX_PRODUCTS` ki value 100 hai. Iska matlab hai ke hum zyada se zyada 100 products store kar sakte hain. Agar 100 products ho jayein toh system naya product add nahi karega.

---

```cpp
struct Product {
    int id;
    char name[50];
    char category[30];
    char supplier[50];
    int quantity;
    double purchasePrice;
    double sellingPrice;
};
```
**Explanation:** Yeh **Product structure** hai. Structure ek container hai jismein related data ek saath rakhte hain. Har product ke 7 fields hain:

| Field | Type | Matlab |
|-------|------|--------|
| `id` | `int` | Product ka unique number (jaise 1001, 1002). Do products ka ID same nahi ho sakta. |
| `name` | `char[50]` | Product ka naam. 50 characters tak likh sakte hain. Jaise "Dell Laptop". |
| `category` | `char[30]` | Product kis category mein hai. Jaise "Electronics", "Grocery". |
| `supplier` | `char[50]` | Supplier company ka naam. Jaise "TechWorld Pvt Ltd". |
| `quantity` | `int` | Kitne products stock mein hain. Jaise 25. |
| `purchasePrice` | `double` | Humne kis price par kharida. Decimal value ho sakti hai jaise 45000.50. |
| `sellingPrice` | `double` | Hum kis price par bechenge. Decimal value ho sakti hai. |

---

```cpp
struct Admin {
    char username[30];
    char password[30];
};
```
**Explanation:** Yeh **Admin structure** hai. Login system ke liye use hota hai. Username 30 characters tak aur password 30 characters tak ho sakta hai.

---

```cpp
extern Product products[MAX_PRODUCTS];
extern int productCount;
```
**Explanation:** `extern` ka matlab hai ke yeh variables **main.cpp** mein define hain, lekin agar koi aur file inhe use karna chahe toh access kar sakti hai.
- `products` ek **array** hai jo 100 products store karega
- `productCount` batata hai ke abhi kitne products add kiye gaye hain

---

```cpp
#endif
```
**Explanation:** Header guard ka end. `#ifndef PRODUCT_H` ke saath match karta hai.

---

## 2. utils.h - Helper Functions

Yeh file mein **utility functions** hain jo baar baar use hote hain.

```cpp
#ifndef UTILS_H
#define UTILS_H
```
**Explanation:** Header guard - same concept as product.h. Dobara include hone se bachata hai.

---

```cpp
inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
```
**Explanation:** Yeh function **screen clear** karta hai.
- `inline` keyword compiler ko batata hai ke function ki body jahan call hoti hai wahan directly paste kar do. Is se program fast hota hai chote functions ke liye.
- `#ifdef _WIN32` check karta hai ke kya yeh Windows hai? Agar haan toh `system("cls")` chalega (Windows command).
- Agar Linux/Mac hai toh `system("clear")` chalega.
- `void` ka matlab hai ke yeh function kuch return nahi karta.

---

```cpp
inline void pause() {
    cout << "\nPress Enter to continue...";
    cin.get();
}
```
**Explanation:** Yeh function **program ko rok deta hai** jab tak user Enter press na kare.
- `cout` se message print hota hai.
- `cin.get()` user ka Enter press wait karta hai. Jab Enter dabao toh program aage badhta hai.
- Har operation ke baad yeh use hota hai taake user result dekh sake.

---

```cpp
inline void printLine(int length = 50) {
    for (int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
}
```
**Explanation:** Yeh function ek **line print** karta hai `=` signs ki.
- `int length = 50` - Default value 50 hai. Matlab agar koi value na do toh 50 `=` signs print honge.
- `for loop` length baar `=` print karta hai.
- `endl` se nayi line par chala jata hai.
- Output: `==================================================`

---

```cpp
inline void printBorder() {
    cout << "\n";
    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}
```
**Explanation:** Yeh `printLine()` jaisa hai lekin `*` signs use karta hai. Decorative border ke liye.

---

```cpp
inline string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string dateTime = dt;
    dateTime = dateTime.substr(0, dateTime.length() - 1);
    return dateTime;
}
```
**Explanation:** Yeh function **current date aur time** return karta hai.
- `time_t now = time(0);` - Current time seconds mein leta hai (1 Jan 1970 se ab tak ke seconds).
- `char* dt = ctime(&now);` - Seconds ko readable date/time string mein convert karta hai. Jaise "Thu Jul 16 10:30:45 2026\n"
- `string dateTime = dt;` - char pointer ko C++ string mein convert karta hai.
- `dateTime.substr(0, dateTime.length() - 1);` - Aakhri character (newline `\n`) remove karta hai.
- `return dateTime;` - Final date/time string return karta hai.

---

## 3. main.cpp - Main Program File

Yeh humari sabse badi file hai jismein saara logic hai.

### 3.1 Includes aur Global Variables

```cpp
#include "product.h"
#include "utils.h"
#include <cstdio>
```
**Explanation:**
- `"product.h"` - Apni product structure wali file include ki. Double quotes isliye kyunki yeh apni file hai.
- `"utils.h"` - Helper functions wali file include ki.
- `<cstdio>` - C standard I/O library. `sprintf()` function ke liye zaroori hai jo hum log messages format karne mein use karte hain.

---

```cpp
Product products[MAX_PRODUCTS];
int productCount = 0;
Admin admin;
```
**Explanation:** Yeh **global variables** hain - poori file mein kahin bhi use ho sakte hain.
- `products[100]` - Ek array jo 100 products store karega. Shuru mein khaali hai.
- `productCount = 0` - Abhi 0 products hain. Jab product add hoga toh yeh barhega.
- `admin` - Admin ka data store karega (username aur password).

---

```cpp
const char* PRODUCTS_FILE = "data/products.dat";
const char* ADMIN_FILE = "data/admin.dat";
const char* LOGS_FILE = "data/logs.txt";
const char* REPORTS_FILE = "data/reports.txt";
const char* BACKUP_FILE = "data/backup.dat";
```
**Explanation:** Yeh **file paths** hain. `const char*` ka matlab hai ke yeh read-only strings hain jo change nahi hongi.
- `products.dat` - Saare products ka data binary format mein store hota hai.
- `admin.dat` - Admin login credentials binary format mein.
- `logs.txt` - Har activity ka record (text format mein).
- `reports.txt` - Generated reports save hoti hain.
- `backup.dat` - Products data ka backup copy.
- Sab files `data/` folder mein save hoti hain.

---

### 3.2 Function Declarations (Forward Declarations)

```cpp
void showMenu();
int getMenuChoice();
void addProduct();
void viewProducts();
void searchProduct();
// ... etc
```
**Explanation:** Yeh **forward declarations** hain. Compiler ko pehle se bata rahe hain ke yeh functions exist karte hain. Actual code neeche likha hai. Isse compiler ko koi confusion nahi hota jab main() se call hoti hain.

---

### 3.3 main() Function - Program ka Start Point

```cpp
int main() {
    clearScreen();
```
**Explanation:** `main()` function jahan se program **start** hota hai. Sabse pehle screen clear karte hain.

---

```cpp
    cout << "\n\n";
    printLine(50);
    cout << "   INVENTORY MANAGEMENT SYSTEM (IMS)" << endl;
    cout << "   Programming Fundamentals Project" << endl;
    printLine(50);
    cout << "\n   Welcome to IMS!" << endl;
    cout << "   This system helps you manage your products." << endl;
    cout << "\n   Starting the system..." << endl;
    pause();
```
**Explanation:** **Welcome screen** display karte hain.
- `printLine(50)` se `=` ki line draw hoti hai.
- IMS ka naam aur welcome message print hota hai.
- `pause()` se user ko time milta hai padhne ka. Jab Enter dabaye toh aage badhta hai.

---

```cpp
    loadData();
    createDefaultAdmin();
    loadAdmin();
```
**Explanation:** **Startup sequence** - teen zaroori kaam:
1. `loadData()` - Agar pehle se products.dat mein data hai toh load karo (program band hone ke baad bhi data rehta hai).
2. `createDefaultAdmin()` - Agar admin.dat file nahi hai toh default admin banao (admin/admin123).
3. `loadAdmin()` - Admin credentials file se load karo.

---

```cpp
    if (!login()) {
        cout << "\n   Login failed! Maximum attempts exceeded." << endl;
        cout << "   Exiting system..." << endl;
        pause();
        return 0;
    }
```
**Explanation:** **Login check**. `login()` function `true` return karta hai agar login successful ho, `false` agar fail ho.
- `!login()` ka matlab "agar login fail hai"
- Agar 3 baar galat password dala toh program exit ho jata hai.
- `return 0;` se program khatam ho jata hai.

---

```cpp
    int choice;
    do {
        showMenu();
        choice = getMenuChoice();
```
**Explanation:** **Main menu loop** - yeh do-while loop hai jo baar baar chalega jab tak user exit na kare.
- `showMenu()` - Menu screen dikhata hai.
- `getMenuChoice()` - User se number leta hai (1 se 12).

---

```cpp
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            // ... cases 3-11
            case 12: /* exit */ break;
            default: /* invalid */ break;
        }
    } while (choice != 12);
```
**Explanation:** **Switch statement** user ki choice ke hisaab se sahi function call karta hai.
- Agar user 1 dale toh `addProduct()` chalega.
- Agar 2 dale toh `viewProducts()` chalega.
- `break` zaroori hai warna neeche ke cases bhi chal jayenge (fall-through).
- `default` tab chalta hai jab user koi galat number dale.
- `while (choice != 12)` - Jab tak user 12 (Exit) na dale, loop chalta rahega.

---

### 3.4 login() Function - Authentication

```cpp
bool login() {
    int attempts = 3;
    char username[30], password[30];
```
**Explanation:**
- `bool` return type - ya toh `true` (success) ya `false` (fail) return karega.
- `attempts = 3` - User ko 3 mauke milenge sahi password dalne ke.
- `username` aur `password` arrays mein user ka input store hoga.

---

```cpp
    while (attempts > 0) {
```
**Explanation:** Jab tak attempts baaki hain (3, 2, 1), loop chalega.

---

```cpp
        cout << "   Username: ";
        cin.getline(username, 30);
        cout << "   Password: ";
        cin.getline(password, 30);
```
**Explanation:** User se username aur password input lete hain.
- `cin.getline()` use kiya hai instead of `cin >>` kyunki `getline` spaces bhi leta hai (jaise "Ahmad Mahmood").
- `30` maximum characters ki limit hai.

---

```cpp
        if (strcmp(username, admin.username) == 0 && strcmp(password, admin.password) == 0) {
```
**Explanation:** **String comparison** - check karte hain ke user ka input admin ke credentials se match karta hai ya nahi.
- `strcmp()` 0 return karta hai jab dono strings same hon.
- `&&` ka matlab "AUR" - dono conditions true honi chahiye (username sahi AUR password sahi).

---

```cpp
            string logMsg = "LOGIN SUCCESS - User: ";
            logMsg += admin.username;
            writeLog(logMsg.c_str());
```
**Explanation:** **Log entry** bana rahe hain.
- `logMsg` mein message banaya.
- `+=` se username add kiya message mein.
- `writeLog()` mein bhejne ke liye `c_str()` use kiya jo C++ string ko C-style string (char*) mein convert karta hai.

---

```cpp
            return true;
```
**Explanation:** Login successful! `true` return karo taake main() aage badh sake.

---

```cpp
        } else {
            cout << "\n   Invalid username or password!" << endl;
            attempts--;
            writeLog(logMsg.c_str());
            pause();
        }
```
**Explanation:** Agar password galat hai:
- Error message dikhao.
- `attempts--` se ek attempt kam ho gaya (3 → 2 → 1 → 0).
- Failed login ka log likho.
- Pause karo taake user error message parh sake.

---

```cpp
    writeLog("LOGIN BLOCKED - Maximum attempts exceeded");
    return false;
```
**Explanation:** Agar 3 attempts khatam ho gaye toh:
- Log mein likho ke login block hua.
- `false` return karo - program exit ho jayega.

---

### 3.5 createDefaultAdmin() - First Time Setup

```cpp
void createDefaultAdmin() {
    ifstream checkFile(ADMIN_FILE, ios::binary);
    if (checkFile.good()) {
        checkFile.close();
        return;
    }
    checkFile.close();
```
**Explanation:**
- `ifstream` se admin.dat file open karte hain read mode mein.
- `checkFile.good()` check karta hai ke file exist karti hai aur readable hai.
- Agar file already hai toh `return` kar jao - kuch karne ki zaroorat nahi.
- Agar file nahi hai (pehli baar program chal raha hai) toh aage badho.

---

```cpp
    strcpy(admin.username, "admin");
    strcpy(admin.password, "admin123");
    saveAdmin();
}
```
**Explanation:**
- `strcpy()` se "admin" username mein copy kiya aur "admin123" password mein.
- `saveAdmin()` se admin.dat file mein save kiya.

---

### 3.6 saveAdmin() aur loadAdmin()

```cpp
void saveAdmin() {
    ofstream file(ADMIN_FILE, ios::binary);
    if (file.is_open()) {
        file.write((char*)(&admin), sizeof(Admin));
        file.close();
    }
}
```
**Explanation:**
- `ofstream` - Output file stream (file mein likhne ke liye).
- `ios::binary` - Binary mode mein file kholti hai (faster, compact).
- `file.write()` - Admin struct ko memory se directly file mein likhta hai.
- `(char*)(&admin)` - Admin struct ka memory address leta hai aur char pointer mein cast karta hai. `write()` ko char* chahiye hota hai.
- `sizeof(Admin)` - Admin struct ka size bytes mein (30 + 30 = 60 bytes).

---

```cpp
void loadAdmin() {
    ifstream file(ADMIN_FILE, ios::binary);
    if (file.is_open()) {
        file.read((char*)(&admin), sizeof(Admin));
        file.close();
    }
}
```
**Explanation:**
- `ifstream` - Input file stream (file se parhne ke liye).
- `file.read()` - File se data parh kar admin struct mein daalta hai. Same casting technique as saveAdmin().

---

### 3.7 saveData() - Products Save to File

```cpp
void saveData() {
    ofstream file(PRODUCTS_FILE, ios::binary);
    if (file.is_open()) {
        file.write((char*)(&productCount), sizeof(int));
        file.write((char*)(products), sizeof(Product) * productCount);
        file.close();
    }
}
```
**Explanation:**
- Pehle `productCount` save karte hain (kitne products hain - yeh integer hai, 4 bytes).
- Phir `products` array save karte hain - sab products ek saath.
- `sizeof(Product) * productCount` - Ek product ka size × kitne products hain = total bytes.
- **PF Concept:** Binary file handling - data as-is memory se file mein jaata hai.

---

### 3.8 loadData() - Products Load from File

```cpp
void loadData() {
    ifstream file(PRODUCTS_FILE, ios::binary);
    if (file.is_open()) {
        file.read((char*)(&productCount), sizeof(int));
        if (productCount > 0 && productCount <= MAX_PRODUCTS) {
            file.read((char*)(products), sizeof(Product) * productCount);
        } else {
            productCount = 0;
        }
        file.close();
    } else {
        productCount = 0;
    }
}
```
**Explanation:**
- Pehle `productCount` parhte hain - kitne products the.
- Safety check: `productCount > 0 && productCount <= MAX_PRODUCTS` - agar valid number hai toh products array load karo.
- Agar file nahi hai (pehli baar) toh `productCount = 0` set karo.

---

### 3.9 writeLog() - Activity Logger

```cpp
void writeLog(const char* message) {
    ofstream file(LOGS_FILE, ios::app);
    if (file.is_open()) {
        file << "[" << getCurrentDateTime() << "] " << message << endl;
        file.close();
    }
}
```
**Explanation:**
- `ios::app` - **Append mode**. File ke end mein likhega, purana data delete nahi hoga.
- Har log entry ka format: `[Date Time] Message`
- Jaise: `[Thu Jul 16 10:30:45 2026] PRODUCT ADDED - ID: 1001, Name: Dell Laptop`

---

### 3.10 Helper Functions

```cpp
bool isDuplicateID(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return true;
        }
    }
    return false;
}
```
**Explanation:** **Linear Search** - check karta hai ke diya gaya ID pehle se exist karta hai ya nahi.
- Loop se har product ka ID check karte hain.
- Agar match mile toh `true` (duplicate hai).
- Agar loop khatam ho jaye aur match na mile toh `false` (unique hai).
- **PF Concept:** Linear Search Algorithm.

---

```cpp
int findProductIndex(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}
```
**Explanation:** Product ka **index** (position) dhundta hai array mein.
- Agar mil gaya toh uska index return karo (0, 1, 2, ...).
- Agar nahi mila toh `-1` return karo (kyunki valid index kabhi negative nahi hota).

---

### 3.11 addProduct() - CRUD: Create

```cpp
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "\n   ERROR: Product limit reached!";
        pause();
        return;
    }
```
**Explanation:** Pehle check karte hain ke 100 products ki limit toh nahi aa gayi. Agar haan toh error dikha ke wapas jao.

---

```cpp
    Product p;
    cout << "\n   Enter Product ID: ";
    cin >> p.id;
```
**Explanation:** Ek naya `Product` struct banaya `p` naam se. Phir user se ID input li.

---

```cpp
    if (isDuplicateID(p.id)) {
        cout << "\n   ERROR: Product ID already exists!";
        cin.clear();
        cin.ignore(10000, '\n');
        pause();
        return;
    }
```
**Explanation:** Check karo ke ID pehle se toh nahi hai.
- `cin.clear()` - Input errors clear karta hai.
- `cin.ignore(10000, '\n')` - Buffer mein jo extra characters hain unhe hata deta hai. Yeh important hai warna next input mein problems aati hain.

---

```cpp
    cin.ignore(10000, '\n');
    cout << "   Enter Product Name: ";
    cin.getline(p.name, 50);
```
**Explanation:** `cin >> p.id` ke baad buffer mein newline character reh jata hai. `cin.ignore()` se usko hataate hain taake `getline()` sahi se kaam kare.

---

```cpp
    cout << "   Enter Quantity: ";
    cin >> p.quantity;
    while (p.quantity < 0) {
        cout << "   Quantity cannot be negative. Enter again: ";
        cin >> p.quantity;
    }
```
**Explanation:** **Input Validation** - Quantity negative nahi ho sakti. Agar user negative number dale toh dobara poocho.
- **PF Concept:** Input Validation with while loop.

---

```cpp
    products[productCount] = p;
    productCount++;
    saveData();
```
**Explanation:** Naya product array mein add karo:
- `products[productCount]` mein naya product daala (jaise agar 5 products hain toh index 5 par jayega).
- `productCount++` se count barh gaya (5 → 6).
- `saveData()` se file mein save kiya taake program band hone ke baad bhi data rahe.

---

```cpp
    char logMsg[200];
    sprintf(logMsg, "PRODUCT ADDED - ID: %d, Name: %s", p.id, p.name);
    writeLog(logMsg);
```
**Explanation:** **Log entry** bana rahe hain:
- `sprintf()` - Formatted string banata hai (jaise `printf()` lekin screen ki jagah string mein).
- `%d` - Integer ke liye (ID).
- `%s` - String ke liye (Name).
- Result: "PRODUCT ADDED - ID: 1001, Name: Dell Laptop"

---

### 3.12 viewProducts() - CRUD: Read

```cpp
    cout << left;
    cout << "   " << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(10) << "Qty"
         << setw(12) << "Purch.Price"
         << setw(12) << "Sell.Price" << endl;
```
**Explanation:** **Table header** print karte hain:
- `cout << left` - Text left-aligned hogi.
- `setw(6)` - ID column ki width 6 characters hogi.
- `setw(20)` - Name column 20 characters.
- Isse table properly aligned dikhti hai.

---

```cpp
    for (int i = 0; i < productCount; i++) {
        cout << "   " << setw(6) << products[i].id
             << setw(20) << products[i].name
             // ... etc
    }
```
**Explanation:** **Loop** se har product print karte hain same format mein.

---

### 3.13 searchProduct() - Searching

```cpp
    int searchChoice;
    cout << "   Search by:" << endl;
    cout << "   1. Product ID" << endl;
    cout << "   2. Product Name" << endl;
    cin >> searchChoice;
```
**Explanation:** User ko **sub-menu** dikhate hain - ID se search karein ya naam se.

---

```cpp
        int index = findProductIndex(searchID);
        if (index != -1) {
            // display product
        } else {
            cout << "   Product not found!";
        }
```
**Explanation:** `findProductIndex()` call karte hain. Agar `-1` nahi aaya toh product mil gaya.

---

```cpp
        if (strstr(products[i].name, searchName) != NULL) {
```
**Explanation:** `strstr()` - String ke andar string dhundta hai.
- Agar "Laptop" search karo aur product ka naam "Dell Laptop" hai toh match milega.
- `NULL` return karta hai agar match na mile.
- **PF Concept:** Partial string matching.

---

### 3.14 updateProduct() - CRUD: Update

```cpp
    int field;
    cout << "   Which field do you want to update?" << endl;
    cout << "   1. Name" << endl;
    cout << "   2. Category" << endl;
    // ... etc
    cin >> field;
```
**Explanation:** User se poochte hain ke **kaunsa field** update karna hai (name, category, supplier, quantity, purchase price, ya selling price).

---

```cpp
    switch (field) {
        case 1:
            cin.getline(products[index].name, 50);
            break;
        // ... other cases
    }
    saveData();
```
**Explanation:** Selected field update karo aur file mein save karo.

---

### 3.15 deleteProduct() - CRUD: Delete

```cpp
    char confirm;
    cout << "   Are you sure? (y/n): ";
    cin >> confirm;
```
**Explanation:** **Confirmation** lete hain delete se pehle. User 'y' ya 'n' dabata hai.

---

```cpp
    if (confirm == 'y' || confirm == 'Y') {
        for (int i = index; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        productCount--;
    }
```
**Explanation:** **Array element delete** karna:
- Deleted product ke baad wale saare products ek position peeche shift karo.
- Jaise: `[A, B, C, D, E]` mein C delete karo → `[A, B, D, E]`
- Loop `index` se start karta hai aur `productCount - 1` tak chalta hai.
- `products[i] = products[i + 1]` - agla product current position par copy karo.
- `productCount--` - ek product kam ho gaya.
- **PF Concept:** Array element deletion with shifting.

---

### 3.16 stockIn() aur stockOut() - Stock Management

```cpp
    products[index].quantity += qty;
    saveData();
```
**Explanation (stockIn):** Product ki quantity mein `qty` add karo.
- `+=` ka matlab `products[index].quantity = products[index].quantity + qty`

---

```cpp
    if (qty > products[index].quantity) {
        cout << "   ERROR: Not enough stock!";
        return;
    }
    products[index].quantity -= qty;
```
**Explanation (stockOut):** Pehle check karo ke itna stock hai ya nahi.
- Agar 5 products hain aur user 10 nikalna chahe toh error dikhaao.
- `-=` ka matlab `products[index].quantity = products[index].quantity - qty`

---

### 3.17 generateReport() - Reports

```cpp
    int totalItems = 0;
    double totalValue = 0;
    for (int i = 0; i < productCount; i++) {
        totalItems += products[i].quantity;
        totalValue += products[i].quantity * products[i].sellingPrice;
    }
```
**Explanation:** **Full Inventory Report** ke liye calculations:
- `totalItems` - Saare products ki total quantity.
- `totalValue` - Har product ki (quantity × selling price) ka sum. Yeh total inventory ki value hai.

---

```cpp
    ofstream reportFile(REPORTS_FILE);
    reportFile << "==============================================\n";
    // ... report content
    reportFile.close();
```
**Explanation:** Report **file mein bhi save** hoti hai (reports.txt) taake baad mein dekh sakein.

---

### 3.18 sortProducts() - Bubble Sort

```cpp
    if (sortChoice == 1) {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (strcmp(products[j].name, products[j + 1].name) > 0) {
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
    }
```
**Explanation:** **Bubble Sort Algorithm** - yeh PF ka important concept hai.

**Kaise kaam karta hai:**
1. Do loops hain - outer (`i`) aur inner (`j`).
2. Inner loop mein **adjacent elements** (bagal bagal wale) compare karte hain.
3. Agar pehla element bada hai toh **swap** karo (jagah badlo).
4. Har outer loop iteration mein sabse bada element apni sahi jagah par chala jata hai (bubble up).

**Swap Process:**
```
temp = products[j];          // pehla element temp mein rako
products[j] = products[j+1]; // doosra pehle ki jagah
products[j+1] = temp;        // temp (pehla) doosre ki jagah
```

**Example:** Sort `[C, A, B]`
- Pass 1: Compare C>A → swap → `[A, C, B]`. Compare C>B → swap → `[A, B, C]`
- Result: `[A, B, C]` ✓

**strcmp() > 0:** Pehli string alphabetically badi hai doosri se (jaise "Dell" > "Apple").

---

### 3.19 lowStockAlert() - Alert System

```cpp
    for (int i = 0; i < productCount; i++) {
        if (products[i].quantity < 5) {
            alertCount++;
            if (products[i].quantity == 0) {
                cout << "   [OUT OF STOCK] ...";
            } else {
                cout << "   [LOW STOCK] ...";
            }
        }
    }
```
**Explanation:** Har product check karte hain:
- Agar quantity 0 hai → "OUT OF STOCK" dikhaao.
- Agar quantity 1-4 hai → "LOW STOCK" dikhaao.
- `alertCount` track karta hai kitne alerts hain.

---

### 3.20 backupData() - Data Backup

```cpp
    saveData();
    ifstream source(PRODUCTS_FILE, ios::binary);
    ofstream dest(BACKUP_FILE, ios::binary);
    dest << source.rdbuf();
```
**Explanation:**
- Pehle current data save karo (`saveData()`).
- `source` products.dat file kholti hai read ke liye.
- `dest` backup.dat file kholti hai write ke liye.
- `dest << source.rdbuf()` - Poori file ko ek hi line mein copy kar deta hai. Simple aur fast.

---

### 3.21 showMenu() aur getMenuChoice()

```cpp
void showMenu() {
    clearScreen();
    printLine(50);
    cout << "      INVENTORY MANAGEMENT SYSTEM" << endl;
    printLine(50);
    cout << "   1.  Add Product" << endl;
    // ... all options
}
```
**Explanation:** Menu screen clear karta hai, border draw karta hai, aur saare 12 options print karta hai.

---

```cpp
int getMenuChoice() {
    int choice;
    cin >> choice;
    cin.clear();
    cin.ignore(10000, '\n');
    return choice;
}
```
**Explanation:** User ki choice leta hai aur return karta hai.
- `cin.clear()` - Agar user ne letter daal diya number ki jagah toh error clear karo.
- `cin.ignore()` - Extra characters buffer se hataao.

---

## PF Concepts Summary

| Concept | Kahan Use Hua |
|---------|--------------|
| **Variables** | productCount, choice, id, qty, etc. |
| **Data Types** | int (ID, quantity), char[] (name), double (price) |
| **Arrays** | products[MAX_PRODUCTS] - 100 products store |
| **Structures** | Product struct, Admin struct |
| **Functions** | 20+ functions - modular code |
| **Loops** | for (arrays iterate), while (validation), do-while (menu) |
| **If-Else** | Conditions check, login validation |
| **Switch** | Menu choice handling |
| **File Handling** | Binary (products.dat, admin.dat), Text (logs.txt, reports.txt) |
| **Searching** | Linear search (findProductIndex, isDuplicateID) |
| **Sorting** | Bubble sort (sortProducts) |
| **Input Validation** | Negative numbers check, duplicate ID check |
| **String Operations** | strcmp, strcpy, strstr |
| **Header Files** | product.h, utils.h - code organization |
| **Global Variables** | products[], productCount |
| **Constants** | MAX_PRODUCTS, file paths |

---

**Code Explanation Complete!**
**Ab aap har line samajh sakte hain ke kyun likhi gayi hai!**
