#include <iostream>

using namespace std;

void largestColumnFirst(int M[][5], int rows) {
    int maxSum = -1, maxColIndex = 0;
    for (int col = 0; col < 5; col++) {
        int colSum = 0;
        for (int row = 0; row < rows; row++) {
            colSum += M[row][col];
        }
        if (colSum > maxSum) {
            maxSum = colSum;
            maxColIndex = col;
        }
    }
    if (maxColIndex != 0) {
        for (int row = 0; row < rows; row++) {
            int temp = M[row][0];
            M[row][0] = M[row][maxColIndex];
            M[row][maxColIndex] = temp;
        }
    }
}

void printMatrix(int M[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

main() {
    int rows;
    cout << "Enter row size: ";
    cin >> rows;
    int M[rows][5];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> M[i][j];
        }
    }
    cout << endl << "Original Matrix:" << endl;
    printMatrix(M, rows);
    largestColumnFirst(M, rows);
    cout << endl << "Matrix after largest column moved to first:" << endl;
    printMatrix(M, rows);
}
