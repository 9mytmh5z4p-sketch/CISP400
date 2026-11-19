// meyers_program1.cpp
#include <iostream>
#include <string>
using namespace std;

class Bird
{
private:
    string name;

public:
    Bird(const string& n) : name(n) { }
    string getName() const { return name; }

    void fly() const
    {
        cout << name << " flaps its wings and flies" << endl;
    }
};

class Penguin : public Bird
{
public:
    Penguin(const string& n) : Bird(n) { }

    void swim() const
    {
        cout << getName() << " swims" << endl;
    }
};

int main()
{
    Penguin pingu("Pingu");

    pingu.swim();
    pingu.fly();

    return 0;
}
