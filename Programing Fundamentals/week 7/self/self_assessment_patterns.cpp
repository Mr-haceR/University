#include <iostream>

using namespace std;

main() {
    /*
        *
        **
        ***
        ****
        *****
        ******
        *******
        ********
        *********
        **********
    */
    for (int i = 1; i <= 10; i = i + 1) {
        for (int j = 1; j <= i; j = j + 1) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    /*
        **********
        *********
        ********
        *******
        ******
        *****
        ****
        ***
        **
        *
    */
    for (int i = 10; i >= 1; i = i - 1) {
        for (int j = 1; j <= i; j = j + 1) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    /*
        **********
         *********
          ********
           *******
            ******
             *****
              ****
               ***
                **
                 *
    */
    for (int i = 10; i >= 1; i = i - 1) {
        for (int j = 1; j <= 10-i; j = j + 1) {
            cout << " ";
        }
        for (int k = 1; k <= i; k = k + 1) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    /*
                 *
                **
               ***
              ****
             *****
            ******
           *******
          ********
         *********
        **********
    */
    for (int i = 1; i <= 10; i = i + 1) {
        for (int j = 1; j <= 10-i; j = j + 1) {
            cout << " ";
        }
        for (int k = 1; k <= i; k = k + 1) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}