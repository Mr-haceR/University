#include <iostream>

using namespace std;

main() {
    int n, sum = 0;
    while (n >= 0)
    {
        cout << "Enter a number: ";
        cin >> n;
        if (n >= 0) {
            sum = sum + n;
        }
    }
    cout << "Sum of entered numbers: " << sum;
}