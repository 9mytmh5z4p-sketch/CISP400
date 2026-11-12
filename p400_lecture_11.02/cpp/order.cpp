// order.cpp
// Base first, then members, then the derived body; destruction in reverse.
#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "Person built" << endl; }
    ~Person() { cout << "Person destroyed" << endl; }
};

class Transcript {
public:
    Transcript() { cout << "Transcript built" << endl; }
    ~Transcript() { cout << "Transcript destroyed" << endl; }
};

class Student : public Person {
private:
    Transcript record;

public:
    Student() { cout << "Student body" << endl; }
    ~Student() { cout << "~Student body" << endl; }
};

int main() {
    Student ava;
    cout << "--- end of main ---" << endl;
    return 0;
}
