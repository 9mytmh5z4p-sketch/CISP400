//polyEx1.cpp
#include <iostream>
using namespace std;

// Parent class
class Animal {
public:
    // Base class function (non-virtual)
    void makeSound() const {
        cout << "Animal makes a generic sound." << endl;
    }
};

// Child class 1
class Dog : public Animal {
public:
    // Overriding makeSound (non-polymorphic)
    void makeSound() const {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

// Child class 2
class Cat : public Animal {
public:
    // Overriding makeSound (non-polymorphic)
    void makeSound() const {
        cout << "Cat meows: Meow! Meow!" << endl;
    }
};

int main() {
    // Create child objects
    Dog dog;
    Cat cat;

    // Create an array of Animal objects
    Animal animals[2] = {dog, cat}; // Object slicing happens here

    // Call makeSound on each object in the array
    for (int i = 0; i < 2; ++i) {
        animals[i].makeSound(); // Calls Animal's version of makeSound
    }

    return 0;
}
