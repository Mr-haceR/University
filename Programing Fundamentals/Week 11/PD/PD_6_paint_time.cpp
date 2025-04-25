#include <iostream>

using namespace std;

main() {
    int length, time = 0;
    cout << "Enter length of array: ";
    cin >> length;
    string arr[length];
    time = (2*length);
    for (int i = 0; i < length; i++) {
        cout << "Enter a color: ";
        cin >> arr[i];
       1
        if (i > 0 && arr[i] != arr[i-1]) {
            time++;
        }
    }wwwwww
    cout << "Time: " << time;
}                                                                                                                                                q