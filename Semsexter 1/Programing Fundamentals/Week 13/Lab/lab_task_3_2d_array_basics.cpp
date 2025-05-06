#include <iostream>
#include <cctype>

using namespace std;

// A
int blueToyotaCars(int cars[][5]) {
    return cars[1][3];
}

// B
int redCars(int cars[][5]) {
    int total_red_cars = 0;
    for (int rows = 0; rows < 5; rows++) {
        total_red_cars += cars[rows][0];
    }
    return total_red_cars;
}

// C
int nissanCars(int cars[][5]) {
    int total_nissan_cars = 0;
    for (int col = 0; col < 5; col++) {
        total_nissan_cars += cars[2][col];
    }
    return total_nissan_cars;
}

// D
int converter(int cars[][5], string color) {
    for (int i = 0; color[i] != '\0'; i++) {
        color[i] = tolower(color[i]);
    }
    int sum = 0, col;
    if (color == "red") {
        col = 0;
    } else if (color == "black") {
        col = 1;
    } else if (color == "brown") {
        col = 2;
    } else if (color == "blue") {
        col = 3;
    } else if (color == "gray") {
        col = 4;
    } else {
        cout << "\nInvalid Color.\n";
    }
    for (int row = 0; row < 5; row++) {
        sum += cars[row][col];
    }
    return sum;
}

void rowToCol(int cars[][5]) {
    for (int col = 0; col < 5; col++) {
        for (int row = 0; row < 5; row++) {
            cout << cars[row][col] << "\t";
        }
        cout << endl;
    }
}

main() {
    int cars[5][5] = {
    //         Red    Black   Brown   Blue    Gray  
    /*Suzuki*/{10,   7,       12,     10,     4   }, 
    /*Toyota*/{18,   11,      15,     17,     2   },
    /*Nissan*/{23,   19,      12,     16,     14  },
    /*BMW   */{7,    12,      16,     0,      2   },
    /*Audi  */{3,    5,       6,      2,      1   } 
    };
    cout << "Blue Toyotas Available: " << blueToyotaCars(cars) << endl;
    cout << "Total Red cars: " << redCars(cars) << endl;
    cout << "Total Nissan cars: " << nissanCars(cars) << endl;
    cout << "Enter color: ";
    string color;
    cin >> color;
    cout << color << " cars: " << converter(cars, color) << endl;
    cout << "Transpose: " << endl;
    rowToCol(cars);
}