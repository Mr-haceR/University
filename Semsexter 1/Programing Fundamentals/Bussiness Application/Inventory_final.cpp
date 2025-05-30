#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

// Globol data structures START

const int TOTAL_USERS = 10;
string usernames[TOTAL_USERS];
string passwords[TOTAL_USERS];
int uniqueID[TOTAL_USERS];
string roles[TOTAL_USERS];
int userCount = 0;

const int TOTAL_PRODUCTS = 10;
string productNames[TOTAL_PRODUCTS];
float productPrices[TOTAL_PRODUCTS];
int productStocks[TOTAL_PRODUCTS];
string productUnits[TOTAL_PRODUCTS];
int productID[TOTAL_PRODUCTS];
int productCount = 0;

string loggedInAs;
int currentUserID;
string adminPassWord = "admin123";
string choice;

// Globol data structures END

// Function prototypes START
string getField(string record, int field);
void loadUsers();
void saveUsers();
void loadProducts();
void saveProducts();
void loadData();
void saveData();
void printHeader();
string deleteUser(string username, string password, int id);
string deleteProduct(string name, int id);
string landingPage();
void showAllHistory();
void adminMenu();
void clearScreen();
string login(string username, string password, int id);
void addUser(string username, string password, int id, string role);
string signUp();
void addProduct(string name, float price, string unit, int stock);
void listProducts();
void viewProductDetails();
void updateProductDetails();
void customerMenu();
void listAllProductsWithDetails();
void sortProducts(int sortType); // 1 for cheapest to most expensive, 2 for most expensive to cheapest
void placeOrder();
void addToHistory(string username, int userID, float total);
void showMyHistory(string username, int userID);
bool createFilesIfNotExist();

// Function prototypes END

// main STRAT

int main() {
    if (!createFilesIfNotExist()) return 1;
    loadData();
    system("color 07");
    while (true) {
        choice = landingPage();
        if (choice == "1") {
            if (userCount == 0) {
                cout << endl << "There are no users in the system yet. Press any key to continue...";
                getch();
                continue;
            }
            string username, password; 
            int id;
            clearScreen();
            printHeader();
            cout << "Login >" << endl << 
                    "------------------------" << endl << endl;
            cout << "You can enter 'q' or 'Q' to go back." << endl;
            usernamee:
            cout << "Enter username: ";
            cin.ignore();
            getline(cin, username);
            if (username == "") {
                cout << endl << "You didn't input anything.";
                goto usernamee;
            }
            if (username == "q" || username == "Q") continue;
            pass:
            cout << "Enter password: ";
            getline(cin, password);
            if (password == "") {
                cout << endl << "You didn't input anything.";
                goto pass;
            }
            if (password == "q" || password == "Q") continue;
            cout << "Enter the unique id assigned to you at sign up: ";
            cin >> id;
            string w = login(username, password, id);
            while (true) {    
                if (w == "ADMIN") {
                    system("color 02");
                    loggedInAs = username;
                    currentUserID = id;
                    adminMenu();
                }
                else if (w == "CUSTOMER") {
                    system("color 03");
                    loggedInAs = username;
                    currentUserID = id;
                    customerMenu();
                }
                else if (w == "WRONG") {
                    cout << endl << "Wrong credentials. Press any key to try again...";
                    getch();
                }
                break;
            }
            system("color 07");
        } 
        else if (choice == "2") {
            if (userCount == TOTAL_USERS) {
                cout << endl << "User limit reached. Press any key to go back...";
                getch();
                continue;
            }
            while (true) {
                choice = signUp();
                clearScreen();
                printHeader();
                if (choice == "1") {
                    cout << "Sign Up > Admin" << endl << 
                            "------------------------" << endl << endl;
                    cout << "You can enter 'q' or 'Q' to go back." << endl;
                    cout << "Enter the Admin PassWord to sign in as admin: ";
                    cin.ignore();
                    string adminPass;
                    getline(cin, adminPass);
                    if (adminPass == "q" || adminPass == "Q") break;
                    if (adminPass == adminPassWord) {
                        string username, password;
                        naam:
                        cout << "Enter username: ";
                        getline(cin, username);
                        if (username == "") {
                            cout << endl << "You didn't input anything.\n";
                            goto naam;
                        }
                        if (username == "q" || username == "Q") break;
                        paas:
                        cout << "Enter password: ";
                        getline(cin, password);
                        if (password == "") {
                            cout << endl << "You didn't input anything.\n";
                            goto paas;
                        }
                        if (password == "q" || password == "Q") break;
                        addUser(username, password, userCount, "ADMIN");
                    }
                    else {
                        cout << endl << "Invalid Admin Password! Press any key to go back...";
                        getch();
                        continue;
                    }
                }
                else if (choice == "2") {
                    cout << "Sign Up > Customer" << endl << 
                            "------------------------" << endl << endl;
                    cout << "You can enter 'q' or 'Q' to go back." << endl;
                    string username, password;
                    cin.ignore();
                    x:
                    cout << "Enter username: ";
                    getline(cin, username);
                    if (username == "") {
                        cout << endl << "You didn't input anything.\n";
                        goto x;
                    }
                    if (username == "q" || username == "Q") break;
                    cout << "Enter password: ";
                    y:
                    getline(cin, password);
                    if (password == "") {
                        cout << endl << "You didn't input anything.\n2";
                        goto y;
                    }
                    if (password == "q" || password == "Q") break;
                    addUser(username, password, userCount, "CUSTOMER");
                }
                else if (choice == "3") {
                    break;
                }
                else {
                    cout << endl << "Invalid choice. Press any key to try again...";
                    getch();
                    continue;
                }
                break;
            }
            continue;
        } 
        else if (choice == "3") {
            if (userCount == 0) {
                cout << endl << "There are no users in the system yet. Press any key to continue...";
                getch();
                continue;
            }
            string username, password, id;
            clearScreen();
            printHeader();
            cout << "Delete Account >" << endl << 
                    "------------------------" << endl << endl;
            cout << "You can enter 'q' or 'Q' to go back." << endl;
            cout << "Enter username: ";
            cin.ignore();
            getline(cin, username);
            if (username == "q" || username == "Q") continue;
            cout << "Enter password: ";
            getline(cin, password);
            if (password == "q" || password == "Q") continue;
            cout << "Enter the unique id assigned to you at sign up: ";
            getline(cin, id);
            if (id == "q" || id == "Q") continue;
            string w = ""; 
            if (username != "" && password != "" && id != "") w = deleteUser(username, password, stoi(id));
            if (w == "DONE") {
                cout << endl << "Account Deleted: " << username << ". Press any key to continue...";
                getch();
            }
            else if (w == "FAILED") {
                cout << "Wrong Credentials. Press any key to continue...";
                getch();
            }
            else if (w == "") {
                cout << "You didn't enter something or everything. Press any key to continue...";
                getch();
            }

        }
        else if (choice == "4") {
            break;
        } 
        else {
            cout << "Invalid choice. Press any key to try again...";
            getch();
        }
    }
    system("color 07");
    clearScreen();
    saveData();
}

// main END

// Function definitions START

bool createFilesIfNotExist() {
    fstream file, file1, file2;
    file.open("users.txt", ios::in);
    file1.open("products.txt", ios::in);
    file2.open("history.txt", ios::in);
    if (!file.is_open()) {
        file.open("users.txt", ios::out);
        if (file.is_open()) {
            file << '0';
            file.close();
        }
        else {
            cout << "Failed to create users.txt";
            return false;
        }
    }
    if (!file1.is_open()) {
        file1.open("products.txt", ios::out);
        if (file1.is_open()) {
            file1 << '0';
            file1.close();
        }
        else {
            cout << "Failed to create products.txt";
            return false;
        }
    }
    if (!file2.is_open()) {
        file2.open("history.txt", ios::out);
        if (file2.is_open()) {
            file2.close();
        }
        else {
            cout << "Failed to create history.txt";
            return false;
        }
    }
    file.close();
    file1.close();
    file2.close();
    return true;
}

void printHeader() {
    cout << endl << "*******************************************************************************************" << endl <<
                    "*                        Smart Inventory & Order Management System                        *" << endl <<
                    "*******************************************************************************************" << endl << endl;
}

string landingPage() {
    clearScreen();
    printHeader();
    cout << "1. Login" << endl <<
            "2. Sign Up" << endl <<
            "3. Delete Account." << endl <<
            "4. Exit" << endl << endl <<
            "Enter your choice: ";
    cin >> choice;
    return choice;
}

void clearScreen() {
    system("cls");
}

string login(string username, string password, int id) {
    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username && passwords[i] == password && uniqueID[i] == id) {
            return roles[i];
        }
    }
    return "WRONG";
}

string signUp() {
    clearScreen();
    printHeader();
    cout << "Sign Up Menu >" << endl << 
            "--------------------------" << endl << endl <<
            "1. As an admin." << endl <<
            "2. As a customer." << endl << 
            "3. Go back" << endl << endl<<
            "Enter your choice: ";
    cin >> choice;
    return choice;
}

string deleteUser(string username, string password, int id) {
    int index = -1;
    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username && passwords[i] == password && uniqueID[i] == id) {
            index = i;
        }
    }
    if (index == -1) return "FAILED";
    for (int j = index; j < userCount-1; j++) {
        usernames[j] = usernames[j + 1];
        passwords[j] = passwords[j + 1];
        roles[j] = roles[j + 1];
        uniqueID[j] = uniqueID[j + 1];
    }
    userCount--;
    return "DONE";
}

void addUser(string username, string password, int id, string role) {
    usernames[userCount] = username;
    passwords[userCount] = password;
    uniqueID[userCount] = id; 
    roles[userCount] = role;
    cout << endl << role << " Added: " << username << "." << endl << "Your unique id is " << userCount << ". Press any key to continue...";
    getch();
    userCount++;
}

void adminMenu() {
    while (true) {
        clearScreen();
        printHeader();
        cout << "Admin Menu >" << endl << 
                "------------------------------------" << endl << endl <<
                "1. Add products." << endl << 
                "2. List All products." << endl << 
                "3. Check product details." << endl << 
                "4. Update product details." << endl <<
                "5. Delete Product." << endl <<
                "6. Orders History" << endl <<
                "7. Logout." << endl << endl <<
                "Enter your choice: ";
        cin >> choice;
        if (choice == "1") {
            clearScreen();
            printHeader();
            string name, unit, price, stock;
            cout << "Admin Menu > Add products" << endl;
            cout << "------------------------------------" << endl << endl;
            cout << "You can enter 'q' or 'Q' to go back to previous menu any time." << endl << endl;
             cin.ignore();
            // Product Name
            Name:
            cout << "Enter product name: ";
            getline(cin, name);
            if (name == "") {
                cout << endl << "You didn't input anything." << endl;
                goto Name;
            }
            if (name == "q" || name == "Q") return;

            // Product Price
            Price:
            cout << "Enter the price of 1 unit of " << name << ": $";
            getline(cin, price);
            if (price == "q" || price == "Q") return;
            if (price == "") {
                cout << endl << "You didn't input anything." << endl;
                goto Price;
            }
            for (int i = 0; price[i] != '\0'; i++) {
                if (!isdigit(price[i])) {
                    cout << endl << "Invalid Input. Try again." << endl;
                    goto Price;
                }
            }
            
            // Product Unit
            Unit:
            cout << "Enter the unit for " << name << ": ";
            getline(cin, unit);
            if (unit == "q" || unit == "Q") return;
            if (unit == "") {
                cout << endl << "You didn't input anything." << endl;
                goto Unit;
            }

            // Product Stock
            Stock:
            cout << "Enter number of " << unit << "s of " << name << " in stock: ";
            getline(cin, stock);
            if (stock == "q" || stock == "Q") return;
            if (stock == "") {
                cout << endl << "You didn't input anything." << endl;
                goto Stock;
            }
            for (int i = 0; stock[i] != '\0'; i++) {
                if (!isdigit(stock[i])) {
                    cout << endl << "Invalid Input. Try again." << endl;
                    goto Stock;
                }
            }
            addProduct(name, stof(price), unit, stoi(stock));
        }
        else if (choice == "2") {
            listProducts();
        }
        else if (choice == "3") {
            viewProductDetails();
        }
        else if (choice == "4") {
            updateProductDetails();
        }
        else if (choice == "5") {
            if (productCount == 0) {
                cout << endl << "There are no users in the system yet. Press any key to continue...";
                getch();
                continue;
            }
            string name, id;
            clearScreen();
            printHeader();
            cout << "Delete Product >" << endl << 
                    "------------------------" << endl << endl;
            cout << "You can enter 'q' or 'Q' any time to go back." << endl;
            for (int i = 0; i < productCount; i++) {
                cout << i + 1 << ". Name: " << productNames[i] << ", Product ID: " << productID[i] << endl; 
            }
            cin.ignore();
            a:
            cout << "Enter Product Name: ";
            getline(cin, name);
            if (name == "") {
                cout << endl << "You didn't input anything." << endl;
                goto a;
            }
            if (name == "q" || name == "Q") return;

            b:
            cout << "Enter Product ID: ";
            getline(cin, id);
            if (id == "") {
                cout << endl << "You didn't input anything." << endl;
                goto b;
            }
            if (name == "q" || name == "Q") return;

            string w = deleteProduct(name, stoi(id));
            if (w == "DONE") {
                cout << endl << "Product Deleted: " << name << ". Press any key to continue...";
                getch();
            }
            else if (w == "FAILED") {
                cout << "Wrong Information. Press any key to continue...";
                getch();
            }
        }
        else if (choice == "6") {
            showAllHistory();
            cout << endl << endl << "Press any key to continue...";
            getch();
        }
        else if (choice == "7") {
            break;
        }
        else {
            cout << endl << "Invalid choice. Press any key to try again...";
            getch();
        }
    }
}

void showAllHistory() {
    int n = 0;
    fstream file;
    file.open("history.txt", ios::in);
    string name, id, total;
    int i = 1;
    cout << endl << "All Order History: " << endl;
    string empty;
    getline(file, empty);
    string record;
    while (!file.eof()) {
        getline(file, record);
        name = getField(record, 1);
        id = getField(record, 2);
        total = getField(record, 3);
        cout << i << ". Customer: " << name << ", User ID: " << id << ": Total was $" << total << endl;
        i++;
    }
    if (i == 1) {
        cout << endl << "No orders yet." << endl;
    }
}

void addToHistory(string username, int userID, float total) {
    fstream file;
    file.open("history.txt", ios::app);
    file << "\n" << username << "," << userID << "," << total;
}

string deleteProduct(string name, int id) {
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (productNames[i] == name && productID[i] == id) {
            index = i;
        }
    }
    if (index == -1) return "FAILED";
    for (int j = index; j < productCount-1; j++) {
        productNames[j] = productNames[j + 1];
        productPrices[j] = productPrices[j + 1];
        productStocks[j] = productStocks[j + 1];
        productID[j] = productID[j + 1];
        productUnits[j] = productUnits[j + 1];
    }
    productCount--;
    return "DONE";
}

void addProduct(string name, float price, string unit, int stock) {
    if (productCount < TOTAL_PRODUCTS) {
        productNames[productCount] = name;
        productPrices[productCount] = price;
        productUnits[productCount] = unit;
        productStocks[productCount] = stock;
        productID[productCount] = productCount;
        cout << endl << "Product Added: " << productNames[productCount] << endl;
        
        cout << "The Unique Product ID is " << productID[productCount] << endl;
        productCount++;
        cout << endl << "Press any key to continue...";
        getch();
    } 
    else {
        cout << endl << "Product limit reached (" << TOTAL_PRODUCTS << "). Press any key to continue..." << endl;
        getch();
    }
}

void listProducts() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > List All products" << endl;
    cout << "------------------------------------" << endl << endl;

    if (productCount == 0) {
        cout << "No products added yet. " << endl;
    } 
    else {
        cout << "Product List: " << endl;
        for (int i = 0; i < productCount; i++) {
            cout << i + 1 << ". " << productNames[i] << endl;
        }
    }
    cout << endl << "Press any key to continue...";
    getch();
}

void viewProductDetails() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > Check product details" << endl;
    cout << "------------------------------------" << endl << endl;

    if (productCount == 0) {
        cout << "No products added yet. " << endl;
        return;
    }
    cout << "Product List: " << endl;
    int last;
    for (int i = 0; i < productCount; i++) {
        cout << i + 1 << ". " << productNames[i] << endl;
        last = i+2;
    }
    cout << last << ". Go back" << endl;
    cout << endl << "Enter the number of the product to view details: ";
    string productNumber;
    cin.ignore();
    getline(cin, productNumber);
    int productNumberInt = stoi(productNumber);
    if (productNumber == to_string(last)) return;
    if (productNumberInt >= 1) {
        if (productNumberInt <= productCount) {
            int index = productNumberInt - 1;
            cout << endl << "Product details for " << productNames[index] << ":" << endl;
            cout << "Name: " << productNames[index] << endl;
            cout << "Price: $" << productPrices[index] << endl;
            cout << "Stock: " << productStocks[index] << " " << productUnits[index] << "(s)" << endl;
            cout << "Product ID: " << productID[index] << endl;
        }
    } 
    else {
        cout << endl << "Invalid product number. " << endl;
    }
    cout << endl << "Press any key to continue...";
    getch();
}

void updateProductDetails() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > Update product details" << endl <<
             "------------------------------------" << endl << endl;
    if (productCount == 0) {
        cout << "No products added yet." << endl;
        return;
    }
    int last;
    cout << "Product List: " << endl;
    for (int i = 0; i < productCount; i++) {
        cout << i + 1 << ". " << productNames[i] << endl;
        last = i + 2;
    }
    cout << last << ". Go back." << endl;
    cout << endl << "Enter the number of the product to view details: ";
    string productNumber;
    cin.ignore();
    getline(cin, productNumber);
    int productNumberInt = stoi(productNumber);
    if (productNumber == to_string(last)) return;
    if (productNumberInt >= 1) {
        if (productNumberInt <= productCount) {
            int index = productNumberInt - 1;
            string price, stock, unit;
            cout << endl << "You can enter 'q' or 'Q' any time to go back." << endl << endl;
            c:
            cout << "Enter new price: $";
            cin.ignore();
            getline(cin, price);
            if (price == "q" || price == "Q") return;
            if (price == "") {
                cout << endl << "You didn't input anything." << endl;
                goto c;
            }
            for (int i = 0; price[i] != '\0'; i++) {
                if (!isdigit(price[i])) {
                    cout << endl << "Invalid Input. Try again." << endl;
                    goto c;
                }
            }
            d:
            cout << "Enter new stock number: ";
            getline(cin, stock);
            if (stock == "q" || stock == "Q") return;
            if (stock == "") {
                cout << endl << "You didn't input anything." << endl;
                goto d;
            }
            for (int i = 0; stock[i] != '\0'; i++) {
                if (!isdigit(stock[i])) {
                    cout << endl << "Invalid Input. Try again." << endl;
                    goto d;
                }
            }
            e:
            cout << "Enter new unit for " << productNames[index] << ": ";
            getline(cin, unit);
            if (unit == "q" || unit == "Q") return;
            if (unit == "") {
                cout << endl << "You didn't input anything." << endl;
                goto e;
            }

            productPrices[index] = stof(price);
            productStocks[index] = stoi(stock);
            productUnits[index] = unit;
            cout << "Product details updated for " << productNames[index] << endl;
        }
    } 
    else {
        cout << endl << "Invalid product number. " << endl;
    }
    cout << endl << "Press any key to continue...";
    getch();
}

void customerMenu() {
    while (true) {
        clearScreen();
        printHeader();
        cout << "Customer Menu >" << endl <<
                "------------------------------------" << endl <<
                "1. List All products along with the details." << endl <<
                "2. Sort all products from cheapest to most expensive." << endl <<
                "3. Sort all products from most expensive to cheapest." << endl <<
                "4. Place an order." << endl <<
                "5. Your Order History" << endl <<
                "6. Sign Out." << endl << endl <<
                "Enter your choice: ";
        cin >> choice;
        if (choice == "1") {
            listAllProductsWithDetails();
        }
        else if (choice == "2") {
            sortProducts(1);
        }
        else if (choice == "3") {
            sortProducts(2);
        }
        else if (choice == "4") {
            placeOrder();
        }
        else if (choice == "5") {
            showMyHistory(loggedInAs, currentUserID);
        }
        else if (choice == "6") {
            break;
        }
        else {
            cout << endl << "Invalid choice. Press any key to try again...";
            getch();
            continue;
        }
        cout << endl << "Press any key to continue...";
        getch();
    }
}

void showMyHistory(string username, int userID) {
    fstream file;
    file.open("history.txt", ios::in);
    string name;
    int id, i = 1;
    float total;
    cout << endl << "Your Order History: " << endl;
    string empty;
    getline(file, empty);
    string record;
    while(!file.eof()) {
        getline(file, record);
        name = getField(record, 1);
        id = stoi(getField(record, 2));
        total = stof(getField(record, 3));
        if (name == username && id == userID) {
            cout << endl << "Order " << i << ". Your total was $" << total;
            i++;
        }
    }
    file.close();
}

void listAllProductsWithDetails() {
    clearScreen();
    printHeader();
    cout << "Customer Menu > List All products with details" << endl;
    cout << "----------------------------------------------" << endl << endl;
    if (productCount == 0) {
        cout << "No products available." << endl;
    } 
    else {
        cout << "Available Products:" << endl;
        for (int i = 0; i < productCount; i++) {
            cout << i + 1 << ".\nName: " << productNames[i] << 
                             "\nPrice: $" << productPrices[i] << 
                             "\nStock: " << productStocks[i] << " " << productUnits[i] << "s" << 
                             "\nProduct ID: " << productID[i] << endl << endl;
        }
    }
}

void sortProducts(int sortType) {
    clearScreen();
    printHeader();
    cout << "Customer Menu > Sort products" << endl;
    cout << "------------------------------------" << endl << endl;

    if (productCount == 0) {
        cout << "No products available to sort." << endl;
        return;
    }
    // Using copy of the original array for sorting purpose.
    string tempNames[TOTAL_PRODUCTS];
    float tempPrices[TOTAL_PRODUCTS];
    int tempStocks[TOTAL_PRODUCTS];
    for (int i = 0; i < productCount; i++) {
        tempNames[i] = productNames[i];
        tempPrices[i] = productPrices[i];
        tempStocks[i] = productStocks[i];
    }
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = 0; j < productCount - i - 1; j++) {
            if ((sortType == 1 && tempPrices[j] > tempPrices[j + 1]) || (sortType == 2 && tempPrices[j] < tempPrices[j + 1])) {
                // Swaping values
                string tempName = tempNames[j];
                tempNames[j] = tempNames[j + 1];
                tempNames[j + 1] = tempName;
                float tempPrice = tempPrices[j];
                tempPrices[j] = tempPrices[j + 1];
                tempPrices[j + 1] = tempPrice;
                int tempStock = tempStocks[j];
                tempStocks[j] = tempStocks[j + 1];
                tempStocks[j + 1] = tempStock;
            }
        }
    }
    if (sortType == 1) cout << "Products sorted from cheapest to most expensive:" << endl;
    else if (sortType == 2) cout << "Products sorted from most expensive to cheapest:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << i + 1 << ". " << tempNames[i] << " - $" << tempPrices[i] << endl;
    }
}

void placeOrder() {
    clearScreen();
    printHeader();
    cout << "Customer Menu > Place an order" << endl;
    cout << "------------------------------------" << endl << endl;
    if (productCount == 0) {
        cout << "No products available to order." << endl;
        return;
    }
    float total_price = 0.0;
    while (true) {
        cout << endl << "Available Products:" << endl;
        for (int i = 0; i < productCount; i++) {
            cout << i + 1 << ". " << productNames[i] << " - $" << productPrices[i] << " (Stock: " << productStocks[i] << ")" << endl;
        }
        cout << productCount + 1 << ". Checkout" << endl << endl;
        cout << "Enter the number of the product to order (or " << productCount + 1 << " to checkout): ";

        cin >> choice;
        int orderChoiceInt = stoi(choice);

        if (orderChoiceInt >= 1) {
            cin.ignore();
            int index = orderChoiceInt - 1;
            if (orderChoiceInt <= productCount) {
                cout << endl << "You can enter 'q' or 'Q' to cancel this particular order. It won't checkout." << endl;
                f:
                cout << "Enter the number of " << productUnits[index] << "s of " << productNames[index] << " you want to buy: ";
                string quantityStr;
                
                getline(cin, quantityStr);
                if (quantityStr == "") {
                    cout << endl << "You didn't input anything" << endl;
                    goto f;
                }
                if (quantityStr == "q" || quantityStr == "Q") continue;
                for (int i = 0; quantityStr[i] != '\0'; i++) {
                    if (!isdigit(quantityStr[i])) {
                        cout << endl << "Invalid Input. Try again." << endl;
                        goto f;
                    }
                }
                int quantity = stoi(quantityStr);
                cout << endl;
                if (quantity > 0) {
                    if (quantity <= productStocks[index]) {
                        total_price += quantity * productPrices[index];
                        productStocks[index] -= quantity;
                        cout << quantity << productUnits[index] <<  "s of " << productNames[index] << " added to your order." << endl;
                    } 
                    else {
                        cout << "Insufficient stock for " << productNames[index] << "." << endl;
                    }
                } 
                else {
                    cout << endl << "Invalid quantity." << endl;
                }
            } 
            else if (orderChoiceInt == productCount + 1) {
                cout << endl << "Your total order price is: $" << total_price << endl;
                addToHistory(loggedInAs, currentUserID, total_price);
                break;
            } 
            else {
                cout << "Invalid choice. Press any key to continue..." << endl;
                getch();
            }
        }
    }
}

string getField(string record, int field) {
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++) {
        if (record[x] == ',') {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field) {
            item = item + record[x];
        }
    }
    return item;
}

void loadUsers() {
    fstream file;
    file.open("users.txt", ios::in);
    string userCountL;
    getline(file, userCountL);
    userCount = stoi(userCountL);
    string empty;
    getline(file, empty);
    string record;
    for (int i = 0; i < userCount; i++) {
        getline(file, record);
        usernames[i] = getField(record, 1);
        passwords[i] = getField(record, 2);
        roles[i] = getField(record, 3);
        uniqueID[i] = stoi(getField(record, 4));
    }
    file.close();
}

void saveUsers() {
    fstream file;
    file.open("users.txt", ios::out);
    file << userCount << "\n";
    for (int i = 0; i < userCount; i++) {
        file << "\n" << usernames[i] << "," << passwords[i] << "," << roles[i] << "," << uniqueID[i];
    }
    file.close();
}

void loadProducts() {
    fstream file;
    file.open("products.txt", ios::in);
    string productCountL;
    getline(file, productCountL);
    productCount = stoi(productCountL);
    string empty;
    getline(file, empty);
    string record;
    for (int i = 0; i < productCount; i++) {
        getline(file, record);
        productNames[i] = getField(record, 1);
        productPrices[i] = stof(getField(record, 2));
        productStocks[i] = stoi(getField(record, 3));
        productID[i] = stoi(getField(record, 4));
        productUnits[i] = getField(record, 5);
    }
    file.close();
}

void saveProducts() {
    fstream file;
    file.open("products.txt", ios::out);
    file << productCount << "\n";
    for (int i = 0; i < productCount; i++) {
        file << "\n" << productNames[i] << "," << productPrices[i] << "," << productStocks[i] << "," << productID[i] << "," << productUnits[i];
    }
    file.close();
}

void loadData() {
    loadUsers();
    loadProducts();
}

void saveData() {
    saveUsers();
    saveProducts();
}

// Function definition END