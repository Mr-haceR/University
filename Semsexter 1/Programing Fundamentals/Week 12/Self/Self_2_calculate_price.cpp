#include <iostream>

using namespace std;

float calculatePrice(float amount) {
    if (amount == 500) amount -= amount * 0.05;
    return amount;
}

main() {
    while (true) {
        float amount;
        cout << "Enter total price: ";
        cin >> amount;
        cout << "Price after discount: " << calculatePrice(amount) << "\n";
    }
}