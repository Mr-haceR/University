#include <iostream>

using namespace std;
float fuel(float distance) {
    return distance * 10;
}
main() {
    float dis;
    cout << "Enter the distance: ";
    cin >> dis;
    cout << "Fuel needed: " << fuel(dis);
}