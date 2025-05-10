#include <iostream>
#include <conio.h>

using namespace std;

// Globol data structures START

const int TOTAL_USERS = 10;
const int TOTAL_PRODUCTS = 10;

char choice;

string productNames[TOTAL_PRODUCTS];
float productPrices[TOTAL_PRODUCTS];
int productStocks[TOTAL_PRODUCTS];
int productCount = 0;

string admin_username = "admin";
string admin_password = "admin123";

// Globol data structures END

// Function prototypes START

void printHeader();
char landingPage();
void clearScreen();
bool adminLogin();
void adminMenu();
void addProduct();
void listProducts();
void viewProductDetails();
void updateProductDetails();
void customerSignUp();
void customerMenu();
void listAllProductsWithDetails();
void sortProducts(int sortType); // 1 for cheapest to most expensive, 2 for most expensive to cheapest
void placeOrder();

// Function prototypes END

// main STRAT

main() {
    while (true) {
        choice = landingPage();
        if (choice == '1') {
            if (adminLogin()) {
                adminMenu();
            }
        } else if (choice == '2') {
            customerSignUp();
        } else if (choice == '3') {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
            getch();
        }
    }
}

// main END

// Function definitions START

void printHeader() {
    cout << endl << "*******************************************************************************************" << endl <<
                    "*                        Smart Inventory & Order Management System                        *" << endl <<
                    "*******************************************************************************************" << endl << endl;
}

char landingPage() {
    clearScreen();
    printHeader();
    cout << "1. Login" << endl <<
            "2. Sign Up" << endl <<
            "3. Exit" << endl << endl <<
            "Enter your choice: ";
    char ch;
    cin >> ch;
    return ch;
}

void clearScreen() {
    system("cls");
}

bool adminLogin() {
    clearScreen();
    printHeader();
    cout << "Login Menu > Admin" << endl;
    cout << "------------------------------------" << endl;
    cout << endl << "(Default username and password is admin and admin123 respectively)" << endl;
    string username, password;
    cout << endl << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (username == admin_username && password == admin_password) {
        cout << endl << "Login successful!" << endl;
        return true;
    } else {
        cout << endl << "Invalid credentials!" << endl;
        return false;
    }
}

void adminMenu() {
    char adminChoice;
    bool loggedIn = true;
    while (loggedIn) {
        clearScreen();
        printHeader();
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Logout." << endl << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
            case '1':
                addProduct();
                break;
            case '2':
                listProducts();
                break;
            case '3':
                viewProductDetails();
                break;
            case '4':
                updateProductDetails();
                break;
            case '5':
                loggedIn = false;
                cout << endl << "Logged out successfully." << endl;
                break;
            default:
                cout << endl << "Invalid choice. Please try again." << endl;
                getch();
        }
        if (loggedIn) {
            cout << endl << "Press Enter to continue...";
            getch();
        }
    }
}

void addProduct() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > Add products" << endl;
    cout << "------------------------------------" << endl;

    if (productCount < TOTAL_PRODUCTS) {
        cout << "Enter product name: ";
        getline(cin >> ws, productNames[productCount]); // Read with leading whitespace
        cout << "Enter the price of 1 unit of " << productNames[productCount] << ": $";
        cin >> productPrices[productCount];
        cout << "Enter number of units of " << productNames[productCount] << " in stock: ";
        cin >> productStocks[productCount];
        productCount++;
        cout << endl << "Product added successfully: " << productNames[productCount - 1] << endl;
    } else {
        cout << endl << "Product limit reached (" << TOTAL_PRODUCTS << ")." << endl;
    }
}

void listProducts() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > List All products" << endl;
    cout << "------------------------------------" << endl;

    if (productCount == 0) {
        cout << "No products added yet." << endl;
    } else {
        cout << "Product List: " << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << i + 1 << ". " << productNames[i] << endl;
        }
    }
}

void viewProductDetails() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > Check product details" << endl;
    cout << "------------------------------------" << endl;

    if (productCount == 0) {
        cout << "No products added yet." << endl;
        return;
    }

    cout << "Enter the number of the product to view details: ";
    int productNumber;
    cin >> productNumber;

    if (productNumber >= 1 && productNumber <= productCount) {
        int index = productNumber - 1;
        cout << endl << "Product details for " << productNames[index] << ":" << endl;
        cout << "Name: " << productNames[index] << endl;
        cout << "Price: $" << productPrices[index] << endl;
        cout << "Stock: " << productStocks[index] << " units" << endl;
    } else {
        cout << endl << "Invalid product number." << endl;
    }
}

void updateProductDetails() {
    clearScreen();
    printHeader();
    cout << "Admin Menu > Update product details" << endl;
    cout << "------------------------------------" << endl;

    if (productCount == 0) {
        cout << "No products added yet." << endl;
        return;
    }

    cout << "Enter the name of the product to update: ";
    string productName;
    getline(cin >> ws, productName);

    for (int i = 0; i < productCount; ++i) {
        if (productNames[i] == productName) {
            cout << "Enter new price: $";
            cin >> productPrices[i];
            cout << "Enter new stock number: ";
            cin >> productStocks[i];
            cout << "Product details updated for " << productNames[i] << endl;
            return;
        }
    }

    cout << endl << "Product not found with the name: " << productName << endl;
}

void customerSignUp() {
    clearScreen();
    printHeader();
    cout << "Customer Sign Up >" << endl;
    cout << "------------------------------------" << endl << endl;
    string customer_name;
    cout << "Enter your name: ";
    getline(cin >> ws, customer_name);
    cout << endl << "Welcome " << customer_name << "!" << endl;
    cout << endl << "Press Enter to continue to the Customer Menu...";
    cin.get();
    customerMenu();
}

void customerMenu() {
    char customerChoice;
    bool signedIn = true;
    while (signedIn) {
        clearScreen();
        printHeader();
        cout << "Customer Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. List All products along with the details." << endl;
        cout << "2. Sort all products from cheapest to most expensive." << endl;
        cout << "3. Sort all products from most expensive to cheapest." << endl;
        cout << "4. Place an order." << endl;
        cout << "5. Sign Out." << endl;
        cout << "Enter your choice: ";
        cin >> customerChoice;
        switch (customerChoice) {
            case '1':
                listAllProductsWithDetails();
                break;
            case '2':
                sortProducts(1);
                break;
            case '3':
                sortProducts(2);
                break;
            case '4':
                placeOrder();
                break;
            case '5':
                signedIn = false;
                cout << endl << "Signed out successfully." << endl;
                break;
            default:
                cout << endl << "Invalid choice. Please try again." << endl;
        }
        if (signedIn) {
            cout << endl << "Press Enter to continue...";
            getch();
        }
    }
}

void listAllProductsWithDetails() {
    clearScreen();
    printHeader();
    cout << "Customer Menu > List All products with details" << endl;
    cout << "------------------------------------" << endl;

    if (productCount == 0) {
        cout << "No products available." << endl;
    } else {
        cout << "Available Products:" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << i + 1 << ". Name: " << productNames[i] << ", Price: $" << productPrices[i] << ", Stock: " << productStocks[i] << " units" << endl;
        }
    }
}

void sortProducts(int sortType) {
    clearScreen();
    printHeader();
    cout << "Customer Menu > Sort products" << endl;
    cout << "------------------------------------" << endl;

    if (productCount == 0) {
        cout << "No products available to sort." << endl;
        return;
    }

    // Create temporary arrays to store product information
    string tempNames[TOTAL_PRODUCTS];
    float tempPrices[TOTAL_PRODUCTS];
    int tempStocks[TOTAL_PRODUCTS];

    // Copy product data to temporary arrays
    for (int i = 0; i < productCount; ++i) {
        tempNames[i] = productNames[i];
        tempPrices[i] = productPrices[i];
        tempStocks[i] = productStocks[i];
    }

    // Sort based on price
    for (int i = 0; i < productCount - 1; ++i) {
        for (int j = 0; j < productCount - i - 1; ++j) {
            if ((sortType == 1 && tempPrices[j] > tempPrices[j + 1]) || (sortType == 2 && tempPrices[j] < tempPrices[j + 1])) {
                // Swap names
                string tempName = tempNames[j];
                tempNames[j] = tempNames[j + 1];
                tempNames[j + 1] = tempName;
                // Swap prices
                float tempPrice = tempPrices[j];
                tempPrices[j] = tempPrices[j + 1];
                tempPrices[j + 1] = tempPrice;
                // Swap stocks (optional, but keeps data consistent)
                int tempStock = tempStocks[j];
                tempStocks[j] = tempStocks[j + 1];
                tempStocks[j + 1] = tempStock;
            }
        }
    }

    cout << (sortType == 1 ? "Products sorted from cheapest to most expensive:" : "Products sorted from most expensive to cheapest:") << endl;
    for (int i = 0; i < productCount; ++i) {
        cout << i + 1 << ". " << tempNames[i] << " - $" << tempPrices[i] << endl;
    }
}

void placeOrder() {
    clearScreen();
    printHeader();
    cout << "Customer Menu > Place an order" << endl;
    cout << "------------------------------------" << endl;

    if (productCount == 0) {
        cout << "No products available to order." << endl;
        return;
    }

    float total_price = 0.0;
    bool isBuying = true;

    while (isBuying) {
        cout << endl << "Available Products:" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << i + 1 << ". " << productNames[i] << " - $" << productPrices[i] << " (Stock: " << productStocks[i] << ")" << endl;
        }
        cout << productCount + 1 << ". Checkout" << endl << endl;
        cout << "Enter the number of the product to order (or " << productCount + 1 << " to checkout): ";
        int orderChoice;
        cin >> orderChoice;

        if (orderChoice >= 1 && orderChoice <= productCount) {
            int index = orderChoice - 1;
            cout << "Enter the quantity of " << productNames[index] << " you want to buy: ";
            int quantity;
            cin >> quantity;

            if (quantity > 0) {
                if (quantity <= productStocks[index]) {
                    total_price += quantity * productPrices[index];
                    productStocks[index] -= quantity;
                    cout << quantity << " units of " << productNames[index] << " added to your order." << endl;
                } else {
                    cout << "Insufficient stock for " << productNames[index] << "." << endl;
                }
            } else {
                cout << "Invalid quantity." << endl;
            }
        } else if (orderChoice == productCount + 1) {
            cout << endl << "Your total order price is: $" << total_price << endl;
            isBuying = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
        if (isBuying) {
            cout << endl;
        }
    }
}

// Function definition END