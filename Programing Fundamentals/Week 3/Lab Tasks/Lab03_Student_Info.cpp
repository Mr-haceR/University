#include <iostream>

using namespace std;

main() {
    string name;
    int roll_number;
    float aggregate;
    char section;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your Roll Number: ";
    cin >> roll_number;
    cout << "Enter your aggregate: ";
    cin >> aggregate;
    cout << "Enter your section: ";
    cin >> section;

    cout << endl << "Student information:" << endl <<
    "Name: " << name << endl <<
    "Roll Number: " << roll_number << endl <<
    "Aggregate: " << aggregate << endl <<
    "Section: " << section;
}
