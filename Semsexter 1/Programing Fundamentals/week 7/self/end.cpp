#include <iostream>

using namespace std;

main() {
    string name;
    while (name != "END") {
        cout << "Enter name: ";
        cin >> name;
        if (name != "END") {
            cout << "Hello " << name << endl;
        }
    }
    cout << "END";
}