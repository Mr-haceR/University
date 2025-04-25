#include <iostream>

using namespace std;

main() {
    int n, i = 1, digit, frequency, temp;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the digit to check its frequency: ";
    cin >> digit;
    if (n < 0) {
        n = n * -1;
    }
    while (i <= n) {
        temp = n % 10;
        if (temp == digit) {
            frequency = frequency + 1;
        }
        n = n / 10;
    }
    cout << "Freequency: " << frequency;
}