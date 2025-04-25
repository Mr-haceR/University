#include <iostream>
using namespace std;

main()
{
	int age_in_years, age_in_days;
	cout << "Enter your age in years: ";
	cin >> age_in_years;
	age_in_days = age_in_years * 365;
	cout << "Your age in days is " << age_in_days;
}