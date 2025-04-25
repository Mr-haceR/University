#include <iostream>

using namespace std;

main() {
    int lilly_age, washing_machine_price, unit_price_of_toy, 
        number_of_toys_of_odd_bdays = 0, number_of_even_bdays = 0, total_money_of_even_bdays = 0,
        sold_toys_money = 0, total_money;
    cout << "Enter Lilly's age: ";
    cin >> lilly_age;
    cout << "Enter the price of the washing machine: ";
    cin >> washing_machine_price;
    cout << "Enter the unit price of the toys: ";
    cin >> unit_price_of_toy;
    for (int i = 1; i <= lilly_age; i = i + 1) {
        if (i % 2 == 0) {
            number_of_even_bdays = number_of_even_bdays + 1;
        }
        else {
            number_of_toys_of_odd_bdays = number_of_toys_of_odd_bdays + 1;
        }
    } 
    int x = 10;
    while (number_of_even_bdays != 0) {
        total_money_of_even_bdays = total_money_of_even_bdays + (x - 1);
        x = x + 10;
        number_of_even_bdays = number_of_even_bdays - 1;
    }
    sold_toys_money = number_of_toys_of_odd_bdays * unit_price_of_toy;
    total_money = total_money_of_even_bdays + sold_toys_money;
    if (total_money >= washing_machine_price) {
        cout << "Yes!" << endl <<
                total_money - washing_machine_price;
    }
    else {
        cout << "No! " << endl <<
                washing_machine_price - total_money;
    }
}