// demoFriend2.cpp
#include <iostream>
using namespace std;

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

void showTemperature(const Temperature& value);

int main() {
    Temperature reading(21.5);

    showTemperature(reading);

    return 0;
}

void showTemperature(const Temperature& value) {
    cout << value.celsius << " degrees Celsius" << endl;
}