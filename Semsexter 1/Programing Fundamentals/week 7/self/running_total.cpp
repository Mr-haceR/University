#include <iostream>

using namespace std;

main() {
    int n, sum = 0;
    for (int i = 0; i < 5; i = i + 1) {
        cout << "Enter a number: ";
        cin >> n;
        sum = sum + n;
    }    
    cout << "Sum: " << sum;
}