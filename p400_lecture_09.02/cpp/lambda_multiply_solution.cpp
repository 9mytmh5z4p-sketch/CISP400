#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void printValues(const int values[], int size);

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int size = 5;
    int multiplier = 3;

    cout << "Before: ";
    printValues(values, size);

    // The lambda reads multiplier, so a by-value capture is enough
    for_each(begin(values), end(values),
             [multiplier](int& value) { value *= multiplier; });

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
