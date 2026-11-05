// stack_unwinding.cpp -- local objects and their parts are destroyed during unwinding
#include <iostream>
#include <stdexcept>
using namespace std;

class Engine {
public:
    ~Engine() { cout << "Engine destroyed" << endl; }
};

class Car {
private:
    Engine engine;      // composition

public:
    ~Car() { cout << "Car destroyed" << endl; }
};

void testDrive(int miles);

int main() {
    try {
        testDrive(-10);
    } catch (const runtime_error& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}

void testDrive(int miles) {
    Car loaner;
    if (miles < 0) {
        throw runtime_error("miles cannot be negative");
    }
    cout << "Drove " << miles << " miles" << endl;
}
