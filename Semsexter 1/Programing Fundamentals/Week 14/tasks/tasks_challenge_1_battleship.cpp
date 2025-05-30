#include <iostream>

using namespace std;

string fire(char map[5][5], string coordinate) {
    int row, col;
    for (int i = 0; coordinate[i] != '\0'; i++) {
        if (coordinate[i] == 'A') row = 0;
        if (coordinate[i] == 'B') row = 1;
        if (coordinate[i] == 'C') row = 2;
        if (coordinate[i] == 'D') row = 3;
        if (coordinate[i] == 'E') row = 4;

        if (coordinate[i] == '1') col = 0;
        if (coordinate[i] == '2') col = 1;
        if (coordinate[i] == '3') col = 2;
        if (coordinate[i] == '4') col = 3;
        if (coordinate[i] == '5') col = 4;
    }
    if (map[row][col] == '.') return "splash";
    else if (map[row][col] == '*') return "BOOM";
}

main() {
    char map[5][5] = {
//        1    2    3    4    5
/*A*/   {'.', '.', '.', '*', '*'},
/*B*/   {'.', '*', '.', '.', '*'},
/*C*/   {'.', '*', '.', '.', '.'},
/*D*/   {'.', '*', '.', '.', '.'},
/*E*/   {'.', '.', '*', '*', '.'}
    };
    string validInputs[25] = {"A1", "A2", "A3", "A4", "A5", "B1", "B2", "B3", "B4", "B5", "C1", "C2", "C3", "C4", "C5", "D1", "D2", "D3", "D4", "D5", "E1", "E2", "E3", "E4", "E5"};
    string coordinate;
    cout << "Enter coordinate to fire torpedo(e.g. , A1, B3, E5): ";
    cin >> coordinate;
    bool valid = false;
    for (int i = 0; i < 25; i++) {
        if (coordinate == validInputs[i]) {
            cout << fire(map, coordinate);
            valid = true;
            break;
        }
    }
    if (!valid) {
        cout << "Invalid Input!";
    }
}