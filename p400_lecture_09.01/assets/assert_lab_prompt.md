# Assertion Lab Prompt

Copy everything between the lines below, then paste your entire `gradebook_buggy.cpp` program after it.

---

You are helping me learn how to use C++ assertions to find bugs. Below is a C++ program that runs but produces wrong results. Do NOT fix any bugs. Your only job is to add assertions that will detect the bugs when I run the program, and to explain each one.

Follow these rules:

1. Add `#include <cassert>` and use the standard `assert` macro. Do not use exceptions, if-statements, or error messages in place of asserts.
2. Do not change, remove, or reorder any existing line of code. Only add new lines.
3. Use the form `assert(condition && "short message");` so the failure message explains what went wrong.
4. Look for these kinds of conditions and add asserts for each one that applies:
   - Preconditions: what must be true when a function starts (check at the top of the function).
   - Postconditions: what the function promises is true when it returns (check just before `return`).
   - Class invariants: what must always be true about the object's data. Put these in a private member function named `checkInvariant()` and call it at the end of every member function that changes the object.
5. Never put a side effect inside an assert. For example, no `++`, `--`, `=`, or function calls that change data.
6. Directly above each assert, add a plain-English comment of one or two sentences that says (a) what condition is being checked and whether it is a precondition, postcondition, or class invariant, and (b) why the program would be wrong if the condition were false.
7. Keep my coding style: `using namespace std;`, function prototypes above `main`, and plain comments with no decorative dots or step numbers.

When you are done, give me:

A. The complete program with your asserts added, in one code block.
B. A short table listing each assert, the function it is in, and the kind of condition (precondition, postcondition, or class invariant).

Do not tell me which bugs exist or how to fix them. I will find them by running the program.

Here is my program:

---

## How to Run the Lab

1. Compile and run `gradebook_buggy.cpp`. Read the output carefully and write down anything that looks wrong.
2. Paste the prompt above and your program into an AI assistant.
3. Compile and run the new version. The program stops at the first assertion that fails.
4. Read the failure message, find the cause, and fix that one bug. Do not remove the assert.
5. Rerun. Repeat until the program runs to the end with no assertion failures.
