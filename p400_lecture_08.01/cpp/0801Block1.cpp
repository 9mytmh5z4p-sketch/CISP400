//0801Block1.cpp
int x = 5;        // x is an lvalue; 5 is an rvalue
int y = x + 3;    // x + 3 is an rvalue (a temporary result)

&x;               // OK: x has an address
 &5;            // error: a literal has no address
 &(x + 3);      // error: a temporary result has no address

 x + 3 = 10;    // error: you can't assign to an rvalue