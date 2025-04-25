#include <iostream>

using namespace std;

main() {
    int age;
    char gender;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter gender (m/f): ";
    cin >> gender;
    if (gender == 'm') {
        if (age >= 16) {
            cout << "Personal Title: Mr.";
        }
        else {
            cout << "Personal Title: Mister";
        }
    }
    else if (gender == 'f') {
        if (age >= 16) {
            cout << "Personal Title: Ms.";
        }
        else {
            cout << "Personal Title: Miss";
        }
    }
}