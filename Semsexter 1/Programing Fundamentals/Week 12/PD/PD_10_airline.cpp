#include <iostream>

using namespace std;

float calculateDiscount(string country, float amount) {
    if (country == "Pakistan" || country == "pakistan") {
        amount -= amount * 0.05;
    }
    else if (country == "Ireland" || country == "ireland") {
        amount -= amount * 0.10;
    }
    else if (country == "India" || country == "india") {
        amount -= amount * 0.20;
    }
    else if (country == "England" || country == "england") {
        amount -= amount * 0.30;
    }
    else if (country == "Canada" || country == "canada") {
        amount -= amount * 0.45;
    }
    return amount;
}

main() {
    string country;
    float price;
    while (true) {
        cout << "Enter country: ";
        cin >> country;
        cout << "Enter price: $";
        cin >> price;
        cout << "Final Price: $" << calculateDiscount(country, price) << endl;
    }
}