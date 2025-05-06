#include <iostream>

using namespace std;

float calculatePayableAmount(string day, float amount) {
    if (day == "Sunday" || day == "sunday") {
        amount -= amount * 0.10;
    }
    return amount;
}

main() {
    string day;
    float purchaseAmount;
    cout << "Enter the day of the purchase: ";
    cin >> day;
    cout << "Enter the total purchase amount: $";
    cin >> purchaseAmount;
    cout << "Payable Amount: $" << calculatePayableAmount(day, purchaseAmount);
}