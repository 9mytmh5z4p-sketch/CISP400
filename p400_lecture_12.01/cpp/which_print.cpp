// which_print.cpp
// GradStudent does not override print(), so the nearest version up the family wins.
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

    void print() const {
        cout << getName() << " (" << getId() << "), " << major << endl;
    }
};

class GradStudent : public Student {
private:
    string advisor;

public:
    GradStudent(const string& n, int i, const string& m, const string& a)
        : Student(n, i, m), advisor(a) { }
    // no print() here
};

int main() {
    Person lee("Lee", 7);
    Student ava("Ava", 1001, "CS");
    GradStudent raj("Raj", 2002, "Math", "Ng");

    lee.print();
    ava.print();
    raj.print();
    return 0;
}
