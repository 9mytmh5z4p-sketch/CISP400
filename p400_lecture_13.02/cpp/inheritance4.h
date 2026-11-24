// inheritance4.h -- demonstrate inheritance
#include <string>
#include <memory>
using namespace std;

enum class Discipline { ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE, };
enum class Classification {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };
class Person
{
protected:
    string name;
public:
    Person() { setName("");}
    Person(const string& pName) {setName(pName);}
    void setName(const string& pName) {name = pName;}
    string getName() const {return name; }
};

class Student : public Person
{
private:
    Discipline major;
    shared_ptr<Person> advisor;
public:
    Student(const string& sname, Discipline d, const shared_ptr<Person>& adv)
        : Person(sname), major(d), advisor(adv) { }
    Discipline getMajor() const {return major; }
};

class Faculty : public Person
{
private:
    Discipline department;
public:
    Faculty(const string& fname, Discipline d) : Person(fname), department(d) { }
    Discipline getDepartment() const {return department; }
};

// TFaculty: faculty with a title, such as "Dr."
class TFaculty : public Faculty
{
private:
    string title;
public:
    TFaculty(const string& fname, Discipline d, const string& t)
        : Faculty(fname, d), title(t) { }
    string getName() const {return title + " " + Person::getName(); }
};
