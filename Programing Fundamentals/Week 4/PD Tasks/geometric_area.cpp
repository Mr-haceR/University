#include <iostream>

using namespace std;

main() {
    string shape;
    cout << "Enter the geometric shape name: ";
    cin >> shape;
    if (shape == "Square") {
        float side;
        cin >> side;
        cout << "Area: " << side*side;
    }
    if (shape == "Rectangle") {
        float length, width;
        cin >> length;
        cin >> width;
        cout << "Area: " << length*width;
    }
    if (shape == "Circle") {
        float radius;
        cin >> radius;
        cout << "Area: " << 3.14*(radius*radius);
    }
    if (shape == "Triangle") {
        float base_length, height;
        cin >> base_length;
        cin >> height;
        cout << "Area: " << 0.5*base_length*height;
    }
}