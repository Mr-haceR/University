#include <iostream>

using namespace std;

main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'z' || str[i] == 'Z') {
            if (str[i] == 'z') {
                cout << 'a';
            }
            else {
                cout << 'A';
            }
        }
        else {
            char temp = str[i] + 1;
            cout << temp;
        }
    }
}