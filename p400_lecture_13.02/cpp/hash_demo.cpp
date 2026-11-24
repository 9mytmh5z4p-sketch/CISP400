// hash_demo.cpp -- each object calls its own Display()
#include "hash_classes.h"

int main() {
  Hash h("Welcome");
  h.Display();

  Toy t("Complex text");
  t.Display();

  SHA256 sha("More text");
  sha.Display();

  SHA3 sha3("Almost done");
  sha3.Display();

return 0;
}
