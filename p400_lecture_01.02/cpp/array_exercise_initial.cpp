// pe0003.cpp
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 50;
    const int MID = 25;
    double alpha[SIZE] {0};

    for (int i = 0; i < MID; i++)
    {
        alpha[i] = i * i;
    }

    for (int i = MID; i < SIZE; i++)
        alpha[i] = pow(i, 3.0);

    const int MAXLINE = 10;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < MAXLINE; j++)
            cout << alpha[i + j] << " ";
        cout << endl;
        i += 9; // Get the i counter right
    }

    return 0;
}
