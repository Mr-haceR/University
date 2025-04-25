#include <iostream>

using namespace std;

main() {
    int amount, tens = 0, fifties = 0, hundreds = 0, fivehundreds = 0, thausands = 0;
    cout << "Enter the amount(in rupees): ";
    cin >> amount;
    if (amount % 10 == 0) {
        while (amount > 0) {
            if (amount > 1000) {
                thausands++;
                amount -= 1000;
            }
            else if (amount > 500) {
                fivehundreds++;
                amount -= 500;
            }
            else if (amount > 100) {
                hundreds++;
                amount -= 100;
            }
            else if (amount > 50) {
                fifties++;
                amount -= 50;
            }
            else if (amount >= 10) {
                tens++;
                amount -= 10;
            }
        }
        cout << "Notes Dispensed: " << endl <<
                "Tens: " << tens << endl <<
                "Fifties: " << fifties << endl <<
                "Hundreds: " << hundreds << endl << 
                "Five Hundreds: " << fivehundreds << endl << 
                "Thousands: " << thausands;
        
    }
    else {
        cout << "Please enter an amount divisible by 10";
    }
}