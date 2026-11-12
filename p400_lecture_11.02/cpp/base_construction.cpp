// base_construction.cpp
// Student passes name and id up to Person's constructor.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int id;

public:
    Person(const string& n, int i) : name(n), id(i) { }

    void print() const {
        cout << name << " (" << id << ")" << endl;
    }
};

class Student : public Person {
private:
    string major;

public:
    // Person(n, i) builds the Person part first, then major(m) builds major
    Student(const string& n, int i, const string& m) : Person(n, i), major(m) { }

    string getMajor() const { return major; }
};

int main() {
    Student ava("Ava", 1001, "CS");
    ava.print();
    cout << "Major: " << ava.getMajor() << endl;
    return 0;
}
