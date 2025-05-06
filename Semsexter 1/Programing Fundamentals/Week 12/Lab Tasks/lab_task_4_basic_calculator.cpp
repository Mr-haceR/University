#include <iostream>

using namespace std;

float add(float x, float y) {
    return x + y;
}
float subtract(float x, float y) {
    return x - y;
}
float multiply(float x, float y) {
    return x * y;
}
float divide(float x, float y) {
    return x / y;
}

main() {
    int x, y;
    char ope;
    cout << "Enter 1st number: ";
    cin >> x;
    cout << "Enter 2nd number: ";
    cin >> y;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> ope;
    if (ope == '+') {
        cout << "Addition: " << add(x, y);
    }
    else if (ope == '-') {
        cout << "Subtraction: " << subtract(x, y);
    }
    else if (ope == '*') {
        cout << "Multiplication: " << multiply(x, y);
    }
    else if (ope == '/') {
        cout << "Division: " << divide(x, y);
    }
    else {
        cout << "Invalid operator!";
    }
}