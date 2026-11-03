// roster_hijack.cpp -- a converting constructor hijacks a function call
// Add explicit to the constructor and the call in main stops compiling.
#include <iostream>
using namespace std;

class Roster {
private:
    int seats;
    int enrolled;

public:
    Roster(int capacity) { seats = capacity; enrolled = 0; }

    void print() const {
        cout << enrolled << " students, " << seats << " seats" << endl;
    }
};

void showSection(const Roster& roster);

int main() {
    int sectionNumber = 30;
    showSection(sectionNumber);    // meant: section 30
    return 0;
}

void showSection(const Roster& roster) {
    roster.print();
}
