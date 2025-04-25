#include <iostream>
using namespace std;

main()
{
	float weightInPounds;
	cout << "Enter weight in pounds(lbs): ";
	cin >> weightInPounds;
	float weightInKilograms = weightInPounds * 0.45;
	cout << "Weight in Kilograms is " << weightInKilograms;	
}