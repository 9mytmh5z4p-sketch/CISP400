// demoStInsertNoFriend.cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;

public:
    Rectangle(int widthValue = 0, int heightValue = 0);
    int height;
};

ostream& operator<<(ostream& output, const Rectangle& rectangle);

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
    // output << rectangle.width << " x " << rectangle.height;
    // The line above would fail because width is private.
    output << "height = " << rectangle.height;
    return output;
}
