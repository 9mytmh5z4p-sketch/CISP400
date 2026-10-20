# Gradebook Assertion Lab: Answer Key (Instructor Only)

The buggy program runs to completion and prints wrong results. Once assertions are added, it stops at one bug per run, in this order.

| Run | Bug | Where | Buggy output | Assertion that catches it | Fix |
|---|---|---|---|---|---|
| 1 | Loop skips the last element (`i < count - 1`) | `highestScore` | Midterm highest is 95, should be 99 | Postcondition: result >= every stored score | Loop to `i < count` |
| 2 | Score of 105 accepted (typo for 95) | `main` / `addScore` | Final exam shows 105 | Precondition: 0 <= score <= 100 | Correct the score; asserting in `addScore` catches any caller |
| 3 | Curve pushes a score past 100 | `applyCurve` | Curved midterm shows 104 | Class invariant: every score 0 to 100 | Cap curved scores at 100 |
| 4 | Average of an empty gradebook divides by zero | `average` (and `highestScore`) | Makeup average is nan, highest is 0 | Precondition: count > 0 | Do not report an empty gradebook, or handle the empty case |
| 5 | Removing from an empty gradebook makes count negative | `removeLast` | Makeup size is -1 | Precondition: count > 0, then class invariant 0 <= count <= CAPACITY | Check size before removing |

Notes:

- Bug 4 also affects `highestScore`, which returns scores[0] for an empty gradebook. `average` is called first in `report`, so its assertion fires first.
- `addScore` has no capacity check, but no call exceeds CAPACITY. A good set of assertions will still include `count < CAPACITY`; point this out as a guard that never fires but protects future callers.
- AI output varies. If a student's version misses an assertion, the bug still shows in the output, which is itself a useful discussion point.
- Reference solution with assertions: `gradebook_asserted_reference.cpp`. All five assertions were tested in the order above, and the program runs cleanly once all five bugs are fixed.
