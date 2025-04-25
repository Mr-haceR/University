#include <iostream>

using namespace std;

main() {
    float n, p1, p2, p3, p4, p5, 
          temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0;
    cout << "Enter numbers count: ";
    cin >> n;
    for (int i = 0; i < n; i = i + 1) {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        if (num < 200) {
            temp1 = temp1 + 1;
        }
        else if (num >= 200 && num <= 399) {
            temp2 = temp2 + 1;
        }
        else if (num >= 400 && num <= 599) {
            temp3 = temp3 + 1;
        }
        else if (num >= 600 && num <= 799) {
            temp4 = temp4 + 1;
        }
        else if (num >= 800 && num <= 999) {
            temp5 = temp5 + 1;
        }
    }
    p1 = (temp1 / n) * 100;
    p2 = (temp2 / n) * 100;
    p3 = (temp3 / n) * 100;
    p4 = (temp4 / n) * 100;
    p5 = (temp5 / n) * 100;
    cout << p1 << "%" << endl <<
         p2 << "%" << endl <<
         p3 << "%" << endl <<
         p4 << "%" << endl <<
         p5 << "%";
}