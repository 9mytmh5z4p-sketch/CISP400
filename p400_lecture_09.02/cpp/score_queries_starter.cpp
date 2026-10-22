#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void printValues(const int values[], int size);

int main() {
    int scores[] = {88, 64, 92, 71, 55, 79};
    int size = 6;
    int passing = 70;

    // TODO: Use count_if with a lambda that captures passing
    // to count the scores at or above passing.
    int passed = 0;
    cout << "Passing scores: " << passed << '\n';

    // TODO: Use find_if with a lambda that captures passing
    // to find the first score below passing.
    // Print it if one exists; otherwise print "Everyone passed".

    // TODO: Use sort with a comparator lambda
    // to put the scores in order from highest to lowest.
    cout << "Highest first: ";
    printValues(scores, size);

    return 0;
}

// Print every value on one line
void printValues(const int values[], int size) {
    for (int i = 0; i < size; i++) {
        cout << values[i] << ' ';
    }
    cout << '\n';
}
