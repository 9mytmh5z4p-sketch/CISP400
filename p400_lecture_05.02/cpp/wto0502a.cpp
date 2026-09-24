#include <iostream>
#include <string>
using namespace std;

class Speaker {
public:
    void sayHello(const string& name) {
        cout << "Hello, " << name << "!" << endl;
    }
};

class Greeter {
public:
    void greetUser(const string& userName) {
        Speaker s;  // 👈 Local variable: dependency
        s.sayHello(userName);
    }
};

int main() {
    Greeter g;
    g.greetUser("Taylor");
    return 0;
}