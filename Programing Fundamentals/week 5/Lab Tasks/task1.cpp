#include <iostream>


using namespace std;

main() {
    float total;
    cout << "Enter total purchase amount: ";
    cin >> total;
    total = total - total*0.10; 
    cout << "Payable amount after discount: " << total;
}