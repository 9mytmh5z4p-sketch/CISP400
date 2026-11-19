// diamond_twice.cpp
// Student and Employee are both Persons, so a TeachingAssistant holds two Persons.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    Person(const string& n) : name(n) { cout << "Person built: " << name << endl; }
    string getName() const { return name; }
};

class Student : public Person {
private:
    string major;

public:
    Student(const string& n, const string& m) : Person(n), major(m) { }
};

class Employee : public Person {
private:
    double salary;

public:
    Employee(const string& n, double s) : Person(n), salary(s) { }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(const string& n, const string& m, double s)
        : Student(n, m), Employee(n, s) { }
};

int main() {
    TeachingAssistant sam("Sam", "CS", 1200.00);
    // cout << sam.getName() << endl;   // error: getName is ambiguous
    return 0;
}
