// Xrdaa.cpp -- real dynamically allocated array
#include <iostream>
using namespace std;

void increaseByOne(int*& pInt, int& size);
int* decreaseByOne(int* pInt, int& size);
void displayArray(const int* pInt, int size);

int main() {                 // build the initial array
    int* pInt = nullptr;
    int size = 1;

    pInt = new int[size];
    pInt[0] = 10;

    displayArray(pInt, size);

    increaseByOne(pInt, size);
    displayArray(pInt, size);

    pInt = decreaseByOne(pInt, size); // now need to catch the new address
    displayArray(pInt, size);

    delete[] pInt;
    return 0;
}

void increaseByOne(int*& pInt, int& size) {
    int* pTemp = nullptr;
    size++;
    pTemp = new int[size];

    pTemp[0] = pInt[0];
    pTemp[1] = 20;

    delete[] pInt;
    pInt = pTemp;   // Update address in main() here - reference
    pTemp = nullptr;
}

int* decreaseByOne(int* pInt, int& size) { // pInt now pass by value
    int* pTemp = nullptr;
    size--;
    pTemp = new int[size];
    pTemp[0] = pInt[0];

    delete[] pInt;
    return pTemp;
}

void displayArray(const int* pInt, int size) {
    for (int i = 0; i < size; i++)
        cout << pInt[i] << " ";
    cout << endl;
}
