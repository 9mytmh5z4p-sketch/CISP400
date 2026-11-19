// ta_print_both.cpp
// TeachingAssistant overrides print() and calls both parents' versions.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string major;

public:
    Student(const string& n, const string& m) : name(n), major(m) { }
    void print() const { cout << name << ", " << major << endl; }
};

class Employee {
private:
    string name;
    double salary;

public:
    Employee(const string& n, double s) : name(n), salary(s) { }
    void print() const { cout << name << ", paid " << salary << endl; }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(const string& n, const string& m, double s)
        : Student(n, m), Employee(n, s) { }

    void print() const {
        Student::print();
        Employee::print();
    }
};

int main() {
    TeachingAssistant sam("Sam", "CS", 1200.00);
    sam.print();
    return 0;
}
