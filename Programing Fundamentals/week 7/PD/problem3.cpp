#include <iostream>

using namespace std;

main() {
    int period, treated = 0, untreated = 0, doctors = 7;
    cout << "Enter the period for which you want to make calculations: ";
    cin >> period;
    if (period >= 1 && period <= 1000) {
        for (int day = 1; day <= period; day = day + 1) {
            if (day % 3 == 0 && untreated > treated) {
                doctors = doctors + 1;
            }
            int patients;
            cout << "Enter the patient count for day " << day << "[0-10000]: ";
            cin >> patients;
            if (patients > doctors) {
                treated = treated + doctors;
                untreated = untreated + (patients - doctors);
            } 
            else {
                treated = treated + patients;
            }
        }
        cout << "Treated: " << treated << endl << 
                "Untreated: " << untreated;
    }
    else {
        cout << "Period should be between 1 and 1000 days.";
    }
}