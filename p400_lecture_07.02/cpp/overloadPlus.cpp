// overloadPlus.cpp
#include <iostream>
using namespace std;

class Point2D {
private:
    int x;
    int y;

public:
    Point2D(int xValue = 0, int yValue = 0);
    Point2D operator+(const Point2D& other) const;
    void print() const;
};

Point2D::Point2D(int xValue, int yValue) {
    x = xValue;
    y = yValue;
}

Point2D Point2D::operator+(const Point2D& other) const {
    return Point2D(x + other.x, y + other.y);
}

void Point2D::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

int main() {
    Point2D first(2, 3);
    Point2D second(4, 1);
    Point2D total = first + second;

    total.print();

    return 0;
}