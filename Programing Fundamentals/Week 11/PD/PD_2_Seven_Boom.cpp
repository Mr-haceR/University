#include <iostream>

using namespace std;

main() {
    bool sevenFlag = false;
    int length;
    cout << "Enter length of the array: ";
    cin >> length;
    int arr[length];
    for (int i = 0; i <= length-1; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }   
    for (int i = 0; i <= length-1; i++) {
        int temp = arr[i];
        while (temp > 0) {
            if (temp % 10 == 7) {
                sevenFlag = true;
                break;
            }
            temp /= 10;
        }
    }
    if (sevenFlag) {
        cout << "Boom!";
    }
    else {
        cout << "There is no 7 in the array.";
    }
}