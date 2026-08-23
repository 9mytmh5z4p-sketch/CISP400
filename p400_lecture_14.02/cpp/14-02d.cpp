// 14-02d.cpp  --  pet ages dynamic array
#include <iostream>
using namespace std;

void printArray(short* arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    // --- Initial array ---
    short* ages = nullptr;
    int    size  = 1;

    ages = new short[size];
    cout << "Age for pet 1: ";
    cin >> ages[0];
    cout << "Ages: ";  printArray(ages, size);

    // --- Increase ---
    int toAdd;
    cout << "How many ages to add? ";  cin >> toAdd;

    short* temp = new short[size + toAdd];
    for (int i = 0; i < size; i++)          // copy existing
        temp[i] = ages[i];
    for (int i = size; i < size + toAdd; i++){  // populate new slots
        cout << "Age for pet " << (i + 1) << ": ";
        cin >> temp[i];
    }
    delete[] ages;  ages = temp;  temp = nullptr;
    size += toAdd;
    cout << "Ages: ";  printArray(ages, size);

    // --- Decrease ---
    int toDel;
    cout << "How many ages to delete? ";  cin >> toDel;

    temp = new short[size - toDel];
    for (int i = 0; i < size - toDel; i++)  // copy only what we keep
        temp[i] = ages[i];
    delete[] ages;  ages = temp;  temp = nullptr;
    size -= toDel;
    cout << "Ages: ";  printArray(ages, size);

    delete[] ages;  ages = nullptr;
    return 0;
}