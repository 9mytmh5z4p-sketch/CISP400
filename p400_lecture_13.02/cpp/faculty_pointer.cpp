// 11-22m.cpp --
#include <iostream>
#include <string>
using namespace std;

enum class Discipline { ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE, };

class Person {
protected:
    string name;
public:
    Person() { setName("");}
    Person(const string& pName) {setName(pName);}
    void setName(const string& pName) {name = pName;}
    string getName() const {return name; }
};

class Student : public Person{
private:
    Discipline major;
public:
    void setMajor(Discipline d) {major = d; }
    Discipline getMajor() const {return major; }
};

class Faculty : public Person{
  private:
    Discipline department;
  public:
//    Faculty(const string& fname, Discipline d) : Person(fname){
//        department = d;
//    }
    void setDepartment(Discipline d) {department = d; }
    Discipline getDepartment() const {return department; }
};

int main(){
    // Setup arrays to print enumerations
    const string dName[] = {"Archelogy", "Biology", "Computer Science"};

    Faculty* prof = new Faculty();                   // instantiate faculty
    prof->setName("Indiana Jones");                  // Msg to set name
    prof->setDepartment(Discipline::ARCHEOLOGY);     // Msg to set department

    cout << "Professor " << prof->getName()
        << " teaches in the " << "Department of ";

    Discipline dept = prof->getDepartment();             // Msg to get department
    cout << dName[static_cast<int>(dept)] << endl;       // Print Dpt in string form

    delete prof;                                     // we called new, so we delete
    return 0;
}
