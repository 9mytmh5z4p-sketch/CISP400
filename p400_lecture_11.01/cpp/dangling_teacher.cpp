// dangling_teacher.cpp -- an aggregated part destroyed before the whole uses it
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
    Department math("Math");
    {
        Teacher lee("Lee");
        math.addTeacher(&lee);
    }                          // lee is destroyed here
    math.print();              // uses a dangling pointer
    return 0;
}
