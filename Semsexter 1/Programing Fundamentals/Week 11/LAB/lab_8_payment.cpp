#include <iostream>
using namespace std;

main()
{
    float amount[4] = {0.25, 0.10, 0.05, 0.01};
    float change[4];
    int sum = 0;
    float total_due;
    cout << "Enter the total amount due: ";
    cin >> total_due;
    cout << "Enter the number of coins of denomination ";
    for (int i = 0; i < 4; i++) {
        cin >> change[i];
        sum += change[i] * amount[i];
    }
    if (sum >= total_due) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}