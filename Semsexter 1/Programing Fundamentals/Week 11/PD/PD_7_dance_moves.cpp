#include <iostream>

using namespace std;

main() {
    string code, dance_moves[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};
    int count = 0,  digit_count = 0;
    cout << "Enter a four digit code: ";
    cin >> code;
    for (int i = 0; code[i] != '\0'; i++) {
        count++;
        if (code[i] >= '0' && code[i] <= '9') {
            digit_count++;
        }
    }
    if (digit_count == 4 && count == 4) {
        for (int i = 0; i < 4; i++) {
            int index = (code[i] - '0') + i;
            if (index > 9) {
                index -= 10;
            }
            cout << dance_moves[index];
            if (i < 3) {
                cout << ", ";
            }
        }
    }
    else {
        cout << "Invalid Input!";
    }
    
}