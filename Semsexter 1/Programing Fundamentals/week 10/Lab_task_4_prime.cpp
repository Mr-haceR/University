#include <iostream>

using namespace std;

main() {
    int start, end;
    bool foundPrime = false;
    cout << "Enter the starting number: ";
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;

    if (start < 0 && end > 0) {
        start = 2; 
    }

    if (start <= end) {
        for (int i = start; i <= end; i++) {
            if (i <= 1) {
                continue;  
            }
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                cout << i << " ";
                foundPrime = true;
            }
        }

        if (!foundPrime) {
            cout << "No prime numbers found in this range." << endl;
        }
    }
    else if (start > end) {
        cout << "Invalid range. Start > End!." << endl;
    }
}
