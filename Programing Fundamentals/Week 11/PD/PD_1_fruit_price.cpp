#include <iostream>

using namespace std;

main() {
    string fruit[4] = {"peach", "apple", "guava", "watermelon"};
    int price[4] = {60, 70, 40, 30};
    string name;
    int quantity, total_bill;
    cout << "Enter name of the fruit: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> quantity;
    for (int i = 0; i < 4; i++) {
        if (fruit[i] == name) {
            total_bill = quantity * price[i];
        }
    }
    cout << "Total Bill: " << total_bill;
}