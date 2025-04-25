#include <iostream>

using namespace std;

main() {
    int cargo_count;
    float average_price, minibus_cargo = 0, truck_cargo = 0, train_cargo = 0, total_tons = 0;
    float p1, p2, p3;
    cout << "Enter the cargo count: ";
    cin >> cargo_count;
    if (cargo_count >= 1 && cargo_count <= 1000) {
        for (int i = 0; i < cargo_count; i = i + 1) {
            int tonnage;
            cout << "Enter the tonnage of the current cargo[1-1000]: ";
            cin >> tonnage;
            total_tons = total_tons + tonnage;
            if (tonnage >= 0 && tonnage <= 3) {
                minibus_cargo = minibus_cargo + tonnage;
            }
            else if (tonnage > 3 && tonnage <= 11) {
                truck_cargo = truck_cargo + tonnage;
            }
            else if (tonnage > 11) {
                train_cargo = train_cargo + tonnage;
            }
        }
        p1 = (minibus_cargo / total_tons) * 100;
        p2 = (truck_cargo / total_tons) * 100;
        p3 = (train_cargo / total_tons) * 100;
        average_price = ((minibus_cargo * 200) + (truck_cargo * 175) + (train_cargo * 120)) / total_tons;
        cout << "Average Price per ton: " <<  average_price << " dollars." << endl;
        cout << "Percentage of cargo carried by minibus: " << p1 << "%" << endl <<
                "Percentage of cargo carried by truck: " << p2 << "%" << endl <<
                "Percentage of cargo carried by train: " << p3 << "%";
    }
    else {
        cout << "Cargo count should be between 1 and 1000.";
    }
}