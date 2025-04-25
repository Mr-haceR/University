#include <iostream>
 
using namespace std;

main() {
    /*
      1
      12
      123
      1234
      12345
    */
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
    /*
      1
      22
      333
      4444
      55555
    */
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
    cout << endl;
    /*
      1
      11
      112
      1123
    */
    for (int i = 1; i <= 4; i++) {
        int n1 = 1, n2 = 1, next;
        for (int j = 1; j <= i; j++) {
            next = n1+n2;
            cout << n1;
            n1 = n2;
            n2 = next;
        }
        cout << endl;
    }
    cout << endl;
    /*
      A
      BC
      DEF
      GHIJ
      KLMNO
      PQRSTU
      VWXYZAB
      CDEFGHIJ
    */
    char x = 'A'; // 65
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= i; j++) {
            cout << x;
            if (x == 'Z') {
                x = 'A';
                continue;
            }
            x++;
        }
        cout << endl;
    }
    cout << endl;

    /*
      12345
      1234
      123
      12
      1
    */

    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;

    /*
      5 4 3 2 1
      4 3 2 1
      3 2 1
      2 1
      1
    */
    for (int i = 5; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    /*
      1
      1 2
      1 2 3
      1 2 3 4
      1 2 3 4 5
      1 2 3 4
      1 2 3
      1 2
      1
    */
    for (int j = 1; j <= 5; j++) {
        for (int k = 1; k <= j; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
    for (int j = 4; j >= 1; j--) {
        for (int k = 1; k <= j; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;

    /*
      * * * * *
      * * * *
      * * *
      * *
      *
      * *
      * * *
      * * * *
      * * * * * 
    */
    for (int i = 1; i <= 9; i++) {
        int stars;
        if (i <= 5) {
            stars = 5 - i + 1;
        }
        else {
            stars = i - 5 + 1;
        }
        for (int j = 1; j <= stars; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

