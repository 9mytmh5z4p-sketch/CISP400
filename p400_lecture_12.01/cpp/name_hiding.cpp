// name_hiding.cpp
// Does not compile: a print() with different parameters hides Person::print().
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

    void print(bool showMajor) const {      // different parameters: not an override
        cout << getName() << " (" << getId() << ")";
        if (showMajor) {
            cout << ", " << major;
        }
        cout << endl;
    }
};

int main() {
    Student ava("Ava", 1001, "CS");
    ava.print(true);
    ava.print();       // error: Person::print() is hidden
    return 0;
}
