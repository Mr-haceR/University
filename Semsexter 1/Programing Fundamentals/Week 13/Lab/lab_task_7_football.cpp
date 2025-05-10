#include <iostream>

using namespace std;

bool isGoalScored(char field[7][16], int row, int col) {
    if ((row >= 0 && row <= 2) && (col >= 1 && col <= 14)) return true;
    return false;
}

void printField(char field[7][16]) {
    for (int row = 0; row < 7; row++) {
        for (int col = 0; col < 16; col++) {
            cout << field[row][col];
        }
        cout << endl;
    }
}

main() {
    char field[7][16] = {
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    printField(field);
    int x, y;
    cout << "Enter coordinates of the football(e.g. 0 1, 1 2, 6 14): ";
    cin >> x >> y;
    if ((x >= 0 && x <= 6) && (y >= 0 && y <= 15)) {
        field[x][y] = '0';
        printField(field);
        if (isGoalScored(field, x, y)) {
            cout << "Goal!";
        }
        else {
            cout << "Not Goal";
        } 
    }
    else {
        cout << "Invalid Input!";
    }
}