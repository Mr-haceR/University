#include <iostream>
using namespace std;
main() {
    double veg_price, fruit_price, veg_kg, fruit_kg, earnings;
    cout << "Enter vegetable price per kg: ";
    cin >> veg_price;
    cout << "Enter fruit price per kg: ";
    cin >> fruit_price;
    cout << "Enter total kg of vegetables: ";
    cin >> veg_kg;
    cout << "Enter total kg of fruits: ";
    cin >> fruit_kg;
    earnings = ((veg_price * veg_kg) + (fruit_price * fruit_kg)) / 1.94;
    cout << "Total earnings in Rps: " << earnings;
    
}