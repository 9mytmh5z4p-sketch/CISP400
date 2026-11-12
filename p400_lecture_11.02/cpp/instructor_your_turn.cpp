// instructor_your_turn.cpp
// Your Turn solution: Instructor inherits from Person and adds an office.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int id;

public:
    Person(const string& n, int i) : name(n), id(i) { }

    void print() const {
        cout << name << " (" << id << ")" << endl;
    }
};

class Instructor : public Person {
private:
    string office;

public:
    Instructor(const string& n, int i, const string& o)
        : Person(n, i), office(o) { }

    string getOffice() const { return office; }
};

int main() {
    Instructor ng("Ng", 7, "BS 214");
    ng.print();
    cout << "Office: " << ng.getOffice() << endl;
    return 0;
}
