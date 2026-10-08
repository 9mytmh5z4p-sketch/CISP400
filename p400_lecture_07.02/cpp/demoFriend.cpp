// demoFriend.cpp
#include <iostream>
using namespace std;

class Temperature;	// forward declaration

void showTemperature(const Temperature& value);

class Temperature {
    friend void showTemperature(const Temperature& value);
private:
    double celsius;

public:
    Temperature(double value = 0.0);

};

Temperature::Temperature(double value) {
    celsius = value;
}

int main() {
    Temperature reading(21.5);

    showTemperature(reading);

    return 0;
}

void showTemperature(const Temperature& value) {
    cout << value.celsius << " degrees Celsius" << endl;
}

/* Demo of forward declaration for class Temperature if we
put the class below the function prototype
*/