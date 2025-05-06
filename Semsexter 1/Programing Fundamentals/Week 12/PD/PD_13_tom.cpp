#include <iostream>
#include <cmath>

using namespace std;

int minutesPlayed(int holidays) {
    return (365 - holidays) * 63 + holidays * 127;
}

void minutesTOHoursMinutes(int minutes) {
    if (minutes < 0) {
        minutes = abs(minutes);
    }
    cout << minutes / 60 << " hours" << " " << minutes - ((minutes / 60) * 60) << " Minutes";
}

main() {
    int holidays;
    cout << "Holidays: ";
    cin >> holidays;
    if (minutesPlayed(holidays) < 30000) {
        cout << "Tom sleeps well" << endl;
    }
    else {
        cout << "Tom will run away" << endl;
    }
    minutesTOHoursMinutes(30000 - minutesPlayed(holidays));
}