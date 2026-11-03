// zero_degrees.cpp -- Temperature to double to bool
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double value = 0.0) { celsius = value; }
    operator double() const { return celsius; }
};

int main() {
    Temperature freezing(0.0);

    if (freezing) {
        cout << "warm" << endl;
    } else {
        cout << "cold" << endl;
    }
    return 0;
}
