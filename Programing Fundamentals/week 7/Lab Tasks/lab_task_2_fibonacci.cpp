#include <iostream>

using namespace std;

main() {
    int length;
    cout << "Enter the length of the Fibonacci serires: ";
    cin >> length;
    int n1 = 0, n2 = 1, next;
    cout << n1 << ", " << n2 << ", ";
    for (int i = 0; i < length - 2; i = i + 1) {
        next = n1 + n2;
        n1 = n2;
        n2 = next;
        cout << next << ", ";
    }
}