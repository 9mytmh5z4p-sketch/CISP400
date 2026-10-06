// 11-1x.cpp -- this demo problem
#include <iostream>
using namespace std;

class Example{
private:
    int x;
public:
    Example(int a){ x = a;}
    void setValue(int);
    void printAddressAndValue();
};

void Example::setValue(int a)
{ x = a; }

void Example::printAddressAndValue(){ 
  int x =50;
  cout << "Object at address: " << " ??? " << " has "
    << "x value of: " << x << endl;
}

int main() {
    Example obj1(10), obj2(20);

    obj1.printAddressAndValue();
    obj2.printAddressAndValue();

    return 0;
}

// How do we print out the class variable x?

