#include <iostream>
using namespace std;
main() {
    double bag_size, cost, area, cost_per_pound, cost_per_sqft;
    cout << "Enter size of fertilizer bag (pounds): ";
    cin >> bag_size;
    cout << "Enter cost of the bag: ";
    cin >> cost;
    cout << "Enter area covered by the bag (square feet): ";
    cin >> area;
    cost_per_pound = cost / bag_size;
    cost_per_sqft = cost / area;
    cout << "Cost per pound: " << cost_per_pound << "\nCost per square foot: " << cost_per_sqft;
    
}