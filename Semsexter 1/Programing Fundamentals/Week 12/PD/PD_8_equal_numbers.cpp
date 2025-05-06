#include <iostream>

using namespace std;

bool isEqual(int x, int y) {
    if (x == y) {
        return true;
    }
    return false;
}

main() {
    int a, b;
    cout << "Enter 1st number: ";
    cin >> a;
    cout << "Enter 2nd number: ";
    cin >> b;
    if (isEqual(a, b)) {
        cout << "True";
    }
    else {
        cout << "False";
    }
}