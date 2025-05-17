#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

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
int productID[TOTAL_PRODUCTS];
int productCount = 0;

string loggedInAs;
int currentUserID;
string choice;

// Globol data structures END

// Function prototypes START
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
void addProduct();
void listProducts();
void viewProductDetails();
void updateProductDetails();
void customerMenu();
void listAllProductsWithDetails();
void sortProducts(int sortType); // 1 for cheapest to most expensive, 2 for most expensive to cheapest
void placeOrder();
void addToHistory(string username, int userID, float total);
void showMyHistory(string username, int userID);

// Function prototypes END

// main STRAT

main() {
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
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
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
                else if (w == "CUSTOMMER") {
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
            if (userCount == 10) {
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
                    string username, password;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    addUser(username, password, userCount, "ADMIN");
                }
                else if (choice == "2") {
                    cout << "Sign Up > Custommer" << endl << 
                            "------------------------" << endl << endl;
                    string username, password;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    addUser(username, password, userCount, "CUSTOMMER");
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
            string username, password; 
            int id;
            clearScreen();
            printHeader();
            cout << "Delete Account >" << endl << 
                    "------------------------" << endl << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter the unique id assigned to you at sign up: ";
            cin >> id;
            string w = deleteUser(username, password, id);
            if (w == "DONE") {
                cout << endl << "Account Deleted: " << username << ". Press any key to continue...";
                getch();
            }
            else if (w == "FAILED") {
                cout << "Wrong Credentials. Press any key to continue...";
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
            "2. As a custommer." << endl << 
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
    for (int j = index; index < userCount-1; j++) {
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
            addProduct();
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
            string name; 
            int id;
            clearScreen();
            printHeader();
            cout << "Delete Product >" << endl << 
                    "------------------------" << endl << endl;
            for (int i = 0; i < productCount; i++) {
                cout << i + 1 << ". Name: " << productNames[i] << ", Product ID: " << productID[i] << endl; 
            }
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Product ID: ";
            cin >> id;
            string w = deleteProduct(name, id);
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
    fstream file;
    file.open("history.txt", ios::in);
    string name, id, total;
    int i = 1;
    cout << endl << "All Order History: " << endl;
    while (!file.eof()) {
        file >> name;
        file >> id;
        file >> total;
        cout << i << ". Custommer: " << name << ", User ID: " << id << ": Total was $" << total << endl;
        i++;
    }
}

void addToHistory(string username, int userID, float total) {
    fstream file;
    file.open("history.txt", ios::app);
    file << "\n" << username << " " << userID << " " << total;
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
    }
    productCount--;
    return "DONE";
}

void addProduct() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > Add products" << endl;
    cout << "------------------------------------" << endl << endl;

    if (productCount < TOTAL_PRODUCTS) {
        cout << "Enter product name: ";
        cin >> productNames[productCount];
        cout << "Enter the price of 1 unit of " << productNames[productCount] << ": $";
        cin >> productPrices[productCount];
        cout << "Enter number of units of " << productNames[productCount] << " in stock: ";
        cin >> productStocks[productCount];
        cout << endl << "Product Added: " << productNames[productCount] << endl;
        productID[productCount] = productCount;
        cout << "The Unique Product ID is " << productID[productCount] << endl;
        productCount++;
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
    for (int i = 0; i < productCount; i++) {
        cout << i + 1 << ". " << productNames[i] << endl;
    }
    cout << endl << "Enter the number of the product to view details: ";
    string productNumber;
    cin >> productNumber;
    if (productNumber >= "1") {
        int productNumberInt = productNumber[0] - '0'; // char to int conversion trick.
        if (productNumber == "10") productNumberInt = 10;
        if (productNumberInt <= productCount) {
            int index = productNumberInt - 1;
            cout << endl << "Product details for " << productNames[index] << ":" << endl;
            cout << "Name: " << productNames[index] << endl;
            cout << "Price: $" << productPrices[index] << endl;
            cout << "Stock: " << productStocks[index] << " units" << endl;
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
    cout << "Product List: " << endl;
    for (int i = 0; i < productCount; i++) {
        cout << i + 1 << ". " << productNames[i] << endl;
    }
    cout << endl << "Enter the number of the product to view details: ";
    string productNumber;
    cin >> productNumber;
    if (productNumber >= "1") {
        int productNumberInt = productNumber[0] - '0'; // char to int conversion trick.
        if (productNumber == "10") productNumberInt = 10;
        if (productNumberInt <= productCount) {
            int index = productNumberInt - 1;
            cout << "Enter new price: $";
            cin >> productPrices[index];
            cout << "Enter new stock number: ";
            cin >> productStocks[index];
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
    int id, total, i = 1;
    cout << endl << "Your Order History: " << endl;
    while(!file.eof()) {
        file >> name;
        file >> id;
        file >> total;
        if (name == username && id == userID) {
            cout << endl << i << ". Your total was $" << total;
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
            cout << i + 1 << ".\nName: " << productNames[i] << "\nPrice: $" << productPrices[i] << "\nStock: " << productStocks[i] << " units" << endl << "\nProduct ID: " << productID[i] << endl;
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
    else cout  << "Products sorted from most expensive to cheapest:" << endl;
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
        cout << "Available Products:" << endl;
        for (int i = 0; i < productCount; i++) {
            cout << i + 1 << ". " << productNames[i] << " - $" << productPrices[i] << " (Stock: " << productStocks[i] << ")" << endl;
        }
        cout << productCount + 1 << ". Checkout" << endl << endl;
        cout << "Enter the number of the product to order (or " << productCount + 1 << " to checkout): ";

        cin >> choice;

        if (choice[0] >= '1') {
            int orderChoiceInt = choice[0] - '0'; // char to int trick
            if (choice == "10") orderChoiceInt = 10;
            if (choice == "11") orderChoiceInt = 11;
            int index = orderChoiceInt - 1;
            if (orderChoiceInt <= productCount) {
                cout << "Enter the quantity of " << productNames[index] << " you want to buy: ";
                int quantity;
                cin >> quantity;

                if (quantity > 0) {
                    if (quantity <= productStocks[index]) {
                        total_price += quantity * productPrices[index];
                        productStocks[index] -= quantity;
                        cout << quantity << " units of " << productNames[index] << " added to your order." << endl;
                    } 
                    else {
                        cout << "Insufficient stock for " << productNames[index] << "." << endl;
                    }
                } 
                else {
                    cout << "Invalid quantity." << endl;
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

void loadUsers() {
    fstream file;
    file.open("users.txt", ios::in);
    string userCountL;
    getline(file, userCountL);
    userCount = stoi(userCountL);
    while (!file.eof()) {
        for (int i = 0; i < userCount; i++) {
            file >> usernames[i];
            file >> passwords[i];
            file >> roles[i];
            file >> uniqueID[i];
        }
    }
    file.close();
}

void saveUsers() {
    fstream file;
    file.open("users.txt", ios::out);
    file << userCount << "\n";
    for (int i = 0; i < userCount; i++) {
        file << usernames[i] << " " << passwords[i] << " " << roles[i] << " " << uniqueID[i] << "\n";
    }
    file.close();
}

void loadProducts() {
    fstream file;
    file.open("products.txt", ios::in);
    string productCountL;
    getline(file, productCountL);
    productCount = stoi(productCountL);
    while (!file.eof()) {
        for (int i = 0; i < productCount; i++) {
            file >> productNames[i];
            file >> productPrices[i];
            file >> productStocks[i];
            file >> productID[i];
        }
    }
    file.close();
}

void saveProducts() {
    fstream file;
    file.open("products.txt", ios::out);
    file << productCount << "\n";
    for (int i = 0; i < productCount; i++) {
        file << productNames[i] << " " << productPrices[i] << " " << productStocks[i] << " " << productID[i] << "\n";
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