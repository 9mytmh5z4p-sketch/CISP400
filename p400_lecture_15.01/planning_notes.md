# Planning Notes — p400_lecture_15.01

Lecture 14.02 was deliberately revised to use scalar dynamic allocations only. Introduce the deferred array-specific material in this lecture rather than assuming students have already seen it.

## Deferred from 14.02

- Runtime-sized arrays with `new Type[size]`
- Matching `new[]` with `delete[]`
- Why scalar and array deallocation forms must not be mixed
- Preserving the base address required by `delete[]`
- Out-of-bounds access in dynamic arrays
- Leaks caused by losing the only pointer to a dynamic array
- Early-return cleanup for dynamic arrays
- `unique_ptr<Type[]>` and `make_unique<Type[]>(size)`
- The fact that `unique_ptr<Type[]>` manages lifetime but does not track array size or provide bounds checking

Begin with a brief scalar `new`/`delete` ownership review, then extend the same allocate–use–release model to arrays. Use explicit scalar-versus-array comparisons before any resizing algorithm.
