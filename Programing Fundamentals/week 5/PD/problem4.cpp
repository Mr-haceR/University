#include <iostream>

using namespace std;

main() {
    int day;
    string month;
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    if ((month == "march" && day >= 21) || (month == "april" && day <= 19)) {
        cout << "Aries|The Ram" << endl;
    } 
    else if ((month == "april" && day >= 20) || (month == "may" && day <= 20)) {
        cout << "Taurus|The Bull" << endl;
    } 
    else if ((month == "may" && day >= 21) || (month == "june" && day <= 20)) {
        cout << "Gemini|The Twins" << endl;
    } 
    else if ((month == "june" && day >= 21) || (month == "july" && day <= 22)) {
        cout << "Cancer|The Crab" << endl;
    } 
    else if ((month == "july" && day >= 23) || (month == "august" && day <= 22)) {
        cout << "Leo|The Lion" << endl;
    } 
    else if ((month == "august" && day >= 23) || (month == "september" && day <= 22)) {
        cout << "Virgo|The Virgin" << endl;
    } 
    else if ((month == "september" && day >= 23) || (month == "october" && day <= 22)) {
        cout << "Libra|The Scales" << endl;
    } 
    else if ((month == "october" && day >= 23) || (month == "november" && day <= 21)) {
        cout << "Scorpio|The Scorpion" << endl;
    } 
    else if ((month == "november" && day >= 22) || (month == "december" && day <= 21)) {
        cout << "Sagittarius|The Archer" << endl;
    } 
    else if ((month == "december" && day >= 22) || (month == "january" && day <= 19)) {
        cout << "Capricorn|The Goat" << endl;
    } 
    else if ((month == "january" && day >= 20) || (month == "february" && day <= 18)) {
        cout << "Aquarius|The Water Bearer" << endl;
    } 
    else if ((month == "february" && day >= 19) || (month == "march" && day <= 20)) {
        cout << "Pisces|The Fishes" << endl;
    }
} 