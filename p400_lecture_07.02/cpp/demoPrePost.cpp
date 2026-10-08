// demoPrePost.cpp
#include <iostream>
using namespace std;

class Counter {
private:
    int value;
public:
    Counter(int start = 0);

    Counter& operator++();		// prefix (++C) operator
    Counter operator++(int);	// postfix (C++) operator

    void print() const;
};
Counter::Counter(int start) {
    value = start;
}
Counter& Counter::operator++() {
    ++value;
    return *this;
}
Counter Counter::operator++(int) {
    Counter original = *this;
    ++value;
    return original;
}
void Counter::print() const {
    cout << value << endl;
}

int main() {
    Counter count(5);

    Counter prefixResult = ++count;

    cout << "Prefix result: ";
    prefixResult.print();

    cout << "Current value: ";
    count.print();

    Counter postfixResult = count++;

    cout << "Postfix result: ";
    postfixResult.print();

    cout << "Current value: ";
    count.print();

    return 0;
}