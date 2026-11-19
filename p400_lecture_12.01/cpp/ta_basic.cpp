// ta_basic.cpp
// A TeachingAssistant is a Student and an Employee.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string major;

public:
    Student(const string& n, const string& m) : name(n), major(m) {
        cout << "Student built" << endl;
    }
    string getMajor() const { return major; }
};

class Employee {
private:
    string name;
    double salary;

public:
    Employee(const string& n, double s) : name(n), salary(s) {
        cout << "Employee built" << endl;
    }
    double getSalary() const { return salary; }
};

// two parents, each with its own public
class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(const string& n, const string& m, double s)
        : Student(n, m), Employee(n, s) { }
};

int main() {
    TeachingAssistant sam("Sam", "CS", 1200.00);
    cout << "Major: " << sam.getMajor() << endl;     // from Student
    cout << "Salary: " << sam.getSalary() << endl;   // from Employee
    return 0;
}
