# Lambda Refactor Lab: Answer Key (Instructor Only)

Reference solution: `cpp/roster_lambdas_reference.cpp`. Its output was checked with `diff` against `roster_loops.cpp` and matches exactly.

Every student score is unique, so `sort` produces the same order as the selection sort. Ties would let the two sorts order equal students differently, which `diff` would flag for reasons unrelated to lambdas.

## Expected Output

```
Roster
  Ada 88
  Linus 64
  Grace 93
  Alan 55
  Barbara 79
  Dennis 71
Passing: 4
First failing: Linus

After a 3 point curve, highest first
  Grace 96
  Ada 91
  Barbara 82
  Dennis 74
  Linus 67
  Alan 58
Honors: 2
A: 2  B: 1  C: 1  D: 1  F: 1
```

## Job by Job

| Job | Original | Refactor | Correct capture | Parameter | Audit notes |
|---|---|---|---|---|---|
| Print the roster | Index loop in `printRoster` | `for_each(roster, roster + size, ...)` | `[]` | `const Student&` | Keeping the index loop is also acceptable; it is already clear. A range-based for does not work here because the array parameter has decayed to a pointer. |
| Count passing | Counting loop | `count_if` | `[passing]` | `const Student&` | `[&]` or `[&passing]` works but overstates what the lambda needs. |
| First failing | Loop with `break` and an index of -1 | `find_if` returning `Student*` | `[passing]` | `const Student&` | Must compare the result with `end(roster)` before dereferencing. The index of -1 sentinel disappears. |
| Apply the curve | Loop calling `addPoints` | `for_each` | `[curve]` | `Student&` | `const Student&` will not compile because `addPoints` is not const. A by-value `Student` parameter compiles but changes only copies, and `diff` catches it: the curve never appears. |
| Sort by score | Selection sort | `sort` with a comparator | `[]` | `const Student&` | Comparator must use `>`, not `>=`. By-value `Student` parameters compile but copy two objects per comparison. |
| Count honors | `ScoreAtLeast` functor in a counting loop | `count_if` with a lambda, functor class deleted | `[honorsMinimum]` or a literal 90 | `const Student&` | Passing the existing `honors` functor object straight to `count_if` is also correct and worth discussing: the algorithm accepts any callable. |
| Tally letter grades | One-pass loop with five counters | Kept as a loop | None | None | This is the trap. See below. |

## The Trap: Letter-Grade Tally

The tally computes five results in one pass. No single algorithm does that, so it should stay a loop (slide 47). Converting it to a range-based for is a fine cleanup.

Two tempting wrong answers, both of which pass `diff`:

1. **`for_each` with a lambda capturing five counters through `[&]`.** It works, but it is a loop wearing an algorithm costume, and `[&]` hides which five variables the lambda changes. This is the habit the audit is designed to catch.
2. **Five separate `count_if` calls**, one per letter. Each call is correct, but the program now walks the roster five times to do one pass of work.

## What AI Tools Commonly Get Wrong

- Writing `[&]` or `[=]` for every lambda instead of naming captures.
- Taking `Student` by value in the comparator or predicates.
- Dereferencing the `find_if` result without checking it against `end`.
- Converting the tally loop.
- Using `>=` in the comparator. Rare, but it breaks `sort`.

AI output varies. If a student's AI produces a clean refactor, the audit still has value: the student must justify each capture and parameter against the checklist.
