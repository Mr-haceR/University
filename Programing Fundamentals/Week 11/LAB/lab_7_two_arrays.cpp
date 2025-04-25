#include <iostream>

using namespace std;

main()
{
    int arr1[2];
    int num;
    cout << "Enter the number of 2nd arrays element: ";
    cin >> num;
    int arr2[num];

    for (int i = 0; i < 2; i++) {
        cout << "Enter the element of 1st array: ";
        cin >> arr1[i];
    }
    for (int i = 0; i < num; i++) {
        cout << "Enter the element of 2nd array: ";
        cin >> arr2[i];
    }
    cout << arr1[0] << " ";
    for (int i = 0; i < num; i++) {
        cout << arr2[i] << " ";
    }
    cout << arr1[1] << " ";
}