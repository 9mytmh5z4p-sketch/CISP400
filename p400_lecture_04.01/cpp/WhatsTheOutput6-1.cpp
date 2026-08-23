//WhatsTheOutput6-1.cpp
#include <iostream>
using namespace std;


int add(int, int);


int main() {
    int x = 3, y = 7;
    cout << add(x, y) << endl;
    cout << add(5, 2) << endl;
    return 0;
}


int add(int a, int b) {
    return a + b;
}

// passing function exercise