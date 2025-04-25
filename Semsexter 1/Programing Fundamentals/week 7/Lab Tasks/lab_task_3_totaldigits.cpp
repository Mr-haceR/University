#include <iostream>

using namespace std;

main() {
    int n, i = 1, counter = 0;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0) {
        n = n * -1;
    }
    while (i <= n) {
        n = n / 10;
        counter = counter + 1;
    }
    cout << "Total number of digits: " << counter;
}