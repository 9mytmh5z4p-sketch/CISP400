// three_levels.cpp
// The rule repeats at every level: the oldest ancestor is built first.
#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "Person" << endl; }
    ~Person() { cout << "~Person" << endl; }
};

class Student : public Person {
public:
    Student() { cout << "Student" << endl; }
    ~Student() { cout << "~Student" << endl; }
};

class GradStudent : public Student {
public:
    GradStudent() { cout << "GradStudent" << endl; }
    ~GradStudent() { cout << "~GradStudent" << endl; }
};

int main() {
    GradStudent ava;
    cout << "--- end of main ---" << endl;
    return 0;
}
