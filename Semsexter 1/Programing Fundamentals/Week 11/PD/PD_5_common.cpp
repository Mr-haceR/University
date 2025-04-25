#include <iostream>

using namespace std;

main() {
    string str1, str2;
    int common_count = 0;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter seconf string: ";
    cin >> str2;
    for (int i = 0; str1[i] != '\0'; i++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                common_count++;
                str2[j] = ' '; 
                break;
            }
        }
    }   
    cout << "Common characters: " << common_count;
}