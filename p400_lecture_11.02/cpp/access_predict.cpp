// access_predict.cpp
// Which of the lines A, B, C, and D compile?
#include <iostream>
#include <string>
using namespace std;

class Member {
private:
    int dues = 20;

protected:
    string name = "Ben";

public:
    string getName() const { return name; }
};

class Officer : public Member {
public:
    void print() const {
        cout << name << endl;          // A
        cout << dues << endl;          // B
    }
};

int main() {
    Officer ben;
    ben.print();
    cout << ben.getName() << endl;     // C
    cout << ben.name << endl;          // D
    return 0;
}
