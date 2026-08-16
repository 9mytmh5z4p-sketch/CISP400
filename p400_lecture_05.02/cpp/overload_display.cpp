#include <iostream>
#include <string>
using namespace std;

void display(int value);
void display(double value);
void display(string value);

int main() {
    display(42);
    display(3.75);
    display("Overloaded display");
    return 0;
}

void display(int value) {
    cout << "int: " << value << endl;
}

void display(double value) {
    cout << "double: " << value << endl;
}

void display(string value) {
    cout << "string: " << value << endl;
}
