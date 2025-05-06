#include <iostream>

using namespace std;

int howManyStickers(int n) {
    return (n * n) * 6;
}
main() {
    int n;
    cout << "Enter the side length of the Rubik's cube: ";
    cin >> n;
    cout << "Number of stickers needed: " << howManyStickers(n);
}