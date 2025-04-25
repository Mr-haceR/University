#include <iostream>

using  namespace std;

main() {
    string day, month;
    float total;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter Month: ";
    cin >> month;
    cout << "Enter total purchase Amount: ";
    cin >> total;
    if ((day == "sunday" && month == "october") || (day == "thursday" && month == "november")) {
        total = total - total*0.10;
    }
    cout << "Amount Payable: " << total;   
}