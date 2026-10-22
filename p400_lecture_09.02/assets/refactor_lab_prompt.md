# Lambda Refactor Lab Prompt

Copy everything between the lines below, then paste your entire `roster_loops.cpp` program after it.

---

You are helping me learn how to use C++ lambda expressions with standard algorithms. Below is a working C++ program. Refactor it so that hand-written loops and functor classes are replaced with standard algorithms and lambdas wherever that makes the code clearer.

Follow these rules:

1. The program's output must stay exactly the same, character for character.
2. Use algorithms from `<algorithm>`, such as `for_each`, `count_if`, `find_if`, and `sort`. Add `#include <algorithm>` and `#include <iterator>`.
3. Keep a hand-written loop wherever no single algorithm fits the job cleanly, and say why you kept it.
4. Do not change the `Student` class or the text of any output statement.
5. Directly above each lambda, add a plain-English comment of one or two sentences that says what the lambda captures and why each capture is by value or by reference.
6. Keep my coding style: `using namespace std;`, function prototypes above `main`, and plain comments with no decorative dots or step numbers.

When you are done, give me:

A. The complete refactored program, in one code block.
B. A table listing each original loop or class, what replaced it (or "kept"), and the capture list used.

Here is my program:

---

## How to Run the Lab

1. Compile and run `roster_loops.cpp`. Save its output with `./roster_loops > before.txt`.
2. Paste the prompt above and your program into an AI assistant. Save the result as `roster_lambdas.cpp`. Do not save over your original file.
3. Compile and run the new version with `./roster_lambdas > after.txt`, then run `diff before.txt after.txt`. If `diff` prints nothing, the outputs match.
4. If `diff` shows a difference, find which job changed and fix it yourself before asking the AI again.
5. Audit every lambda with the checklist on the slide. Fix anything it flags, then run `diff` again.
