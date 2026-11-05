// car_relationships.cpp -- one class with four relationships
#include <iostream>
#include <string>
using namespace std;

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) { }
    ~Engine() { cout << "Engine destroyed" << endl; }
};

class GPS {
public:
    ~GPS() { cout << "GPS destroyed" << endl; }
};

class Driver {
private:
    string name;

public:
    Driver(const string& n) : name(n) { }
    ~Driver() { cout << "Driver destroyed" << endl; }
    string getName() const { return name; }
};

class GasStation {
public:
    double pricePerGallon() const { return 4.50; }
};

class Car {
private:
    Engine engine;     // composition: built and destroyed with the car
    GPS* gps;          // aggregation: installed now, moved to the next car later
    Driver* driver;    // association: works with the car, not part of it

public:
    Car(int hp) : engine(hp), gps(nullptr), driver(nullptr) { }
    ~Car() { cout << "Car destroyed" << endl; }   // no delete: Car owns only its engine

    void installGPS(GPS* unit) { gps = unit; }
    void setDriver(Driver* d) { driver = d; }

    // dependency: the station is used only during this call
    double refuel(const GasStation& station, double gallons) const {
        return station.pricePerGallon() * gallons;
    }
};

int main() {
    GPS unit;
    Driver ada("Ada");
    GasStation corner;

    {
        Car sedan(180);
        sedan.installGPS(&unit);
        sedan.setDriver(&ada);
        cout << "Refuel: $" << sedan.refuel(corner, 10) << endl;
    }                                  // sedan is destroyed here

    cout << "Car is gone; GPS and " << ada.getName() << " remain" << endl;
    return 0;
}
