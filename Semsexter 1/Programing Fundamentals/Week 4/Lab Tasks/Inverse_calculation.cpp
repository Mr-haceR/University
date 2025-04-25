#include <iostream>

using namespace std;

main() {
	float num1, num2;
	char op;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter operator: ";
	cin >> op;
	cout << "Enter second number: ";
	cin >> num2;

	if (op == '+') {
		cout << "Inverse Result: " << num1 - num2;
	}
	if (op == '-') {
		cout << "Inverse Result: " << num1 + num2;
	}
	if (op == '*') {
		cout << "Inverse Result: " << num1 / num2;
	}
	if (op == '/') {
		cout << "Inverse Result: " << num1 * num2;
	}
}