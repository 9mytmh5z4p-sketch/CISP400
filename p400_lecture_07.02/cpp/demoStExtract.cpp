// demoStExtract.cpp
#include <iostream>
using namespace std;

class Rectangle;

istream& operator>>(istream& input, Rectangle& rectangle);

class Rectangle {
    friend istream& operator>>(istream& input,
                               Rectangle& rectangle);
private:
    int width;
    int height;

public:
    void print() const;

};

void Rectangle::print() const {
    cout << "Rectangle: " << width << " x " << height << endl;
}

int main() {
    Rectangle room;

    cout << "Enter width and height: ";
    cin >> room;

    room.print();

    return 0;
}

istream& operator>>(istream& input, Rectangle& rectangle) {
    input >> rectangle.width >> rectangle.height;
    return input;
}