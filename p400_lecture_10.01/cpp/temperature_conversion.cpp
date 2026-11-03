// temperature_conversion.cpp -- a conversion operator
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double value = 0.0) { celsius = value; }

    // Converts a Temperature to its Celsius value
    operator double() const { return celsius; }
};

int main() {
    Temperature today(21.5);

    double reading = today;          // initialization
    double warmer = today + 1.5;     // arithmetic

    cout << reading << " " << warmer << endl;
    return 0;
}
