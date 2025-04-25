#include <iostream>

using namespace std;

main() {
    string login;
    cout << "Who is there? ";
    cin >> login;
    if (login == "Admin") {
        string password;
        cout << "Password: ";
        cin >> password;
        if (password == "TheMaster") {
            cout << "Welcome!";
        }
        else if (password == "") {
            cout << "Cancelled";
        }
        else {
            cout << "Wrong password";
        }
    }
    else if (login == "") {
        cout << "Cancelled";
    } 
    else {
        cout << "I don't know you";
    }
}