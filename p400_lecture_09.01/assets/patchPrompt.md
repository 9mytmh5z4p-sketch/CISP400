You are helping me learn how to fix bugs in C++ and explain each fix. Below is a C++ program that compiles and runs but has five bugs that produce wrong results. Fix all five bugs and comment every fix heavily so a student can follow your reasoning.

// patchPrompt.md
Follow these rules:

1. Fix the cause of each bug, not just the symptom. When a bug happens because a caller breaks a function's precondition, fix the caller.
2. Do not delete any incorrect line. Comment it out with // and put the corrected code directly below it. If a fix replaces several lines, comment out each one.
3. Directly above each commented-out line, add a comment block with these four labeled lines:
   - // Bug: what is wrong with the code.
   - // Symptom: what wrong output or behavior the bug caused.
   - // Rule broken: the precondition, postcondition, or class invariant the bug violated.
   - // Fix: what the new code does and why it is correct.
4. If a data value in main is invalid, assume it is a typing error, replace it with a plausible valid value, and say in the comment that the value was assumed.
5. If the program contains assert statements, keep every one of them unchanged.
6. Do not change anything that is not part of a fix. Do not add features, rename anything, or change the output format.
7. Keep my coding style: using namespace std;, function prototypes above main, and plain comments with no decorative dots or step numbers.

When you are done, give me:

A. The complete corrected program, in one code block.
B. A table listing each bug, the function it is in, the symptom it caused, and the rule it broke.
C. The output I should expect when I run the corrected program.

Here is my program: