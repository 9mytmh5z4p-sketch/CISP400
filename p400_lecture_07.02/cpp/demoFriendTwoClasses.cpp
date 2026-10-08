// demoFriendTwoClasses.cpp
#include <iostream>
using namespace std;

class A;
class B;

int add(const A& left, const B& right);

class A {
    friend int add(const A& left, const B& right);
private:
    int value;

public:
    A(int number = 0);
};

class B {
    friend int add(const A& left, const B& right);
private:
    int value;

public:
    B(int number = 0);
};

int main() {
    A first(12);
    B second(1);

    cout << add(first, second) << endl;

    return 0;
}

A::A(int number) {
    value = number;
}

B::B(int number) {
    value = number;
}

int add(const A& left, const B& right) {
    return left.value + right.value;
}
