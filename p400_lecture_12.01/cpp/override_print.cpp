// override_print.cpp
// Student overrides print() so a Student also shows its major.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int id;

public:
    Person(const string& n, int i) : name(n), id(i) { }
    string getName() const { return name; }
    int getId() const { return id; }

    void print() const {
        cout << name << " (" << id << ")" << endl;
    }
};

class Student : public Person {
private:
    string major;

public:
    Student(const string& n, int i, const string& m) : Person(n, i), major(m) { }

    // same name, same parameters, same const: this overrides Person::print()
    void print() const {
        cout << getName() << " (" << getId() << "), " << major << endl;
    }
};

int main() {
    Person lee("Lee", 7);
    Student ava("Ava", 1001, "CS");

    lee.print();    // Person's version
    ava.print();    // Student's version
    return 0;
}
