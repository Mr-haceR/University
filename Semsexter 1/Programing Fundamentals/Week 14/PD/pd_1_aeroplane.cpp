#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

const int ROWS = 13, COLUMNS = 6;
char seats[ROWS][COLUMNS] = {
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'}
};

bool loaded = false;
string choice;

int columnLetterToNumber(char col);
void clearScreen();
void printHeader();
string landingPage();
void loadSeats();
void reserveSeat();
void printSeats();
void saveSeats();
void newArrangement();
bool createFileIfNotExist();

int main() {
    if (!createFileIfNotExist()) return 1;
    loadSeats();
    while (true) {
        choice = landingPage();
        if (choice == "1") {
            loadSeats();
            clearScreen();
            printHeader();
            cout << endl << "Seat Arrangement Loaded. Press any key to continue...";
            getch();
        }
        else if (choice == "2") {
            if (!loaded) {
                loadSeats();
            }
            reserveSeat();
        }
        else if (choice == "3") {
            if (!loaded) {
                cout << endl << "Load data first! Press any key to continue...";
                getch();
                continue;
            }
            printSeats();
            cout << endl << "Press any key to continue...";
            getch();
        }
        else if (choice == "4") {
            saveSeats();
            clearScreen();
            printHeader();
            cout << endl << "Data Saved... Press any key to continue...";
            getch();
        }
        else if (choice == "5") {
            newArrangement();
        }
        else if (choice == "6") {
            saveSeats();
            break;
        }
        else {
            cout << endl << "Invalid Choice! Press any key to try again...";
            getch();
        }
    }
}

bool createFileIfNotExist() {
    fstream file;
    file.open("seats.txt", ios::in);
    if (!file.is_open()) {
        file.open("seats.txt", ios::out);
        if (file.is_open()) {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    file << seats[i][j] << " ";
                }
                file << "\n";
            }
            file.close();
        }
        else {
            cout << "Failed to create seats.txt";
            return false;
        }
    }
    file.close();
    return true;
}

int columnLetterToNumber(char col) {
    return (toupper(col) - 'A') + 1;
}

void printHeader() {
    cout << "*******************************************************************" << endl <<
            "*                    Aeroplane Seat Management                    *" << endl <<
            "*******************************************************************" << endl;
}

string landingPage() {
    clearScreen();
    printHeader();
    cout << endl << "1. Load the reserved seats arrangement from the file." << endl <<
                    "2. Ask the user for ticket type and desired seat." << endl << 
                    "3. Print the reserved seats arrangement." << endl <<
                    "4. Store the reserved seats arrangement in the file." << endl << 
                    "5. New Plane seats arrangement." << endl << 
                    "6. Exit." << endl << endl <<
                    "Enter your choice: ";
    cin >> choice;
    return choice;
}

void loadSeats() {
    fstream file;
    file.open("seats.txt", ios::in);
    while (!file.eof()) {
        for (int row = 0; row < ROWS; row++) {
            for (int column = 0; column < COLUMNS; column++) {
                file >> seats[row][column];
            }
        }
    }
    file.close();
    loaded = true;
}

void reserveSeat() {
    int row, column; 
    char columnL;
    string type;
    printSeats();
    cout << endl << "Enter type(first, bussiness or economy): ";
    cin >> type;
    
    if (type == "first") {
        while (true) {
            cout << "Enter row(1-2): ";
            cin >> row;
            if (row < 1 || row > 2) {
                cout << endl << "Seat not in first class. Press any key to try again...";
                getch();
                continue;
            }
            cout << "Enter column(A-F): ";
            cin >> columnL;
            column = columnLetterToNumber(columnL);
            if (column < 1 || column > 6) {
                cout << endl << "Invalid column! Press any key to continue...\n";
                getch();
            }
            break;
        }
    }
    else if (type == "bussiness") {
        while (true) {
            cout << "Enter row(3-7): ";
            cin >> row;
            if (row < 3 || row > 7) {
                cout << endl << "Seat not in bussiness class. Press any key to try again...";
                getch();
                continue;
            }
            cout << "Enter column(A-F): ";
            cin >> columnL;
            column = columnLetterToNumber(columnL);
            if (column < 1 || column > 6) {
                cout << endl << "Invalid column! Press any key to continue...\n";
                getch();
            }
            break;
        }
    }
    else if (type == "economy") {
        while (true) {
            cout << "Enter row(8-" << ROWS << "): ";
            cin >> row;
            if (row < 8 || row > ROWS) {
                cout << endl << "Seat not in economy class. Press any key to try again...";
                getch();
                continue;
            }
            cout << "Enter column(A-F): ";
            cin >> columnL;
            column = columnLetterToNumber(columnL);
            if (column < 1 || column > 6) {
                cout << endl << "Invalid column! Press any key to continue...\n";
                getch();
            }
            break;
        }
    }
    else {
        cout << endl << "Invalid Class. Press any key to continue...";
        getch();
    }

    if (seats[row-1][column-1] == 'X') { 
        cout << endl << "Seat already reserved. Press any key to continue...";
        getch();
    }
    else {
        seats[row-1][column-1] = 'X';
    }
}

void printSeats() {
    clearScreen();
    printHeader();
    cout << endl << "         A  B  C  D  E  F" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "Row ";
        if (i + 1 < 10) cout << " ";
        cout << (i + 1) << " ";
        for (int j = 0; j < COLUMNS; j++) {
            cout << "  " << seats[i][j];
        }
        cout << endl;
    }
}

void saveSeats() {
    fstream file;
    file.open("seats.txt", ios::out);
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            file << seats[row][column] << " ";
        }
        file << endl;
    }
    file.close();
}

void newArrangement() {
    clearScreen();
    printHeader();
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            seats[row][column] = '*';
        }
    }
    cout << endl << "Everything reset... New Plane seat arrangement initialized. Saved & Reloaded." << endl 
         << endl << "Press any key to contnue...";
    getch();
    saveSeats();
    loadSeats();
}

void clearScreen() {
    system("cls");
}