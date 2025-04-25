#include <iostream>

using namespace std;

main() {
    string fruit, day;
    float quantity;
    float total_price;
    cout << "Enter fruit name: ";
    cin >> fruit;
    cout << "Enter day of the week: ";
    cin >> day;
    cout << "Enter quantity: ";
    cin >> quantity;
    if (day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday") {
        if (fruit == "banana") {
            total_price = quantity * 2.50;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "apple") {
            total_price = quantity * 1.20;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "orange") {
            total_price = quantity * 0.85;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "grapefruit") {
            total_price = quantity * 1.45;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "kiwi") {
            total_price = quantity * 2.70;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "pinapple") {
            total_price = quantity * 5.50;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "grapes") {
            total_price = quantity * 3.85;
            cout << "Total price: " << total_price << "$"; 
        }
        else {
            cout << "Invalid fruit!";
        }
    }
    else if (day == "Saturday" || day == "Sunday") {
        if (fruit == "banana") {
            total_price = quantity * 2.70;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "apple") {
            total_price = quantity * 1.25;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "orange") {
            total_price = quantity * 0.90;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "grapefruit") {
            total_price = quantity * 1.60;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "kiwi") {
            total_price = quantity * 3.00;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "pinapple") {
            total_price = quantity * 5.60;
            cout << "Total price: " << total_price << "$"; 
        }
        else if (fruit == "grapes") {
            total_price = quantity * 4.20;
            cout << "Total price: " << total_price << "$"; 
        }
        else {
            cout << "Invalid fruit!";
        }
    }
    else {
        cout << "Invalid day!";
    }
} 