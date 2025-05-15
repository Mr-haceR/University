#include <iostream>

using namespace std;

const int MAX = 10;

bool isProbabilityMatrix(float matrix[MAX][MAX], int rowSize) {
    float sum = 0;
    int x = 0;
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < rowSize; col++) {
            sum += matrix[row][col];
            if (sum >= 1.0 && sum < 1.1) {
                x++;
            }
            else {
                return false;
            }
        }
    }
    if (x == rowSize) {
        return true;
    }
    return false;
}

main() {
    int n;
    cout << "Enter n for nxn matrix: ";
    cin >> n;
    float matrix[MAX][MAX];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << "Enter the value for matrix[" << row << "][" << col << "]: ";
            cin >> matrix[row][col];
        }
    }
    cout << isProbabilityMatrix(matrix, n);
}