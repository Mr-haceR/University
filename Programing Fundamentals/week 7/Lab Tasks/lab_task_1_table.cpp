#include <iostream>

using namespace std;

main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for(int i = 1; i <= 10; i = i + 1) {
        cout << n << " X " << i << " = " << n * i << endl;
    }   
}