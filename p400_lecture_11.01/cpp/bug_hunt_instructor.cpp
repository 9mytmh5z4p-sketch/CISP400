// bug_hunt_instructor.cpp
// CISP 400 Lecture 11.01 activity: Bug Hunt (instructor copy)
// All three bugs fixed and exceptions added.
// FIX and PART 2 comments mark the changes.

#include <iostream>
#include <stdexcept>   // PART 2: runtime_error lives here
#include <string>
#include <vector>
using namespace std;

class Roster {
public:
    // FIX 2: explicit stops an int from quietly becoming a Roster
    explicit Roster(int capacity) : capacity(capacity) {
        if (capacity < 1) {
            throw runtime_error("capacity must be at least 1");   // PART 2
        }
    }

    void add(const string& name) {
        if (size() >= capacity) {
            // PART 2
            throw runtime_error("roster is full: " + name + " not added");
        }
        names.push_back(name);
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
    // FIX 1: Roster has no default constructor, so build it in the initializer list
    Course(const string& t, int seats) : title(t), roster(seats) {}

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
    // FIX 3: declare the instructor first so it outlives the course
    // that points to it
    Instructor adjunct("Ng");

    Course oop("CISP 400", 3);
    oop.enroll("Ava");
    oop.enroll("Ben");
    oop.setInstructor(&adjunct);

    oop.print();
    printOpenSeats(oop.getRoster());   // FIX 2: pass the roster, not its seat count

    // PART 2: a full roster refuses the student
    try {
        oop.enroll("Cam");
        oop.enroll("Dee");   // fourth student, only three seats
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << "\n";
    }

    // PART 2: a bad capacity stops the course from being built
    try {
        Course empty("CISP 401", 0);
        empty.print();   // never runs
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << "\n";
    }

    oop.print();
    return 0;
}
