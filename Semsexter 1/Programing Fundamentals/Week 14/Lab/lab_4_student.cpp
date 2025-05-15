#include <iostream>
#include <fstream>

using namespace std;

int count = 0;

void getstudentdetails(string names[], int ages[], float matricmarks[], float fscmarks[], float ecatmarks[], int count, string filename) {
    fstream file;
    file.open(filename, ios::out);
    for (int i = 0; i < count; i++) {
        file << "Name: " << names[i] << endl;
        file << "Age: " << ages[i] << endl;
        file << "Matric Marks: " << matricmarks[i] << endl;
        file << "FSC Marks: " << fscmarks[i] << endl;
        file << "ECAT Marks: " << ecatmarks[i] << endl;
        file << endl;
    }
    file.close();
}

void studentdetails(string names[], int ages[], float matricmarks[], float fscmarks[], float ecatmarks[], int count) {
    string filename;
    cout << "Enter the filename to save the data: ";
    cin >> filename;
    while (true) {
        cout << "Enter the name of student: ";
        cin >> names[count];
        cout << "Enter the age of student: ";
        cin >> ages[count];
        cout << "Enter the matric marks of student: ";
        cin >> matricmarks[count];
        cout << "Enter the fsc marks of student: ";
        cin >> fscmarks[count];
        cout << "Enter the ecat marks of student: ";
        cin >> ecatmarks[count];
        count++;
        cout << "Enter no to stop or yes to continue: ";
        string choice;
        cin >> choice;
        if (choice == "no")
        {
            break;
        }
    }
    getstudentdetails(names, ages, matricmarks, fscmarks, ecatmarks, count, filename);
}


main() {
    int size = 20;
    string names[size];
    int ages[size];
    float matricmarks[size];
    float fscmarks[size];
    float ecatmarks[size];
    studentdetails(names, ages, matricmarks, fscmarks, ecatmarks, count);
}