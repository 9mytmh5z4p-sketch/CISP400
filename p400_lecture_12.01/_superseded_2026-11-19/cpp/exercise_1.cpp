#include <iostream>
#include <string>
using namespace std;

int main() {
    string names[5];
    int scores[5];

    // Input names and scores
    for (int i = 0; i < 5; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> names[i];

        cout << "Enter score for " << names[i] << ": ";
        cin >> scores[i];
    }

    cout << "\n--- Student Results ---\n";

    // Output names and scores
    for (int i = 0; i < 5; i++) {
        cout << names[i] << " scored " << scores[i] << endl;
    }

    return 0;
}