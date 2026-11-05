// roster_exception.cpp -- a constructor that refuses with an exception
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
    int size() const { return seats; }
};

int main() {
    try {
        Roster sections(-5);
        cout << sections.size() << " seats" << endl;
    } catch (const runtime_error& e) {
        cout << "Could not build roster: " << e.what() << endl;
    }

    cout << "Program continues" << endl;
    return 0;
}
