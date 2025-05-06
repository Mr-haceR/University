#include <iostream>

using namespace std;

float inchesToFeet(float inches) {
    return inches / 12;
}

main() {
    float inches;
    cout << "Enter the measurement in inches: ";
    cin >> inches;
    cout << "Equivalent measurement in feet: " << inchesToFeet(inches);
}