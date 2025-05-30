#include <iostream>

using namespace std;

int countIdenticalArrays(int arr[][3], int rows) {
    int arr1[3];
    for (int i = 0; i < 3; i++) {
        arr1[i] = arr[0][i];
    }
    int n = 0, x = 0;
    for (int row = 1; row < rows; row++) {
        for (int col = 0; col < 3; col++) {
            if (arr1[col] == arr[row][col]) {
                n++;
            }
        }
        if (n == 3) {
            x++;
        }
        n = 0;
    }
    if (x == 0) return x;
    return x + 1;
}

main() {
    int rows;
    cout << " Enter number of rows for the array: ";
    cin >> rows;
    int arr[rows][3];
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "Enter element at position [" << row << "]" << "[" << col << "]";
            cin >> arr[row][col];
        }
    }
    cout << "The of identical rows in array is : " << countIdenticalArrays(arr, rows);
}
