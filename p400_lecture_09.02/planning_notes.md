# Planning Notes: p400_lecture_09.02

## Appendix Items to Include

Add these when the appendix is built (after all topics are approved).

- **Lambda Expressions: More Examples** — Generic lambdas. One slide showing a lambda with `auto` parameters. Mention that its `operator()` is a template; the full treatment is in the deferred Function Templates lecture.
- **Lambda Expressions: More Examples** — Immediately invoked lambdas. One slide showing a lambda called where it is defined to initialize a `const` variable that needs several steps of logic.
- **Lambda Expressions: Common Mistakes** — Missing semicolon after a lambda stored in a variable (`auto f = [] { ... };`).
- **Captures and Closures: More Examples** — Init captures (`[x = expr]`, C++14). One slide showing a capture initialized from an expression, such as `[count = 0]() mutable { return ++count; }`.
- **Captures and Closures: Common Mistakes** — Dangling reference capture. A code example of a function that returns a lambda capturing a local by reference; the local is destroyed before the lambda is called. This needs a function returning a lambda, so it is an exception to the prototypes-above-main style and belongs here rather than in the main slides.

## Deferred Topics

- std::function and Callbacks, Function Templates, and Class Templates are listed in `p400_inventory.csv` with lecture TBD.
