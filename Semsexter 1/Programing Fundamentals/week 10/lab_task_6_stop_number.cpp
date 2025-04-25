#include <iostream>

using namespace std;

main() {
    int N, M, S;
    cout << "Enter value of N: ";
    cin >> N;
    cout << "Enter value of M: ";
    cin >> M;
    cout << "Enter the stop number(S): ";
    cin >> S;
    if (N >= 0 && N < M) {
        if (M <= 10000) {
            if (S >= N && S <= M) {
                for (int i = M; i >= N; i--) {
                    int remainder2 = i - (2 * (i / 2));
                    int remainder3 = i - (3 * (i / 3));
                    if (remainder2 == 0 && remainder3 == 0) {
                        if (i == S) {
                            break;
                        }
                        else {
                            cout << i << " ";
                        }
                    }
                }
            }
            else {
                cout << "Invalid input: N <= S <= M condition not met.";
            }
        }
        else {
            cout << "Invalid input: M <= 10000 condition not met.";
        }
    }
    else {
        cout << "Invalid inputs: 0 <= N < M condition not met.";
    }
}