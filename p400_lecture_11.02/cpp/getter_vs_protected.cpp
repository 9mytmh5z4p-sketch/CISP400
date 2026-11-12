// getter_vs_protected.cpp
// Two ways for Student to reach Person's name.
#include <iostream>
#include <string>
using namespace std;

// Fix 1: name stays private; everyone uses the public getter
class Person {
private:
    string name;

public:
    void setName(const string& n) { name = n; }
    string getName() const { return name; }
};

class Student : public Person {
private:
    string major;

public:
    void setMajor(const string& m) { major = m; }
    void print() const { cout << getName() << ", " << major << endl; }
};

// Fix 2: name is protected; derived classes may use it directly
class Member {
protected:
    string name;

public:
    void setName(const string& n) { name = n; }
};

class Officer : public Member {
private:
    string role;

public:
    void setRole(const string& r) { role = r; }
    void print() const { cout << name << ", " << role << endl; }
};

int main() {
    Student ava;
    ava.setName("Ava");
    ava.setMajor("CS");
    ava.print();

    Officer ben;
    ben.setName("Ben");
    ben.setRole("Treasurer");
    ben.print();
    // cout << ben.name;   // error: protected is family only; main is not family
    return 0;
}
