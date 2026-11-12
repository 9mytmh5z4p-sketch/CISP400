// stack_trap.cpp
// A Stack that inherits from vector passes "uses a vector" but fails "is a vector".
#include <iostream>
#include <vector>
using namespace std;

class Stack : public vector<int> {
    // no private vector: Stack IS a vector,
    // so the storage is inherited

public:
    void push(int value) { push_back(value); }
    int pop() {
        int top = back();
        pop_back();
        return top;
    }
    // no empty() here: it is inherited from vector
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.insert(s.begin(), 99);   // compiles: Stack inherited insert from vector
    s[1] = 42;                 // compiles: and operator[] too

    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
    return 0;
}
