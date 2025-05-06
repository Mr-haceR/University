#include <iostream>

using namespace std;

bool Vote(int age) {
    if (age >= 18) {
        return true;
    }
    return false;
}

main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if (age > 0) {
        if(Vote(age)) {
            cout << "You are eligible to vote.";
        }   
        else {
            cout << "You are not eligible to vote.";
        }
    }
    else {
        cout << "Age can't be negative!";
    }
}