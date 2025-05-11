#include <iostream>
using namespace std;

const int ROWS = 20;
const int COLS = 20;
char board[ROWS][COLS];

int playerX = ROWS - 2;
int playerY = COLS / 2;

struct Fire {
    int x, y;
    bool active = false;
} fire;

void initializeBoard() {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
    board[playerX][playerY] = 'p'; // Player
}

void printBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j)
            cout << board[i][j];
        cout << endl;
    }
}

void movePlayerLeft() {
    if (playerY > 1) {
        board[playerX][playerY] = ' ';
        playerY--;
        board[playerX][playerY] = 'p';
    }
}

void movePlayerRight() {
    if (playerY < COLS - 2) {
        board[playerX][playerY] = ' ';
        playerY++;
        board[playerX][playerY] = 'p';
    }
}

void fireBullet() {
    if (!fire.active) {
        fire.x = playerX - 1;
        fire.y = playerY;
        fire.active = true;
        board[fire.x][fire.y] = '.';
    }
}

void moveFire(int timeStep) {
    if (fire.active) {
        board[fire.x][fire.y] = ' '; // Clear previous fire position
        fire.x -= timeStep;
        if (fire.x <= 0) {
            fire.active = false;
        } else {
            board[fire.x][fire.y] = '.';
        }
    }
}

void moveEnemy(char enemyChar, string direction) {
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            if (board[i][j] == enemyChar) {
                board[i][j] = ' ';
                if (direction == "left" && j > 1)
                    board[i][j - 1] = enemyChar;
                else if (direction == "right" && j < COLS - 2)
                    board[i][j + 1] = enemyChar;
                return;
            }
        }
    }
}

int main() {
    initializeBoard();
    board[5][5] = 'x';
    board[4][10] = 'x';
    board[7][14] = 'x';

    char command;
    while (true) {
        system("cls"); // Use "clear" if on Linux/macOS
        printBoard();
        cout << "Command (a=left, d=right, f=fire, m=move fire, e=move enemy, q=quit): ";
        cin >> command;

        if (command == 'a')
            movePlayerLeft();
        else if (command == 'd')
            movePlayerRight();
        else if (command == 'f')
            fireBullet();
        else if (command == 'm')
            moveFire(1);
        else if (command == 'e')
            moveEnemy('x', "left");
        else if (command == 'q')
            break;
    }

    return 0;
}
