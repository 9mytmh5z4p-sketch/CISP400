// constructor_count.cpp -- a converting constructor runs without being named
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double value = 0.0) {
        celsius = value;
        cout << "Temperature(" << value << ")" << endl;
    }
};

int main() {
    Temperature today = 21.5;
    cout << "done" << endl;
    return 0;
}
