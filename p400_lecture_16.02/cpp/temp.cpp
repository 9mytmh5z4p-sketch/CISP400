//temp.cpp
#include <iostream>
#include <iomanip>
using namespace std;

// ─────────────────────────────────────────────
//  Temperature class
//  - setCelsius()   : inline setter
//  - getFahrenheit(): non-inline getter
//  - getKelvin()    : non-inline getter
// ─────────────────────────────────────────────
class Temperature {
private:
    double celsius;

public:
    // Inline setter — defined inside the class body makes it implicitly inline
    void setCelsius(double c) { celsius = c; }

    // Non-inline getters — declared here, defined outside the class below
    double getFahrenheit() const;
    double getKelvin() const;
};

// ─────────────────────────────────────────────
//  Non-inline member function definitions
// ─────────────────────────────────────────────

// Celsius to Fahrenheit: F = (C × 9/5) + 32
double Temperature::getFahrenheit() const {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Celsius to Kelvin: K = C + 273.15
double Temperature::getKelvin() const {
    return celsius + 273.15;
}

// ─────────────────────────────────────────────
//  Main
// ─────────────────────────────────────────────
int main() {
    Temperature temp;
    double input;
    cout << fixed << setprecision(2);


    cout << "Enter a temperature in Celsius: ";
    cin >> input;

    temp.setCelsius(input);

    cout << "\nConversion Results:\n";
    cout << "  Celsius:    " << input               << " C\n";
    cout << "  Fahrenheit: " << temp.getFahrenheit() << " F\n";
    cout << "  Kelvin:     " << temp.getKelvin()     << " K\n";

    return 0;
}