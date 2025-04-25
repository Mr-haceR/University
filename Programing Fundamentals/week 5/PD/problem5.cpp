#include <iostream>

using namespace std;

main() {
    char customer_type, time;
    int minutes;
    float price;
    cout << "Enter which type of customer you are (Regular or Premium) select (r / p): ";
    cin >> customer_type;
    if (customer_type == 'r' || customer_type == 'R') {
        cout << "Enter number of minutes you used the service: ";
        cin >> minutes;
        price = 10;
        if (minutes > 50) {
            price = price + (minutes - 50) * 0.20;
        }
        cout << "The charges are: " << price << "$";
    }
    else if (customer_type == 'p' || customer_type == 'P') {
        cout << "(Press 'D' for day time or Press 'N' for night time) call: ";
        cin >> time;
        cout << "Enter number of minutes you used the service: ";
        cin >> minutes;
        price = 25;
        if (time == 'd' || time == 'D') {
            if (minutes > 75) {
                price = price + (minutes - 75) * 0.10;
            }
        }
        else if (time == 'n' || time == 'N') {
            if (minutes > 100) {
                price = price + (minutes - 100) * 0.05;
            }
        }
        cout << "The charges are: " << price << "$";
    }
    else {
        cout << "Invalid Input!";
    }
} 