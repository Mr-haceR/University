#include <iostream>

using namespace std;

main() {
    int h, x, y;
    cout << "Enter the value of 'h': ";
    cin >> h;
    cout << "Enter 'x' coordinte of the point: ";
    cin >> x;
    cout << "Enter 'y' coordinate of the point: ";
    cin >> y;
    if (((x > 0 && x < 3 * h)) && ((y > 0 && y < h)) || ((x > h && x < 2 * h) && y < 4 * h)) {
        cout << "Inside";
    }
    else if ((y == 0 && (x >= 0 && x <= h * 3)) || 
            (x == 0 && (y >= 0 && y <= h)) || 
            (y == h && ((x >= 0 && x <= h) || (x >= h * 2 && x <= h * 3))) || 
            (x == h && (y >= h && y <= h * 4)) || 
            (x == h * 2 && (y >= h && y <= h * 4)) ||
            (x == h * 3 && (y >= 0 && y <= h)) || 
            (y == h * 4 && (x >= h && x <= h * 2))) {
        cout << "Border";
    }
    else {
        cout << "Outside";
    }
} 