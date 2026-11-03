// plus_equal_chain.cpp -- operator+= returns the calling object
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double value = 0.0) { celsius = value; }

    Temperature& operator+=(const Temperature& rhs) {
        celsius += rhs.celsius;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Temperature& t);
};

int main() {
    Temperature a(20.0);
    Temperature b(5.0);

    cout << (a += b) << " " << a << endl;
    return 0;
}

ostream& operator<<(ostream& out, const Temperature& t) {
    out << t.celsius;
    return out;
}
