#include <iostream>

using namespace std;

main() {
    string vowels = "aeiouAEIOU";
    string str;
    int vowel_count = 0;
    cout << "Enter a string: ";
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; vowels[j] != '\0'; j++) {
            if (str[i] == vowels[j]) {
                vowel_count++;
            }
        }
    }
    cout << vowel_count;
}