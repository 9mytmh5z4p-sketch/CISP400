# Bug Hunt: Table of Errors (Instructor)

Lecture 11.01 activity. Students get `cpp/bug_hunt_starter.cpp`; the answer key is `cpp/bug_hunt_instructor.cpp`.

Students can use any compiler, including a web-based one. No special build flags are needed.

## Part 1: The Three Bugs

Students usually find them in this order, because each fix exposes the next.

| # | Where | What students see | Cause | Fix | Lecture topic |
|---|-------|-------------------|-------|-----|---------------|
| 1 | `Course` constructor | Compile error: `no matching function for call to 'Roster::Roster()'` | Members are built before the constructor body runs. `roster` must be built first with `Roster()`, which does not exist. The assignment in the body comes too late. | Build the members in the initializer list: `Course(const string& t, int seats) : title(t), roster(seats) {}` | Topic 3: Aggregation and Composition ("Does This Compile?") |
| 2 | `printOpenSeats(oop.getRoster().seats());` in `main` | Compiles and runs, but prints `Open seats: 3` when two of three seats are filled. The right answer is 1. | The call passes the int `3` instead of the roster. `Roster(int)` is not `explicit`, so C++ quietly builds a temporary empty `Roster` with 3 seats and reports on it. | Pass the roster: `printOpenSeats(oop.getRoster());`. Mark `Roster(int)` as `explicit` so the mistake becomes a compile error. | Topic 1: Conversion Review (`explicit`) |
| 3 | The block holding `Instructor adjunct("Ng");` in `main` | The output prints `(Ng has left)` and then, on the next line, `taught by Ng`. The course reports an instructor who no longer exists. | `oop` keeps a pointer to `adjunct`, but `adjunct` is destroyed at the closing brace of the block. `print()` then reads a dead object. This is aggregation gone wrong: the part does not outlive the whole. | Declare `adjunct` in `main` before `oop`, so it is built first and destroyed last. | Topic 4: Relationship Applications ("A Pointer with No Owner") |

## Part 2: Adding Exceptions

| Requirement | Code in the answer key |
|-------------|------------------------|
| Include the header | `#include <stdexcept>` |
| Constructor refuses a bad capacity | In `Roster(int)`: `if (capacity < 1) throw runtime_error("capacity must be at least 1");` |
| `add()` refuses when full | Replace the silent `if` with `if (size() >= capacity) throw runtime_error(...);` and keep `push_back` after it |
| Catch both in `main` | One `try` that enrolls a 4th student, and one `try` that builds `Course empty("CISP 401", 0);`. Each has `catch (const runtime_error& e)` printing `e.what()` |

Expected output of the answer key:

```
CISP 400: 2 of 3 seats filled, taught by Ng
Open seats: 1
Error: roster is full: Dee not added
Error: capacity must be at least 1
CISP 400: 3 of 3 seats filled, taught by Ng
(Ng has left)
```

The answer key's last line is correct: `adjunct` was declared first, so it is destroyed last, after `oop`.

## Discussion Points

- **Bug 3 prints the right name.** The destroyed `Instructor` usually still holds "Ng" in memory, so the output looks correct. Only the destructor's message gives it away. Undefined behavior that prints the right answer is still a bug. Ask students what the output would show without the destructor message.
- **Cam got in, Dee did not.** The exception stops the `try` block at `Dee`, but `Cam` was already added. That is why the final line shows 3 of 3.
- **`empty.print()` never runs.** When a constructor throws, the object never exists, so there is nothing to print and no destructor runs (Topic 5, "When the Constructor Throws").
- **Why throw instead of the old silent `if`?** The original `add()` dropped students with no warning, which is a fourth, quieter bug. A good follow-up question is "Which is worse: crashing, or silently losing data?"
- **Bug 2 with `explicit` added.** If a student marks the constructor `explicit` before fixing the call, the compiler points straight at the bad line. That is what `explicit` is for.
