// hash_toy_array.cpp -- an array of Toy objects
#include "hash_classes.h"

int main() {
  Toy myToys[3]{Toy("Hello World"), Toy("Semper Fi"),
    Toy("The happiness of your life depends upon the quality of your thoughts.")};

  for (auto h : myToys) h.Display();

return 0;
}
