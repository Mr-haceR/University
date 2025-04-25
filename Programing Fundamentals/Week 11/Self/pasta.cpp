#include <iostream>

using namespace std;

main() {
    string least_sold, most_sold,pastas[5] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
    int number[5], larget, smallest;
    for (int i = 0; i < 5; i++) {
        cout << "Enter the number of " << pastas[i] << " pastas sold: ";
        cin >> number[i];
        if (number[i] < 0) {
            cout << "Can't input negative number. Try again." << endl;
            i--;
            continue;
        }
        if (i == 0) {
            larget = number[i];
            most_sold = pastas[i];
            least_sold = pastas[i];
            smallest = number[i]; 
        }
        else {
            if (number[i] > larget) {
                larget = number[i];
                most_sold = pastas[i];
            }
            else if (number[i] < smallest) {
                smallest = number[i];
                least_sold = pastas[i];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << "Number of " << pastas[i] << " pastas sold: " << number[i] << endl;
    }
    cout << endl;
    cout << "Highst selling: " << most_sold << endl;
    cout << "Lowest sold: " << least_sold;
}