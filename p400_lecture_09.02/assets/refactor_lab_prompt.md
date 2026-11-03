# Lambda Refactor Lab Prompt

Copy everything between the lines below, then paste your entire program from `main.cpp` after it.

---

You are helping me learn how to use C++ lambda expressions with standard algorithms. Below is a working C++ program. Refactor it so that hand-written loops and functor classes are replaced with standard algorithms and lambdas wherever that makes the code clearer.

Follow these rules:

1. The program's output must stay exactly the same, character for character. The program checks this itself when it runs.
2. Do not change `main`, `EXPECTED_OUTPUT`, `checkOutput`, or anything below the comment that says "Output check: do not change anything below this line."
3. All roster output must keep going to the `out` stream parameter, not directly to `cout`.
4. Use algorithms from `<algorithm>`, such as `for_each`, `count_if`, `find_if`, and `sort`. Add `#include <algorithm>` and `#include <iterator>`.
5. Keep a hand-written loop wherever no single algorithm fits the job cleanly, and say why you kept it.
6. Do not change the `Student` class or the text of any output statement.
7. Directly above each lambda, add a plain-English comment of one or two sentences that says what the lambda captures and why each capture is by value or by reference.
8. Keep my coding style: `using namespace std;`, function prototypes above `main`, and plain comments with no decorative dots or step numbers.

When you are done, give me:

A. The complete refactored program, in one code block.
B. A table listing each original loop or class, what replaced it (or "kept"), and the capture list used.

Here is my program:

---

## How to Run the Lab

1. Copy `roster_loops.cpp` into `main.cpp` in your Replit project and click Run. The last line of the output should read "Output check: PASS."
2. Paste the prompt above and your program into an AI assistant.
3. Replace the contents of `main.cpp` with the AI's program and click Run.
4. If the output check says FAIL, it shows the first line that differs. Find which job printed that line and fix it yourself before asking the AI again.
5. Audit every lambda with the checklist on the slide. Fix anything it flags, then click Run again.
