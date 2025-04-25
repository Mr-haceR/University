#include <iostream>

using namespace std;

main() {
      string country;
      cout << "Enter your country: ";
      cin >> country;
      if (!(country == "Germany" || country == "Australia")) {
        cout << "You should come to visit these sometime!";
      }
} 