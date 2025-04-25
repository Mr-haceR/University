#include <iostream>

using  namespace std;

main() {
    string day;
    float total;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter total purchase amount: ";
    cin >> total;
    if (day == "sunday" && total > 5000) {
        total = total - total*0.10;
    }
    else {
        if (total > 5000) {
            total = total - total*0.05;
        }
    }
    cout << "Amount Payable: " << total;
}