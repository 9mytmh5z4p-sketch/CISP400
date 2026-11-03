// ambiguous_plus.cpp -- two conversion routes and how explicit breaks the tie
// Remove explicit from operator double and t + 5.0 becomes ambiguous.
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double value = 0.0) { celsius = value; }
    explicit operator double() const { return celsius; }

    friend Temperature operator+(const Temperature& a, const Temperature& b);
};

int main() {
    Temperature t(20.0);
    Temperature warmer = t + 5.0;
    cout << static_cast<double>(warmer) << endl;
    return 0;
}

Temperature operator+(const Temperature& a, const Temperature& b) {
    return Temperature(a.celsius + b.celsius);
}
