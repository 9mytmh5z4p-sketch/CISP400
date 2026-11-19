# CISP 400 — Instructor's Answer Sheet

**Scott Meyers — Make Sure Public Inheritance Models "Is-a"**

## Instructional Objectives

Upon completion of this activity, students should be able to:

1. Identify the members a derived object inherits from its base class.
2. Apply the is-a test to the behavior of a base class, not only to its name.
3. Explain how a class hierarchy can let the compiler reject an impossible operation.
4. Explain how a derived constructor passes arguments to its base class.
5. Explain why a derived class cannot use a base class's private data directly.
6. Justify a class-hierarchy design decision using technical reasoning.

## Background — Meyers's Design Principle

Scott Meyers's *Effective C++* states its advice as short, numbered items. Item 32, "Make sure public inheritance models 'is-a,'" argues that public inheritance is a promise: everything that applies to a base class object must apply to a derived class object.

Meyers uses birds and penguins to show that an English sentence that sounds right is not enough. Penguins are birds, but if the `Bird` class promises that every bird can fly, `Penguin` cannot keep that promise.

For this activity, the central distinction is:

**The real world:** What is true of the things being modeled.

**The program's promise:** What the base class guarantees to every piece of code that uses it.

Meyers prefers designs in which the compiler rejects an invalid operation, such as asking a penguin to fly, over designs that allow it and fail, or behave wrongly, at run time.

The programs are instructional illustrations inspired by Meyers's published item, not code written by Meyers.

Related item: Item 38, "Model 'has-a' or 'is-implemented-in-terms-of' through composition."

## Question 1 — What Does a Penguin Contain?

**Expected answer**

| Member | Where it comes from |
|---|---|
| `name` | Inherited from `Bird` (private, so `Penguin` cannot use it directly) |
| `Bird(const string&)` | Not inherited; `Penguin` calls it from its own constructor |
| `getName()` | Inherited from `Bird` |
| `fly()` | Inherited from `Bird` |
| `Penguin(const string&)` | Written in `Penguin` |
| `swim()` | Written in `Penguin` |

**Teaching point:** `Penguin` never mentions `fly()`, yet every penguin has it. Inheriting brings every public member along, which is exactly the problem.

**Potential misconception:** Students may list `name` as missing because `Penguin` cannot touch it. It is present in every `Penguin` object; it is only inaccessible.

### Private Data

**Expected answer**

`swim()` calls the public `getName()` that `Penguin` inherited from `Bird`.

It cannot use `name` directly. `name` is private, and private means this class only; a derived class is an outsider too.

**Teaching point:** Keeping `name` private and sharing a getter is 11.02's recommended design. Making `name` protected would also work, but every derived class would then depend on how `Bird` stores it.

## Question 2 — Applying the Is-a Test

**Expected output**

Program 1 prints:

```text
Pingu swims
Pingu flaps its wings and flies
```

The second line is false: penguins cannot fly. For reference, Program 2 prints `Pingu swims` and `Jack flaps its wings and flies`.

**Teaching point:** Both programs compile and run. Program 1 is not a compile error or a crash; it is a program that confidently says something false.

### Is the Output True?

**Expected answer**

"A Penguin is a Bird" is true in biology. In Program 1 it is false, because `Bird` promises `fly()`, and a penguin cannot fly.

The is-a test from last lecture must hold for everything the base class can do, not just for the class names.

**Teaching point:** The base class's public interface is a list of promises. A derived class that cannot keep one of them is not a true is-a.

## Question 3 — Understanding Program 2

**Expected answer**

The line does not compile:

```text
error: 'class Penguin' has no member named 'fly'
```

In Program 2, `fly()` lives in `FlyingBird`. `Penguin` inherits from `Bird`, which makes no promise about flying, so penguins never get `fly()`.

This is better than Program 1. The mistake is caught by the compiler, before the program runs, instead of producing wrong output that someone has to notice.

**Teaching point:** A good hierarchy makes an impossible operation impossible to write.

### Discussion Extension

Ask students whether Program 2 is "more correct biology."

**Expected response:** Not really. Program 2 is more accurate about what this program needs: some birds fly and some do not. A program that never mentions flying would be correct with a single `Bird` class.

## Question 4 — Building the Bird Part

**Expected answer**

`Penguin(const string& n) : Bird(n) { }` passes the name up to `Bird`'s constructor in the member initializer list.

**Extension, if time allows:** ask what would happen if `Penguin`'s constructor assigned `name = n;` in its body. It would not compile, for two reasons: `Bird` has no default constructor, so the `Bird` part cannot be built before the body runs, and `name` is private to `Bird`.

The parts of `jack` are built in this order: `Bird`, then `FlyingBird`, then `Sparrow`. They are destroyed in the reverse order.

**Teaching point:** This reviews 11.02's base class construction and construction order.

## Question 5 — Making a Design Decision

**Expected answer**

Program 2 is the stronger starting point: `Eagle` derives from `FlyingBird`, and `Ostrich` derives from `Bird`.

`Duck` is the hard case. It flies and swims, but only `Penguin` has `swim()`. Students might propose a `SwimmingBird` class, then notice that a duck needs both, which leads toward multiple inheritance (covered later in this lecture).

Potential advantages of Program 2's design include:

- The compiler rejects asking a flightless bird to fly.
- Each class promises only what its objects can do.

Potential disadvantages include:

- Every new ability can add a new class, and combinations multiply: flying, swimming, flying and swimming.
- The hierarchy must be redesigned when a new combination appears.

A strong answer notices that abilities like flying and swimming may be better modeled as has-a parts than as levels of a hierarchy, which is Meyers's Item 38.

**Teaching point:** Neither design is universally correct. The right hierarchy depends on what the program promises its callers.

## Class Discussion — Suggested Facilitation

Begin by asking which program students would rather maintain.

Invite several students to explain their choices before introducing Meyers's position.

Next, ask what is wrong with Program 1. Guide students to see that nothing is wrong with the C++; the problem is a promise in `Bird` that `Penguin` cannot keep.

Then ask whether Program 2 models birds better. Guide students toward recognizing that it models this program's needs better, which is the point of the discussion question.

Finally, return to Meyers's central idea:

**Public inheritance is a promise: everything true of a base class object must be true of a derived class object.**

Students should recognize that this principle must be balanced against the cost of a deeper hierarchy and the alternative of has-a.

Bridge to today's lecture: Topic 1 introduces overriding, which lets a derived class change how an inherited function behaves. Ask students to keep the penguin in mind. An override that changes what a function promises is the same mistake in a new form.

## Suggested Assessment Criteria

| Criterion | Strong evidence of understanding |
|---|---|
| Inheritance review | Correctly lists inherited and written members, including the private, inaccessible `name` |
| Is-a reasoning | Applies the is-a test to the base class's behavior, not just its name |
| Compiler as checker | Explains why Program 2's compile error is preferable to Program 1's output |
| Construction review | Explains `: Bird(n)` and the build order of `jack` |
| Design analysis | Identifies a meaningful advantage and limitation of the chosen hierarchy |

## References

Scott Meyers, *Effective C++: 55 Specific Ways to Improve Your Programs and Designs*, Third Edition, Addison-Wesley, 2005. Item 32, "Make sure public inheritance models 'is-a,'" and Item 38, "Model 'has-a' or 'is-implemented-in-terms-of' through composition."

learncpp, Introduction to inheritance:

https://www.learncpp.com/cpp-tutorial/introduction-to-inheritance/

All examples conform to C++17.
