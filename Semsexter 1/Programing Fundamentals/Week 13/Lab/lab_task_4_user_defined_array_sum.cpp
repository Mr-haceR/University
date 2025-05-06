#include <iostream>

using namespace std;

void printSum(int matrix[][3], int rowSize) {
    int sum = 0;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    cout << "The sum of the elements in the matrix is: " << sum << endl;
}

main() {
    int rowSize;
    cout << "Enter the number of rows for the matrix: ";
    cin >> rowSize;
    int matrix[rowSize][3];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    printSum(matrix, rowSize);
}