#include <iostream>

using namespace std;

main() {
    bool running = true;
    bool limitReached = false;
    int studentsAdded = 0;
    string studentName1, studentName2, studentName3;
    float MAtric_Marks1, MAtric_Marks2, MAtric_Marks3;
    float Inter_Marks1, Inter_Marks2, Inter_Marks3;
    float Entry_Test_Marks1, Entry_Test_Marks2, Entry_Test_Marks3;
    while (running) {
        int choice;
        
        cout << endl;
        cout << "******************************************************************" << endl;
        cout << "*             University Admission Managemnt System              *" << endl;
        cout << "******************************************************************" << endl << endl;
        cout << "Main Menu >" << endl;
        cout << "----------------------------------" << endl;
        cout << "Select an option from the following:" << endl;
        cout << "1. Add New Student" << endl;
        cout << "2. View All Student" << endl;
        cout << "3. Print the Records in Merit Order" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            if (!limitReached) {
                if (studentsAdded == 0) {
                    cout << "Enter Student Name: ";
                    cin >> studentName1;
                    cout << "Enter Matric Marks: ";
                    cin >> MAtric_Marks1;
                    cout << "Enter Inter Marks: ";
                    cin >> Inter_Marks1;
                    cout << "Enter Entry Test Marks: ";
                    cin >> Entry_Test_Marks1;
                    studentsAdded++;
                }
                else if (studentsAdded == 1) {
                    cout << "Enter Student Name: ";
                    cin >> studentName2;
                    cout << "Enter Matric Marks: ";
                    cin >> MAtric_Marks2;
                    cout << "Enter Inter Marks: ";
                    cin >> Inter_Marks2;
                    cout << "Enter Entry Test Marks: ";
                    cin >> Entry_Test_Marks2;
                    studentsAdded++;
                }
                else if (studentsAdded == 2) {
                    cout << "(Add New Student)" << endl;
                    cout << "Enter Student Name: ";
                    cin >> studentName3;
                    cout << "Enter Matric Marks: ";
                    cin >> MAtric_Marks3;
                    cout << "Enter Inter Marks: ";
                    cin >> Inter_Marks3;
                    cout << "Enter Entry Test Marks: ";
                    cin >> Entry_Test_Marks3;
                    studentsAdded++;
                }
                else {
                    cout << endl << "Students Limit Reached!" << endl;
                }
            }
        }
        else if (choice == 2) {
            if (studentsAdded == 0) {
                cout << endl << "No students are added!" << endl;
            }
            else if (studentsAdded == 1) {
                cout << endl << "Student:" << endl;
                cout << "Name: " << studentName1 << endl << 
                        "Matric Marks: " << MAtric_Marks1 << endl << 
                        "Inter Marks: " << Inter_Marks1 << endl <<
                        "Entry Test Marks: " << Entry_Test_Marks1 << endl;
            }
            else if (studentsAdded == 2) {
                cout << endl << "Student:" << endl;
                cout << "Name: " << studentName1 << endl << 
                        "Matric Marks: " << MAtric_Marks1 << endl << 
                        "Inter Marks: " << Inter_Marks1 << endl <<
                        "Entry Test Marks: " << Entry_Test_Marks1 << endl;
                cout << endl << "Student:" << endl;
                cout << "Name: " << studentName2 << endl << 
                        "Matric Marks: " << MAtric_Marks2 << endl << 
                        "Inter Marks: " << Inter_Marks2 << endl <<
                        "Entry Test Marks: " << Entry_Test_Marks2 << endl; 
            }
            else if (studentsAdded == 3) {
                cout << endl << "Student:" << endl;
                cout << "Name: " << studentName1 << endl << 
                        "Matric Marks: " << MAtric_Marks1 << endl << 
                        "Inter Marks: " << Inter_Marks1 << endl <<
                        "Entry Test Marks: " << Entry_Test_Marks1 << endl;
                cout << endl << "Student:" << endl;
                cout << "Name: " << studentName2 << endl << 
                        "Matric Marks: " << MAtric_Marks2 << endl << 
                        "Inter Marks: " << Inter_Marks2 << endl <<
                        "Entry Test Marks: " << Entry_Test_Marks2 << endl;
                cout << endl << "Student:" << endl;
                cout << "Name: " << studentName3 << endl << 
                        "Matric Marks: " << MAtric_Marks3 << endl << 
                        "Inter Marks: " << Inter_Marks3 << endl <<
                        "Entry Test Marks: " << Entry_Test_Marks3 << endl;
            }
        }
        else if (choice == 3) {
            if (studentsAdded == 0) {
                cout << endl << "No students are added!" << endl;
            }
            else if (studentsAdded == 1) {
                float total1 = (MAtric_Marks1 / 1100 * .17 + Inter_Marks1 / 1100 * .50 + Entry_Test_Marks1 / 400 * .33) * 100;
                cout << endl << studentName1 << "\t" << total1 << "%" << endl;
            }
            else if (studentsAdded == 2) {
                float total1 = (MAtric_Marks1 / 1100 * .17 + Inter_Marks1 / 1100 * .50 + Entry_Test_Marks1 / 400 * .33) * 100;
                float total2 = (MAtric_Marks2 / 1100 * .17 + Inter_Marks2 / 1100 * .50 + Entry_Test_Marks2 / 400 * .33) * 100;
                if (total1 > total2) {
                    cout << endl << studentName1 << "\t" << total1 << "%" << endl;
                    cout << endl << studentName2 << "\t" << total2 << "%" << endl;
                }
                else {
                    cout << endl << studentName2 << "\t" << total2 << "%" << endl;
                    cout << endl << studentName1 << "\t" << total1 << "%" << endl;
                }
            }
            else if (studentsAdded == 3) {
                float total1 = (MAtric_Marks1 / 1100 * .17 + Inter_Marks1 / 1100 * .50 + Entry_Test_Marks1 / 400 * .33) * 100;
                float total2 = (MAtric_Marks2 / 1100 * .17 + Inter_Marks2 / 1100 * .50 + Entry_Test_Marks2 / 400 * .33) * 100;  
                float total3 = (MAtric_Marks3 / 1100 * .17 + Inter_Marks3 / 1100 * .50 + Entry_Test_Marks3 / 400 * .33) * 100;
                if (total1 > total2 && total1 > total3) {
                    cout << studentName1 << "\t" << total1 << "%" << endl;
                    if (total2 > total3) {
                        cout << studentName2 << "\t" << total2 << "%" << endl;
                        cout << studentName3 << "\t" << total3 << "%" << endl;
                    }
                    else {
                        cout << studentName3 << "\t" << total3 << "%" << endl;
                        cout << studentName2 << "\t" << total2 << "%" << endl;
                    }
                }
                else if (total2 > total1 && total2 > total3) {
                    cout << studentName2 << "\t" << total2 << "%" << endl;
                    if (total1 > total3) {
                        cout << studentName1 << "\t" << total1 << "%" << endl;
                        cout << studentName3 << "\t" << total3 << "%" << endl;
                    }
                    else {
                        cout << studentName3 << "\t" << total3 << "%" << endl;
                        cout << studentName1 << "\t" << total1 << "%" << endl;
                    }
                }
                else if (total3 > total1 && total3 > total2){
                    cout << studentName3 << "\t" << total3 << "%" << endl;
                    if (total1 > total2) {
                        cout << studentName1 << "\t" << total1 << "%" << endl;
                        cout << studentName2 << "\t" << total2 << "%" << endl;
                    }
                    else {
                        cout << studentName2 << "\t" << total2 << "%" << endl;
                        cout << studentName1 << "\t" << total1 << "%" << endl;
                    }
                }
            }
        }
        else if (choice == 4) {
            running = false;   
        }
        else {
            cout << endl << "Invalid Choice!" << endl;
        }
    }
}