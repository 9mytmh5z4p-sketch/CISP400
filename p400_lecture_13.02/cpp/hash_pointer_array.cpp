// hash_pointer_array.cpp -- an array of pointers to the parent class
#include "hash_classes.h"

int main() {
  Hash* myToys[4];
  myToys[0] = new Hash("Hello World");
  myToys[1] = new Toy("Semper Fi");
  myToys[2] = new SHA256(
    "The happiness of your life depends upon the quality of your thoughts.");
  myToys[3] = new SHA3("Done!");


  for (auto h : myToys) h->Display();    // remember to change me

return 0;
}
