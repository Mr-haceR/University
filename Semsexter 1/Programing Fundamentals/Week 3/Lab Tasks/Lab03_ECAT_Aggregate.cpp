#include <iostream>
using namespace std;

main()
{
	float matric_marks, inter_marks, ECAT_marks;
	float aggregate;
	cout <<	"Enter your Matric marks out of 1100: ";
	cin >> matric_marks;
	cout << "Enter your Intermediate marks out of 550: ";
	cin >> inter_marks;
	cout << "Enter your ECAT marks out of 400: ";
	cin >> ECAT_marks;
	aggregate = ((ECAT_marks/400)*100)*0.5 + ((inter_marks/550)*100)*0.4 + ((matric_marks/1100)*100)*0.1;
	cout << "Your UET Aggregate is " << aggregate;
}