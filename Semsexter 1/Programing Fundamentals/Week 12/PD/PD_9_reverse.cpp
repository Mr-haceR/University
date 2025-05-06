#include <iostream>

using namespace std;

void reverse(string x) {
    if (x == "true" || x == "True") {
        cout << "False";
    }
    else if (x == "false" || x == "False") {
        cout << "True";
    }
    else {
        cout << "Invalid input!";
    }
}

main() {
    string inp;
    cout << "Enter true or false: ";
    cin >> inp;
    reverse(inp);
}