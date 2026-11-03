// string_conversion.cpp -- string's converting constructor from a C-string
#include <iostream>
#include <string>
using namespace std;

void greet(const string& name);

int main() {
    string course = "CISP 400";   // C-string to string
    greet("Ada");                 // the same conversion, in a call
    cout << course << endl;
    return 0;
}

void greet(const string& name) {
    cout << "Hello, " << name << endl;
}
