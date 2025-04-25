#include <iostream>
using namespace std;
main() {
    int sum = 0, temp;
    cout << "Enter first number: "; 
    cin >> temp; sum = sum + temp;
    cout << "Enter second number: "; 
    cin >> temp; sum = sum + temp;
    cout << "Enter third number: "; 
    cin >> temp; sum = sum + temp;
    cout << "Enter fourth number: "; 
    cin >> temp; sum = sum + temp;
    cout << "Enter fifth number: ";
    cin >> temp; sum = sum + temp;
    cout << "Sum of the 5 numbers: " << sum;
}