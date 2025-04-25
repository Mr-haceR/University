#include <iostream>
using namespace std;
main() {
    int u, a, t, v;
    cout << "Enter initial velocity: ";
    cin >> u;
    cout << "Enter acceleration: ";
    cin >> a;
    cout << "Enter time: ";
    cin >> t;
    v = u + (a * t);
    cout << "Final velocity: " << v;
    
}