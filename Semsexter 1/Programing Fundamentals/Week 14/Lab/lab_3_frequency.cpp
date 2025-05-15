#include <iostream>
#include <fstream>

using namespace std;

int calculateFrequency(string filename) {
    int frequency = 0;
    char character;
    fstream file;
    file.open(filename, ios::in);
    string firstLine;
    getline(file, firstLine);
    while (!file.eof()) {
        file >> character;
        if (character == firstLine[0] || (character == firstLine[0] - 32 || character == firstLine[0] + 32)) {
            frequency++;
        }
    }
    return frequency;
}

main() {
    cout << calculateFrequency("Task3.txt");
}