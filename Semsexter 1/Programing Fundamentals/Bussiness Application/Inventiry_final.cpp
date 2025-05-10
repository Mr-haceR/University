#include <iostream>

using namespace std;

// Globol data structures START

char choice;

// Globol data structures END

// Function prototypes START

void printHeader();
char landingPage();
void clearScreen();

// Function prototypes END

// main STRAT

main() {
    choice = landingPage();
}

// main END

// Function definitions START

void printHeader() {
    cout << endl << "*******************************************************************************************" << endl <<
                    "*                        Smart Inventory & Order Management System                        *" << endl <<
                    "*******************************************************************************************" << endl << endl;
}

char landingPage() {
    clearScreen();
    printHeader();
    cout << "1. Login" << endl <<
            "2. Sign Up" << endl <<
            "3. Exit" << endl << endl <<
            "Enter your choice: ";
    cin >> choice;
    return choice;
}

void clearScreen() {
    system("cls");
}

// Function definition END