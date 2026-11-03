# Unit Test Partner Lab: Instructor Notes

Do not post this file. Students receive `unit_test_partner_prompt.md` and `cpp/gradebook_lab_starter.cpp`, both safe to share in full.

## Where It Fits

After 10.01 Topic 7 (Unit Testing). The lab applies "work out expected values by hand," "what if assertions are turned off," and "unit or regression?" with an LLM as a partner that can see the code but may not use it as the answer key.

## Bugs in the Starter

| Bug | Where | Caught by a unit test? |
|---|---|---|
| `highestScore` loop stops at `i < count - 1`, missing the last score | Member function | Yes: a test with the largest score last |
| `applyCurve` has no cap at 100 | Member function | Yes: curve a score of 99 or 100 |
| `addScore(105)` is accepted | `runProgram` | No: breaks a precondition; this is the assertions' job |
| `report` on an empty gradebook divides by zero | `runProgram` | No: breaks a precondition |
| `removeLast` on an empty gradebook makes the count negative | `runProgram` | No: breaks a precondition |

Tests that stay inside the preconditions can find the first two bugs only. That is the intended lesson: unit tests catch a unit giving a wrong answer; assertions catch callers breaking the rules.

## Reference Tests

Both were run against the starter with g++ and fail as shown.

~~~cpp
bool testHighestScoreIncludesLastElement() {
    // Arrange: the largest score is added last
    Gradebook book;
    book.addScore(88);
    book.addScore(72);
    book.addScore(95);
    book.addScore(99);

    // Act
    int result = book.highestScore();

    // Assert: 99 is the largest of 88 72 95 99
    return check(result == 99, "highestScore includes the last score");
}

bool testCurveNeverExceeds100() {
    // Arrange
    Gradebook book;
    book.addScore(99);
    book.addScore(50);

    // Act
    book.applyCurve(5);

    // Assert: capped scores are 100 and 55, so the average is 155 / 2 = 77.5
    return check(closeEnough(book.average(), 77.5, 0.001), "a curve never pushes a score past 100");
}
~~~

With the sample test plus these two, the starter prints `3 tests run, 2 failed`. On the uncapped curve the buggy average is 104 / 2 + 55 / 2 = 79.5, so a student who expects 79.5 took the value from the code.

## Sample Specification

A complete specification a student might write from the file's comments:

1. A Gradebook holds at most 5 scores, and every score is from 0 to 100.
2. `addScore(score)` adds one score. Allowed only when the gradebook is not full and the score is 0 to 100.
3. `removeLast()` removes the most recently added score. Allowed only when the gradebook is not empty.
4. `applyCurve(points)` adds `points` to every score, but no score may go above 100.
5. `average()` returns the mean of the stored scores. Allowed only when the gradebook is not empty.
6. `highestScore()` returns the largest stored score, wherever it is. Allowed only when the gradebook is not empty.
7. `size()` returns how many scores are stored.

Item 4's cap comes from the class comment, "Every score should be between 0 and 100." Students who miss it will not test the curve cap; the LLM should ask about it in Step 1.

## Checking Specifications

Students see a `BankAccount` example in their handout, not this table. The Testable column here names the two lines that decide whether a suite can catch the bugs, so do not share it before the lab.

| Too vague to test | Testable | What the vague one misses |
|---|---|---|
| highestScore finds the highest score. | Returns the largest stored score, no matter when it was added. Needs at least one score. | Position, where the bug lives, and the precondition |
| applyCurve adds points. | Adds `points` to every score; no score may go above 100. | The cap from the class invariant |
| average gets the average. | Returns the mean as a `double`. Needs at least one score. | Precision and the empty case |
| addScore adds a score. | Adds one score from 0 to 100. Not allowed when 5 scores are stored. | Both preconditions |

While circulating, read two lines on each specification: does `highestScore` say "no matter when it was added," and does `applyCurve` mention the cap? A student missing either cannot write the test that catches that bug. Ask "Does it matter when the score was added?" or "What does the class comment say about every score?" rather than giving the line.

### Grading the Specification

| Level | Looks like |
|---|---|
| Strong | Every function has its precondition, return value, and effect; the cap and position both appear |
| Partial | Return values are present, but preconditions or the cap are missing |
| Weak | Each function's name restated, with nothing a test could check |

## Deliberate Breaks

Good changes for Step 3, and which tests should catch each. On the unfixed starter, students should break a function their suite currently passes, such as `size` or `average`, so a new FAIL is clearly caused by their change:

| Change | Caught by |
|---|---|
| Delete `count++;` in `addScore` | Any size test |
| `total / count` becomes `total / CAPACITY` in `average` | Any average test with fewer than 5 scores |
| `scores[i] > best` becomes `scores[i] < best` in `highestScore` | Any highest-score test with more than one score |
| `int best = scores[0];` becomes `int best = 0;` | Nothing on legal input, a useful discussion: the change is wrong only for negative scores, which the specification forbids |

## Running It in Class (about 30 minutes)

| Time | Students | Instructor |
|---|---|---|
| 3 min | Compile the starter, open a new chat, paste the prompt and the file | Check that each chat opens with the LLM's promise |
| 6 min | Write the specification, then a one-minute partner check | Circulate and read two lines on each specification (see Checking Specifications) |
| 11 min | Write four to six tests | Watch for expected values with no arithmetic |
| 5 min | Run, then break the code twice | Ask anyone whose suite passes on the starter to show the arithmetic |
| 5 min | Debrief | Whole-class question: "Whose tests passed on the buggy version, and why?" |

If time runs short, stop at four tests. Breaking the code on purpose matters more than the number of tests.

## Red Flags When Grading

- A suite that passes on the starter: the expected values came from the code or the program output.
- An expected value of 95 for the largest-last test, or 79.5 for the curve test: copied from the buggy behavior.
- No arithmetic shown, or arithmetic written after the test result.
- A test that calls `addScore(101)` or `average()` on an empty gradebook: a precondition violation. Compare the "What If Assertions Are Turned Off?" slide.
- A transcript where the LLM names a bug before Step 4. Not the student's fault if they noted it; check that they still worked the value out.
