// person_student.cpp
// Student inherits name, id, and print() from Person and adds a major.
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
    string getName() const { return name; }

    void print() const {
        cout << name << " (" << id << ")" << endl;
    }
};

class Student : public Person {
private:
    string major;

public:
    void setMajor(const string& m) { major = m; }
    string getMajor() const { return major; }
};

int main() {
    Student ava;
    ava.setName("Ava");          // inherited from Person
    ava.setId(1001);             // inherited from Person
    ava.setMajor("CS");          // added by Student

    ava.print();                 // inherited: prints name and id only
    cout << ava.getName() << " studies " << ava.getMajor() << endl;
    return 0;
}
