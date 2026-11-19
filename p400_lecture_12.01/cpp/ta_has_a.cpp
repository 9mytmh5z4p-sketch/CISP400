// ta_has_a.cpp
// A TeachingAssistant is a Student and has a Job: no diamond.
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
    string getMajor() const { return major; }
};

class Job {
private:
    string title;
    double salary;

public:
    Job(const string& t, double s) : title(t), salary(s) { }
    double getSalary() const { return salary; }
};

class TeachingAssistant : public Student {     // is a Student
private:
    Job job;                                    // has a Job

public:
    TeachingAssistant(const string& n, const string& m, double s)
        : Student(n, m), job("TA", s) { }

    double getSalary() const { return job.getSalary(); }
};

int main() {
    TeachingAssistant sam("Sam", "CS", 1200.00);
    cout << sam.getName() << ", " << sam.getMajor()
         << ", paid " << sam.getSalary() << endl;
    return 0;
}
