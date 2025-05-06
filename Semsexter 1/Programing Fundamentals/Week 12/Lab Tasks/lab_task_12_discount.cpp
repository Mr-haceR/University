#include <iostream>

using namespace std;

float payableAmount(string day, float amount) {
    if (day == "sunday" || day == "Sunday") {
        amount -= amount * 0.10;
        return amount;
    }
    amount -= amount * 0.05;
    return amount;
}

main() {
    while (true) {
        string day;
        float amount;
        cout << "Enter the day of the purchase: ";
        cin >> day;
        cout << "Enter the total purchase amount: $";
        cin >> amount;
        cout << "Payable Amount: $" << payableAmount(day, amount) << endl << endl;
    }
}