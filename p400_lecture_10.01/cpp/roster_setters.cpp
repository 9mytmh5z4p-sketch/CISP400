// roster_setters.cpp -- setters that chain by returning *this
// Change both return types to Roster (no &) and the capacity is lost.
#include <iostream>
#include <string>
using namespace std;

class Roster {
private:
    string name;
    int seats;

public:
    explicit Roster(int capacity) { name = "Unnamed"; seats = capacity; }

    Roster& setName(const string& value) { name = value; return *this; }
    Roster& setCapacity(int value) { seats = value; return *this; }

    void print() const { cout << name << ": " << seats << " seats" << endl; }
};

int main() {
    Roster section(25);
    section.setName("CISP 400").setCapacity(30);
    section.print();
    return 0;
}
