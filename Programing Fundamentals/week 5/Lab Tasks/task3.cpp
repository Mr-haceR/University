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
        if (total > 5000.0) {
            total = total - total*0.10;
        }
    }    
    cout << "Payable Amount: " << total;
}