#include <iostream>

using namespace std;

float calculateFuel(float distance) {
    float result = distance * 10;
    if (result < 100) {
        result = 100;
    }
    return result;
}

main() {
    float dis;
    cout << "Enter the distance: ";
    cin >> dis;
    cout << "Fuel needed: " << calculateFuel(dis);
}  