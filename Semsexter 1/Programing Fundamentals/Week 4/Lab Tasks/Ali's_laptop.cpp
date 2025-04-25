#include <iostream>

using namespace std;

main() {
    int salary, laptop_price;
    cout << "Enter Ali's salary: ";
    cin >> salary;
    cout << "Enter the price of the laptop: ";
    cin >> laptop_price;
    int advance_salary = (salary * 6) * 0.5;
    if (advance_salary >= laptop_price) {
        cout << "Ali can buy the laptop, with the advance salary.";
    } else {
        int remaining_amount = laptop_price - advance_salary;
        int months_needed = remaining_amount / salary;
        if (remaining_amount % salary != 0) {
            months_needed = months_needed + 1;
        }
        cout << "Ali can't buy the laptop with the advance salary, he needs " << months_needed << " months worth of more salary.";
    }
}