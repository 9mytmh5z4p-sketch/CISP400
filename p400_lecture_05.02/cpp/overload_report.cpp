#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void printReport(string label, int value);
void printReport(string label, double value);
void printReport(string label, int low, int high);

int main() {
    printReport("Count", 42);
    printReport("Average", 87.5);
    printReport("Range", 10, 100);
    return 0;
}

void printReport(string label, int value) {
    cout << label << ": " << value << endl;
}

void printReport(string label, double value) {
    cout << fixed << setprecision(1);
    cout << label << ": " << value << endl;
}

void printReport(string label, int low, int high) {
    cout << label << ": " << low << " to " << high << endl;
}
