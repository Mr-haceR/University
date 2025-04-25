#include <iostream>
using namespace std;

main()
{
	float mb, bits;
	cout << "Enter number of Mega Bytes: ";
	cin >> mb;
	bits = mb * 1024 * 1024 * 8;
	cout << mb << "MB = " << bits;
}