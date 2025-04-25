#include <iostream>

using namespace std;

main () {
    string day;
    float total;
    cout << "Enter current day: ";
    cin >> day;
    cout << "Enter total Purchase Amount: ";
    cin >> total;
    if (day == "Sunday" || day == "sunday") {
        total = total - total*0.10;
    }
    cout << "Payable amount: " << total;
}