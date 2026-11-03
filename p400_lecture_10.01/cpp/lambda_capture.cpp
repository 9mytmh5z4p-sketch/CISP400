// lambda_capture.cpp -- capture by value versus capture by reference
#include <iostream>
using namespace std;

int main() {
    int bonus = 5;
    auto byValue = [bonus](int score) { return score + bonus; };
    auto byReference = [&bonus](int score) { return score + bonus; };

    bonus = 10;
    cout << byValue(80) << " " << byReference(80) << endl;
    return 0;
}
