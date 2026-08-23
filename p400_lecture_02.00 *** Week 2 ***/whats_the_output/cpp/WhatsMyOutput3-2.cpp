// WhatsMyOutput3-2.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num = 42;
    double price = 9.5;
    
    cout << setw(10) << num << endl;
    cout << left << setw(10) << num << "end" << endl;
    cout << right << setw(8) << price << endl;
    cout << fixed << setprecision(2) << price << endl;
    cout << setw(6) << "Hi" << setw(6) << num << endl;
    
    return 0;
}

// Answer
//.........42
//.42........end
//......9.5
//.9.50
//....Hi....42