#include <iostream>


using namespace std;

main() {
    float speed;
    cout << "Enter speed of the car(km/h): ";
    cin >> speed;
    if (speed <= 100) {
        cout << "Perfect! You are going good.";
    }
    else {
        cout << "Halt….YOU WILL BE CHALLANED!!!";
    }
}