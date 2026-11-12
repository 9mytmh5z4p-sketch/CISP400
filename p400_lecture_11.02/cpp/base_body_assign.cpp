// base_body_assign.cpp
// Does not compile: Person has no default constructor.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int id;

public:
    Person(const string& n, int i) { name = n; id = i; }
    string getName() const { return name; }
};

class Student : public Person {
private:
    string major;

public:
    Student(const string& n, int i, const string& m) {
        name = n;
        id = i;
        major = m;
    }
};

int main() {
    Student ava("Ava", 1001, "CS");
    cout << ava.getName() << endl;
    return 0;
}
