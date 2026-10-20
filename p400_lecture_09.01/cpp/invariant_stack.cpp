#include <iostream>
#include <cassert>
using namespace std;

const int CAPACITY = 3;

// Class invariant: 0 <= count <= CAPACITY
class BoundedStack {
private:
    int items[CAPACITY];
    int count = 0;
    void checkInvariant() const;

public:
    void push(int value);
    int pop();
    int size() const;
};

int main() {
    BoundedStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    // size() returns count, which is 3 after three pushes
    cout << "Size: " << stack.size() << '\n';

    // This call violates the precondition of push
    stack.push(40);
    cout << "This line never prints\n";

    return 0;
}

void BoundedStack::checkInvariant() const {
    assert(count >= 0 && count <= CAPACITY && "count is out of range");
}

void BoundedStack::push(int value) {
    // Precondition: check before writing, while count is the next open slot
    assert(count < CAPACITY && "push on a full stack");
    items[count] = value;
    count++;
    // After the change, confirm 0 <= count <= CAPACITY
    checkInvariant();
}

int BoundedStack::pop() {
    // Precondition: the stack is not empty
    assert(count > 0 && "pop on an empty stack");
    count--;
    checkInvariant();
    return items[count];
}

int BoundedStack::size() const {
    // The size of the stack is the value of count
    return count;
}
