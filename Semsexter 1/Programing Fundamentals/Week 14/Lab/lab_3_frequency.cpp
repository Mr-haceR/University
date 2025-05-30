#include <iostream>
#include <fstream>

using namespace std;

int calculateFrequency(string filename) {
    int frequency = 0;
    char character;
    fstream file;
    file.open(filename, ios::in);
    if (!file.is_open()) {
        file.open(filename, ios::out);
        if (file.is_open()) {
            string text =  "S\nThe sun peeked over the horizon,\npainting the sky in shades of orange and pink.\nBirds chirped cheerfully,\nwelcoming the new day.\nSarah sat on her porch,\nsipping a cup of steaming coffee.\nShe took a deep breath,\nfilling her lungs with the crisp morning air,\nand smiled as the world woke up around her.";
            file << text;
            file.close();
            file.open(filename, ios::in);
        }
        else {
            cout << "Failed to create " << filename;
        }
    }
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