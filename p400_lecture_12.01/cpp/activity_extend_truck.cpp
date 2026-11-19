// activity_extend_truck.cpp
// Programming Activity, one possible answer: Truck extends Vehicle::describe().
#include <iostream>
using namespace std;

class Vehicle {
private:
    int wheels = 4;

public:
    void describe() const {
        cout << "A vehicle with " << wheels << " wheels" << endl;
    }
};

class Truck : public Vehicle {
private:
    int bedFeet = 6;

public:
    // same name, parameters, and const: overrides Vehicle::describe()
    void describe() const {
        Vehicle::describe();                              // the parent's part
        cout << "Truck bed: " << bedFeet << " feet" << endl;   // the child's part
    }
};

int main() {
    Vehicle car;
    Truck pickup;

    car.describe();
    cout << endl;
    pickup.describe();
    return 0;
}
