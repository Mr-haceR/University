#include <iostream>
using namespace std;
main() {
    int n, sum;
    cout << "Enter the number of sides in the polygon: ";
    cin >> n;
    sum = (n - 2) * 180;
    cout << "Total sum of internal angles: " << sum;
    
}