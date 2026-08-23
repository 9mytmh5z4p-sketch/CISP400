# Homework Assignment 6: Personalized C++ Program with Resource Management and Exceptions

## Assignment Overview

Create a complete C++ program based on a creative theme of your choice. Your program must use a class that owns dynamic memory, demonstrate deep copying and move operations, and detect and handle exceptional conditions. The resource-owning class should solve a meaningful problem in the theme rather than exist as an isolated language demonstration.

Everyone must meet the same technical requirements, but your theme, class names, prompts, data, calculations, and output should be personalized. Your program must compile, run, and produce logically consistent output.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment and compile with warnings enabled, including `-Wall`.
- Include a source-file header and a Program Greeting.
- Place function prototypes above `main()` and function definitions below `main()` where applicable.
- Keep `main()` as the program coordinator and do not use global variables.
- Give each function and method one clear responsibility.
- Use named constants rather than unexplained magic numbers.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or any equivalent library container or data-structure class. Build required collections with ordinary arrays, pointers, classes, structs, and helper functions.
- Do not use smart pointers for the required dynamic-memory work.
- Use whole-line comments for major logic and specification sections. End-of-line comments are permitted only beside variable declarations.

## Technical Requirements: 10 Required Tasks

### Task 1: Establish a Personalized Program

Your program must:

- **1.1.** Choose one unifying theme that gives the resource-owning class a natural purpose.
- **1.2.** Add a source-file header containing your name, assignment name, and a two- to three-sentence program description.
- **1.3.** Display a Program Greeting at the beginning with your name, program title or theme, and purpose.
- **1.4.** Personalize prompts, identifiers, calculations, and output wording.
- **1.5.** Integrate resource management and exceptions into the central program problem.

### Task 2: Design a Resource-Owning Class

Your program must:

- **2.1.** Create a programmer-defined class that owns dynamic memory through a raw pointer.
- **2.2.** Give the class a theme-related responsibility such as storing records, samples, readings, scores, or other related values.
- **2.3.** Track the logical size and allocated capacity of the owned data.
- **2.4.** Provide methods that access or modify the owned data safely.
- **2.5.** Keep the owned data private and expose a clear public interface.

### Task 3: Allocate, Resize, and Release Resources

Your program must:

- **3.1.** Allocate the class’s dynamic storage with `new` or `new[]`.
- **3.2.** Add a method that grows or replaces the storage when the current capacity is insufficient.
- **3.3.** Copy the needed values into replacement storage before releasing the old storage.
- **3.4.** Add at least one meaningful operation such as insert, remove, search, update, or summarize.
- **3.5.** Release the owned memory in the destructor with the matching form of `delete` or `delete[]`.

### Task 4: Implement a Deep-Copy Constructor

Your program must:

- **4.1.** Implement an explicit copy constructor for the resource-owning class.
- **4.2.** Allocate independent storage for the copied object.
- **4.3.** Copy the logical values and relevant size or capacity information.
- **4.4.** Demonstrate that changing the original object does not change the copy.
- **4.5.** Use a whole-line comment identifying the deep-copy implementation.

### Task 5: Implement Copy Assignment Safely

Your program must:

- **5.1.** Overload the assignment operator for the resource-owning class.
- **5.2.** Check for self-assignment before replacing owned resources.
- **5.3.** Release or replace the destination’s old storage safely.
- **5.4.** Copy the source values into independent destination storage.
- **5.5.** Demonstrate assignment between two meaningful objects in the running program.

### Task 6: Implement Move Construction and Move Assignment

Your program must:

- **6.1.** Implement a move constructor that transfers ownership from a temporary or expiring object.
- **6.2.** Set the moved-from object to a safe empty state.
- **6.3.** Implement move assignment for the resource-owning class.
- **6.4.** Release the destination’s old resource before taking ownership of the source resource.
- **6.5.** Demonstrate move construction or move assignment in a meaningful function call or return operation.

### Task 7: Create and Handle Exceptions

Your program must:

- **7.1.** Identify at least two exceptional conditions such as invalid size, out-of-range index, missing record, or impossible calculation.
- **7.2.** Create a custom exception class or use `std::runtime_error`.
- **7.3.** Throw an exception when one of the defined conditions occurs.
- **7.4.** Catch the exception in an appropriate caller.
- **7.5.** Display a useful message and prevent invalid data from being used after recovery.

### Task 8: Protect Class Invariants

Your program must:

- **8.1.** Define at least one invariant that must remain true for the resource-owning class.
- **8.2.** Check the invariant before or after an operation that could violate it.
- **8.3.** Use at least one assertion for a programmer assumption or internal state check.
- **8.4.** Use exception handling for invalid client input or recoverable runtime conditions.
- **8.5.** Keep the object valid after a failed operation or caught exception.

### Task 9: Use the Class in a Complete Program

Your program must:

- **9.1.** Create and use at least two objects of the resource-owning class.
- **9.2.** Pass an object to a function by an appropriate parameter style such as value, reference, pointer, or const reference.
- **9.3.** Call at least five programmer-defined functions or methods in addition to `main()`.
- **9.4.** Display a theme-appropriate report showing the data or results managed by the objects.
- **9.5.** Use the copy constructor, assignment operator, move operation, and exception path during a real testable program flow.

### Task 10: Test Resource Safety and Program Behavior

Your program must:

- **10.1.** Test normal construction, insertion or modification, copying, assignment, moving, and destruction.
- **10.2.** Test self-assignment and confirm that it leaves the object valid.
- **10.3.** Test every defined exception condition and verify the recovery message.
- **10.4.** Compile with `-Wall` and correct compiler warnings before submitting.
- **10.5.** Confirm that the program releases every dynamically allocated resource and produces logically correct output.

## Theme Selection Guidance

Choose a theme that naturally owns a variable-size collection or resource. Examples include a sensor-history manager, inventory record set, music playlist, image buffer, score archive, laboratory sample list, or simulation state. You may choose another theme if the class’s dynamic resource and copy/move behavior are meaningful.

## Submission Requirements

Submit the completed C++ source file through Canvas by **November 22, 2026**. Compile with `-Wall`, run normal and exceptional test cases, verify copy and move behavior, and confirm that all dynamic memory is released. Rename the source file from `.cpp` to `.txt` only when preparing the Canvas upload. Follow the syllabus for submission and late-policy requirements.

## Final Reminder

This assignment is about ownership and object lifetime. A correct program must continue to behave safely when objects are copied, assigned, moved, or asked to handle invalid operations.
