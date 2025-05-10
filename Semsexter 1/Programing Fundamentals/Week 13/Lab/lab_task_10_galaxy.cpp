#include <iostream>
using namespace std;

char objects[5][5] = {
    {'-', '#', '#', '-', '#'},
    {'#', '-', '-', '#', '-'},
    {'-', '#', '-', '-', '-'},
    {'#', '-', '#', '-', '#'},
    {'#', '-', '-', '-', '-'}
};

bool gravity = false;
bool isBlackHole = true;

void displayWorld() {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            cout << objects[row][col] << "\t";
        }
        cout << endl;
    }
}

void setGravityStatus(bool status) {
    gravity = status;
}

void timeTick(int ticks) {
    if (!gravity) return;

    for (int t = 0; t < ticks; t++) {
        char newObjects[5][5];
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                newObjects[row][col] = '-';
            }
        }
        for (int row = 4; row >= 0; row--) {
            for (int col = 0; col < 5; col++) {
                if (objects[row][col] == '#') {
                    int nextRow = row + 1;
                    if (nextRow == 5) {
                        if (isBlackHole) {
                            nextRow = 0;
                        } 
                        else {
                            nextRow = 4;
                            if (newObjects[nextRow][col] == '-') {
                                newObjects[nextRow][col] = '#';
                                continue;
                            } 
                            else {
                                nextRow = row;
                            }
                        }
                    }
                    if (newObjects[nextRow][col] == '-') {
                        newObjects[nextRow][col] = '#';
                    } 
                    else {
                        newObjects[row][col] = '#'; 
                    }
                }
            }
        }
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                objects[row][col] = newObjects[row][col];
            }
        }
    }

    cout << endl;
}

main() {
    displayWorld();
    setGravityStatus(true);
    timeTick(4);
    displayWorld();
}