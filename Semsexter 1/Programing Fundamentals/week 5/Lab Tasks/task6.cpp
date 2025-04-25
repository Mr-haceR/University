#include <iostream>

using  namespace std;

main() {
    string day, month;
    float total;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter total purchase amount: ";
    cin >> total;   
    if (day == "sunday" && (month == "october" || month == "march")) {
        total = total - total*0.10;
    }
    cout << "Payable Amount: " << total;
}