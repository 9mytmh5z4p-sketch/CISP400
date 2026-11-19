// meyers_program2.cpp
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
};

class FlyingBird : public Bird
{
public:
    FlyingBird(const string& n) : Bird(n) { }

    void fly() const
    {
        cout << getName() << " flaps its wings and flies" << endl;
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

class Sparrow : public FlyingBird
{
public:
    Sparrow(const string& n) : FlyingBird(n) { }
};

int main()
{
    Penguin pingu("Pingu");
    Sparrow jack("Jack");

    pingu.swim();
    jack.fly();

    return 0;
}
