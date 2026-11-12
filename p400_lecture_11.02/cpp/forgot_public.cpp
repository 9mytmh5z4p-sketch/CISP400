// forgot_public.cpp
// Does not compile: without public, class inheritance is private.
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    void setName(const string& n) { name = n; }
    string getName() const { return name; }
};

class Student : Person {     // missing public
private:
    string major;

public:
    void setMajor(const string& m) { major = m; }
};

int main() {
    Student ava;
    ava.setName("Ava");      // error: setName is now private in Student
    cout << ava.getName() << endl;
    return 0;
}
