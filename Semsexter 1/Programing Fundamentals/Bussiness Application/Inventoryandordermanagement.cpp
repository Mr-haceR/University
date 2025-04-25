#include <iostream>

using namespace std;

main() {
    int choice;
    cout << "*******************************************************************************************" << endl;
    cout << "*                        Smart Inventory & Order Management System                        *" << endl;
    cout << "*******************************************************************************************" << endl;
    cout << endl;
    cout << "Login Menu >" << endl;
    cout << "------------------------------------" << endl;
    cout << "1. As an admin." << endl;
    cout << "2. As a customer." << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    string product1, product2, product3;
    float price1, price2, price3;
    int stock1, stock2, stock3;
    if (choice == 1) {
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << endl << "Enter product name: ";
            cin >> product1;
            cout << "Enter product price: $";
            cin >> price1;
            cout << "Enter number of items in stock: ";
            cin >> stock1;
            cout << endl << "Product added: " << product1 << endl;
        }
        else if (choice >= 2 || choice <= 4) {
            cout << "No products yet." << endl;
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit." << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << endl << "Enter product name: ";
            cin >> product2;
            cout << "Enter  product price: $";
            cin >> price2;
            cout << "Enter number of items in stock: ";
            cin >> stock2;
            cout << endl << "Product added: " << product2 << endl;
        }
        else if (choice == 2) {
            cout << endl << "Following are all the available products: " << endl << endl << product1 << endl;
        }
        else if (choice == 3) {
            cout << endl << "Product details: " << endl << endl;
            cout << "Name: " << product1 << endl << 
                    "Price: $" << price1 << endl <<
                    "Stock: " << stock1 << endl;
            cout << "-----------------------------------" << endl;
        }
        else if (choice == 4) {
            cout << endl << "Choose a product to update the details: " << endl <<
                            "1. " << product1 << endl << endl <<
                            "Enter your choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter new price: $";
                cin >> price1;
                cout << "Enter new stock: ";
                cin >> stock1;
                cout << "Product details updated: " << product1 << endl;
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit." << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << endl << "Enter product name: ";
            cin >> product3;
            cout << "Enter product price: $";
            cin >> price3;
            cout << "Enter number of items in stock: ";
            cin >> stock3;
            cout << endl << "Product added: " << product3 << endl;
        }
        else if (choice == 2) {
            cout << endl << "Following are all the available products: " << endl << endl << product1 << endl << product2 << endl;
        }
        else if (choice == 3) {
            cout << endl << "Product details: " << endl << endl;
            cout << "Name: " << product1 << endl << 
                    "Price: $" << price1 << endl <<
                    "Stock: " << stock1 << endl;
            cout << "-----------------------------------" << endl;
            cout << "Name: " << product2 << endl << 
                    "Price: $" << price2 << endl <<
                    "Stock: " << stock2 << endl;
            cout << "-----------------------------------" << endl;
        }
        else if (choice == 4) {
            cout << endl << "Choose a product to update the details: " << endl <<
                            "1. " << product1 << endl << 
                            "2. " << product2 << endl << endl <<
                            "Enter your choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter new price: $";
                cin >> price1;
                cout << "Enter new stock: ";
                cin >> stock1;
                cout << "Product details updated: " << product1 << endl;
            }
            else if (choice == 2) {
                cout << "Enter new price: $";
                cin >> price2;
                cout << "Enter new stock: ";
                cin >> stock2;
                cout << "Product details updated: " << product2 << endl;
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit." << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "You can't add more products!";
        }
        else if (choice == 2) {
            cout << endl << "Following are all the available products: " << endl << endl << product1 << endl << product2 << endl << product3 << endl;
        }
        else if (choice == 3) {
            cout << endl << "Product details: " << endl << endl;
            cout << "Name: " << product1 << endl << 
                    "Price: $" << price1 << endl <<
                    "Stock: " << stock1 << endl;
            cout << "-----------------------------------" << endl; 
            cout << "Name: " << product2 << endl << 
                    "Price: $" << price2 << endl <<
                    "Stock: " << stock2 << endl;
            cout << "-----------------------------------" << endl; 
            cout << "Name: " << product3 << endl << 
                    "Price: $" << price3 << endl <<
                    "Stock: " << stock3 << endl;
            cout << "-----------------------------------" << endl; 
        }
        if (choice == 4) {
            cout << endl << "Choose a product to update the details: " << endl <<
                            "1. " << product1 << endl <<
                            "2. " << product2 << endl << 
                            "3. " << product3 << endl << endl <<
                            "Enter your choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter new price: $";
                cin >> price1;
                cout << "Enter new stock: ";
                cin >> stock1;
                cout << "Product details updated: " << product1 << endl;
            }
            else if (choice == 2) {
                cout << "Enter new price: $";
                cin >> price2;
                cout << "Enter new stock: ";
                cin >> stock2;
                cout << "Product details updated: " << product2 << endl;
            }
            else if (choice == 3) {
                cout << "Enter new price: $";
                cin >> price3;
                cout << "Enter new stock: ";
                cin >> stock3;
                cout << "Product details updated: " << product3 << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
       
    }
    else if (choice == 2) {
        cout << "There are no products for the customer to buy." << endl;
    }
    else {
        cout << "Invalid choice!";
    }
    cout << "*******************************************************************************************" << endl;
    cout << "*                        Smart Inventory & Order Management System                        *" << endl;
    cout << "*******************************************************************************************" << endl;
    cout << endl;
    cout << "Login Menu >" << endl;
    cout << "------------------------------------" << endl;
    cout << "1. As an admin." << endl;
    cout << "2. As a customer." << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << endl << "Enter product name: ";
            cin >> product1;
            cout << "Enter product price: $";
            cin >> price1;
            cout << "Enter number of items in stock: ";
            cin >> stock1;
            cout << endl << "Product added: " << product1 << endl;
        }
        else if (choice >= 2 || choice <= 4) {
            cout << "No products yet." << endl;
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit." << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << endl << "Enter product name: ";
            cin >> product2;
            cout << "Enter  product price: $";
            cin >> price2;
            cout << "Enter number of items in stock: ";
            cin >> stock2;
            cout << endl << "Product added: " << product2 << endl;
        }
        else if (choice == 2) {
            cout << endl << "Following are all the available products: " << endl << endl << product1 << endl;
        }
        else if (choice == 3) {
            cout << endl << "Product details: " << endl << endl;
            cout << "Name: " << product1 << endl << 
                    "Price: $" << price1 << endl <<
                    "Stock: " << stock1 << endl;
            cout << "-----------------------------------" << endl;
        }
        else if (choice == 4) {
            cout << endl << "Choose a product to update the details: " << endl <<
                            "1. " << product1 << endl << endl <<
                            "Enter your choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter new price: $";
                cin >> price1;
                cout << "Enter new stock: ";
                cin >> stock1;
                cout << "Product details updated: " << product1 << endl;
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit." << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << endl << "Enter product name: ";
            cin >> product3;
            cout << "Enter product price: $";
            cin >> price3;
            cout << "Enter number of items in stock: ";
            cin >> stock3;
            cout << endl << "Product added: " << product3 << endl;
        }
        else if (choice == 2) {
            cout << endl << "Following are all the available products: " << endl << endl << product1 << endl << product2 << endl;
        }
        else if (choice == 3) {
            cout << endl << "Product details: " << endl << endl;
            cout << "Name: " << product1 << endl << 
                    "Price: $" << price1 << endl <<
                    "Stock: " << stock1 << endl;
            cout << "-----------------------------------" << endl;
            cout << "Name: " << product2 << endl << 
                    "Price: $" << price2 << endl <<
                    "Stock: " << stock2 << endl;
            cout << "-----------------------------------" << endl;
        }
        else if (choice == 4) {
            cout << endl << "Choose a product to update the details: " << endl <<
                            "1. " << product1 << endl << 
                            "2. " << product2 << endl << endl <<
                            "Enter your choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter new price: $";
                cin >> price1;
                cout << "Enter new stock: ";
                cin >> stock1;
                cout << "Product details updated: " << product1 << endl;
            }
            else if (choice == 2) {
                cout << "Enter new price: $";
                cin >> price2;
                cout << "Enter new stock: ";
                cin >> stock2;
                cout << "Product details updated: " << product2 << endl;
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Admin Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Add products." << endl;
        cout << "2. List All products." << endl;
        cout << "3. Check product details." << endl;
        cout << "4. Update product details." << endl;
        cout << "5. Exit." << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "You can't add more products!";
        }
        else if (choice == 2) {
            cout << endl << "Following are all the available products: " << endl << endl << product1 << endl << product2 << endl << product3 << endl;
        }
        else if (choice == 3) {
            cout << endl << "Product details: " << endl << endl;
            cout << "Name: " << product1 << endl << 
                    "Price: $" << price1 << endl <<
                    "Stock: " << stock1 << endl;
            cout << "-----------------------------------" << endl; 
            cout << "Name: " << product2 << endl << 
                    "Price: $" << price2 << endl <<
                    "Stock: " << stock2 << endl;
            cout << "-----------------------------------" << endl; 
            cout << "Name: " << product3 << endl << 
                    "Price: $" << price3 << endl <<
                    "Stock: " << stock3 << endl;
            cout << "-----------------------------------" << endl; 
        }
        if (choice == 4) {
            cout << endl << "Choose a product to update the details: " << endl <<
                            "1. " << product1 << endl <<
                            "2. " << product2 << endl << 
                            "3. " << product3 << endl << endl <<
                            "Enter your choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter new price: $";
                cin >> price1;
                cout << "Enter new stock: ";
                cin >> stock1;
                cout << "Product details updated: " << product1 << endl;
            }
            else if (choice == 2) {
                cout << "Enter new price: $";
                cin >> price2;
                cout << "Enter new stock: ";
                cin >> stock2;
                cout << "Product details updated: " << product2 << endl;
            }
            else if (choice == 3) {
                cout << "Enter new price: $";
                cin >> price3;
                cout << "Enter new stock: ";
                cin >> stock3;
                cout << "Product details updated: " << product3 << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
       
    }
    else if (choice == 2) {
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Customer Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. List All products along with the details." << endl;
        cout << "2. Sort all products from cheapest to most expensive." << endl;
        cout << "3. Sort all products from most expensive to cheapest." << endl;
        cout << "4. Place an order." << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice = 1) {
            cout << endl << "Product details: " << endl << endl;
            cout << "Name: " << product1 << endl << 
                    "Price: $" << price1 << endl <<
                    "Stock: " << stock1 << endl;
            cout << "-----------------------------------" << endl; 
            cout << "Name: " << product2 << endl << 
                    "Price: $" << price2 << endl <<
                    "Stock: " << stock2 << endl;
            cout << "-----------------------------------" << endl; 
            cout << "Name: " << product3 << endl << 
                    "Price: $" << price3 << endl <<
                    "Stock: " << stock3 << endl;
            cout << "-----------------------------------" << endl; 
        }
        else if (choice == 2) {
            if (price1 < price2 && price1 < price3) {
                cout << "1. " << product1 << endl;
                if (price2 < price3) {
                    cout << "2. " << product2 << endl;
                    cout << "3. " << product3 << endl;
                }
                else {
                    cout << "2. " << product3 << endl;
                    cout << "3. " << product2 << endl;
                }
            }
            else if (price2 < price1 && price2 < price3) {
                cout << "1. " << product2 << endl;
                if (price1 < price3) {
                    cout << "2. " << product1 << endl;
                    cout << "3. " << product3 << endl;
                }
                else {
                    cout << "2. " << product3 << endl;
                    cout << "3. " << product1 << endl;
                }
            }
            else if (price3 < price1 && price3 < price2) {
                cout << "1. " << product3 << endl;
                if (price1 < price2) {
                    cout << "2. " << product1 << endl;
                    cout << "3. " << product2 << endl;
                }
                else {
                    cout << "2. " << product2 << endl;
                    cout << "3. " << product1 << endl;
                }
            }
        }
        else if (choice == 3) {
            if (price1 > price2 && price1 > price3) {
                cout << "1. " << product1 << endl;
                if (price2 > price3) {
                    cout << "2. " << product2 << endl;
                    cout << "3. " << product3 << endl;
                }
                else {
                    cout << "2. " << product3 << endl;
                    cout << "3. " << product2 << endl;
                }
            }
            else if (price2 > price1 && price2 > price3) {
                cout << "1. " << product2 << endl;
                if (price1 > price3) {
                    cout << "2. " << product1 << endl;
                    cout << "3. " << product3 << endl;
                }
                else {
                    cout << "2. " << product3 << endl;
                    cout << "3. " << product1 << endl;
                }
            }
            else if (price3 > price1 && price3 > price2) {
                cout << "1. " << product3 << endl;
                if (price1 > price2) {
                    cout << "2. " << product1 << endl;
                    cout << "3. " << product2 << endl;
                }
                else {
                    cout << "2. " << product2 << endl;
                    cout << "3. " << product1 << endl;
                }
            }
        }
        else if (choice == 4) {
            cout << endl << "Enter the product you want to buy: " << endl << 
                            "1. " << product1 << endl <<
                            "2. " << product2 << endl << 
                            "3. " << product3 << endl << endl <<
                            "Enter your choice: ";
            cin >> choice;
            int n;
            float total_price;
            cout << "Enter number of items: ";
            cin >> n;
            if (choice == 1) {
                if (n <= stock1) {
                    total_price = n * price1;
                    cout << "Your total is " << total_price << endl;
                }
                else {
                    cout << "Out of stock!" << endl;
                }
            }
            else if (choice == 2) {
                if (n <= stock2) {
                    total_price = n * price2;
                    cout << "Your total is " << total_price << endl;
                }
                else {
                    cout << "Out of stock!" << endl;
                }
            }
            else if (choice == 3) {
                if (n <= stock3) {
                    total_price = n * price3;
                    cout << "Your total is " << total_price << endl;
                }
                else {
                    cout << "Out of stock!" << endl;
                }
            }
            else {
                cout << "Invalid choice!";
            }
        }
        else if (choice == 5) {
            cout << "Exit." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    else {
        cout << endl << "Invalid choice!";
    }
}