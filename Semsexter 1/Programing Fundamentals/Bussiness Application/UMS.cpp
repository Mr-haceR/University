#include<iostream>

using namespace std;

main(){

    string studentName1, studentName2, studentName3;
    float MAtric_Marks1, MAtric_Marks2, MAtric_Marks3;
    float Inter_Marks1, Inter_Marks2, Inter_Marks3;
    float Entry_Test_Marks1, Entry_Test_Marks2, Entry_Test_Marks3;
    int option; 
    
    cout << "******************************************************************" << endl;
    cout << "*             University Admission Managemnt System              *" << endl;
    cout << "******************************************************************" << endl;
    cout << "Main Menu >" << endl;
    cout << "Select an option from the following:" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. View All Student" << endl;
    cout << "3. Print thee Records in Merit Order" << endl;
    cout << "4. Exit" << endl;
    cout<<"Enter your choice: ";
    cin>>option;
    if (option == 1) {
        cout << "(Add New Student)" << endl;
        cout << "Enter Student Name: ";
        cin >> studentName1;
        cout << "Enter Matric Marks: ";
        cin >> MAtric_Marks1;
        cout << "Enter Inter Marks: ";
        cin >> Inter_Marks1;
        cout << "Enter Entry Test Marks: ";
        cin >> Entry_Test_Marks1;
    }
    else if (option == 2) {
        cout << "(View All Student)" << endl;
        cout << "You don't have any student record" << endl;
    }
    else if (option == 3) {
        cout << "(Records in Merit order)" << endl;
        cout << "You don't have any student record" << endl;
    }
    else if (option == 4) {
        cout << "Exit" << endl;
    }
    else {
        cout << "Invalid Option" << endl;
    }
    cout << "******************************************************************" << endl;
    cout << "*             University Admission Managemnt System              *" << endl;
    cout << "******************************************************************" << endl;
    cout << "Main Menu >" << endl;
    cout << "Select an option from the following:" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. View All Student" << endl;
    cout << "3. Print thee Records in Merit Order" << endl;
    cout << "4. Exit" << endl;
    cout<<"Enter your choice: ";
    cin>>option;
    if (option == 1) {
        cout << "(Add New Student)" << endl;
        cout << "Enter Student Name: ";
        cin >> studentName2;
        cout << "Enter Matric Marks: ";
        cin >> MAtric_Marks2;
        cout << "Enter Inter Marks: ";
        cin >> Inter_Marks2;
        cout << "Enter Entry Test Marks: ";
        cin >> Entry_Test_Marks2;
    }
    else if (option == 2) {
        cout << "(View All Student)" << endl;
        cout << "student name\tMatric Marks\tInter Marks\tEntry Test Marks" << endl;
        cout << studentName1 << "\t" << MAtric_Marks1 << "\t" << Inter_Marks1 << "\t" << Entry_Test_Marks1 << endl;
    }
    else if (option == 3) {
        cout << "(Records in Merit order)" << endl;
        cout << "You don't have any student record" << endl;
    }
    else if (option == 4) {
        cout << "Exit" << endl;
    }
    else {
        cout << "Invalid Option" << endl;
    }
    cout << "******************************************************************" << endl;
    cout << "*             University Admission Managemnt System              *" << endl;
    cout << "******************************************************************" << endl;
    cout << "Main Menu >" << endl;
    cout << "Select an option from the following:" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. View All Student" << endl;
    cout << "3. Print thee Records in Merit Order" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> option;
    if (option == 1) {
        cout << "(Add New Student)" << endl;
        cout << "Enter Student Name: ";
        cin >> studentName3;
        cout << "Enter Matric Marks: ";
        cin >> MAtric_Marks3;
        cout << "Enter Inter Marks: ";
        cin >> Inter_Marks3;
        cout << "Enter Entry Test Marks: ";
        cin >> Entry_Test_Marks3;
    }
    else if (option == 2) {
        cout << "(View All Student)" << endl;
        cout << "student name\tMatric Marks\tInter Marks\tEntry Test Marks" << endl;
        cout << studentName1 << "\t" << MAtric_Marks1 << "\t" << Inter_Marks1 << "\t" << Entry_Test_Marks1 << endl;
        cout << studentName2 << "\t" << MAtric_Marks2 << "\t" << Inter_Marks2 << "\t" << Entry_Test_Marks2 << endl;
    }
    else if (option == 3) {
        cout << "(Records in Merit order)" << endl;
        cout << "You don't have any student record" << endl;
    }
    else if (option == 4) {
        cout << "Exit" << endl;
    }
    else {
        cout << "Invalid Option" << endl;
    }
    cout << "******************************************************************" << endl;
    cout << "*             University Admission Managemnt System              *" << endl;
    cout << "******************************************************************" << endl;
    cout << "Main Menu >" << endl;
    cout << "Select an option from the following:" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. View All Student" << endl;
    cout << "3. Print thee Records in Merit Order" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";;
    cin >> option;
    if (option == 1) {
        cout << "(Add New Student)" << endl;
        cout << "You can't add more students" << endl;

    }
    else if (option == 2) {
        cout << "(View All Student)" << endl;
        cout << "student name\tMatric Marks\tInter Marks\tEntry Test Marks" << endl;
        cout << studentName1 << "\t" << MAtric_Marks1 << "\t" << Inter_Marks1 << "\t" << Entry_Test_Marks1 << endl;
        cout << studentName2 << "\t" << MAtric_Marks2 << "\t" << Inter_Marks2 << "\t" << Entry_Test_Marks2 << endl; 
        cout << studentName3 << "\t" << MAtric_Marks3 << "\t" << Inter_Marks3 << "\t" << Entry_Test_Marks3 << endl;
    }
    else if (option == 3) {
        cout << "(Records in Merit order)" << endl;
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
    else if (option == 4){
        cout << "Exit" << endl;
    }
    else {
        cout << "Invalid Option" << endl;
    }
}