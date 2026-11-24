// hash_mixed_array.cpp -- a mixed array of the parent class
#include "hash_classes.h"

int main() {
  Hash myToys[4]{Hash("Hello World"), Toy("Semper Fi"),
    SHA256("The happiness of your life depends upon the quality of your thoughts."),
    SHA3("Done!")};


  for (auto h : myToys) h.Display();

return 0;
}
