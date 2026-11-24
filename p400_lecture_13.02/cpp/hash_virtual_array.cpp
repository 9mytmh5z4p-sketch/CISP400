// hash_virtual_array.cpp -- the same pointer array, with Display() virtual
#include "hash_classes_virtual.h"

int main() {
  Hash* myToys[4];
  myToys[0] = new Hash("Hello World");
  myToys[1] = new Toy("Semper Fi");
  myToys[2] = new SHA256(
    "The happiness of your life depends upon the quality of your thoughts.");
  myToys[3] = new SHA3("Done!");


  for (auto h : myToys) h->Display();

return 0;
}
