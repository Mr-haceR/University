#include <iostream>

using namespace std;

main() {
    int speed;
    cout << "Enter speed: ";
    cin >> speed;
    if (speed <= 10) {
        cout << "Slow";
    }
    if (speed <= 50) {
        if (speed > 10) {
            cout << "Average";
        }
    }
    if (speed <= 150) {
        if(speed > 50) {
            cout << "Fast";
        }
    }
    if (speed <=1000) {
        if (speed > 150) {
            cout << "Ultra Fast";
        }
    }
    if (speed > 1000) {
        cout << "Extremely fast";
    }
}