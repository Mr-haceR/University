#include <iostream>
#include <string>
using namespace std;

int A[3][3], B[3][3], C[3][3];

void print(char matrix) {
    if (matrix == 'A')  {
        for (int i = 0; i < 3; i++) {
            cout << "[";
            for (int j = 0; j < 3; j++) {
                cout << A[i][j];
                if (j < 2) cout << "\t";
            }
            cout << "]\n";
        }
    }
    else if (matrix == 'B') {
        for (int i = 0; i < 3; i++) {
            cout << "[";
            for (int j = 0; j < 3; j++) {
                cout << B[i][j];
                if (j < 2) cout << "\t";
            }
            cout << "]\n";
        }
    }
    else if (matrix == 'C') {
        for (int i = 0; i < 3; i++) {
            cout << "[";
            for (int j = 0; j < 3; j++) {
                cout << C[i][j];
                if (j < 2) cout << "\t";
            }
            cout << "]\n";
        }
    }
    else {
        cout << "Invalid matrix.\n";
        return;
    }
}
void calculate(char op, int order) {
    if (op == '+') {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (order == 0) C[row][col] = A[row][col] + B[row][col];
                else if (order == 1) C[row][col] = B[row][col] + A[row][col];
                else if (order == 2) C[row][col] = A[row][col] + A[row][col];
                else if (order == 3) C[row][col] = B[row][col] + B[row][col];
                else C[row][col] = 0;
            }
        }
    }
    else if (op == '-') {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (order == 0) C[row][col] = A[row][col] - B[row][col];
                else if (order == 1) C[row][col] = B[row][col] - A[row][col];
                else if (order == 2) C[row][col] = A[row][col] - A[row][col]; 
                else if (order == 3) C[row][col] = B[row][col] - B[row][col]; 
                else C[row][col] = 0;
            }
        }
    }
    else if (op == '*') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
            }
        }
        if (order == 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        else if (order == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        C[i][j] += B[i][k] * A[k][j];
                    }
                }
            }
        }
        else if (order == 2) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        C[i][j] += A[i][k] * A[k][j];
                    }
                }
            }
        }
        else if (order == 3) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        C[i][j] += B[i][k] * B[k][j];
                    }
                }
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    C[i][j] = 0;
                }
            }
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
            }
        }
    }
}
bool isIdentity(char matrixName) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (matrixName == 'A') {
                if (i == j && A[i][j] != 1) return false;
                if (i != j && A[i][j] != 0) return false;
            } else if (matrixName == 'B') {
                if (i == j && B[i][j] != 1) return false;
                if (i != j && B[i][j] != 0) return false;
            } else if (matrixName == 'C') {
                if (i == j && C[i][j] != 1) return false;
                if (i != j && C[i][j] != 0) return false;
            }
        }
    return true;
}
bool isSymmetric(char matrixName) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (matrixName == 'A' && A[i][j] != A[j][i]) return false;
            if (matrixName == 'B' && B[i][j] != B[j][i]) return false;
            if (matrixName == 'C' && C[i][j] != C[j][i]) return false;
        }
    return true;
}
bool isDiagonal(char matrixName) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                if (matrixName == 'A' && A[i][j] != 0) return false;
                if (matrixName == 'B' && B[i][j] != 0) return false;
                if (matrixName == 'C' && C[i][j] != 0) return false;
            }
        }
    return true;
}
void transpose(char matrixName) {
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) {
            if (matrixName == 'A') {
                int temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
            else if (matrixName == 'B') {
                int temp = B[i][j];
                B[i][j] = B[j][i];
                B[j][i] = temp;
            }
            else if (matrixName == 'C') {
                int temp = C[i][j];
                C[i][j] = C[j][i];
                C[j][i] = temp;
            }
        }
}
void scalarMultiply(char matrixName, int scalar) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrixName == 'A') C[i][j] = A[i][j] * scalar;
            else if (matrixName == 'B') C[i][j] = B[i][j] * scalar;
        }
    }
}

main() {
    string command;
    cout << "***********************************************************" << endl <<
            "*                    Matrix Calculator                    *" << endl << 
            "***********************************************************" << endl << endl;
    while (true) {
        cout << ">> ";
        cin >> command;
        if (command == "Exit") break;
        if ((command[0] == 'A' || command[0] == 'B') && command[1] == '=' && command[2] == '{' && command.back() == '}') {
            int matrix[3][3];
            int row = 0, col = 0, num = 0;
            bool readingNumber = false;
            bool valid = true;
            for (int i = 3; i < command.size(); i++) {
                char ch = command[i];
                if (isdigit(ch)) {
                    num = num * 10 + (ch - '0');
                    readingNumber = true;
                } 
                else if (ch == ',' || ch == '}') {
                    if (readingNumber) {
                        if (row >= 3) {
                            valid = false;
                            break;
                        }
                        matrix[row][col] = num;
                        col++;
                        if (col == 3) {
                            col = 0;
                            row++;
                        }
                        num = 0;
                        readingNumber = false;
                    }
                    if (ch == '}' && i != command.size() - 1) {
                        valid = false;
                        break;
                    }
                } 
                else {
                    valid = false;
                    break;
                }
            }
            if (!valid || row != 3 || col != 0) {
                cout << "Invalid input format or number of elements. Use: A={1,2,...,9}\n";
                continue;
            }
            if (command[0] == 'A') {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        A[i][j] = matrix[i][j];
                    }
                }
            } 
            else {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        B[i][j] = matrix[i][j];
                    }
                }
            }
        }
        else if (command == "print(A)") {
            print('A');
        }
        else if (command == "print(B)") {
            print('B');
        }
        else if (command == "print(C)") {
            print('C');
        }
        else if (command == "C=A+B") {
            calculate('+', 0);
        }
        else if (command == "C=A-B") {
            calculate('-', 0);
        }
        else if (command == "C=A*B") {
            calculate('*', 0);
        }
        else if (command == "C=B+A") {
            calculate('+', 1);
        }
        else if (command == "C=B-A") {
            calculate('-', 1);
        }
        else if (command == "C=B*A") {
            calculate('*', 1);
        }
        else if (command == "C=A+A") {
            calculate('+', 2);
        }
        else if (command == "C=A-A") {
            calculate('-', 2);
        }
        else if (command == "C=A*A") {
            calculate('*', 2);
        }
        else if (command == "C=B+B") {
            calculate('+', 3);
        }
        else if (command == "C=B-B") {
            calculate('-', 3);
        }
        else if (command == "C=B*B") {
            calculate('*', 3);
        }
        else if (command == "isIdentity(A)") {
            if (isIdentity('A')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isIdentity(B)") {
            if (isIdentity('B')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isIdentity(C)") {
            if (isIdentity('C')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isSymmetric(A)") {
            if (isSymmetric('A')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isSymmetric(B)") {
            if (isSymmetric('B')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isSymmetric(C)") {
            if (isSymmetric('C')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isDiagonal(A)") {
            if (isDiagonal('A')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isDiagonal(B)") {
            if (isDiagonal('B')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "isDiagonal(C)") {
            if (isDiagonal('C')) cout << "True\n";
            else cout << "False\n";
        }
        else if (command == "transpose(A)") {
            transpose('A');
        }
        else if (command == "transpose(B)") {
            transpose('B');
        }
        else if (command == "transpose(B)") {
            transpose('C');
        }
        else if (command[0] == 'C' && command[1] == '=' && command[3] == '*' && ((command.back() == 'A' || command.back() == 'B') || (isdigit(command.back())))) {
            if (isdigit(command[2])) {
                scalarMultiply(command.back(), command[2] - '0');
            }
            else if (isdigit(command.back())) {
                scalarMultiply(command[2], command.back() - '0');
            }
        }
        else {
            cout << "Unknown command.\n";
        }
    }
}