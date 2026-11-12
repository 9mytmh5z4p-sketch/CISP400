// stack_has_a.cpp
// The fix: a Stack has a vector and shows only push, pop, and empty.
#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> items;    // has-a: the vector is hidden inside

public:
    void push(int value) { items.push_back(value); }
    int pop() {
        int top = items.back();
        items.pop_back();
        return top;
    }
    bool empty() const { return items.empty(); }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    // s.insert(s.begin(), 99);   // error: Stack has no member named insert

    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
    return 0;
}
