#include <iostream>

using namespace std;

main() {
    bool same = true;
    int length;
    cout << "Enter length of the array: ";
    cin >> length;
    string arr[length];
    for (int i = 0; i <= length-1; i++) {
        cout << "Enter array element: ";
        cin >> arr[i];
        if (i > 0 && arr[i] != arr[i-1]) {
            same = false;
        }
    }
    if (same) {
        cout << "True";
    }
    else {
        cout << "False";
    }
}