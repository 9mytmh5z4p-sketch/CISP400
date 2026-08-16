# Topics — p400_lecture_15.01

| Topic | Emphasis | Time Budget | Optional | Prerequisites | Tone Flag | Note |
|-------|----------|-------------|----------|---------------|-----------|------|
| Reference Variables — Review | standard | 8 | no | 04.02 | Students have seen this before — frame it as a quick contract refresher, not a re-teach. Keep it tight. | Contrast with pointers: ref is an alias, pointer is an address. When to use which. |
| What's the Output? | standard | 10 | no | Reference Variables — Review | | Two exercises on reference behavior and pointer aliasing. Placed immediately after the review so students are warmed up. |
| Heap vs. Stack | high | 8 | no | | Students find the lifetime distinction confusing — be concrete. | Lifetime, scope, who allocates and deallocates. Why the heap exists at all. |
| new and delete | high | 12 | no | Heap vs. Stack | | Scalar allocation only. Syntax, what happens in memory, the responsibility to delete. |
| Dynamic Arrays | standard | 10 | no | new and delete | | new int[n], variable-size at runtime, delete[]. Contrast with stack arrays and VLAs. |

---

## Field Guide

| Field | Notes |
|-------|-------|
| **Topic** | Name of the topic to cover |
| **Emphasis** | Leave blank for standard depth. Note if extra depth is needed, e.g. "students struggle with this" |
| **Time Budget** | Rough target in minutes, e.g. "10 min". Leave blank to let content dictate |
| **Optional** | Yes = cut if running short. Leave blank = required |
| **Prerequisites** | Topic or lecture number students need to have seen first. Leave blank if none |
| **Tone Flag** | Any framing notes, e.g. "students find this intimidating — be encouraging" |
| **Note** | Notes to myself regarding this topic. |
