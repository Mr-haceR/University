#include <iostream>

using namespace std;

main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int res = 1;
    cout <<  res << ", ";
    for (int i = 1; i <= n; i++) {
        res = res * 2;
        cout <<  res << ", ";
    }
}