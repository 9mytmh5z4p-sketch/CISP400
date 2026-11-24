# Polymorphism Programming Activity: Instructor Notes

Lecture 13.02. Slides: Programming Activity, after Topic 4.

## Part 1: Build It (about 10 minutes)

Students write a base class with one `virtual` function, two public child classes that override it, one object of each class in `main`, an array of base class pointers, and a loop that calls the function through `->`.

Solution: `cpp/activity_band_solution.cpp`

```
An instrument makes a sound
Guitar strums: twang
Drum beats: boom boom
```

The array points at objects in `main` (`&horn`, `&guitar`, `&drum`), so there is no `new` and no `delete`. Deleting through a base pointer needs a virtual destructor, which is 14.01.

## Part 2: Break It (about 15 minutes)

One change at a time: predict, compile and run, then restore. Each broken version is in `cpp/activity_breaks/`. Results were checked with g++ 11.4 and `-Wall -Wextra`.

| # | Change | File | Result |
|:-:|---|---|---|
| 1 | Remove `virtual` from `Instrument::play()` | `break1_no_virtual.cpp` | `An instrument makes a sound` three times |
| 2 | `Instrument band[3] = {horn, guitar, drum};` and `band[i].play()` | `break2_array_of_objects.cpp` | `An instrument makes a sound` three times |
| 3 | `Guitar::play()` without `const` | `break3_guitar_no_const.cpp` | Base line, base line, `Drum beats: boom boom` |
| 4 | `virtual` on `Guitar::play()` only | `break4_virtual_in_child_only.cpp` | `An instrument makes a sound` three times |
| 5 | `class Guitar : Instrument` | `break5_no_public.cpp` | `error: 'Instrument' is an inaccessible base of 'Guitar'` |
| 6 | `band[i].play()` on the pointer array | `break6_dot_not_arrow.cpp` | `error: request for member 'play' in 'band[i]', which is of pointer type 'Instrument*' (maybe you meant to use '->' ?)` |

## Discussion Points

- **Same symptom, three causes.** Changes 1, 2, and 4 print exactly the same output. When a program prints the base class's version, check that the base function is `virtual`, that the call goes through a pointer or reference, and that the signatures match.
- **The silent one.** Change 3 compiles with no warning in g++ 11. Only the Guitar line changes, which is easy to miss in a longer list. clang warns that the child function hides the overloaded virtual function, and `override` (14.01) makes it a compile error.
- **Change 2 with `virtual` still present.** `virtual` cannot help an object that has been sliced: each array slot is a real `Instrument`.
- **Change 5 error location.** The error points at `&guitar` in the array line, not at the class line where `public` is missing, which mirrors 11.02's Forgot public.
- **Change 4.** `virtual` in a child affects only calls through a `Guitar*` and its descendants, never calls through an `Instrument*`.
