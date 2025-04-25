#include <iostream>

using namespace std;

main() {
    int n, i = 1, sum = 0, temp;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0) {
        n = n * -1;
    }
    while (i <= n) {
        temp = n % 10;
        sum = sum + temp;
        n = n / 10; 
    }    
    cout << "Sum of digits: " << sum;
}