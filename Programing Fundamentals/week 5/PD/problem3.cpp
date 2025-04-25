#include <iostream>

using namespace std;

main() {
    string name;
    float english_marks, maths_marks, chemistry_marks, social_sciences_marks, biology_marks, total;
    float percentage;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter English marks: ";
    cin >> english_marks;  
    cout << "Enter Maths marks: ";
    cin >> maths_marks;
    cout << "Enter Chemistry marks: ";
    cin >> chemistry_marks;
    cout << "Enter Social Sciences marks: ";
    cin >> social_sciences_marks;
    cout << "Enter Biology marks: ";
    cin >> biology_marks;
    total = english_marks + maths_marks + chemistry_marks + social_sciences_marks + biology_marks;
    percentage = total / 500 * 100;
    cout << "Student Name: " << name << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Obtained percentage: " << percentage << "%" << endl;
    if (percentage >= 90.0 && percentage <= 100.0) {
        cout << "Obtained grade: A+";
    }
    else if (percentage >= 80.0 && percentage < 90.0) {
        cout << "Obtained grade: A";
    }
    else if (percentage >= 70.0 && percentage < 80.0) {
        cout << "Obtained grade: B+";
    }
    else if (percentage >= 60.0 && percentage < 70.0) {
        cout << "Obtained grade: B";
    }
    else if (percentage >= 50.0 && percentage < 60.0) {
        cout << "Obtained grade: C";
    }
    else if (percentage >= 40.0 && percentage < 50.0) {
        cout << "Obtained grade: D";
    }
    else if (percentage < 40.0) {
        cout << "Obtained grade: F";
    }
} 