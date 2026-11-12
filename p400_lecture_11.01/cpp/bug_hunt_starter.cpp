// bug_hunt_starter.cpp
// CISP 400 Lecture 11.01 activity: Bug Hunt
//
// Part 1: this program has three bugs. Find and fix all three.
//   One stops it from compiling.
//   One compiles but prints the wrong answer.
//   One compiles and looks fine, but uses an object after it is gone.
//   Read the output line by line. Does every line make sense?
//
// Part 2: add exceptions to the Roster class.
//   The constructor should throw a runtime_error when capacity is less than 1.
//   add() should throw a runtime_error when the roster is full,
//   instead of quietly ignoring the student.
//   In main, catch both errors and print the message from what().

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Roster {
public:
    Roster(int capacity) : capacity(capacity) {}

    void add(const string& name) {
        if (size() < capacity) {
            names.push_back(name);
        }
    }

    int size() const { return static_cast<int>(names.size()); }
    int seats() const { return capacity; }

private:
    vector<string> names;
    int capacity;
};

class Instructor {
public:
    Instructor(const string& n) : name(n) {}
    ~Instructor() { cout << "(" << name << " has left)\n"; }
    string getName() const { return name; }

private:
    string name;
};

// Course owns its Roster (composition) and uses an Instructor (aggregation).
class Course {
public:
    Course(const string& t, int seats) {
        title = t;
        roster = Roster(seats);
    }

    void enroll(const string& student) { roster.add(student); }
    void setInstructor(Instructor* i) { teacher = i; }
    const Roster& getRoster() const { return roster; }

    void print() const {
        cout << title << ": " << roster.size() << " of " << roster.seats()
             << " seats filled, taught by "
             << (teacher ? teacher->getName() : "TBA") << "\n";
    }

private:
    string title;
    Roster roster;
    Instructor* teacher = nullptr;
};

void printOpenSeats(const Roster& r) {
    cout << "Open seats: " << r.seats() - r.size() << "\n";
}

int main() {
    Course oop("CISP 400", 3);
    oop.enroll("Ava");
    oop.enroll("Ben");

    {
        Instructor adjunct("Ng");
        oop.setInstructor(&adjunct);
    }

    oop.print();
    printOpenSeats(oop.getRoster().seats());

    return 0;
}
