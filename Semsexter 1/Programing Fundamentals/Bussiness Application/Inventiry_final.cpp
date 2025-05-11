#include <iostream>
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
int productCount = 0;

string choice;

// Globol data structures END

// Function prototypes START

void printHeader();
string landingPage();
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

// Function prototypes END

// main STRAT

main() {
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
            cout << w;
            while (true) {    
                if (w == "ADMIN") {
                    system("color 02");
                    adminMenu();
                }
                else if (w == "CUSTOMMER") {
                    system("color 03");
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
            break;
        } 
        else {
            cout << "Invalid choice. Press any key to try again...";
            getch();
        }
    }
    system("color 07");
    clearScreen();
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
            "3. Exit" << endl << endl <<
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
                "5. Logout." << endl << endl <<
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
            break;
        }
        else {
            cout << endl << "Invalid choice. Press any key to try again...";
            getch();
        }
    }
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
                "5. Sign Out." << endl << endl <<
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
            cout << i + 1 << ".\n Name: " << productNames[i] << "\nPrice: $" << productPrices[i] << "\nStock: " << productStocks[i] << " units" << endl;
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
                break;
            } 
            else {
                cout << "Invalid choice. Press any key to continue..." << endl;
                getch();
            }
        }
    }
}

// Function definition END