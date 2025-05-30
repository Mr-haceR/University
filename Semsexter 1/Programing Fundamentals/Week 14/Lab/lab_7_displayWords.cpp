#include <iostream>
#include <fstream>

using namespace std;

void displayWords(string fileName) {
    fstream file;
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        file.open(fileName, ios::out);
        if (file.is_open()) {
            string text = "You're on a journey that's uniquely yours,\nfilled with challenges and triumphs that shape who you are.\nEmbrace the learning process,\nfor it's not just about grades but about the growth you experience along the way.\nBelieve in your abilities,\nfor within you lies incredible potential waiting to be unleashed.\nEvery setback is a lesson,\nevery hurdle a chance to grow stronger.\nKeep your dreams vivid and your determination fierce.\nYou're crafting a future that's shaped by your dedication and hard work.\nSo,\nstay curious,\nstay passionate,\nand keep reaching for the stars because your efforts today will pave the way for a\nbrighter tomorrow.\nYou've got this!";
            file << text;
            file.close();
            file.open(fileName, ios::in);
        }
        else {
            cout << "Failed to create " << fileName;
        }
    }
    string word;
    while (!file.eof()) {
        file >> word;
        if (word.length() < 4) {
            cout << word << " ";
        }
    }
}

main() {
    displayWords("Task7.txt");
}