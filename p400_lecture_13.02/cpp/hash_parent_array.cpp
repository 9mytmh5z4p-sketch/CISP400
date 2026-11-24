// hash_parent_array.cpp -- the same Toys in an array of the parent class
#include "hash_classes.h"

int main() {
  Hash myToys[3]{Toy("Hello World"), Toy("Semper Fi"),
    Toy("The happiness of your life depends upon the quality of your thoughts.")};

  for (auto h : myToys) h.Display();

return 0;
}
