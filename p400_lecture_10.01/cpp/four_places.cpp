// four_places.cpp -- the four places a conversion fires
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
    Fahrenheit(const Temperature& t) { degrees = t * 9.0 / 5.0 + 32.0; }
    double value() const { return degrees; }
};

void show(Fahrenheit f);
Fahrenheit forecast(Temperature t);

int main() {
    Temperature today(20.0);
    Fahrenheit a = today;              // copy initialization
    Fahrenheit b;
    b = today;                         // assignment
    show(today);                       // passing to a function
    Fahrenheit c = forecast(today);
    cout << a.value() << " " << b.value() << " " << c.value() << endl;
    return 0;
}

void show(Fahrenheit f) {
    cout << f.value() << endl;
}

Fahrenheit forecast(Temperature t) {
    return t;                          // return
}
