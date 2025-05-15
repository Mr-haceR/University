#include <iostream>
#include <conio.h>

using namespace std;

bool player1Wins = false;
bool gameOver = false;
int count = 0;

void printHeader();
void printBoard(char board[][3]);
void checkRow(char board[][3]);
void checkColumn(char board[][3]);
void checkDiagonal(char board[][3]);
void clearScreen();

main() {
    string player1, player2;
    bool player1Turn = true;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    clearScreen();
    system("color 02");
    printHeader();
    cout << "Enter Player 1 name: ";
    cin >> player1;
    cout << "Enter Player 2 name: ";
    cin >> player2;
    cout << endl << player1 << " (X) vs " << player2  << " (O)" << endl << "Press any key to start the game...";
    getch();

    while (!gameOver) {
        clearScreen();
        printHeader();
        printBoard(board);
        int row, col;
        if (player1Turn) {
            cout << endl << endl << player1 << "'s turn (X)" << endl << "Enter row and column with space(i.e. x y): ";
            cin >> row >> col;
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << endl << "Invalid move. Press any key to try again..." << endl;
                getch();
                continue;
            }
            else {
                board[row][col] = 'X';
                player1Turn = false;
            }
        } 
        else {
            cout << endl << endl << player2 << "'s turn (O)" << endl << "Enter row and column with space(i.e. x y): ";
            cin >> row >> col;
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << endl << "Invalid move. Press any key to try again..." << endl;
                getch();
                continue;
            }
            else {
                board[row][col] = 'O';
                player1Turn = true;
            }
        }
        checkRow(board);
        checkColumn(board);
        checkDiagonal(board);
        if (player1Wins) {
            clearScreen();
            printHeader();
            printBoard(board);
            cout << endl << endl << player1 << " wins!" << endl << endl << "Press any key to exit...";
            getch();
        }
        else if (count == 8) {
            clearScreen();
            printHeader();
            printBoard(board);
            cout << endl << endl << "It's a draw!" << endl << endl << "Press any key to exit...";
            getch();
        }
        else if (gameOver) {
            clearScreen();
            printHeader();
            printBoard(board);
            cout << endl << endl << player2 << " wins!" << endl << endl << "Press any key to exit...";
            getch();
        }
        count++;
    }
}

void checkRow(char board[][3]) {
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == 'X') {
                player1Wins = true;
                gameOver = true;
            } else if (board[row][0] == 'O') {
                gameOver = true;
            }
        }
    }
}

void checkColumn(char board[][3]) {
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == 'X') {
                player1Wins = true;
                gameOver = true;
            } else if (board[0][col] == 'O') {
                gameOver = true;
            }
        }
    }
}

void checkDiagonal(char board[][3]) {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            player1Wins = true;
            gameOver = true;
        } else if (board[0][0] == 'O') {
            gameOver = true;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            player1Wins = true;
            gameOver = true;
        } else if (board[0][2] == 'O') {
            gameOver = true;
        }
    }
}

void printHeader() {
    cout << endl << "*****************************************************************" << endl <<
                    "*                          Tic Tac Toe                          *" << endl <<
                    "*****************************************************************" << endl << endl;
}

void printBoard(char board[][3]) {
    cout << "     0     1     2" << endl << endl;
    for (int row = 0; row < 3; row++) {
        cout << row << "    ";
        for (int col = 0; col < 3; col++) {
            cout << board[row][col];
            if (col < 2) {
                cout << "  |  ";
            }
            
        }
        if (row < 2) {
            cout << endl << "   -----------------" << endl;
        }
    }
}

void clearScreen() {
    system("cls"); 
}