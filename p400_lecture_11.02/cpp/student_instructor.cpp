// student_instructor.cpp
// Student and Instructor share everything in Person;
// each adds only what is special.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int id = 0;

public:
    void setName(const string& n) { name = n; }
    void setId(int i) { id = i; }
    void print() const { cout << name << " (" << id << ")" << endl; }
};

class Student : public Person {      // a Student is a Person
private:
    string major;

public:
    void setMajor(const string& m) { major = m; }
};

class Instructor : public Person {   // an Instructor is a Person
private:
    string office;

public:
    void setOffice(const string& o) { office = o; }
};

int main() {
    Student ava;
    ava.setName("Ava");      // written once, in Person
    ava.setId(1001);
    ava.setMajor("CS");

    Instructor ng;
    ng.setName("Ng");        // the same code, reused
    ng.setId(7);
    ng.setOffice("BS 214");

    ava.print();
    ng.print();
    return 0;
}
