#include <iostream>

using namespace std;

main() {
    int resistor_count;
    cout << "Enter the number of resistors in series: ";
    cin >> resistor_count;
    float resistors[resistor_count], RT = 0;
    for (int i = 0; i <= resistor_count-1; i++) {
        cout << "Enter R" << i+1 << ": ";
        cin >> resistors[i];
        RT += resistors[i];
    }
    cout << RT << "ohms";
}