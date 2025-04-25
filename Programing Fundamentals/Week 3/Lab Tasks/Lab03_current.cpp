#include <iostream>

using namespace std;

main()
{
	float charge, time, current;
	cout << "Enter charge(Q) in Coulombs: ";
	cin >> charge;
	cout << "Enter time(t) in seconds: ";
	cin >> time;
	current = charge / time;
	cout << "Current(I) in Ampere is " << current;
}