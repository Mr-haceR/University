#include <iostream>

using namespace std;

main() {
    string name;
    int count = 0;
    cout << "Enter a name: ";
    cin >> name;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    if (name[count-1] == 'n') {
        cout << "True";
    }
    else {
        cout << "False";
    }
}