// demoFriendClass.cpp
#include <iostream>
using namespace std;

class Square;

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle();
    void convert(const Square& square);
    int area() const;
};

class Square {
    friend class Rectangle;
private:
    int side;

public:
    Square(int value = 0);
};

int main() {
    Rectangle rectangle;
    Square square(4);

    rectangle.convert(square);

    cout << rectangle.area() << endl;

    return 0;
}

Rectangle::Rectangle() {
    width = 0;
    height = 0;
}

Square::Square(int value) {
    side = value;
}

void Rectangle::convert(const Square& square) {
    width = square.side;
    height = square.side;
}

int Rectangle::area() const {
    return width * height;
}
