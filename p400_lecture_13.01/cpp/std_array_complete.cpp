#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

void display(const array<int, 5>& values);

int main() {
    array<int, 5> values = {42, 7, 19, 3, 11};

    sort(values.begin(), values.end());

    cout << "Count: " << values.size() << "\n";
    display(values);

    return 0;
}

void display(const array<int, 5>& values) {
    for (int value : values) {
        cout << value << " ";
    }
    cout << "\n";
}
