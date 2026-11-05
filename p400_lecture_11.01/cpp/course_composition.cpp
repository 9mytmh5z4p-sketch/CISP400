// course_composition.cpp -- composition with a member initializer list
#include <iostream>
#include <string>
using namespace std;

class Roster {
private:
    int seats;

public:
    explicit Roster(int capacity) { seats = capacity; }
    int size() const { return seats; }
};

class Course {
private:
    string name;
    Roster roster;

public:
    Course(const string& n, int seats) : name(n), roster(seats) { }

    void print() const {
        cout << name << ": " << roster.size() << " seats" << endl;
    }
};

int main() {
    Course cisp("CISP 400", 30);
    cisp.print();

    Course copy = cisp;        // copies name and roster; no copy code written
    copy.print();
    return 0;
}
