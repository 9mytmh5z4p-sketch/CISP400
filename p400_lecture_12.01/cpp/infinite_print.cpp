// infinite_print.cpp
// Compiles, then crashes: without Person::, print() calls itself forever.
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
        print();                         // meant Person::print()
        cout << ", " << major << endl;
    }
};

int main() {
    Student ava("Ava", 1001, "CS");
    ava.print();
    return 0;
}
