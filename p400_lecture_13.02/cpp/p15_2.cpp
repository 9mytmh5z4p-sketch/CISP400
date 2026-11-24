// p15-2.cpp -- the same program without virtual
#include "inheritance4.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<shared_ptr<Person>> people
    {
        make_shared<TFaculty>
        ("Indiana Jones", Discipline::ARCHEOLOGY, "Dr."),
        make_shared<Student>
        ("Tom Cruise", Discipline::COMPUTER_SCIENCE, nullptr),
        make_shared<Faculty>
        ("James Stock", Discipline::BIOLOGY),
        make_shared<TFaculty>
        ("Sharon ROck", Discipline::BIOLOGY, "Professor"),
        make_shared<TFaculty>
        ("Nicole Eweman", Discipline::ARCHEOLOGY, "Dr.")
    };

    for (int k = 0; k < people.size(); k++)
    {
        cout << people[k]->getName() << endl;
    }
    return 0;
}
