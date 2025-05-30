#include <iostream>
#include <fstream>

using namespace std;

int countlines(string filename) {
    fstream file;
    int count = 0;
    file.open(filename, ios::in);
    if (!file.is_open()) {
        file.open(filename, ios::out);
        if (file.is_open()) {
            string text =  "The sun peeked over the horizon,\npainting the sky in shades of orange and pink.\nBirds chirped cheerfully,\nwelcoming the new day.\nSarah sat on her porch,\nsipping a cup of steaming coffee.\nShe took a deep breath,\nfilling her lungs with the crisp morning air,\nand smiled as the world woke up around her.";
            file << text;
            file.close();
            file.open(filename, ios::in);
        }
        else {
            cout << "Failed to create " << filename;
        }
    }
    string line;
    while (!file.eof()) {
        getline(file, line);
        count += line.length();
    }
    file.close();
    return count;
}

main() {
    cout << countlines("Task2.txt");
}