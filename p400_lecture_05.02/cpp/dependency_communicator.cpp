#include <iostream>
#include <string>

using namespace std;

class Message {
private:
    string text;

public:
    Message(const string& t) : text(t) {}

    string getText() const {
        return text;
    }
};

class Messenger {
public:
    void deliverMessage(const Message& msg) {
        cout << "Delivering: " << msg.getText() << endl;
    }
};

class Communicator {
public:
    void start() {
        Message m("Mission Start");    // Local dependency
        Messenger courier;              // Another local dependency
        courier.deliverMessage(m);
    }
};

int main() {
    Communicator c;
    c.start();
    return 0;
}
