#include <iostream>
using namespace std;
main() {
    int n, w, h, walls;
    cout << "Enter the number of square meters you can paint: ";
    cin >> n;
    cout << "Enter the width of a wall: ";
    cin >> w;
    cout << "Enter the height of a wall: ";
    cin >> h;
    walls = n / (w * h);
    cout << "Number of walls you can paint: " << walls;
}