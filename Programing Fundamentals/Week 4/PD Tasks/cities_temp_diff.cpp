#include <iostream>

using namespace std;

main() {
    float temp1, temp2;
    cout << "Temperature of City 1: ";
    cin >> temp1;
    cout << "Temperature of City 2: ";
    cin >> temp2;
    if (temp1 - temp2 >= 10) {
        cout << "Difference is too big";
    }
    cout << "Program ends";
}