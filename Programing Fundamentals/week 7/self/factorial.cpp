#include <iostream>

using namespace std;

main() {
    int n, fact = 1;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= n; i = i + 1) {
        fact = fact * i;
    }
    cout << "Factorial: " << fact;
}