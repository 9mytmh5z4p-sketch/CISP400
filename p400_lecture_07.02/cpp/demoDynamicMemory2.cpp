// demoDynamicMemory2.cpp
#include <iostream>
using namespace std;

class myVec {
    friend ostream& operator<<(ostream& output, const myVec& values);
    friend istream& operator>>(istream& input, myVec& values);

private:
    int* values;
    int size;
    bool finished;

public:
    myVec();
    ~myVec();
    void addValue(int value);
    bool isFinished() const;
};

myVec::myVec() {
    values = nullptr;
    size = 0;
    finished = false;
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

bool myVec::isFinished() const {
    return finished;
}

ostream& operator<<(ostream& output, const myVec& values);
istream& operator>>(istream& input, myVec& values);

int main() {
    myVec values;

    while (!values.isFinished()) {
        cin >> values;

        if (!values.isFinished()) {
            cout << values;
        }
    }

    cout << "Program ended." << endl;

    return 0;
}

ostream& operator<<(ostream& output, const myVec& values) {
    output << "myVec debug info" << endl;
    output << "size: " << values.size << endl;
    output << "values: ";

    for (int index = 0; index < values.size; ++index) {
        output << values.values[index] << " ";
    }

    output << endl;

    return output;
}

istream& operator>>(istream& input, myVec& values) {
    int value;

    cout << "Enter an int (0 to quit): ";
    input >> value;

    if (value == 0) {
        values.finished = true;
    }
    else {
        values.addValue(value);
    }

    return input;
}