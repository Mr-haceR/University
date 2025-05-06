#include <iostream>

using namespace std;

bool evenOrOdd(int n) {
    if (n % 2 == 0) {
        return true;
    }
    return false;
}

main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (evenOrOdd(n)) {
        cout << "Number " << n << " is even.";
    }
    else {
        cout << "Number " << n << " is odd.";
    }
}