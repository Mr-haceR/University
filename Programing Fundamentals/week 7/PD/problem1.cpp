#include <iostream>

using namespace std;

main() {
    int num, x;
    cout << "Enter the parameter num: ";
    cin >> num;
    if (num >= 1) {
        for (int i = 1; i <= num; i = i + 1) {
            if (i % 4 == 0) {
                x = i * 10;
            }
            else {
                x = i;
            }
            cout << x << ", ";
        }
    }
    else {
        cout << "The parameter should be greater than or equal to 1.";
    }
}