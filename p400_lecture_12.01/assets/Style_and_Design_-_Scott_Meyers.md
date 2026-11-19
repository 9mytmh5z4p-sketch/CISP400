# CISP 400 — Programming Style and Software Design

**Scott Meyers — Make Sure Public Inheritance Models "Is-a"**

**Name:** _________________________ **Date:** _______________

## Introduction

Two programs can both compile and run while making very different promises about the objects they describe.

In this activity, you will examine two C++ programs that model birds, apply the is-a test from last lecture, and decide which design tells the truth about penguins.

Our focus is a design principle from Scott Meyers's *Effective C++*: **public inheritance means is-a, and everything that is true of the base class must be true of the derived class.**

## Part 1 — Examine the Programs

Both programs model a penguin named Pingu.

### Program 1

```cpp
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
```

### Program 2

```cpp
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
```

## Part 2 — Investigation and Analysis

### Question 1 — What Does a Penguin Contain?

In Program 1, list every data member and every member function a `Penguin` object has. For each one, state whether it was written in `Penguin` or inherited from `Bird`.

`name` is private in `Bird`. How does `Penguin::swim()` print the penguin's name? Could `swim()` use `name` directly? Why or why not?

### Question 2 — Applying the Is-a Test

Without compiling it, predict what Program 1 prints. Is the output true?

Say the sentence "A Penguin is a Bird." Is it true in biology? Is it true for everything a `Bird` can do *in Program 1*? Explain the difference.

### Question 3 — Understanding Program 2

Suppose a programmer adds this line to the end of `main` in Program 2:

```cpp
pingu.fly();
```

What happens, and why? Is that result better or worse than what Program 1 does? Explain.

### Question 4 — Building the Bird Part

Explain how a `Penguin` gives its name to the `Bird` part of the object.

In Program 2, list the order in which the parts of `jack` are built.

### Question 5 — Making a Design Decision

A zoo application must add an `Ostrich`, an `Eagle`, and a `Duck`, which both flies and swims.

Which design would you extend, and how? Identify at least one advantage and one potential disadvantage of your approach.

## Part 3 — Class Discussion

Be prepared to discuss the following question:

**Should a class hierarchy model the real world, or the promises a program makes to the code that uses it?**

Support your position using specific examples from the two programs.
