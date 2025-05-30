#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

const int TOTAL_USERS = 10;
string usernames[TOTAL_USERS], passwords[TOTAL_USERS], roles[TOTAL_USERS], uniqueId[TOTAL_USERS];
int userCount = 0;

string choice;

void clearScreen();
void printHeader();
string landingPage();
void addUser(string role, string username, string password);
string signUp();
string signIn();
void loadData();
void saveData();

int main() {
    loadData();
    while (true) {
        choice = landingPage();
        if (choice == "1") {
            if (userCount == 0) {
                cout << endl << "No users in the system yet. Press any key to continue...";
                getch();
                continue;
            }
            string x = signIn();
            if (x != "!") {
                cout << endl << "Welcome " << x << ". Press any key to continue...";
                getch();
            } else {
                cout << endl << "Wrong Information! Press any key to continue...";
                getch();
            }
        } else if (choice == "2") {
            while (true) {
                if (userCount == TOTAL_USERS) {
                    cout << endl << "Max user limit reached. Press any key to continue...";
                    getch();
                    break;
                }
                choice = signUp();
                if (choice == "1") {
                    string name, pass;
                    cin.ignore(); // clear leftover newline
                    cout << endl << "Enter your Username: ";
                    getline(cin, name);
                    cout << "Enter Password: ";
                    getline(cin, pass);
                    addUser("ADMIN", name, pass);
                } else if (choice == "2") {
                    string name, pass;
                    cin.ignore(); // clear leftover newline
                    cout << endl << "Enter your Username: ";
                    getline(cin, name);
                    cout << "Enter Password: ";
                    getline(cin, pass);
                    addUser("CUSTOMER", name, pass);
                } else if (choice == "3") {
                    break;
                } else {
                    cout << endl << "Invalid Choice! Press any key to try again...";
                    getch();
                }
            }
        } else if (choice == "3") {
            saveData();
            break;
        } else {
            cout << endl << "Invalid Choice! Press any key to try again...";
            getch();
        }
    }
    return 0;
}

void printHeader() {
    cout << "*******************************************************************" << endl <<
            "*                      Business Application                       *" << endl <<
            "*******************************************************************" << endl;
}

string landingPage() {
    clearScreen();
    printHeader();
    cout << endl << "1. Sign In" << endl <<
                    "2. Sign Up" << endl <<
                    "3. Exit" << endl <<
                    "Enter your choice: ";
    cin >> choice;
    return choice;
}

string signUp() {
    clearScreen();
    printHeader();
    cout << endl << "1. As an Admin." << endl <<
                    "2. As a Customer." << endl <<
                    "3. Go back." << endl << endl <<
                    "Enter your choice: ";
    cin >> choice;
    return choice;
}

void addUser(string role, string username, string password) {
    usernames[userCount] = username;
    passwords[userCount] = password;
    roles[userCount] = role;
    uniqueId[userCount] = to_string(userCount);
    cout << endl << role << " Added: " << usernames[userCount] << endl <<
            "Your unique ID is " << userCount << ". Press any key to continue...";
    getch();
    userCount++;
}

string signIn() {
    string username, password, id;
    clearScreen();
    printHeader();
    cout << endl << "Enter Username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password); 
    cout << "Enter the unique Id assigned to you at Sign Up: ";
    cin >> id;
    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == username && passwords[i] == password && uniqueId[i] == id) {
            return username;
        }
    }
    return "!";
}

void clearScreen() {
    system("cls");
}

void loadData() {
    fstream file;
    file.open("users.txt", ios::in);
    if (!file.is_open()) {
        file.open("users.txt", ios::out);
        if (file.is_open()) {
            file << '0' << endl;
            file.close();
            file.open("users.txt", ios::in);
        } else {
            cout << "Failed to create users.txt";
            return;
        }
    }
    string record;
    string userCount_s;
    getline(file, userCount_s);
    userCount = stoi(userCount_s);
    for (int i = 0; i < userCount; i++) {
        getline(file, usernames[i]);
        getline(file, passwords[i]);
        getline(file, roles[i]);
        getline(file, uniqueId[i]);
    }
    file.close();
}

void saveData() {
    fstream file;
    file.open("users.txt", ios::out);
    file << userCount << endl;
    for (int i = 0; i < userCount; i++) {
        file << usernames[i] << endl
             << passwords[i] << endl
             << roles[i] << endl
             << uniqueId[i] << endl;
    }
    file.close();
}
