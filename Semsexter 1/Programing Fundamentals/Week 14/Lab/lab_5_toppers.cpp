#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int count = 0;

void saveToFile(string names[], int adNumbers[], float percentages[], string fileName) {
    fstream file, file1;
    file.open("Task5.txt", ios::in);
    file1.open(fileName, ios::out);
    string line;
    while(!file.eof()) {
        getline(file, line);
        getline(file, line);
        getline(file, line);
        float p = stof(line);
        if (p  > 70.0) {
            file1 << "Name: " << names[count] << "\n" << 
                     "Admission Number: " << adNumbers[count] << "\n" <<
                     "Percentage: " << percentages[count] << "\n\n";
        }
        count++;
    }
    file1.close();
    file.close();
}

void getStudentDetails(string names[], int adNumbers[], float percentages[], string fileName) {
    fstream file;
    file.open(fileName, ios::in);
    string line;
    while (!file.eof()) {
        getline(file, line);
        names[count] = line;
        getline(file, line);
        adNumbers[count] = stoi(line);
        getline(file, line);
        percentages[count] = stof(line);
        count++;
    }
    count = 0;
    file.close();
}

main() {
    int size = 2;
    string names[size];
    int adNumbers[size];
    float percentages[size];
    getStudentDetails(names, adNumbers, percentages, "Task5.txt");
    saveToFile(names, adNumbers, percentages, "topperStudents.txt");
}