#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

// A functor that multiplies a value by a stored multiplier
class MultiplyBy {
private:
    int multiplier;

public:
    MultiplyBy(int factor);
    void operator()(int& value) const;
};

void printValues(const int values[], int size);

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int size = 5;
    int multiplier = 3;

    cout << "Before: ";
    printValues(values, size);

    // TODO: Replace MultiplyBy(multiplier) with a lambda that captures multiplier.
    // Then delete the MultiplyBy class and its member function definitions.
    for_each(begin(values), end(values), MultiplyBy(multiplier));

    cout << "After:  ";
    printValues(values, size);

    return 0;
}

MultiplyBy::MultiplyBy(int factor) : multiplier(factor) {}

void MultiplyBy::operator()(int& value) const {
    value *= multiplier;
}

// Print every value on one line
void printValues(const int values[], int size) {
    for (int i = 0; i < size; i++) {
        cout << values[i] << ' ';
    }
    cout << '\n';
}
