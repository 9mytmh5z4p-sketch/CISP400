// diamond_virtual.cpp
// virtual inheritance: Student and Employee share one Person.
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

class Student : virtual public Person {
private:
    string major;

public:
    Student(const string& n, const string& m) : Person(n), major(m) { }
};

class Employee : virtual public Person {
private:
    double salary;

public:
    Employee(const string& n, double s) : Person(n), salary(s) { }
};

class TeachingAssistant : public Student, public Employee {
public:
    // the most derived class now builds the shared Person itself
    TeachingAssistant(const string& n, const string& m, double s)
        : Person(n), Student(n, m), Employee(n, s) { }
};

int main() {
    TeachingAssistant sam("Sam", "CS", 1200.00);
    cout << sam.getName() << endl;
    return 0;
}
