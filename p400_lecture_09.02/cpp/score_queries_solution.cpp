#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void printValues(const int values[], int size);

int main() {
    int scores[] = {88, 64, 92, 71, 55, 79};
    int size = 6;
    int passing = 70;

    // Count the scores at or above passing
    int passed = count_if(begin(scores), end(scores),
                          [passing](int score) { return score >= passing; });
    cout << "Passing scores: " << passed << '\n';

    // Find the first score below passing
    int* firstFail = find_if(begin(scores), end(scores),
                             [passing](int score) { return score < passing; });

    if (firstFail != end(scores)) {
        cout << "First failing score: " << *firstFail << '\n';
    } else {
        cout << "Everyone passed\n";
    }

    // Highest score first
    sort(begin(scores), end(scores),
         [](int a, int b) { return a > b; });
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
