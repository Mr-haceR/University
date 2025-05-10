#include <iostream>
using namespace std;


void printMatrix(int matrix[3][3]) {
    cout << "\nThe matrix you entered is: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

bool isIdentityMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && matrix[i][j] != 1) {
                return false;
            }
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

main() {
    int matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    printMatrix(matrix);
    if (isIdentityMatrix(matrix)) {
        cout << "The matrix is an identity matrix." << endl;
    } else {
        cout << "The matrix is not an identity matrix." << endl;
    }
}