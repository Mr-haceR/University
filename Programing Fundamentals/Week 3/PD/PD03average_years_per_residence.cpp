#include <iostream>
using namespace std;
main() {
    int age, moves, avg_years;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter the number of times you have moved: ";
    cin >> moves;
    avg_years = age / (moves + 1);
    cout << "Average years per residence: " << avg_years;
}