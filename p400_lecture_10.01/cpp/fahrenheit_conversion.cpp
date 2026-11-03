// fahrenheit_conversion.cpp -- converting one class into another
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double value = 0.0) { celsius = value; }
    operator double() const { return celsius; }
};

class Fahrenheit {
private:
    double degrees;

public:
    Fahrenheit(double value = 32.0) { degrees = value; }

    // Converts a Celsius Temperature to Fahrenheit
    Fahrenheit(const Temperature& t) { degrees = t * 9.0 / 5.0 + 32.0; }

    double value() const { return degrees; }
};

int main() {
    Temperature today(20.0);
    Fahrenheit report = today;
    cout << report.value() << endl;
    return 0;
}
