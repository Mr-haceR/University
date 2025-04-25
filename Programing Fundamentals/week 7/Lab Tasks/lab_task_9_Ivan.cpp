#include <iostream>

using namespace std;

main() {
    int inheritence, year_until_stay_in_the_past_ends, age = 18, money_spent = 0;
    cout << "Enter the inheritence money: ";
    cin >> inheritence;
    cout << "Enter the uear until Ivan is going to live in the past: ";
    cin >> year_until_stay_in_the_past_ends;
    for (int i = 1800; i <= year_until_stay_in_the_past_ends; i = i + 1) {
        if (i % 2 == 0) {
            money_spent = money_spent + 12000;
        }
        else {
            money_spent = money_spent + (12000 + 50 * age);
        }
        age = age + 1;
    }
    if (money_spent <= inheritence) {
        cout << "Yes! He will live a carefree life and will have " << inheritence - money_spent << " dollars left.";
    }
    else {
        cout << "No! He will need " << money_spent - inheritence << " dollars to survive.";
    }
}