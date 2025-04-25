#include <iostream>

using namespace std;

main() {
    string movies[5] = {"Gladiator", "StarWars", "Terminator", "TakingLives", "TombRider"};
    string name;
    int ticket_price = 500;
    cout << "Enter movie name: ";
    cin >> name;
    for (int i = 0; i < 5; i++) {
        if (movies[i] == name) {
            if (i % 2 != 0) {
                ticket_price -= ticket_price * 0.05;
            }
            else {
                ticket_price -= ticket_price * 0.10;
            }
        }
    }   
    cout << "Ticket Price: " << ticket_price;
}