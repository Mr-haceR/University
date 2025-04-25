#include <iostream>

using namespace std;

main() {
    int x1, x2, x3;
    cout << "Enter 1st integer: ";
    cin >> x1;
    cout << "Enter 2nd integer: ";
    cin >> x2;
    cout << "Enter 3rd integer: ";
    cin >> x3;
    if (x1 >= 50 || x2 >= 50 || x3 >= 50) {
        cout << "One of Value is too large";
    }   
}