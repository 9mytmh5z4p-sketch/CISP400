// base_member_init.cpp
// Does not compile: Student cannot build Person's members itself.
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person(const string& n, int i) : name(n), id(i) { }
};

class Student : public Person {
private:
    string major;

public:
    Student(const string& n, int i, const string& m)
        : name(n), id(i), major(m) { }
};

int main() {
    Student ava("Ava", 1001, "CS");
    return 0;
}
