// inhComp.cpp -- inherit compposition?
#include <iostream>
using namespace std;

class comp {
public:
    comp() { cout << "Comp class\n";}
};

class base {
public:
  comp test;
};

class child : base {

};

int main() {
  child s;
}
