// activity_band_solution.cpp
// Programming Activity, Part 1: a working polymorphic array.
#include <iostream>
using namespace std;

class Instrument {
public:
    virtual void play() const {
        cout << "An instrument makes a sound" << endl;
    }
};

class Guitar : public Instrument {
public:
    void play() const {
        cout << "Guitar strums: twang" << endl;
    }
};

class Drum : public Instrument {
public:
    void play() const {
        cout << "Drum beats: boom boom" << endl;
    }
};

int main() {
    Instrument horn;
    Guitar guitar;
    Drum drum;

    Instrument* band[3] = {&horn, &guitar, &drum};

    for (int i = 0; i < 3; i++) {
        band[i].play();
    }
    return 0;
}
