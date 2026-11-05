// constructor_throws.cpp -- what is cleaned up when a constructor throws
#include <iostream>
#include <stdexcept>
#include <string>
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

class Title {
private:
    string text;

public:
    Title(const string& t) : text(t) { }
    ~Title() { cout << "Title destroyed" << endl; }
};

class Course {
private:
    Title title;
    Roster roster;

public:
    Course(const string& t, int seats) : title(t), roster(seats) { }
    ~Course() { cout << "Course destroyed" << endl; }
};

int main() {
    try {
        Course empty("CISP 400", 0);
    } catch (const runtime_error& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}
