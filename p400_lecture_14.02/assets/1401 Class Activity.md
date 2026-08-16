# 1401 Class Activity

### Let's start off with some work with functions

+ Create a global variable and display it's contents from 2 functions: funcOne() and funcTwo().

```C++
#include <iostream>
using namespace std;

// Global variable
int globalVar = 42;

// Function Prototypes
void funcOne();
void funcTwo();


int main() {
    cout << "Main sees globalVar = " << globalVar << endl;
    funcOne();
    funcTwo();

    return 0;
}
// Function 1
void funcOne() {
    cout << "funcOne sees globalVar = " << globalVar << endl;
}

// Function 2
void funcTwo() {
    cout << "funcTwo sees globalVar = " << globalVar << endl;
}
```

+ Now, comment out the global variable. What happens?

+ Create an int in main(). Modify funcOne only to accept the variable from main(). Use comments on funcTwo() so your program will run.


#include <iostream>
using namespace std;

// Global variable
//int globalVar = 42;

// Function Prototypes
void funcOne(int);
void funcTwo();


int main() {
	int mainVar = 142;
    cout << "Main sees mainVar = " << mainVar << endl;
    funcOne(mainVar);
    funcTwo();

    return 0;
}
// Function 1
void funcOne(int var) {
    cout << "funcOne sees mainVar = " << var << endl;
}

// Function 2
void funcTwo() {
    //cout << "funcTwo sees globalVar = " << globalVar << endl;
}

### Recap
We see how using a global variable can allow functions access to variables we would otherwise need to pass around. Now, let's introduce heap variables.

+ Comment out mainVar. Create and initialize an int heapVar. See if you can get the two functions to display it. Don't forget to clean up afterwards.

```C+
#include <iostream>
using namespace std;

// Global variable
//int globalVar = 42;

// Gives security folks heart attacks
int* ptr = new int{1046};

// Function Prototypes
void funcOne(int*);
void funcTwo();


int main() {
	//int mainVar = 142;
	//int* ptr = new int{1046}; no funcTwo
    cout << "Main sees mainVar = " << *ptr << endl;
    funcOne(ptr);
    funcTwo();

    // clean up
    delete ptr;
    ptr = nullptr;
    return 0;
}
// Function 1
void funcOne(int* var) {
    cout << "funcOne sees mainVar = " << *var << endl;
}

// Function 2
void funcTwo() {
    cout << "funcTwo sees mainVar = " << *ptr << endl;
}
```

### Recap
We learned that even though we can have variables on the heap, they are not global variables unless we declare them in the global space.

* Heap allocation does not make something global
* Only declaring a variable in global scope makes it global
* A heap object is only accessible if something points to it

This is good because it means that otherwise heap data would have security through obscurity only.

### Heap Arrays

+ Let's go ahead and work with arrays on the heap.
+ Create a 5 int array on the heap. Create a randFunc() to randomly assign an integer between 1 and 100 to each cell. Display the array in main().

```C++
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

// Global pointer (still here to match your original structure)
int* ptr = new int{1046};

// Function Prototypes
void funcOne(int*);
void funcTwo();
void randFunc(int*, int);

int main() {
    // Seed random generator
    srand(time(0));

    cout << "Main sees mainVar = " << *ptr << endl;
    funcOne(ptr);
    funcTwo();

    // Create array on heap
    int size = 5;
    int* arr = new int[size];

    // Fill array with random values
    randFunc(arr, size);

    // Display array in main
    cout << "\nArray contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Clean up
    delete ptr;
    ptr = nullptr;

    delete[] arr;
    arr = nullptr;

    return 0;
}

// Function 1
void funcOne(int* var) {
    cout << "funcOne sees mainVar = " << *var << endl;
}

// Function 2
void funcTwo() {
    cout << "funcTwo sees mainVar = " << *ptr << endl;
}

// Fill array with random numbers (1–100)
void randFunc(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}
```

### Summary
This looks very similar to an array but it's a heap variable. We already learned how to use pointers and arrays, this is no different - it just points to a different place in memory.


### Mind Bender

+ in main, build a 3 element array of int pointers. Initialize to nullptr; Then, initialize each array element with an int on the heap (single int). Display the values of your array.

```C++
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

// Global pointer (still here to match your original structure)
int* ptr = new int{1046};

// Function Prototypes
void funcOne(int*);
void funcTwo();
void randFunc(int*, int);

int main() {
    // Seed random generator
    srand(time(0));

    cout << "Main sees mainVar = " << *ptr << endl;
    funcOne(ptr);
    funcTwo();

    // Create array on heap
    int size = 5;
    int* arr = new int[size];

    // Fill array with random values
    randFunc(arr, size);

    // Display array in main
    cout << "\nArray contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ===== NEW TASK =====
    // Array of 3 int pointers (on stack)
    int* ptrArr[3] = { nullptr, nullptr, nullptr };

    // Allocate each element on the heap
    for (int i = 0; i < 3; i++) {
        ptrArr[i] = new int(rand() % 100 + 1);
    }

    // Display values
    cout << "\nPointer array contents: \n";
    for (int i = 0; i < 3; i++) {
        cout << ptrArr[i] << ": " << *ptrArr[i] << endl;
    }
    cout << endl;

    // Clean up pointer array
    for (int i = 0; i < 3; i++) {
        delete ptrArr[i];
        ptrArr[i] = nullptr;
    }
    // ===== END TASK =====

    // Clean up
    delete ptr;
    ptr = nullptr;

    delete[] arr;
    arr = nullptr;

    return 0;
}

// Function 1
void funcOne(int* var) {
    cout << "funcOne sees mainVar = " << *var << endl;
}

// Function 2
void funcTwo() {
    cout << "funcTwo sees mainVar = " << *ptr << endl;
}

// Fill array with random numbers (1–100)
void randFunc(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}
```

### Recap

This  forces you to think about pointer-to-pointer structure and ownership.
Mentally
ptrArr[0] --> int
ptrArr[1] --> int
ptrArr[2] --> int

One question - if arrays are so compact on the stack, why is there so much space here on the heap. Normally an int would be 4 bytes, here its 0x20 or 32 bytes. Extra space is often added to align memory with some multiple, either 16 or 32 bytes. That's how the allocator in the OS works for small data sizes.

Note: if we allocated an array of ints instead of pointer to ints that block of heap memory WOULD BE contigious and each index would be separated by 4 bytes.




