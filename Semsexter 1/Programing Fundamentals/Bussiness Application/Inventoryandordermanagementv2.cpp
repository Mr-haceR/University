#include <iostream>

using namespace std;

main() {
    bool running = true;
    int productAdded = 0;
    bool productLimitReached = false;
    string product1 = "empty", product2 = "empty", product3 = "empty";
    float price1 = 0.0, price2 = 0.0, price3 = 0.0;
    int stock1 = 0, stock2 = 0, stock3 = 0;
    string admin_username = "admin", admin_password = "admin123";
    while (running) {
        int choice;
        cout << endl;
        cout << "*******************************************************************************************" << endl;
        cout << "*                        Smart Inventory & Order Management System                        *" << endl;
        cout << "*******************************************************************************************" << endl;
        cout << endl;
        cout << "Login Menu >" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. As an admin." << endl;
        cout << "2. As a customer." << endl;
        cout << "3. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            bool notAuthenticated = true;
            while (notAuthenticated) {
                cout << endl << "(Default username and password is admin and admin123 respectively)" << endl;
                string username, password;
                cout << endl;
                cout << "*******************************************************************************************" << endl;
                cout << "*                                       Admin Login                                       *" << endl;
                cout << "*******************************************************************************************" << endl;
                cout << endl << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                if (username == admin_username && password == admin_password) {
                    notAuthenticated = false;
                    bool logged_in_as_admin = true;
                    while (logged_in_as_admin) {
                        cout << endl;
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
                        cout << "5. Logout." << endl << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;
                        if (choice == 1) {
                            if (!productLimitReached) {
                                if (productAdded == 0) {
                                    cout << endl << "Enter product name: ";
                                    cin >> product1;
                                    cout << "Enter the price of 1 unit of " << product1 << ": $";
                                    cin >> price1;
                                    cout << "Enter number of units of " << product1 << " in stock: ";
                                    cin >> stock1;
                                    cout << endl << "Product added: " << product1 << endl;
                                    productAdded++;
                                }
                                else if (productAdded == 1) {
                                    cout << endl << "Enter product name: ";
                                    cin >> product2;
                                    cout << "Enter the price of 1 unit of " << product2 << ": $";
                                    cin >> price2;
                                    cout << "Enter number of units of " << product2 << " in stock: ";
                                    cin >> stock2;
                                    cout << endl << "Product added: " << product2 << endl;
                                    productAdded++;
                                } 
                                else if (productAdded == 2) {
                                    cout << endl << "Enter product name: ";
                                    cin >> product3;
                                    cout << "Enter the price of 1 unit of " << product3 << ": $";
                                    cin >> price3;
                                    cout << "Enter number of units of " << product3 << " in stock: ";
                                    cin >> stock3;
                                    cout << endl << "Product added: " << product3 << endl;
                                    productAdded++;
                                    productLimitReached = true;
                                } 
                            } 
                            else {
                                cout << endl << "Product limit reached." << endl;
                            }
                        }
                        else if (choice == 2) {
                            if (productAdded == 0) {
                                cout << endl << "You haven't added any products yet." << endl;
                            }
                            else if (productAdded == 1) {
                                cout << endl << "Product List: " << endl;
                                cout << endl << "1. " << product1 << endl;
                            }
                            else if (productAdded == 2) {
                                cout << endl << "Product List: " << endl;
                                cout << endl << "1. " << product1 << endl <<
                                                "2. " << product2 << endl;
                            }
                            else if (productAdded == 3) {
                                cout << endl << "Product List: " << endl;
                                cout << endl << "1. " << product1 << endl <<
                                                "2. " << product2 << endl <<
                                                "3. " << product3 << endl;
                            }
                        }
                        else if (choice == 3) {
                            if (productAdded == 0) {
                                cout << endl << "You haven't added any products yet." << endl;
                            }
                            else if (productAdded == 1) {
                                cout << endl << "Product details: " << endl;
                                cout << "1:" << endl << "Name: " << product1 << endl << 
                                        "Price: $" << price1 << endl <<
                                        "Stock: " << stock1 << " units" << endl;
                            }
                            else if (productAdded == 2) {
                                cout << endl << "Product details: " << endl;
                                cout << "1:" << endl << "Name: " << product1 << endl << 
                                        "Price: $" << price1 << endl <<
                                        "Stock: " << stock1 << " units" << endl;
                                cout << "2:" << endl << "Name: " << product2 << endl << 
                                        "Price: $" << price2 << endl <<
                                        "Stock: " << stock2 << " units" << endl;
                            }
                            else if (productAdded == 3) {
                                cout << endl << "Product details: " << endl;
                                cout << "1:" << endl << "Name: " << product1 << endl << 
                                        "Price: $" << price1 << endl <<
                                        "Stock: " << stock1 << " units" << endl;
                                cout << "2:" << endl << "Name: " << product2 << endl << 
                                        "Price: $" << price2 << endl <<
                                        "Stock: " << stock2 << " units" << endl;
                                cout << "3:" << endl << "Name: " << product3 << endl << 
                                        "Price: $" << price3 << endl <<
                                        "Stock: " << stock3 << " units" << endl;
                            }
                        }
                        else if (choice == 4) {
                            string name;
                            cout << endl << "Enter the name of the product: ";
                            cin >> name;
                            if (name == product1) {
                                cout << "Enter new price: $";
                                cin >> price1;
                                cout << "Enter new stock number: ";
                                cin >> stock1;
                                cout << "Product details Updated: " << product1 << endl;
                            }
                            else if (name == product2) {
                                cout << "Enter new price: $";
                                cin >> price2;
                                cout << "Enter new stock number: ";
                                cin >> stock2;
                                cout << "Product details Updated: " << product2 << endl;
                            }
                            else if (name == product3) {
                                cout << "Enter new price: $";
                                cin >> price3;
                                cout << "Enter new stock number: ";
                                cin >> stock3;
                                cout << "Product details Updated: " << product3 << endl;
                            }
                            else {
                                cout << endl << "Invalid name!" << endl;
                            }
                        }
                        else if (choice == 5) {
                            logged_in_as_admin = false;
                        }
                        else {
                            cout << endl << "Invalid choice!" << endl;
                        }
                    }
                }
                else {
                    if (username == admin_username && password != admin_password) {
                        cout << endl << "Invalid Password!" << endl;
                    }
                    else if (username != admin_username && password == admin_password) {
                        cout << endl << "Invalid Username!" << endl;
                    }
                    else {
                        cout << endl << "Invalid Username & Password!" << endl;
                    }
                }
            }
        }
        else if (choice == 2) {
            string customer_name;
            cout << endl;
            cout << "*******************************************************************************************" << endl;
            cout << "*                                    Custommer Sign Up                                    *" << endl;
            cout << "*******************************************************************************************" << endl << endl;
            cout << "Enter your name: ";
            cin >> customer_name;
            cout << endl << "Welcome " << customer_name << endl;
            bool customerSignedIn = true;
            while (customerSignedIn) {
                cout << endl;
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
                cout << "5. Sign Out." << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1) {
                    if (productAdded == 0) {
                        cout << endl << "You haven't added any products yet." << endl;
                    }
                    else if (productAdded == 1) {
                        cout << endl << "Product details: " << endl;
                        cout << "1:" << endl << "Name: " << product1 << endl << 
                                "Price: $" << price1 << endl <<
                                "Stock: " << stock1 << " units" << endl;
                    }
                    else if (productAdded == 2) {
                        cout << endl << "Product details: " << endl;
                        cout << "1:" << endl << "Name: " << product1 << endl << 
                                "Price: $" << price1 << endl <<
                                "Stock: " << stock1 << " units" << endl;
                        cout << "2:" << endl << "Name: " << product2 << endl << 
                                "Price: $" << price2 << endl <<
                                "Stock: " << stock2 << " units" << endl;
                    }
                    else if (productAdded == 3) {
                        cout << endl << "Product details: " << endl;
                        cout << "1:" << endl << "Name: " << product1 << endl << 
                                "Price: $" << price1 << endl <<
                                "Stock: " << stock1 << " units" << endl;
                        cout << "2:" << endl << "Name: " << product2 << endl << 
                                "Price: $" << price2 << endl <<
                                "Stock: " << stock2 << " units" << endl;
                        cout << "3:" << endl << "Name: " << product3 << endl << 
                                "Price: $" << price3 << endl <<
                                "Stock: " << stock3 << " units" << endl;
                    }
                }
                else if (choice == 2) {
                    cout << endl << "All products ordered from cheapest to most expensive: "<< endl << endl;
                    if (productAdded == 0) {
                        cout << endl << "No Products Added yet." << endl;
                    }
                    else if (productAdded == 1) {
                        cout << "1. " << product1 << endl;
                    }
                    else if (productAdded == 2) {
                        if (price1 < price2) {
                            cout << "1. " << product1 << endl;
                            cout << "2. " << product2 << endl;
                        }
                        else {
                            cout << "1. " << product2 << endl;
                            cout << "2. " << product1 << endl;
                        }
                    }
                    else if (productAdded == 3) {
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
                }
                else if (choice == 3) {
                    cout << endl << "All products ordered from most expensive to cheapest: "<< endl << endl;
                    if (productAdded == 0) {
                        cout << endl << "No Products Added yet." << endl;
                    }
                    else if (productAdded == 1) {
                        cout << "1. " << product1 << endl;
                    }
                    else if (productAdded == 2) {
                        if (price1 > price2) {
                            cout << "1. " << product1 << endl;
                            cout << "2. " << product2 << endl;
                        }
                        else {
                            cout << "1. " << product2 << endl;
                            cout << "2. " << product1 << endl;
                        }
                    }
                    else if (productAdded == 3) {
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
                }
                else if (choice == 4) {
                    bool isBuying = true;
                    float total_price = 0.0;
                    while (isBuying) {
                        cout << endl;
                        cout << "*******************************************************************************************" << endl;
                        cout << "*                                       Place Order                                       *" << endl;
                        cout << "*******************************************************************************************" << endl << endl;
                        cout << "Enter the product you want to buy: " << endl << 
                                "1. " << product1 << endl <<
                                "2. " << product2 << endl << 
                                "3. " << product3 << endl << 
                                "4. Checkout." << endl << endl <<
                                "Enter your choice: ";
                        cin >> choice;
                        int n = 0;
                        if (choice == 1) {
                            if (product1 != "empty") {
                                cout << endl << "Enter number of units of the item: ";
                                cin >> n;
                                if (n <= stock1) {
                                    total_price = total_price +  (n * price1);
                                    cout << endl << "Added to cart: " << n << " units of " << product1 << endl;
                                    stock1 = stock1 - n;
                                }
                                else {
                                    cout << endl << "Out of stock." << endl;
                                }
                            }
                            else {
                                cout << endl << "There is no product in this slot." << endl;
                            }
                        }
                        else if (choice == 2) {
                            if (product2 != "empty") {
                                cout << endl << "Enter number of units of the item: ";
                                cin >> n;
                                if (n <= stock2) {
                                    total_price = total_price +  (n * price2);
                                    cout << endl << "Added to cart: " << n << " units of " << product2 << endl;
                                    stock2 = stock2 - n;
                                }
                                else {
                                    cout << endl << "Out of stock." << endl;
                                }
                            }
                            else {
                                cout << endl << "There is no product in this slot." << endl;
                            }
                        }
                        else if (choice == 3) {
                            if (product2 != "empty") {
                                cout << endl << "Enter number of units of the item: ";
                                cin >> n;
                                if (n <= stock3) {
                                    total_price = total_price +  (n * price3);
                                    cout << endl << "Added to cart: " << n << " units of " << product3 << endl;
                                    stock3 = stock3 - n;
                                }
                                else {
                                    cout << endl << "Out of stock." << endl;
                                }
                            }
                            else {
                                cout << endl << "There is no product in this slot." << endl;
                            }
                        }
                        else if (choice == 4) {
                            cout << endl << "Your total is $" << total_price << "." << endl << endl;
                            isBuying = false;
                        }
                        else {
                            cout << "Invalid choice!";
                        }
                    }
                }
                else if (choice == 5) {
                    customerSignedIn = false;
                }
                else {
                    cout << endl << "Invalid choice!" << endl;
                }
            }
        }
        else if (choice == 3) {
            running = false;
        }
        else {
            cout << "Invalid choice!" << endl << endl;
        }
    }
}