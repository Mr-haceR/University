#include <iostream>
using namespace std;
main() {
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;
    int add, multiply, subtract, result;
    cout << "Enter first number: "; cin >> a;
    cout << "Enter second number: "; cin >> b;
    cout << "Enter third number: "; cin >> c;
    cout << "Enter fourth number: "; cin >> d;
    cout << "Enter fifth number: "; cin >> e;
    cout << "Enter sixth number: "; cin >> f;
    cout << "Enter seventh number: "; cin >> g;
    cout << "Enter eighth number: "; cin >> h;
    cout << "Enter ninth number: "; cin >> i;
    cout << "Enter tenth number: "; cin >> j;
    cout << "Enter eleventh number: "; cin >> k;
    cout << "Enter twelfth number: "; cin >> l;
    cout << "Enter thirteenth number: "; cin >> m;
    cout << "Enter fourteenth number: "; cin >> n;
    cout << "Enter fifteenth number: "; cin >> o;
    add = a + b + c + d + e;
    multiply = f * g * h * i * j;
    subtract = k - l - m - n - o;
    result = (add + multiply) - subtract;
    cout << "Final result: " << result;
}