// construction_order.cpp -- members are built in declaration order
// Compile with -Wall to see the -Wreorder warning.
#include <iostream>
using namespace std;

class Part {
private:
    char id;

public:
    Part(char c) { id = c; cout << "build " << id << endl; }
    ~Part() { cout << "destroy " << id << endl; }
};

class Whole {
private:
    Part first;
    Part second;

public:
    Whole() : second('B'), first('A') { cout << "Whole body" << endl; }
    ~Whole() { cout << "~Whole body" << endl; }
};

int main() {
    Whole w;
    return 0;
}
