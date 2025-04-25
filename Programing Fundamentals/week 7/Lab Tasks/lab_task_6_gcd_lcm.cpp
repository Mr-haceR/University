#include <iostream>

using namespace std;

main() {
    int n1, n2, gcd, lcm;
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;
    int a = n1, b = n2;
    while (n2 != 0) {
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    gcd = n1;
    lcm = (a * b) / n1;
    cout << "GCD: " << gcd <<endl;
    cout << "LCM: " << lcm;
}