#include <iostream>

using namespace std;

main() {
    string temp, humidity;
    cout  << "Enter temperature(Warm/Cold): ";
    cin >> temp;
    cout << "Enter humidity(Dry/Humid): ";
    cin >> humidity;
    if (temp == "warm") {
        if (humidity == "dry") {
            cout << "Play tennis";    
        }
        else if (humidity == "humid") {
            cout << "swim";
        }
    }
    else if (temp == "cold") {
        if (humidity == "dry") {
            cout << "Play basketball";
        }
        else if (humidity == "humid") {
            cout << "Watch tv";
        }
    }
    
} 