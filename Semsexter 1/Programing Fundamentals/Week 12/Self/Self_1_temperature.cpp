#include <iostream>

using namespace std;

bool checkTemp(string temp) {
    return (temp == "98.6") ? true : false;
}

main() {
    while (true) {
        string temp;
        cout << "Temperature of patient(Fahrenheit): ";
        cin >> temp;
        if (checkTemp(temp)) cout << "Normal\n";
        cout << "Program Ends\n";
    }
}