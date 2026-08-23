#include <iostream>
using namespace std;

double area(double side);
double area(double length, double width);
double area(double base, double height, char shapeCode);

int main() {
    cout << area(4.0) << endl;
    cout << area(5.0, 3.0) << endl;
    cout << area(6.0, 2.5, 't') << endl;
    return 0;
}

double area(double side) {
    return side * side;
}

double area(double length, double width) {
    return length * width;
}

double area(double base, double height, char shapeCode) {
    if (shapeCode == 't') {
        return base * height / 2.0;
    }
    return base * height / 2.0;
}
