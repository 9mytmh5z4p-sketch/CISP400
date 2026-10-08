// demoStInsert.cpp
#include <iostream>
using namespace std;

class Rectangle;

ostream& operator<<(ostream& output, const Rectangle& rectangle);

class Rectangle {
    friend ostream& operator<<(ostream& output,
                               const Rectangle& rectangle);
private:
    int width;
    int height;

public:
    Rectangle(int widthValue = 0, int heightValue = 0);
};

Rectangle::Rectangle(int widthValue, int heightValue) {
    width = widthValue;
    height = heightValue;
}

int main() {
    Rectangle room(8, 5);

    cout << room << endl;

    return 0;
}

ostream& operator<<(ostream& output, const Rectangle& rectangle) {
    output << rectangle.width << " x " << rectangle.height;
    return output;
}