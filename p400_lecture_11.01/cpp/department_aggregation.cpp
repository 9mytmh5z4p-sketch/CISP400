// department_aggregation.cpp -- aggregation through stored pointers
#include <iostream>
#include <string>
using namespace std;

const int MAX_TEACHERS = 10;

class Teacher {
private:
    string name;

public:
    Teacher(const string& n) : name(n) { }
    string getName() const { return name; }
};

// Department does not own its teachers, so it has no destructor
class Department {
private:
    string title;
    Teacher* teachers[MAX_TEACHERS];
    int count;

public:
    Department(const string& t) : title(t), count(0) { }

    void addTeacher(Teacher* t) {
        if (count < MAX_TEACHERS) {
            teachers[count] = t;
            count++;
        }
    }

    void print() const {
        cout << title << ":";
        for (int i = 0; i < count; i++) {
            cout << " " << teachers[i]->getName();
        }
        cout << endl;
    }
};

int main() {
    Teacher lee("Lee");
    Teacher ruiz("Ruiz");

    {
        Department math("Math");
        math.addTeacher(&lee);
        math.addTeacher(&ruiz);
        math.print();
    }                              // math is destroyed here

    cout << lee.getName() << " still exists" << endl;
    return 0;
}
