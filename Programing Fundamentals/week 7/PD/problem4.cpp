#include <iostream>

using namespace std;

main() {
    float n, temp1 = 0, temp2 = 0, temp3 = 0;
    float p1, p2, p3;
    cout << "Enter the number of integers: ";
    cin >> n;
    if (n >= 1 && n <= 1000) {
        for (int i = 0; i < n; i = i + 1) {
            int num;
            cout << "Enter a number: ";
            cin >> num;
            if (num % 2 == 0) {
                temp1 = temp1 + 1;
            }
            if (num % 3 == 0) {
                temp2 = temp2 + 1;
            }
            if (num % 4 == 0) {
                temp3 = temp3 + 1;
            }
        }
        p1 = (temp1 / n) * 100;
        p2 = (temp2 / n) * 100;
        p3 = (temp3 / n) * 100;
        cout << "Percentage of numbers divisible by 2: " << p1 << "%" << endl <<
                "Percentage of numbers divisible by 3: " << p2 << "%" << endl <<
                "Percentage of numbers divisible by 4: " << p3 << "%";
    }
    else {
        cout << "Number of integers should be between 1 and 1000.";
    }
}