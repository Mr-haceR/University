#include <iostream>
using namespace std;
main() {
    int i, p, chance;
    cout << "Enter the number of imposters: ";
    cin >> i;
    cout << "Enter the total number of players: ";
    cin >> p;
    chance = (100 * i) / p;
    cout << "Chance of being an imposter: " << chance << "%";
    
}