#include <iostream>

using namespace std;

float calculatePrice(int red, int white, int tulip) {
    float total = (red * 2.00) + (white * 4.10) + (tulip * 2.50);
    return total;
}

float discount(float total) {
    if (total > 200) {
        total -= total * 0.20;
    }
    return total;
}

main() {
    int red, white, tulip;
    cout << "Red Rose: ";
    cin >> red;
    cout << "White Roses: ";
    cin >> white;
    cout << "Tulips: ";
    cin >> tulip;
    float total = calculatePrice(red, white, tulip);
    cout << "Original Price: " << total << endl;
    cout << "Price after discount: " << discount(total);
}