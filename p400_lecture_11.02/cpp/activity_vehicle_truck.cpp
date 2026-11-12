// activity_vehicle_truck.cpp
// Programming Activity, one possible answer: a Truck is a Vehicle.
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
public:
    void haul() const {
        cout << "Hauling cargo" << endl;
    }
};

int main() {
    Truck pickup;
    pickup.describe();   // written in Vehicle, the parent
    pickup.haul();       // written in Truck, the child
    return 0;
}
