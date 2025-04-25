#include <iostream>

using namespace std;

main() {
    int length, n;
    cout << "Enter length of the array: ";
    cin >> length;
    int arr[length];
    for (int i = 0; i <= length-1; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }
    cout << "Enter number of times even-odd transformation need to be done: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < length; j++) {
            if (arr[j] % 2 == 0) {
                arr[j] -= 2;
                if (i == n-1) {
                    cout << arr[j] << ", ";
                }
            }
            else {
                arr[j] += 2;
                if (i == n-1) {
                    cout << arr[j] << ", ";
                }
            }
        }
    }
}