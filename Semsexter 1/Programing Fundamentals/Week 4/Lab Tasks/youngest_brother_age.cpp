#include <iostream>

using namespace std;

main() {
	string brother1, brother2, brother3;
	int age1, age2, age3;
	cout << "Enter Name of Brother 1: ";
	cin >> brother1;
	cout << "Enter age of Brother 1: ";
	cin >> age1;

	cout << "Enter Name of Brother 2: ";
	cin >> brother2;
	cout << "Enter age of Brother 2: ";
	cin >> age2;

	cout << "Enter Name of Brother 3: ";
	cin >> brother3;
	cout << "Enter age of Brother 3: ";
	cin >> age3;

	if(age1 == age2) {
		if(age2 == age3) {
			cout << "The brothers are triplets";
  		}
	}

	if(age1 < age2) {
		if(age1 < age3) {
	  		cout << brother1 << " is younger ";
    		}
	}

	if(age2 < age1) {
		if(age2 < age3) {
	  		cout << brother2 << " is younger" ;
		}
	}

}