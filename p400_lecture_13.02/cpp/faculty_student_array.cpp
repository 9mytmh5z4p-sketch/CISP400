// 11-22m2.cpp --
#include <iostream>
#include <string>
#include <memory>
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
    shared_ptr<Person> advisor;
public:
    Student(const string& sname, Discipline d,
            const shared_ptr<Person>& adv) : Person(sname){
        major = d;
        advisor = adv;
    }
    void setMajor(Discipline d) {major = d; }
    Discipline getMajor() const {return major; }
    void setAdvisor(shared_ptr<Person> p) {advisor = p; }
    shared_ptr<Person> getAdvisor() const {return advisor; }
};

class Faculty : public Person{
  private:
    Discipline department;
  public:
    Faculty();    // total waste
    Faculty(const string& fname, Discipline d) : Person(fname){
        department = d;
    }
    void setDepartment(Discipline d) {department = d; }
    Discipline getDepartment() const {return department; }
};

// Function Prototype
void PrintLine(const Faculty &);

int main(){

//    Faculty arrFac[3];    // uses the default constructor
  Faculty arrFac[] = {Faculty("Bob Smith", Discipline::BIOLOGY),
                      Faculty("Indiana Jones", Discipline::ARCHEOLOGY),
                      Faculty("Ida Lovelace", Discipline::COMPUTER_SCIENCE),
                      Student("Sam", Discipline::BIOLOGY, nullptr)
                      };
  PrintLine(arrFac[0]);
  PrintLine(arrFac[1]);
  PrintLine(arrFac[2]);
//  PrintLine(arrFac[3]);
  return 0;
}

void PrintLine(const Faculty& fac) {
  // Setup arrays to print enumerations
  const string dName[] = {"Archelogy", "Biology", "Computer Science"};
  cout << "Professor " << fac.getName()
      << " teaches in the " << "Department of ";
  cout << dName[static_cast<int>(fac.getDepartment())] << endl;
}
