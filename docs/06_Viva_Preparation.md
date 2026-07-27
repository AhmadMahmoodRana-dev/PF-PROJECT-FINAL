# VIVA PREPARATION GUIDE
## Inventory Management System (IMS)
### Programming Fundamentals Project - Roman Urdu

---

## Section A: Code aur Concepts ke Sawaal

---

### Q1: Aapne parallel arrays kyun use ki? Struct kyun nahi?

**Answer:** Humne parallel arrays use ki kyunki yeh zyada basic concept hai. PF mein humne arrays, loops, conditions padhe hain. Parallel arrays mein har field ki apni alag array hoti hai - jaise `ids[]`, `names[]`, `quantities[]`. Sab mil kar ek index par ek product banate hain.

Struct bhi use kar sakte the lekin parallel arrays se har cheez alag alag dikhti hai aur basics clear hoti hain.

---

### Q2: `const int MAX_PRODUCTS = 100` ka kya matlab hai?

**Answer:** `const` ka matlab hai ke yeh value change nahi ho sakti - yeh ek constant hai. `MAX_PRODUCTS` ki value 100 hai. Iska matlab hai ke hum zyada se zyada 100 products store kar sakte hain. Agar 100 ho jayein toh system error dega "Product limit reached".

**Follow-up:** `#define` se kya farq hai?
- `const int` C++ ka proper constant hai (type-safe)
- `#define` preprocessor macro hai (sirf text replace hota hai)
- `const int` zyada safe aur standard hai

---

### Q3: `do-while` loop kyun use kiya `while` ki jagah main menu mein?

**Answer:** `do-while` loop kam az kam EK BAAR zaroor chalta hai. Menu dikhane ke liye yeh zaroori hai ke pehle menu dikhe, phir user input le, phir check kare. `while` loop pehle condition check karta hai - agar pehli baar mein hi condition false ho toh kabhi chale hi nahi.

```
do {                while (condition) {
    showMenu();         showMenu();
    getInput();         getInput();
} while (cond);     }
```
`do-while` = pehle kaam, phir check
`while` = pehle check, phir kaam

---

### Q4: Switch statement kahan use kiya aur kyun?

**Answer:** Switch statement 2 jagah use kiya:

1. **Main menu mein** (main.cpp) - User 1-12 mein se number deta hai, uske hisaab se sahi function call hota hai. Switch `if-else if-else` chain se zyada clean hai jab ek hi variable ke different values check karne hon.

2. **Update product mein** - User field number deta hai (1-6), uske hisaab se sahi array update hoti hai.

**Break kyun zaroori hai?**
Agar `break` na likho toh "fall-through" hoga - matlab case 1 ke baad case 2, case 3 bhi chal jayenge. Yeh bug hai.

---

### Q5: Bubble sort kaise kaam karta hai? Step by step samjhao.

**Answer:** Bubble sort mein:

1. Do nested loops hain - outer (`i`) aur inner (`j`)
2. Inner loop mein bagal-bagal wale elements (adjacent) compare hoti hain
3. Agar pehla bada hai → swap (jagah badlo)
4. Har outer loop pass mein sabse bada element "bubble up" ho kar sahi jagah aa jata hai

**Example: [C, A, D, B] sort by name:**

Pass 1:
- C > A → swap → [A, C, D, B]
- C > D → no swap → [A, C, D, B]
- D > B → swap → [A, C, B, D]  ← D sahi jagah aa gaya

Pass 2:
- A > C → no swap → [A, C, B, D]
- C > B → swap → [A, B, C, D]  ← C sahi jagah

Pass 3:
- A > B → no swap → [A, B, C, D]  ← DONE!

**Time Complexity:** O(n²) - kyunki 2 nested loops hain
**Space Complexity:** O(1) - extra memory nahi chahiye (in-place sort)

---

### Q6: Linear search kya hai? Binary search se kya farq hai?

**Answer:**

**Linear Search:**
- Pehle element se last tak ek ek karke check karo
- Agar match mile → return index
- Agar match na mile → return -1
- **Unsorted** data par bhi kaam karta hai
- Time: O(n)

**Binary Search:**
- **Sirf sorted** data par kaam karta hai
- Beech ka element check karo, aadha data eliminate karo
- Time: O(log n) - bohat fast

Humne linear search use ki kyunki humara data sorted nahi hai (jab sort karte hain tab sorted hota hai).

---

### Q7: `cin.ignore(10000, '\n')` kyun use kiya?

**Answer:** Jab `cin >>` se number parhte hain, toh user ne Enter dabaya tha. Yeh newline character `\n` input buffer mein reh jata hai. Agar uske baad `getline()` use karein toh wo khali string le leta hai (kyunki buffer mein already `\n` hai).

`cin.ignore(10000, '\n')` buffer mein se 10000 characters tak ya `\n` tak sab skip kar deta hai. Yeh zaroori hai taake agla `getline()` sahi kaam kare.

---

### Q8: `cin.clear()` ka kya kaam hai?

**Answer:** Agar user number ki jagah letter daal de (jaise "abc" jab int chahiye tha), toh `cin` fail state mein chala jata hai. Uske baad koi input kaam nahi karta. `cin.clear()` is error state ko reset karta hai taake dobara input le sakein.

---

### Q9: `string::find()` aur `string::npos` kya hain?

**Answer:**
- `string::find(text)` - Ek string ke andar doosri string dhundta hai
- Agar mil jaye → uski position return karta hai (0, 1, 2...)
- Agar na mile → `string::npos` return karta hai (npos = not found = bahut bada number)

```cpp
string name = "Dell Laptop";
name.find("Laptop")  // returns 5 (position)
name.find("Mouse")   // returns string::npos (not found)
```

Yeh **partial matching** hai - "Lap" search karo toh "Laptop" mein mil jayega.

---

### Q10: `ofstream` aur `ifstream` mein kya farq hai?

**Answer:**
- `ofstream` = Output File Stream = file mein **likhne** ke liye (write)
- `ifstream` = Input File Stream = file se **parhne** ke liye (read)
- `fstream` = dono kaam kar sakta hai (read + write)

Humne `<<` operator se likha (ofstream) aur `>>` ya `getline()` se parha (ifstream).

---

### Q11: `ios::app` ka kya matlab hai?

**Answer:** `ios::app` = Append Mode. Jab file kholti hai toh purana data delete NAHI hota. Nayi data file ke END mein judti hai. Hum logs.txt mein yeh use karte hain taake purani log entries delete na hon.

Agar `ios::app` na likho toh file overwrite ho jayegi (purana sab data khatam).

---

### Q12: `getline(cin, variable)` aur `cin >> variable` mein kya farq hai?

**Answer:**

| Feature | `cin >>` | `getline()` |
|---------|----------|-------------|
| Spaces leta hai? | Nahi (space par ruk jata hai) | Haan (poori line) |
| Newline skip? | Haan | Nahi |
| Use kab? | Numbers, single words | Sentences, names with spaces |

Example: Agar user "Dell Laptop" likhe:
- `cin >>` sirf "Dell" lega
- `getline()` poora "Dell Laptop" lega

---

### Q13: `to_string()` ka kya use hai?

**Answer:** `to_string()` number ko string mein convert karta hai.

```cpp
int id = 101;
string s = to_string(id);  // s = "101"
```

Hum log messages banane mein use karte hain:
```cpp
"PRODUCT ADDED - ID: " + to_string(101) + ", Name: Dell"
```
Bina `to_string()` ke integer ko string ke saath `+` nahi kar sakte.

---

### Q14: Global variables kyun use kiye? Nuksan kya hai?

**Answer:** Humne arrays (`ids[]`, `names[]`, etc.) aur `productCount` ko global rakha hai taake har function mein pass karne ki zaroorat na ho. 20+ functions hain - agar har function mein arrays pass karte toh code bohat complex ho jata.

**Nuksan (Disadvantages):**
- Koi bhi function global variable ko change kar sakta hai (unintended bugs)
- Debugging mushkil hoti hai
- Real projects mein globals avoid kiye jate hain

---

### Q15: Function declaration aur definition mein kya farq hai?

**Answer:**

**Declaration** (sirf naam aur type):
```cpp
void addProduct();
```
Compiler ko batata hai ke yeh function exist karta hai.

**Definition** (pura code):
```cpp
void addProduct() {
    // ... actual code
}
```
Function ka actual logic yahan hota hai.

Humne declarations upar likhe hain taake `main()` mein kisi bhi function ko call kar sakein, chahe definition neeche ho.

---

## Section B: Project Related Sawaal

---

### Q16: IMS kya hai? Real life mein kahan use hota hai?

**Answer:** IMS = Inventory Management System. Yeh businesses ko apna stock (samaan) manage karne mein madad karta hai.

**Real life examples:**
- Dukaan ka stock management (kirana store)
- Warehouse inventory
- Pharmacy stock
- Electronics shop
- Library books management

Pehle register mein likhte the, ab computer se fast aur accurate hota hai.

---

### Q17: Database kyun nahi use kiya?

**Answer:** Hum PF (Programming Fundamentals) ke student hain. Abhi humne file handling seekhi hai, database nahi. Database (jaise MySQL, SQLite) advance topics hain jo OOP ya Database course mein parhate hain. Humari file-based storage (text files) PF level ke liye kaafi hai.

---

### Q18: Data permanently kaise save hota hai?

**Answer:** Hum **text files** mein data save karte hain:
- `saveData()` - products.dat mein saare products likhta hai
- `loadData()` - Program start pe products.dat se data wapas parhta hai
- Jab program band hota hai toh data file mein rehta hai
- Jab dobara start hota hai toh `loadData()` se wapas aa jata hai

Yeh **data persistence** kehlata hai.

---

### Q19: Login system mein security issues kya hain?

**Answer:**
1. **Plain text password** - admin.dat mein password asaan text mein hai, koi encryption nahi
2. **Default credentials** - admin/admin123 bohat common hai
3. **No lockout** - 3 baar fail ke baad sirf exit hota hai, permanent lock nahi

**Real system mein kya hoga:**
- Password hashing (encrypted)
- Account lockout
- Password complexity rules
- Two-factor authentication

---

### Q20: Agar 100 se zyada products hon to kya hoga?

**Answer:** System error dikhayega: "ERROR: Product limit reached! Cannot add more products." Aur naya product add nahi hoga.

**Solution real project mein:** Dynamic arrays (vectors) use karte jismein size barh sakti hai. Lekin vectors advance topic hain.

---

### Q21: Backup ka kya faida hai?

**Answer:** Agar products.dat file corrupt ho jaye ya galti se delete ho jaye, toh backup.dat se data wapas mil sakta hai. Backup ek safety copy hai. Real businesses mein backup daily hota hai.

---

### Q22: Low stock alert threshold kya hai?

**Answer:** Quantity < 5. Agar kisi product ki quantity 5 se kam hai toh system alert deta hai:
- Quantity 0 → [OUT OF STOCK]
- Quantity 1-4 → [LOW STOCK]

Yeh business ko batata hai ke abhi stock order karo warna khatam ho jayega.

---

## Section C: Tricky / Trap Sawaal

---

### Q23: `return 0` ka matlab kya hai main() mein?

**Answer:** `return 0` ka matlab hai program **successfully** khatam hua. 0 = success. Agar koi error ho toh non-zero value (1, -1) return karte hain. Operating system ko pata chalta hai ke program theek se chala ya nahi.

---

### Q24: `endl` aur `\n` mein kya farq hai?

**Answer:**
- `endl` - Nayi line + **buffer flush** (data turant screen/file par jata hai)
- `\n` - Sirf nayi line (faster, buffer flush nahi)

Chote programs mein farq nahi padta. Bade programs mein `\n` zyada fast hai.

---

### Q25: Array ki size 100 hai lekin sirf 5 products hain. Baaki 95 jagah ka kya hota hai?

**Answer:** Baaki 95 positions mein **garbage values** hoti hain (kuch bhi random data). Lekin hum sirf `0` se `productCount-1` tak access karte hain, toh garbage values ka asar nahi hota. `productCount` humein batata hai ke kitne valid products hain.

---

### Q26: `products[i] = products[i+1]` struct mein kaise kaam karta hai?

**Answer:** Humne struct use NAHI ki, parallel arrays use ki hain. Lekin agar struct hota toh C++ mein struct ka pura assignment ho jata - saare fields ek saath copy ho jate. Parallel arrays mein humein 7 arrays alag alag shift karni padti hain:
```cpp
ids[i] = ids[i+1];
names[i] = names[i+1];
// ... 5 aur
```

---

### Q27: Bubble sort ki worst case, best case, aur average case complexity?

**Answer:**
- **Worst case:** O(n²) - reverse sorted array
- **Average case:** O(n²)
- **Best case:** O(n) - already sorted (agar optimization karo - flag se check karo ke koi swap hua ya nahi)

Humara code mein optimization nahi hai, toh best case bhi O(n²) hai.

---

### Q28: Agar user delete kare aur confirm mein 'n' dabaye to kya hota hai?

**Answer:** Deletion cancel ho jati hai. `if (confirm == 'y' || confirm == 'Y')` false hota hai toh else block chalta hai: "Deletion cancelled." Product wahi rehta hai jahan tha.

---

### Q29: String concatenation (`+`) kaise kaam karta hai?

**Answer:** `+` operator 2 strings jodta hai:
```cpp
string a = "Hello";
string b = " World";
string c = a + b;  // c = "Hello World"
```

Lekin `+` string + int nahi kar sakta. Isliye `to_string()` use karte hain:
```cpp
"ID: " + to_string(101)  // "ID: 101"
```

---

### Q30: Program crash kab ho sakta hai?

**Answer:**
1. **Array out of bounds** - Agar `ids[150]` access karein jab size 100 hai
2. **File not found** - Agar data/ folder na ho aur file open na ho
3. **Division by zero** - (humare code mein nahi hai)
4. **Invalid input** - Agar `cin >>` fail ho jaye (humne `cin.clear()` se handle kiya)

Humne zyada tar cases handle kiye hain (bounds check, file check, input validation).

---

## Section D: Code Walkthrough Questions

### Q31: Ek product add karne ka complete flow samjhao.

**Answer:**
1. `addProduct()` call hota hai
2. Check: productCount < 100?
3. User se ID input lo
4. `isDuplicateID()` check karo → already hai toh error
5. User se Name, Category, Supplier, Quantity, Prices lo
6. Input validation (negative numbers reject)
7. Arrays mein store karo (`ids[pos]`, `names[pos]`, etc.)
8. `productCount++`
9. `saveData()` → file mein save
10. `writeLog()` → log entry
11. Success message

---

### Q32: Product delete karne ka flow samjhao.

**Answer:**
1. `deleteProduct()` call hota hai
2. User se ID lo
3. `findProductIndex()` se index dhundho
4. Product details dikhao
5. Confirmation lo (y/n)
6. Agar 'y' → Shifting:
   - `for (int i = index; i < productCount - 1; i++)`
   - Har array mein: `array[i] = array[i+1]`
7. `productCount--`
8. `saveData()` + `writeLog()`

---

### Q33: Sorting mein parallel arrays kaise swap hoti hain?

**Answer:** Jab do products swap karte hain toh 7 arrays ke 7 elements swap hote hain:
```
temp1 = ids[j];          ids[j] = ids[j+1];          ids[j+1] = temp1;
temp2 = names[j];        names[j] = names[j+1];      names[j+1] = temp2;
temp3 = categories[j];   categories[j] = categories[j+1]; categories[j+1] = temp3;
... (suppliers, quantities, purchasePrices, sellingPrices)
```
Agar ek bhi array miss ho toh product ka data corrupt ho jayega (ID kisi aur product ki, naam kisi aur ka).

---

## Section E: Extra Tips for Viva

### Yaad Rakhne Wali Cheezein:

1. **Bubble sort** = adjacent compare + swap, O(n²)
2. **Linear search** = one by one check, O(n)
3. **do-while** = kam az kam ek baar chalta hai
4. **switch** = ek variable ke multiple values
5. **ofstream** = write, **ifstream** = read
6. **ios::app** = append mode (purana data safe)
7. **cin.ignore()** = buffer clean karo
8. **cin.clear()** = error state reset karo
9. **const** = value change nahi ho sakti
10. **string::npos** = "not found"

### Common Mistakes Jo Teacher Poch Sakte Hain:

- "Agar `break` bhool jao switch mein to kya hoga?" → Fall-through
- "Agar `cin.ignore()` na likho to kya hoga?" → getline() khali string lega
- "Global variable ka nuksan?" → Koi bhi function change kar sakta hai
- "Bubble sort slow kyun hai?" → O(n²) - do nested loops

---

**Viva Preparation Complete!**
**In sawaalon ki taiyari karo, teacher kuch bhi pooch sakte hain!**
