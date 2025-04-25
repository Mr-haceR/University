#include <iostream>

using  namespace std;

main() {
    string day;
    float total;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter total purchase amount: ";
    cin >> total;   
    if (day == "sunday") {
        total = total - total*0.10;
    }
    else if (day == "monday") {
        total = total - total*0.08;
    }
    else {
        total = total - total*0.05;
    }
    cout << "Payable Amount: " << total;
}