#include <iostream>

using namespace std;

main() {
    int red, white, tulip;
    float total_price;
    cout << "Enter the number of red roses: ";
    cin >> red;
    cout << "Enter the number of white roses: ";
    cin >> white;
    cout << "Enter the number of tulips: ";
    cin >> tulip;
    total_price = (red*2.00) + (white*4.10) + (tulip*2.50);
    cout << "Original Price: " << total_price << endl;
    if (total_price > 200.00) {
        total_price = total_price - total_price*0.20;
        cout << "Price after Discount: " << total_price;
    }
}