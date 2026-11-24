// hash_classes_virtual.h -- the same hierarchy with Display() virtual
#include <iostream>
#include <string>
using namespace std;

class Hash {
protected:
  string plainText;
public:
  Hash(string str = "Empty") {plainText = str;
      cout << endl;  // prints a blank line each time a Hash is built
                     }
  virtual void Display(){cout << "Base text: " << plainText << endl;};
};

class Toy : public Hash {
public:
    Toy(const string& s) : Hash(s){};
  virtual void Display() {
    unsigned int hash = 0;
    for (char c : plainText)
      hash = hash * 31 + c;  // Simple multiplicative hash algorithm
    cout << "Toy Hash of '" << plainText << "': " << hash << endl;
  }
};

class SHA256 : public Hash {
public:
    SHA256(const string& s = "Default") : Hash(s){};
  virtual void Display() {
    cout << "SHA-256 Hash of '" << plainText << "': ***SHA-256***" << endl;
  }
};

class SHA3 : public SHA256 {
public:
    SHA3(const string& s = "Default") : SHA256(s){};
  virtual void Display() {
    cout << "SHA-3 Hash of '" << plainText << "': ***SHA-3***" << endl;
  }
};
