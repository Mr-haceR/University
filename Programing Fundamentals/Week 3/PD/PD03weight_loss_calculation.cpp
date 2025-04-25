#include <iostream>
using namespace std;
main() {
    string name;
    int weight, days;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter weight to lose (kg): ";
    cin >> weight;
    days = weight * 15;
    cout << "Number of days required: " << days;
    
}