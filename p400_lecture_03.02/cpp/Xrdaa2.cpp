// Xrdaa2.cpp -- real dynamically allocated array with repeated resizing
#include <iostream>
using namespace std;

void increaseByOne(int*& pInt, int& size, int value);
int* decreaseByOne(int* pInt, int& size);
void displayArray(const int* pInt, int size);

int main() {
    int* pInt = new int[1];
    int size = 1;
    pInt[0] = 10;

    displayArray(pInt, size);

    const int valuesToAdd[] = {20, 30, 40, 50, 60};
    const int numberOfValues = sizeof(valuesToAdd) / sizeof(valuesToAdd[0]);

    for (int i = 0; i < numberOfValues; i++) {
        increaseByOne(pInt, size, valuesToAdd[i]);
        displayArray(pInt, size);
    }

    const int numberOfValuesToRemove = 3;

    for (int i = 0; i < numberOfValuesToRemove; i++) {
        pInt = decreaseByOne(pInt, size);
        displayArray(pInt, size);
    }

    delete[] pInt;
    return 0;
}

void increaseByOne(int*& pInt, int& size, int value) {
    int* pTemp = new int[size + 1];

    for (int i = 0; i < size; i++)
        pTemp[i] = pInt[i];

    pTemp[size] = value;
    size++;

    delete[] pInt;
    pInt = pTemp;
}

int* decreaseByOne(int* pInt, int& size) {
    if (size <= 1)
        return pInt;

    int* pTemp = new int[size - 1];

    for (int i = 0; i < size - 1; i++)
        pTemp[i] = pInt[i];

    size--;
    delete[] pInt;
    return pTemp;
}

void displayArray(const int* pInt, int size) {
    for (int i = 0; i < size; i++)
        cout << pInt[i] << " ";
    cout << endl;
}
