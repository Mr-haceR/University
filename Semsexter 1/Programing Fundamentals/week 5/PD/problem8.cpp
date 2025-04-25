#include <iostream>

using namespace std;

main() {
    int exam_hour, exam_minute, arrival_hour, arrival_minute;
    cout << "Exam Starting Time(hours): ";
    cin >> exam_hour;
    cout << "Exam Starting Time(minutes): ";
    cin >> exam_minute;
    cout << "Student hour of arrival: ";
    cin >> arrival_hour;
    cout << "Student minutes of arrival: ";
    cin >> arrival_minute;
    int exam_time = exam_hour * 60 + exam_minute;
    int arrival_time = arrival_hour * 60 + arrival_minute;
    int difference = arrival_time - exam_time;
    if (difference > 0) {
        cout << "Late" << endl;
        if (difference < 60) {
            cout << difference << " minutes after the start" << endl;
        } 
        else {
            int hours = difference / 60;
            int minutes = difference % 60;
            cout << hours << ":";
            if (minutes < 10) {
                 cout << "0";
            }
            cout << minutes << " hours after the start" << endl;
        }
    } 
    else if (difference >= -30) {
        cout << "On time" << endl;
        if (difference != 0) {
            cout << -difference << " minutes before the start" << endl;
        }
    } 
    else {
        cout << "Early" << endl;
        if (-difference < 60) {
            cout << -difference << " minutes before the start" << endl;
        }
        else {
            int hours = -difference / 60;
            int minutes = -difference % 60;
            cout << hours << ":";
            if (minutes < 10) {
                 cout << "0";
            }
            cout << minutes << " hours before the start" << endl;
        }
    }
} 