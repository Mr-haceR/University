#include <iostream>

using namespace std;

main() {
    float total_price, total_price_after_discount;
    cout << "Enter the total price of bought items(Rs): ";
    cin >> total_price;
    if (total_price <= 5000) {
        total_price_after_discount = total_price - total_price* 0.05;
    }
    else {
        total_price_after_discount = total_price - total_price * 0.05;
    }
    cout << "Price after discount is " << total_price_after_discount;
}

