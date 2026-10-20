#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

// TODO: Write a MultiplyBy functor here.
// It stores a multiplier that is set by its constructor.
// Its operator() takes an int by reference and multiplies it by the stored multiplier.

void printValues(const int values[], int size);

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << "Before: ";
    printValues(values, size);

    // TODO: Use for_each with a MultiplyBy object to triple every value.

    cout << "After:  ";
    printValues(values, size);

    return 0;
}

// Print every value on one line
void printValues(const int values[], int size) {
    for (int i = 0; i < size; i++) {
        cout << values[i] << ' ';
    }
    cout << '\n';
}
