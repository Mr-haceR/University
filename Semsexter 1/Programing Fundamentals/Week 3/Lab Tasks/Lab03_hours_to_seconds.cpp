#include <iostream>
using namespace std;

main()
{
	int hours, seconds;
	cout << "Enter time in hours: ";
	cin >> hours;
	seconds = hours * 3600;
	cout << hours << "Hours = " << seconds << "Seconds";
}
