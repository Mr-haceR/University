#include <iostream>
#include <fstream>

using namespace std;

int countlines(string filename) {
    fstream file;
    int count = 0;
    file.open(filename, ios::in);
    string line;
    while (!file.eof()) {
        getline(file, line);
        count++;
    }
    file.close();
    return count;
}

main() {
    cout << countlines("Task1.txt");
}