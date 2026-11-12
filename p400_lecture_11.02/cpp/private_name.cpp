// private_name.cpp
// Does not compile: a derived class cannot read its base's private members.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    void setName(const string& n) { name = n; }
};

class Student : public Person {
private:
    string major;

public:
    void setMajor(const string& m) { major = m; }
    void print() const {
        cout << name << ", " << major << endl;   // error: name is private
    }
};

int main() {
    Student ava;
    ava.setName("Ava");
    ava.setMajor("CS");
    ava.print();
    return 0;
}
