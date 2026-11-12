// base_throws.cpp
// When the Person part refuses, the Student is never built.
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    Person(const string& n) : name(n) {
        if (n.empty()) {
            throw runtime_error("name cannot be empty");
        }
        cout << "Person built: " << name << endl;
    }
};

class Student : public Person {
private:
    string major;

public:
    Student(const string& n, const string& m) : Person(n), major(m) {
        cout << "Student built" << endl;
    }
};

int main() {
    try {
        Student ava("Ava", "CS");
        Student nobody("", "Math");
        cout << "after nobody" << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
