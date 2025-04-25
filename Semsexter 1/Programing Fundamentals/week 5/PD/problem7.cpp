#include <iostream>

using namespace std;

main() {
    string month;
    int stays;
    float apartment_rent, studio_rent;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter number of stays: ";
    cin >> stays;
    if (month == "May" || month == "October") {
        apartment_rent = 65 - 65*0.10;
        studio_rent = 50;
        if (stays > 14) {
            studio_rent = studio_rent - studio_rent*0.30; 
        }
        else if (stays > 7) {
            studio_rent = studio_rent - studio_rent*0.05;
        }
    }
    else if (month == "June" || month == "September") {
        apartment_rent = 68.70 - (68.70*0.10);
        studio_rent = 75.20;
        if (stays > 14) {
            studio_rent = studio_rent - studio_rent*0.20; 
        }
    }
    else if (month == "July" || month == "August") {
        apartment_rent = 77 - 77*0.10;
        studio_rent = 76;
    }
    cout << "Apartment: " << apartment_rent*stays << endl;
    cout << "Studio: " << studio_rent*stays << endl;
} 