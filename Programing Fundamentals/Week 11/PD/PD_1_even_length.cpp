#include <iostream>

using namespace std;

main() {
    string str;
    int count = 0;
    cout << "Enter a string: ";
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    if (count % 2 == 0) {
        cout << "True";
    }
    else {
        cout << "False";
    }
}