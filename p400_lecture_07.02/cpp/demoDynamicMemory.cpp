// demoDynamicMemory.cpp
#include <iostream>
using namespace std;

class myVec {
private:
    int* values;
    int size;

public:
    myVec();
    ~myVec();
    void addValue(int value);
    void print() const;
};
myVec::myVec() {
    values = nullptr;
    size = 0;
}
myVec::~myVec() {
    delete[] values;
}
void myVec::addValue(int value) {
    int* expandedValues = new int[size + 1];

    for (int index = 0; index < size; ++index) {
        expandedValues[index] = values[index];
    }

    expandedValues[size] = value;

    delete[] values;
    values = expandedValues;
    ++size;
}
void myVec::print() const {
    for (int index = 0; index < size; ++index) {
        cout << values[index] << " ";
    }

    cout << endl;
}

int main() {
    myVec values;
    int input;

    cout << "Enter an int (0 to quit): ";
    cin >> input;

    while (input != 0) {
        values.addValue(input);

        cout << "Values: ";
        values.print();

        cout << "Enter an int (0 to quit): ";
        cin >> input;
    }

    cout << "Program ended." << endl;

    return 0;
}
