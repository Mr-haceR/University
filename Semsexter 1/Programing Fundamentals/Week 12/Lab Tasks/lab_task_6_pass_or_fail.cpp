#include <iostream>

using namespace std;

bool passOrFail(int score) {
    if (score > 50) {
        return true;
    }
    return false;
}

main() {
    int score;
    cout  << "Enter your score: ";
    cin >> score;
    if (score > 0) {
        if (passOrFail(score)) {
            cout << "Pass";
        }
        else {
            cout << "Fial";
        }
    }
    else {
        cout << "Score can't be negtive!";
    }
}