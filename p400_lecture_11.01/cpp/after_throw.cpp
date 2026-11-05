// after_throw.cpp -- statements after a throw are skipped
#include <iostream>
#include <stdexcept>
using namespace std;

class Roster {
private:
    int seats;

public:
    explicit Roster(int capacity) {
        if (capacity <= 0) {
            throw runtime_error("capacity must be positive");
        }
        seats = capacity;
    }
};

int main() {
    try {
        cout << "A" << endl;
        Roster r(-5);
        cout << "B" << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << "C" << endl;
    return 0;
}
