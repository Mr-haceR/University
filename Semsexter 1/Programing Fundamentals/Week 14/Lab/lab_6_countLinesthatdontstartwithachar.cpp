#include <iostream>
#include <fstream>

using namespace std;

int countLines(string fileName) {
    int count = 0;
    fstream file;
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        file.open(fileName, ios::out);
        if (file.is_open()) {
            string text = "f\nYou're on a journey that's uniquely yours,\nfilled with challenges and triumphs that shape who you are.\nEmbrace the learning process,\nfor it's not just about grades but about the growth you experience along the way.\nBelieve in your abilities,\nfor within you lies incredible potential waiting to be unleashed.\nEvery setback is a lesson,\nevery hurdle a chance to grow stronger.\nKeep your dreams vivid and your determination fierce.\nYou're crafting a future that's shaped by your dedication and hard work.\nSo,\nstay curious,\nstay passionate,\nand keep reaching for the stars because your efforts today will pave the way for a\nbrighter tomorrow.\nYou've got this!";
            file << text;
            file.close();
            file.open(fileName, ios::in);
        }
        else {
            cout << "Failed to create " << fileName;
        }
    }
    char character;
    string line;
    getline(file, line);
    character = line[0];
    while (!file.eof()) {
        getline(file, line);
        char firstChar = line[0];
        if (firstChar != character) {
            count++;
        }
    }
    return count;
}

main() {
    cout << countLines("Task6.txt");
}