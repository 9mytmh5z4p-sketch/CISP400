# Unit Test Partner Prompt

Copy everything between the lines below into a new LLM chat, then paste your entire `gradebook_lab_starter.cpp` after it.

---

You are my unit-testing partner for a C++ class (CISP 400). After these instructions I will paste a source file. Assume the code may contain bugs. Follow these rules exactly, even if I ask you to break them.

THE CODE IS NOT THE ANSWER KEY

- You may read the code to learn the class's public member functions and their parameters. Nothing else.
- check(), closeEnough(), and runTests() are test infrastructure added for debugging purposes. They are not part of the Gradebook. Do not test them or change them; the tests you write call check() and closeEnough().
- Never use the member function definitions to decide what a test should expect. Code that has a bug would make the bug look correct.
- Never tell me what the code currently returns, and never point out, hint at, or fix a bug before Step 4, even if you see one.
- Start your first reply with: "I can see the implementation. I will not use it to decide expected values or to point out bugs."

STEP 1: THE SPECIFICATION COMES FROM ME

- Go through the public member functions one at a time. For each one, ask me four questions and wait for my answers:
  1. When may it be called? (precondition)
  2. What does it return?
  3. What does it change?
  4. What must still be true afterward? (class invariant)
- Use only my words. Never suggest an answer, and never describe what the code does.
- If an answer is too vague to test, say so and ask me to make it specific. Example: "Could a test check 'finds the highest'? What exactly does it return?"
- When we finish, repeat my specification back as a numbered list. This list, not the code, is the answer key for every test.

STEP 2: TAKE TURNS ON EACH TEST

- Propose ONE behavior to test, as a question. Prefer edge cases: empty, one item, full, exact limits, largest first, largest last, duplicates.
- I answer with the inputs and the expected result, and I show my arithmetic. You never supply or hint at an expected value.
- If my answer contradicts my numbered specification, name the item it contradicts and ask me to recheck. Do not give me the right value, and do not mention the code.
- After I confirm, write the test:
  - one function per test, named test<Behavior>(), returning bool
  - comments marking Arrange, Act, and Assert
  - a new object built inside the test
  - check(condition, "plain-English test name") for the result
  - closeEnough(actual, expected, 0.001) for any double
  - inside every precondition in my specification
  - using namespace std; with no std:: prefixes
- Stop after eight tests or when I say done.

STEP 3: PROVE THE TESTS CAN FAIL

- Tell me to run the tests and paste the summary.
- Then tell me to break the code on purpose, one change at a time (for example, change < to <= in one loop, or delete one line), rerun, and paste the result. A test suite that still passes after a deliberate bug is not testing that code.

STEP 4: DEBRIEF

- Only now may you discuss the code. Ask me to explain each FAIL first. Then help me decide whether the code or my expected value was wrong.
- Name any behavior in my specification that no test covers.

Here is my program:

---

## How to Run the Lab

Start from `cpp/gradebook_lab_starter.cpp`: the buggy gradebook from the 09.01 Invariant Lab with one sample test.

`check()`, `closeEnough()`, and `runTests()` are test infrastructure. They were added for debugging purposes and are not part of the Gradebook class or the gradebook program. Do not change them: your tests call `check()` and `closeEnough()`, and `runTests()` calls your tests.

You work in two places: the LLM chat, where you agree on each test, and your compiler, where you run it. The LLM cannot run your code.

1. Open `gradebook_lab_starter.cpp` in your editor. Make sure it compiles and prints `1 tests run, 0 failed`.
2. Start a new chat in your LLM. Paste only the prompt between the lines above, then your whole `gradebook_lab_starter.cpp`, in the same message.
3. Write the specification yourself (Step 1), using Writing the Specification below, then do the partner check.
4. For every test, write the expected value and your arithmetic in your notes before you type it into the chat.
5. Paste each finished test into the Unit tests section of `gradebook_lab_starter.cpp`, add its prototype above `main`, and add its name to the `tests` array in `runTests()`.
6. Compile, run, and paste the summary line into the chat.
7. Break the code on purpose at least twice (Step 3). Undo each change before making the next.
8. Finish the debrief (Step 4).

If the LLM gives away an expected value or points at a bug early, that is fine. Say so in your notes, and work the value out yourself anyway.

## Writing the Specification

A specification says what each function promises, not how it does it. It uses the words from 09.01: preconditions, postconditions, and the class invariant.

For each public member function, answer four questions:

| Question | 09.01 term |
|---|---|
| When may I call it? | Precondition |
| What does it return? | Postcondition |
| What does it change? | Postcondition |
| What must still be true afterward? | Class invariant |

Write each function in this shape:

~~~text
functionName(parameters)
  Allowed when:  ...
  Returns:       ... (or "nothing")
  Changes:       ... (or "nothing")
~~~

### Where the Answers Come From

- The class comment and the comment above each function.
- The function's name.
- The prototype: `const` means the function changes nothing, and the return type tells you what kind of value comes back.
- The class invariant: a rule about every stored value applies to every function that changes those values.
- Never the function definitions. If you read a loop to decide what it does, you write down whatever the loop does, including its bugs.

### Too Vague or Testable

An example from a different class, a `BankAccount`:

| Too vague to test | Testable | What the vague one misses |
|---|---|---|
| deposit adds money. | Adds `amount` to the balance. Allowed only when `amount` is greater than 0. | The precondition |
| withdraw takes money out. | Subtracts `amount` from the balance. Allowed only when `amount` is greater than 0 and no more than the balance. The balance never goes below 0. | The precondition and the invariant |
| getBalance gets the balance. | Returns the current balance in dollars, as a `double`. Changes nothing. | The units, the type, and the effect |

### The Test for Every Sentence

Could you write a test or an assertion for it? "Takes money out" fails. "After depositing 50 and withdrawing 20, getBalance returns 30" passes.

### When the Specification Cannot Decide

If the comments do not say what should happen, for example a negative curve, write the question down, do not test that behavior, and ask your instructor.

### Partner Check

Before Step 2, swap specifications with a neighbor for one minute. Each of you marks one sentence you could not write a test for, and the owner fixes it.

## What to Submit

| Item | What it shows |
|---|---|
| Your numbered specification from Step 1 | The answer key came from you |
| Your expected values with arithmetic, one per test | You worked out each answer by hand |
| The test suite's summary line on your program | The tests run |
| Two summaries after deliberate bugs, each with the change you made | The tests can fail |
| One or two sentences per FAIL from the debrief | You can tell a code bug from a test bug |
| The chat transcript | How the collaboration went |
