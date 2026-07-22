#include "product.h"
#include "utils.h"

Product products[MAX_PRODUCTS];
int productCount = 0;
Admin admin;

// File paths for data storage
const string PRODUCTS_FILE = "data/products.dat";
const string ADMIN_FILE = "data/admin.dat";
const string LOGS_FILE = "data/logs.txt";
const string REPORTS_FILE = "data/reports.txt";
const string BACKUP_FILE = "data/backup.dat";

// Function declarations
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
void writeLog(const string& message);
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

    // Load saved data and admin credentials from files
    loadData();
    createDefaultAdmin();
    loadAdmin();

    // Authenticate the admin user
    if (!login()) {
        cout << "\n   Login failed! Maximum attempts exceeded." << endl;
        cout << "   Exiting system..." << endl;
        pause();
        return 0;
    }

    int choice;

    // Main menu loop - keeps showing menu until user chooses exit (12)
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
                // Save data and exit
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

// Authenticates the admin with username and password (3 attempts)
bool login() {
    int attempts = 3;
    string username, password;

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
        getline(cin, username);
        cout << "   Password: ";
        getline(cin, password);

        // Compare entered credentials with stored admin data
        if (username == admin.username && password == admin.password) {
            cout << "\n   Login Successful! Welcome, " << admin.username << "!" << endl;
            writeLog("LOGIN SUCCESS - User: " + admin.username);
            pause();
            return true;
        } else {
            cout << "\n   Invalid username or password!" << endl;
            attempts--;
            writeLog("LOGIN FAILED - Attempted Username: " + username);
            pause();
        }
    }

    writeLog("LOGIN BLOCKED - Maximum attempts exceeded");
    return false;
}

// Creates a default admin account if no admin file exists
void createDefaultAdmin() {
    ifstream checkFile(ADMIN_FILE);
    if (checkFile.good()) {
        checkFile.close();
        return; // Admin file already exists
    }
    checkFile.close();

    // Set default credentials
    admin.username = "admin";
    admin.password = "admin123";
    saveAdmin();
}

// Saves admin credentials to file (text format)
void saveAdmin() {
    ofstream file(ADMIN_FILE);
    if (file.is_open()) {
        file << admin.username << endl;
        file << admin.password << endl;
        file.close();
    }
}

// Loads admin credentials from file
void loadAdmin() {
    ifstream file(ADMIN_FILE);
    if (file.is_open()) {
        getline(file, admin.username);
        getline(file, admin.password);
        file.close();
    }
}

// Saves all product data to file (text format, one field per line)
void saveData() {
    ofstream file(PRODUCTS_FILE);
    if (file.is_open()) {
        // First line: total number of products
        file << productCount << endl;
        for (int i = 0; i < productCount; i++) {
            file << products[i].id << endl;
            file << products[i].name << endl;
            file << products[i].category << endl;
            file << products[i].supplier << endl;
            file << products[i].quantity << endl;
            file << products[i].purchasePrice << endl;
            file << products[i].sellingPrice << endl;
        }
        file.close();
    } else {
        cout << "\n   ERROR: Could not save data to file!" << endl;
    }
}

// Loads all product data from file
void loadData() {
    ifstream file(PRODUCTS_FILE);
    if (file.is_open()) {
        file >> productCount;
        // Only read products if the count is valid
        if (productCount > 0 && productCount <= MAX_PRODUCTS) {
            for (int i = 0; i < productCount; i++) {
                file >> products[i].id;
                file.ignore(); // skip the newline after id
                getline(file, products[i].name);
                getline(file, products[i].category);
                getline(file, products[i].supplier);
                file >> products[i].quantity;
                file >> products[i].purchasePrice;
                file >> products[i].sellingPrice;
                file.ignore(); // skip the newline after selling price
            }
        } else {
            productCount = 0;
        }
        file.close();
    } else {
        productCount = 0;
    }
}

// Writes a log entry with timestamp to the log file
void writeLog(const string& message) {
    ofstream file(LOGS_FILE, ios::app);
    if (file.is_open()) {
        file << "[" << getCurrentDateTime() << "] " << message << endl;
        file.close();
    }
}

// Checks if a product with the given ID already exists
bool isDuplicateID(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return true;
        }
    }
    return false;
}

// Finds the index of a product by its ID, returns -1 if not found
int findProductIndex(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Adds a new product to the inventory
void addProduct() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      ADD NEW PRODUCT" << endl;
    printLine(50);

    // Check if we have space for more products
    if (productCount >= MAX_PRODUCTS) {
        cout << "\n   ERROR: Product limit reached! Cannot add more products." << endl;
        pause();
        return;
    }

    Product p;

    cout << "\n   Enter Product ID: ";
    cin >> p.id;

    // Check if a product with this ID already exists
    if (isDuplicateID(p.id)) {
        cout << "\n   ERROR: Product ID " << p.id << " already exists!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        pause();
        return;
    }

    cin.ignore(10000, '\n'); // Clear the newline after reading id

    cout << "   Enter Product Name: ";
    getline(cin, p.name);

    cout << "   Enter Category (e.g., Electronics, Grocery): ";
    getline(cin, p.category);

    cout << "   Enter Supplier Name: ";
    getline(cin, p.supplier);

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

    // Add product to array and increment count
    products[productCount] = p;
    productCount++;

    saveData();

    writeLog("PRODUCT ADDED - ID: " + to_string(p.id) + ", Name: " + p.name);

    cout << "\n   Product added successfully!" << endl;
    printLine(50);
    pause();
}

// Displays all products in a table format
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

// Searches for a product by ID or name
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

    // Search by product ID
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

    // Search by product name (partial match)
    } else if (searchChoice == 2) {
        string searchName;
        cout << "\n   Enter Product Name to search: ";
        getline(cin, searchName);

        bool found = false;
        for (int i = 0; i < productCount; i++) {
            // Check if search term appears anywhere in the product name
            if (products[i].name.find(searchName) != string::npos) {
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

// Updates a specific field of an existing product
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

    // Display current product details
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

    // Update the chosen field
    switch (field) {
        case 1:
            cout << "   Enter new Name: ";
            getline(cin, products[index].name);
            break;
        case 2:
            cout << "   Enter new Category: ";
            getline(cin, products[index].category);
            break;
        case 3:
            cout << "   Enter new Supplier: ";
            getline(cin, products[index].supplier);
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

    writeLog("PRODUCT UPDATED - ID: " + to_string(products[index].id) +
        ", Field: " + to_string(field));

    cout << "\n   Product updated successfully!" << endl;
    pause();
}

// Deletes a product from the inventory
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

    // Show product details before deletion
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
        string logMsg = "PRODUCT DELETED - ID: " + to_string(products[index].id) +
            ", Name: " + products[index].name;

        // Shift all products after index one position left
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

// Adds stock (increases quantity) for a product
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

    writeLog("STOCK IN - ID: " + to_string(products[index].id) +
        ", Name: " + products[index].name +
        ", Quantity Added: " + to_string(qty) +
        ", New Stock: " + to_string(products[index].quantity));

    cout << "\n   Stock updated successfully!" << endl;
    cout << "   New Stock of '" << products[index].name << "': " << products[index].quantity << endl;
    pause();
}

// Removes stock (decreases quantity) for a product
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

    // Check if there is enough stock to remove
    if (qty > products[index].quantity) {
        cout << "\n   ERROR: Not enough stock! Available: " << products[index].quantity << endl;
        pause();
        return;
    }

    products[index].quantity -= qty;
    saveData();

    writeLog("STOCK OUT - ID: " + to_string(products[index].id) +
        ", Name: " + products[index].name +
        ", Quantity Removed: " + to_string(qty) +
        ", Remaining: " + to_string(products[index].quantity));

    cout << "\n   Stock updated successfully!" << endl;
    cout << "   Remaining Stock of '" << products[index].name << "': " << products[index].quantity << endl;
    pause();
}

// Generates and displays different types of reports (also saves to file)
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

    // Full Inventory Report
    if (reportType == 1) {
        cout << "      FULL INVENTORY REPORT" << endl;
        printLine(50);

        int totalItems = 0;
        double totalValue = 0;

        // Calculate totals
        for (int i = 0; i < productCount; i++) {
            totalItems += products[i].quantity;
            totalValue += products[i].quantity * products[i].sellingPrice;
        }

        cout << "\n   Date: " << getCurrentDateTime() << endl;
        cout << "   Total Products: " << productCount << endl;
        cout << "   Total Items in Stock: " << totalItems << endl;
        cout << "   Total Inventory Value: Rs." << totalValue << endl;

        // Write report to file
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

        // Display all products on screen
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

    // Low Stock Report (quantity between 1 and 4)
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

    // Out of Stock Report (quantity = 0)
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

// Sorts the products array using bubble sort
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

    // Bubble sort implementation
    if (sortChoice == 1) {
        // Sort by name using string comparison
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (products[j].name > products[j + 1].name) {
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
        cout << "\n   Products sorted by Name (A-Z)!" << endl;
        writeLog("PRODUCTS SORTED - By Name");

    } else if (sortChoice == 2) {
        // Sort by selling price (low to high)
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
        // Sort by quantity (low to high)
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

    // Display sorted products
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

// Shows products with low stock (quantity less than 5)
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

// Creates a backup copy of the products data file
void backupData() {
    clearScreen();
    cout << "\n";
    printLine(50);
    cout << "      BACKUP DATA" << endl;
    printLine(50);

    // Save current data first
    saveData();

    ifstream source(PRODUCTS_FILE);
    if (!source.is_open()) {
        cout << "\n   ERROR: No data file found to backup!" << endl;
        pause();
        return;
    }

    ofstream dest(BACKUP_FILE);
    if (!dest.is_open()) {
        cout << "\n   ERROR: Could not create backup file!" << endl;
        source.close();
        pause();
        return;
    }

    // Copy file contents line by line
    string line;
    while (getline(source, line)) {
        dest << line << endl;
    }

    source.close();
    dest.close();

    writeLog("BACKUP CREATED");

    cout << "\n   Backup created successfully!" << endl;
    cout << "   Data backed up to: " << BACKUP_FILE << endl;
    cout << "   Backup Date: " << getCurrentDateTime() << endl;
    cout << "   Products Backed Up: " << productCount << endl;
    pause();
}

// Displays the main menu options
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

// Gets and returns the user's menu choice
int getMenuChoice() {
    int choice;
    cout << "   Enter your choice (1-12): ";
    cin >> choice;

    cin.clear();
    cin.ignore(10000, '\n');

    return choice;
}
