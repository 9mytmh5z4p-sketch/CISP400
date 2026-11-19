// extend_print.cpp
// Student extends Person::print() instead of replacing it.
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
    Student(const string& n, int i, const string& m) : Person(n, i), major(m) { }

    void print() const {
        Person::print();                 // run Person's version first
        cout << ", " << major << endl;   // then add Student's part
    }
};

int main() {
    Student ava("Ava", 1001, "CS");
    ava.print();
    return 0;
}
