#include <iostream>
using namespace std;
main() {
    string movie;
    double adult_price, child_price, percent, total, donated, remaining;
    int adult_sold, child_sold;
    cout << "Enter movie name: ";
    cin >> movie;
    cout << "Enter adult ticket price: ";
    cin >> adult_price;
    cout << "Enter child ticket price: ";
    cin >> child_price;
    cout << "Enter number of adult tickets sold: ";
    cin >> adult_sold;
    cout << "Enter number of child tickets sold: ";
    cin >> child_sold;
    cout << "Enter percentage of revenue to donate: ";
    cin >> percent;
    total = (adult_price * adult_sold) + (child_price * child_sold);
    donated = total * (percent / 100);
    remaining = total - donated;
    cout << "Total revenue: " << total << "\nRemaining amount after donation: " << remaining;
    
}