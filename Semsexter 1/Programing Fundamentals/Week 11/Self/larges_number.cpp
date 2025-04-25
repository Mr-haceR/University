#include <iostream>

using namespace std;

main() {
    int numbers[5], largest;
    for (int i = 0; i < 5; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> numbers[i];
        if (i == 0) {
            largest = numbers[0];
        }
        else {
            if (numbers[i] > largest) {
                largest = numbers[i];
            }
        }
    }
    cout << "Largest number: " << largest;
}