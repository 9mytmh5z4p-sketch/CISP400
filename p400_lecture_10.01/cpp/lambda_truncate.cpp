// lambda_truncate.cpp -- a return type that silently converts
#include <iostream>
using namespace std;

int main() {
    auto toWhole = [](double x) -> int { return x; };
    cout << toWhole(3.9) << endl;
    return 0;
}
