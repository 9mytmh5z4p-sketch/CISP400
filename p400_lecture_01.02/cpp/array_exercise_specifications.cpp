// pe0003.cpp
// Prof. Fowler
// 8/26/21
#include <cmath>
#include <iostream>
using namespace std;

void ProgramGreeting();

int main()
{
    const int SIZE = 50;
    const int MID = 25;
    double alpha[SIZE] {0};

    ProgramGreeting();

    // Specification B1
    for (int i = 0; i < MID; i++)
    {
        alpha[i] = i * i;
    }

    // Specification A1
    for (int i = MID; i < SIZE; i++)
        alpha[i] = pow(i, 3.0);

    // Specification C1
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

void ProgramGreeting()
{
    cout << "\nWelcome to my Program\n";
    cout << "More fluff here" << endl;
}
