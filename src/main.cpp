#include "product.h"
#include "utils.h"
#include <cstdio>

Product products[MAX_PRODUCTS];
int productCount = 0;
Admin admin;

const char* PRODUCTS_FILE = "data/products.dat";
const char* ADMIN_FILE = "data/admin.dat";
const char* LOGS_FILE = "data/logs.txt";
const char* REPORTS_FILE = "data/reports.txt";
const char* BACKUP_FILE = "data/backup.dat";

void showMenu();
int getMenuChoice();
void addProduct();
void viewProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void stockIn();
void stockOut();
void generateReport();
void sortProducts();
void lowStockAlert();
void backupData();

bool login();
void createDefaultAdmin();
void saveData();
void loadData();
void saveAdmin();
void loadAdmin();
void writeLog(const char* message);
bool isDuplicateID(int id);
int findProductIndex(int id);

int main() {
    clearScreen();

    cout << "\n\n";
    printLine(50);
    cout << "   INVENTORY MANAGEMENT SYSTEM (IMS)" << endl;
    cout << "   Programming Fundamentals Project" << endl;
    printLine(50);
    cout << "\n   Welcome to IMS!" << endl;
    cout << "   This system helps you manage your products." << endl;
    cout << "\n   Starting the system..." << endl;

    pause();

    loadData();
    createDefaultAdmin();
    loadAdmin();

    if (!login()) {
        cout << "\n   Login failed! Maximum attempts exceeded." << endl;
        cout << "   Exiting system..." << endl;
        pause();
        return 0;
    }

    int choice;

    do {
        showMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                stockIn();
                break;
            case 7:
                stockOut();
                break;
            case 8:
                generateReport();
                break;
            case 9:
                sortProducts();
                break;
            case 10:
                lowStockAlert();
                break;
            case 11:
                backupData();
                break;
            case 12:
                saveData();
                writeLog("LOGOUT - User exited the system");
                clearScreen();
                cout << "\n\n";
                printLine(50);
                cout << "   Thank you for using IMS!" << endl;
                cout << "   Goodbye!" << endl;
                printLine(50);
                cout << "\n\n";
                break;
            default:
                cout << "\n   Invalid choice! Please enter a number between 1 and 12." << endl;
                pause();
        }

    } while (choice != 12);

    return 0;
}

bool login() {
    int attempts = 3;
    char username[30], password[30];

    while (attempts > 0) {
        clearScreen();
        cout << "\n";
        printLine(50);
        cout << "          ADMIN LOGIN" << endl;
        printLine(50);
        cout << "\n";
        cout << "   Attempts Remaining: " << attempts << endl;
        cout << "\n";
        cout << "   Username: ";
        cin.getline(username, 30);
        cout << "   Password: ";
        cin.getline(password, 30);

        if (strcmp(username, admin.username) == 0 && strcmp(password, admin.password) == 0) {
            cout << "\n   Login Successful! Welcome, " << admin.username << "!" << endl;
            string logMsg = "LOGIN SUCCESS - User: ";
            logMsg += admin.username;
            writeLog(logMsg.c_str());
            pause();
            return true;
        } else {
            cout << "\n   Invalid username or password!" << endl;
            attempts--;
            string logMsg = "LOGIN FAILED - Attempted Username: ";
            logMsg += username;
            writeLog(logMsg.c_str());
            pause();
        }
    }

    writeLog("LOGIN BLOCKED - Maximum attempts exceeded");
    return false;
}

void createDefaultAdmin() {
    ifstream checkFile(ADMIN_FILE, ios::binary);
    if (checkFile.good()) {
        checkFile.close();
        return;
    }
    checkFile.close();

    strcpy(admin.username, "admin");
    strcpy(admin.password, "admin123");
    saveAdmin();
}

void saveAdmin() {
    ofstream file(ADMIN_FILE, ios::binary);
    if (file.is_open()) {
        file.write((char*)(&admin), sizeof(Admin));
        file.close();
    }
}

void loadAdmin() {
    ifstream file(ADMIN_FILE, ios::binary);
    if (file.is_open()) {
        file.read((char*)(&admin), sizeof(Admin));
        file.close();
    }
}

void saveData() {
    ofstream file(PRODUCTS_FILE, ios::binary);
    if (file.is_open()) {
        file.write((char*)(&productCount), sizeof(int));
        file.write((char*)(products), sizeof(Product) * productCount);
        file.close();
    } else {
        cout << "\n   ERROR: Could not save data to file!" << endl;
    }
}

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

void writeLog(const char* message) {
    ofstream file(LOGS_FILE, ios::app);
    if (file.is_open()) {
        file << "[" << getCurrentDateTime() << "] " << message << endl;
        file.close();
    }
}

bool isDuplicateID(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return true;
        }
    }
    return false;
}

int findProductIndex(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addProduct() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      ADD NEW PRODUCT" << endl;
    printLine(50);

    if (productCount >= MAX_PRODUCTS) {
        cout << "\n   ERROR: Product limit reached! Cannot add more products." << endl;
        pause();
        return;
    }

    Product p;

    cout << "\n   Enter Product ID: ";
    cin >> p.id;

    if (isDuplicateID(p.id)) {
        cout << "\n   ERROR: Product ID " << p.id << " already exists!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        pause();
        return;
    }

    cin.ignore(10000, '\n');

    cout << "   Enter Product Name: ";
    cin.getline(p.name, 50);

    cout << "   Enter Category (e.g., Electronics, Grocery): ";
    cin.getline(p.category, 30);

    cout << "   Enter Supplier Name: ";
    cin.getline(p.supplier, 50);

    cout << "   Enter Quantity: ";
    cin >> p.quantity;
    while (p.quantity < 0) {
        cout << "   Quantity cannot be negative. Enter again: ";
        cin >> p.quantity;
    }

    cout << "   Enter Purchase Price (Rs.): ";
    cin >> p.purchasePrice;
    while (p.purchasePrice < 0) {
        cout << "   Price cannot be negative. Enter again: ";
        cin >> p.purchasePrice;
    }

    cout << "   Enter Selling Price (Rs.): ";
    cin >> p.sellingPrice;
    while (p.sellingPrice < 0) {
        cout << "   Price cannot be negative. Enter again: ";
        cin >> p.sellingPrice;
    }

    cin.ignore(10000, '\n');

    products[productCount] = p;
    productCount++;

    saveData();

    char logMsg[200];
    sprintf(logMsg, "PRODUCT ADDED - ID: %d, Name: %s", p.id, p.name);
    writeLog(logMsg);

    cout << "\n   Product added successfully!" << endl;
    printLine(50);
    pause();
}

void viewProducts() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      VIEW ALL PRODUCTS" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory." << endl;
        pause();
        return;
    }

    cout << "\n";
    cout << left;
    cout << "   " << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(10) << "Qty"
         << setw(12) << "Purch.Price"
         << setw(12) << "Sell.Price" << endl;
    printLine(75);

    for (int i = 0; i < productCount; i++) {
        cout << "   " << setw(6) << products[i].id
             << setw(20) << products[i].name
             << setw(15) << products[i].category
             << setw(10) << products[i].quantity
             << "Rs." << setw(9) << products[i].purchasePrice
             << "Rs." << setw(9) << products[i].sellingPrice << endl;
    }

    printLine(75);
    cout << "   Total Products: " << productCount << endl;

    pause();
}

void searchProduct() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      SEARCH PRODUCT" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory to search." << endl;
        pause();
        return;
    }

    int searchChoice;
    cout << "\n   Search by:" << endl;
    cout << "   1. Product ID" << endl;
    cout << "   2. Product Name" << endl;
    cout << "   Enter choice: ";
    cin >> searchChoice;
    cin.ignore(10000, '\n');

    if (searchChoice == 1) {
        int searchID;
        cout << "\n   Enter Product ID to search: ";
        cin >> searchID;
        cin.ignore(10000, '\n');

        int index = findProductIndex(searchID);
        if (index != -1) {
            cout << "\n   Product Found!" << endl;
            printLine(40);
            cout << "   ID:            " << products[index].id << endl;
            cout << "   Name:          " << products[index].name << endl;
            cout << "   Category:      " << products[index].category << endl;
            cout << "   Supplier:      " << products[index].supplier << endl;
            cout << "   Quantity:      " << products[index].quantity << endl;
            cout << "   Purchase Price: Rs." << products[index].purchasePrice << endl;
            cout << "   Selling Price:  Rs." << products[index].sellingPrice << endl;
            printLine(40);
        } else {
            cout << "\n   Product with ID " << searchID << " not found!" << endl;
        }
    } else if (searchChoice == 2) {
        char searchName[50];
        cout << "\n   Enter Product Name to search: ";
        cin.getline(searchName, 50);

        bool found = false;
        for (int i = 0; i < productCount; i++) {
            if (strstr(products[i].name, searchName) != NULL) {
                if (!found) {
                    cout << "\n   Matching Products:" << endl;
                    printLine(75);
                    cout << left;
                    cout << "   " << setw(6) << "ID"
                         << setw(20) << "Name"
                         << setw(15) << "Category"
                         << setw(10) << "Qty"
                         << setw(12) << "Purch.Price"
                         << setw(12) << "Sell.Price" << endl;
                    printLine(75);
                    found = true;
                }
                cout << "   " << setw(6) << products[i].id
                     << setw(20) << products[i].name
                     << setw(15) << products[i].category
                     << setw(10) << products[i].quantity
                     << "Rs." << setw(9) << products[i].purchasePrice
                     << "Rs." << setw(9) << products[i].sellingPrice << endl;
            }
        }
        if (!found) {
            cout << "\n   No products found matching '" << searchName << "'!" << endl;
        } else {
            printLine(75);
        }
    } else {
        cout << "\n   Invalid search option!" << endl;
    }

    pause();
}

void updateProduct() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      UPDATE PRODUCT" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory to update." << endl;
        pause();
        return;
    }

    int updateID;
    cout << "\n   Enter Product ID to update: ";
    cin >> updateID;
    cin.ignore(10000, '\n');

    int index = findProductIndex(updateID);
    if (index == -1) {
        cout << "\n   Product with ID " << updateID << " not found!" << endl;
        pause();
        return;
    }

    cout << "\n   Current Product Details:" << endl;
    printLine(40);
    cout << "   ID:            " << products[index].id << endl;
    cout << "   Name:          " << products[index].name << endl;
    cout << "   Category:      " << products[index].category << endl;
    cout << "   Supplier:      " << products[index].supplier << endl;
    cout << "   Quantity:      " << products[index].quantity << endl;
    cout << "   Purchase Price: Rs." << products[index].purchasePrice << endl;
    cout << "   Selling Price:  Rs." << products[index].sellingPrice << endl;
    printLine(40);

    int field;
    cout << "\n   Which field do you want to update?" << endl;
    cout << "   1. Name" << endl;
    cout << "   2. Category" << endl;
    cout << "   3. Supplier" << endl;
    cout << "   4. Quantity" << endl;
    cout << "   5. Purchase Price" << endl;
    cout << "   6. Selling Price" << endl;
    cout << "   Enter choice: ";
    cin >> field;
    cin.ignore(10000, '\n');

    switch (field) {
        case 1:
            cout << "   Enter new Name: ";
            cin.getline(products[index].name, 50);
            break;
        case 2:
            cout << "   Enter new Category: ";
            cin.getline(products[index].category, 30);
            break;
        case 3:
            cout << "   Enter new Supplier: ";
            cin.getline(products[index].supplier, 50);
            break;
        case 4:
            cout << "   Enter new Quantity: ";
            cin >> products[index].quantity;
            cin.ignore(10000, '\n');
            break;
        case 5:
            cout << "   Enter new Purchase Price: ";
            cin >> products[index].purchasePrice;
            cin.ignore(10000, '\n');
            break;
        case 6:
            cout << "   Enter new Selling Price: ";
            cin >> products[index].sellingPrice;
            cin.ignore(10000, '\n');
            break;
        default:
            cout << "\n   Invalid choice! No changes made." << endl;
            pause();
            return;
    }

    saveData();

    char logMsg[200];
    sprintf(logMsg, "PRODUCT UPDATED - ID: %d, Field: %d", products[index].id, field);
    writeLog(logMsg);

    cout << "\n   Product updated successfully!" << endl;
    pause();
}

void deleteProduct() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      DELETE PRODUCT" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory to delete." << endl;
        pause();
        return;
    }

    int deleteID;
    cout << "\n   Enter Product ID to delete: ";
    cin >> deleteID;
    cin.ignore(10000, '\n');

    int index = findProductIndex(deleteID);
    if (index == -1) {
        cout << "\n   Product with ID " << deleteID << " not found!" << endl;
        pause();
        return;
    }

    cout << "\n   Product Details:" << endl;
    printLine(40);
    cout << "   ID:            " << products[index].id << endl;
    cout << "   Name:          " << products[index].name << endl;
    cout << "   Category:      " << products[index].category << endl;
    cout << "   Supplier:      " << products[index].supplier << endl;
    cout << "   Quantity:      " << products[index].quantity << endl;
    cout << "   Purchase Price: Rs." << products[index].purchasePrice << endl;
    cout << "   Selling Price:  Rs." << products[index].sellingPrice << endl;
    printLine(40);

    char confirm;
    cout << "\n   Are you sure you want to delete this product? (y/n): ";
    cin >> confirm;
    cin.ignore(10000, '\n');

    if (confirm == 'y' || confirm == 'Y') {
        char logMsg[200];
        sprintf(logMsg, "PRODUCT DELETED - ID: %d, Name: %s", products[index].id, products[index].name);

        for (int i = index; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        productCount--;

        saveData();
        writeLog(logMsg);

        cout << "\n   Product deleted successfully!" << endl;
    } else {
        cout << "\n   Deletion cancelled." << endl;
    }

    pause();
}

void stockIn() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      STOCK IN (Add Stock)" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory." << endl;
        pause();
        return;
    }

    int id, qty;
    cout << "\n   Enter Product ID: ";
    cin >> id;

    int index = findProductIndex(id);
    if (index == -1) {
        cout << "\n   Product with ID " << id << " not found!" << endl;
        cin.ignore(10000, '\n');
        pause();
        return;
    }

    cout << "   Current Stock of '" << products[index].name << "': " << products[index].quantity << endl;
    cout << "   Enter quantity to add: ";
    cin >> qty;
    cin.ignore(10000, '\n');

    while (qty <= 0) {
        cout << "   Quantity must be positive. Enter again: ";
        cin >> qty;
        cin.ignore(10000, '\n');
    }

    products[index].quantity += qty;
    saveData();

    char logMsg[200];
    sprintf(logMsg, "STOCK IN - ID: %d, Name: %s, Quantity Added: %d, New Stock: %d",
            products[index].id, products[index].name, qty, products[index].quantity);
    writeLog(logMsg);

    cout << "\n   Stock updated successfully!" << endl;
    cout << "   New Stock of '" << products[index].name << "': " << products[index].quantity << endl;
    pause();
}

void stockOut() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      STOCK OUT (Remove Stock)" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory." << endl;
        pause();
        return;
    }

    int id, qty;
    cout << "\n   Enter Product ID: ";
    cin >> id;

    int index = findProductIndex(id);
    if (index == -1) {
        cout << "\n   Product with ID " << id << " not found!" << endl;
        cin.ignore(10000, '\n');
        pause();
        return;
    }

    cout << "   Current Stock of '" << products[index].name << "': " << products[index].quantity << endl;
    cout << "   Enter quantity to remove: ";
    cin >> qty;
    cin.ignore(10000, '\n');

    while (qty <= 0) {
        cout << "   Quantity must be positive. Enter again: ";
        cin >> qty;
        cin.ignore(10000, '\n');
    }

    if (qty > products[index].quantity) {
        cout << "\n   ERROR: Not enough stock! Available: " << products[index].quantity << endl;
        pause();
        return;
    }

    products[index].quantity -= qty;
    saveData();

    char logMsg[200];
    sprintf(logMsg, "STOCK OUT - ID: %d, Name: %s, Quantity Removed: %d, Remaining: %d",
            products[index].id, products[index].name, qty, products[index].quantity);
    writeLog(logMsg);

    cout << "\n   Stock updated successfully!" << endl;
    cout << "   Remaining Stock of '" << products[index].name << "': " << products[index].quantity << endl;
    pause();
}

void generateReport() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      GENERATE REPORTS" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory to generate report." << endl;
        pause();
        return;
    }

    int reportType;
    cout << "\n   Select Report Type:" << endl;
    cout << "   1. Full Inventory Report" << endl;
    cout << "   2. Low Stock Report (Qty < 5)" << endl;
    cout << "   3. Out of Stock Report (Qty = 0)" << endl;
    cout << "   Enter choice: ";
    cin >> reportType;
    cin.ignore(10000, '\n');

    clearScreen();
    cout << "\n";
    printLine(50);

    ofstream reportFile(REPORTS_FILE);

    if (reportType == 1) {
        cout << "      FULL INVENTORY REPORT" << endl;
        printLine(50);

        int totalItems = 0;
        double totalValue = 0;

        for (int i = 0; i < productCount; i++) {
            totalItems += products[i].quantity;
            totalValue += products[i].quantity * products[i].sellingPrice;
        }

        cout << "\n   Date: " << getCurrentDateTime() << endl;
        cout << "   Total Products: " << productCount << endl;
        cout << "   Total Items in Stock: " << totalItems << endl;
        cout << "   Total Inventory Value: Rs." << totalValue << endl;

        if (reportFile.is_open()) {
            reportFile << "==============================================\n";
            reportFile << "        INVENTORY REPORT\n";
            reportFile << "        Generated: " << getCurrentDateTime() << "\n";
            reportFile << "==============================================\n\n";
            reportFile << "Total Products: " << productCount << "\n";
            reportFile << "Total Items in Stock: " << totalItems << "\n";
            reportFile << "Total Value: Rs." << totalValue << "\n\n";
            reportFile << "--- ALL PRODUCTS ---\n\n";

            for (int i = 0; i < productCount; i++) {
                reportFile << "ID: " << products[i].id
                           << " | " << products[i].name
                           << " | Category: " << products[i].category
                           << " | Qty: " << products[i].quantity
                           << " | Purchase: Rs." << products[i].purchasePrice
                           << " | Selling: Rs." << products[i].sellingPrice << "\n";
            }

            reportFile << "\n==============================================\n";
            reportFile << "         END OF REPORT\n";
            reportFile << "==============================================\n";
            reportFile.close();
        }

        cout << "\n   Products:" << endl;
        cout << left;
        cout << "   " << setw(6) << "ID"
             << setw(20) << "Name"
             << setw(15) << "Category"
             << setw(10) << "Qty"
             << setw(12) << "Purch.Price"
             << setw(12) << "Sell.Price" << endl;
        printLine(75);

        for (int i = 0; i < productCount; i++) {
            cout << "   " << setw(6) << products[i].id
                 << setw(20) << products[i].name
                 << setw(15) << products[i].category
                 << setw(10) << products[i].quantity
                 << "Rs." << setw(9) << products[i].purchasePrice
                 << "Rs." << setw(9) << products[i].sellingPrice << endl;
        }
        printLine(75);

    } else if (reportType == 2) {
        cout << "      LOW STOCK REPORT (Qty < 5)" << endl;
        printLine(50);
        cout << "\n   Date: " << getCurrentDateTime() << endl;

        int lowCount = 0;

        if (reportFile.is_open()) {
            reportFile << "==============================================\n";
            reportFile << "        LOW STOCK REPORT\n";
            reportFile << "        Generated: " << getCurrentDateTime() << "\n";
            reportFile << "==============================================\n\n";
        }

        for (int i = 0; i < productCount; i++) {
            if (products[i].quantity > 0 && products[i].quantity < 5) {
                cout << "   [!] ID: " << products[i].id
                     << " | " << products[i].name
                     << " | Qty: " << products[i].quantity << endl;
                if (reportFile.is_open()) {
                    reportFile << "ID: " << products[i].id
                               << " | " << products[i].name
                               << " | Qty: " << products[i].quantity << "\n";
                }
                lowCount++;
            }
        }

        if (lowCount == 0) {
            cout << "\n   No low stock items found." << endl;
        } else {
            cout << "\n   Total Low Stock Items: " << lowCount << endl;
        }

        if (reportFile.is_open()) {
            reportFile << "\nTotal Low Stock Items: " << lowCount << "\n";
            reportFile << "\n==============================================\n";
            reportFile << "         END OF REPORT\n";
            reportFile << "==============================================\n";
            reportFile.close();
        }

    } else if (reportType == 3) {
        cout << "      OUT OF STOCK REPORT (Qty = 0)" << endl;
        printLine(50);
        cout << "\n   Date: " << getCurrentDateTime() << endl;

        int outCount = 0;

        if (reportFile.is_open()) {
            reportFile << "==============================================\n";
            reportFile << "        OUT OF STOCK REPORT\n";
            reportFile << "        Generated: " << getCurrentDateTime() << "\n";
            reportFile << "==============================================\n\n";
        }

        for (int i = 0; i < productCount; i++) {
            if (products[i].quantity == 0) {
                cout << "   [X] ID: " << products[i].id
                     << " | " << products[i].name
                     << " | Qty: 0" << endl;
                if (reportFile.is_open()) {
                    reportFile << "ID: " << products[i].id
                               << " | " << products[i].name
                               << " | Qty: 0\n";
                }
                outCount++;
            }
        }

        if (outCount == 0) {
            cout << "\n   No out of stock items found." << endl;
        } else {
            cout << "\n   Total Out of Stock Items: " << outCount << endl;
        }

        if (reportFile.is_open()) {
            reportFile << "\nTotal Out of Stock Items: " << outCount << "\n";
            reportFile << "\n==============================================\n";
            reportFile << "         END OF REPORT\n";
            reportFile << "==============================================\n";
            reportFile.close();
        }

    } else {
        cout << "\n   Invalid report type!" << endl;
    }

    writeLog("REPORT GENERATED");
    cout << "\n   Report saved to " << REPORTS_FILE << endl;
    pause();
}

void sortProducts() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      SORT PRODUCTS" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory to sort." << endl;
        pause();
        return;
    }

    int sortChoice;
    cout << "\n   Sort by:" << endl;
    cout << "   1. Name (A-Z)" << endl;
    cout << "   2. Selling Price (Low to High)" << endl;
    cout << "   3. Quantity (Low to High)" << endl;
    cout << "   Enter choice: ";
    cin >> sortChoice;
    cin.ignore(10000, '\n');

    Product temp;

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
        cout << "\n   Products sorted by Name (A-Z)!" << endl;
        writeLog("PRODUCTS SORTED - By Name");

    } else if (sortChoice == 2) {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (products[j].sellingPrice > products[j + 1].sellingPrice) {
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
        cout << "\n   Products sorted by Selling Price (Low to High)!" << endl;
        writeLog("PRODUCTS SORTED - By Price");

    } else if (sortChoice == 3) {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (products[j].quantity > products[j + 1].quantity) {
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
        cout << "\n   Products sorted by Quantity (Low to High)!" << endl;
        writeLog("PRODUCTS SORTED - By Quantity");

    } else {
        cout << "\n   Invalid choice!" << endl;
        pause();
        return;
    }

    saveData();

    cout << "\n   Sorted Products:" << endl;
    cout << left;
    cout << "   " << setw(6) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(10) << "Qty"
         << setw(12) << "Purch.Price"
         << setw(12) << "Sell.Price" << endl;
    printLine(75);

    for (int i = 0; i < productCount; i++) {
        cout << "   " << setw(6) << products[i].id
             << setw(20) << products[i].name
             << setw(15) << products[i].category
             << setw(10) << products[i].quantity
             << "Rs." << setw(9) << products[i].purchasePrice
             << "Rs." << setw(9) << products[i].sellingPrice << endl;
    }
    printLine(75);

    pause();
}

void lowStockAlert() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      LOW STOCK ALERT" << endl;
    printLine(50);

    if (productCount == 0) {
        cout << "\n   No products in inventory." << endl;
        pause();
        return;
    }

    int alertCount = 0;

    cout << "\n   Products with LOW STOCK (Quantity < 5):" << endl;
    cout << "\n";

    for (int i = 0; i < productCount; i++) {
        if (products[i].quantity < 5) {
            alertCount++;
            if (products[i].quantity == 0) {
                cout << "   [OUT OF STOCK] ID: " << products[i].id
                     << " | " << products[i].name
                     << " | Qty: " << products[i].quantity << endl;
            } else {
                cout << "   [LOW STOCK]    ID: " << products[i].id
                     << " | " << products[i].name
                     << " | Qty: " << products[i].quantity << endl;
            }
        }
    }

    if (alertCount == 0) {
        cout << "   All products have sufficient stock!" << endl;
    } else {
        cout << "\n   Total Alerts: " << alertCount << " product(s) need attention." << endl;
    }

    pause();
}

void backupData() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      BACKUP DATA" << endl;
    printLine(50);

    saveData();

    ifstream source(PRODUCTS_FILE, ios::binary);
    if (!source.is_open()) {
        cout << "\n   ERROR: No data file found to backup!" << endl;
        pause();
        return;
    }

    ofstream dest(BACKUP_FILE, ios::binary);
    if (!dest.is_open()) {
        cout << "\n   ERROR: Could not create backup file!" << endl;
        source.close();
        pause();
        return;
    }

    dest << source.rdbuf();
    source.close();
    dest.close();

    writeLog("BACKUP CREATED");

    cout << "\n   Backup created successfully!" << endl;
    cout << "   Data backed up to: " << BACKUP_FILE << endl;
    cout << "   Backup Date: " << getCurrentDateTime() << endl;
    cout << "   Products Backed Up: " << productCount << endl;
    pause();
}

void showMenu() {
    clearScreen();

    cout << "\n";
    printLine(50);
    cout << "      INVENTORY MANAGEMENT SYSTEM" << endl;
    printLine(50);
    cout << "\n";
    cout << "   1.  Add Product" << endl;
    cout << "   2.  View Products" << endl;
    cout << "   3.  Search Product" << endl;
    cout << "   4.  Update Product" << endl;
    cout << "   5.  Delete Product" << endl;
    cout << "   6.  Stock In" << endl;
    cout << "   7.  Stock Out" << endl;
    cout << "   8.  Generate Reports" << endl;
    cout << "   9.  Sort Products" << endl;
    cout << "  10.  Low Stock Alert" << endl;
    cout << "  11.  Backup Data" << endl;
    cout << "  12.  Exit" << endl;
    cout << "\n";
    printLine(50);
}

int getMenuChoice() {
    int choice;
    cout << "   Enter your choice (1-12): ";
    cin >> choice;

    cin.clear();
    cin.ignore(10000, '\n');

    return choice;
}
