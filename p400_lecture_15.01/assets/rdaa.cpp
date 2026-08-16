// rdaa.cpp  -- real dynamically allocated array
#include <iostream>
using namespace std;

int main(){     // build the initial array
    int* pInt = nullptr;
    int size = 1;

    pInt = new int[size];
    pInt[0] = 10;

    for (int i = 0; i < size; i++)
	cout << pInt[i] << "  ";
    cout << endl;

// increase by 1
    int* pTemp = nullptr;
    size++;
    pTemp = new int[size];

    pTemp[0] = pInt[0];
    pTemp[1] = 20;

    delete[] pInt;
    pInt = pTemp;
    pTemp = nullptr;

    for (int i = 0; i < size; i++)
	cout << pInt[i] << "  ";
    cout << endl;

    // decrease by 1 from the right
//    int* pTemp = nullptr;
    size--;
    pTemp = new int[size];
    pTemp[0] = pInt[0];

    delete[] pInt;
    pInt = pTemp;
    pTemp = nullptr;

    for (int i = 0; i < size; i++)
	cout << pInt[i] << "  ";
    cout << endl;

    return 0;
}
