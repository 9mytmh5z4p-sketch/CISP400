// 0801Demo1.cpp
// Overload show() and let the compiler decide lvalue or rvalue
#include <iostream>
#include <string>
#include <utility>
using namespace std;

void show(const string& s);
void show(string&& s);
string makeGreeting();

int main() {
    string name = "Ada";

    show(name);                  // name is an lvalue
    show(string("temporary"));   // temporary object -> rvalue
    show(makeGreeting());        // returned by value -> rvalue
    show(name + " Lovelace");    // result of + is an rvalue
    show(move(name));            // move casts name to an rvalue
}

void show(const string& s) {
    cout << "lvalue overload: " << s << '\n';
}

void show(string&& s) {
    cout << "rvalue overload: " << s << '\n';
}

string makeGreeting() {
    return "hello from a function";
}
