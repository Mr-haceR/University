#include <iostream>

using namespace std;

main() {
    int holidays, total_play_time, diff, hours, minutes;
    cout << "Holidays: ";
    cin >> holidays;
    total_play_time = (365 - holidays) * 63 + holidays * 127;
    diff = 30000 - total_play_time;
    string result = "Tom sleeps well";
    if (diff < 0) {
        result = "Tom will run away";
    }
    cout << result << endl;
    hours = diff / 60;
    minutes = diff % 60;
    if (hours < 0) {
        hours = -hours;
    }
    if (minutes < 0) {
        minutes = -minutes;
    }
    cout << hours << " hours and " << minutes << " minutes ";
    if (diff > 0) {
        cout << "less for play";
    }
    if (diff < 0) {
        cout << "for play";
    }
}