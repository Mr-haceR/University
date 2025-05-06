#include <iostream>

using namespace std;

bool challan(int speed) {
    if (speed > 100) {
        return true;
    }
    return false;
}

main() {
    int speed;
    cout << "Enter speed in km/h: ";
    cin >> speed;
    if (challan(speed)) {
        cout << "Halit.... YOU WILL BE CHALLANED!!!";
    }
    else {
        cout << "Perfect! You're going good.";
    }
}