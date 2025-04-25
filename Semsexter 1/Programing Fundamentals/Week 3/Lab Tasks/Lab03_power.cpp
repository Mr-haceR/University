#include <iostream>
using namespace std;

main()
{
	float volt, current, power;
	cout << "Enter voltage(in volts): ";
	cin >> volt;
	cout << "Enter current(in Ampere): ";
	cin >> current;
	power = volt * current;
	cout << "Power is " << power;
}
