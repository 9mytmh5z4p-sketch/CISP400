# Homework Assignment 3: Personalized C++ Program with Stream Operators and Dynamic Data

## Assignment Overview

Create a complete C++ program based on a creative theme of your choice. Your program must coordinate at least four dependent objects, overload stream insertion and extraction for each object, use assertions, and manage a dynamic collection without library containers.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment.
- Include a source-file header and a Program Greeting.
- Use prototypes above `main()` and definitions below `main()`.
- Keep `main()` as the coordinator and do not use global variables.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or any library container or data-structure class. Build the required dynamic structures yourself with arrays, pointers, classes, structs, and helper functions.
- The program must produce logically consistent output.

## Technical Requirements: 10 Required Tasks

### Task 1: Establish a Personalized Program

- **1.1.** Choose one coherent theme for the program.
- **1.2.** Add a source-file header with your name, assignment name, and a two- to three-sentence description.
- **1.3.** Display a Program Greeting with your name, title or theme, and program purpose.
- **1.4.** Personalize identifiers, prompts, calculations, and output wording.
- **1.5.** Make every required object and operation contribute to the same scenario.

### Task 2: Create a Network of Objects

- **2.1.** Create at least four programmer-defined objects.
- **2.2.** Give each object a distinct theme-related responsibility.
- **2.3.** Establish dependency relationships among the objects.
- **2.4.** Use the objects in a complete operation that changes or summarizes program data.
- **2.5.** Display output that makes the relationships understandable.

### Task 3: Define a Struct Record

- **3.1.** Define at least one theme-related struct.
- **3.2.** Give the struct at least two related members.
- **3.3.** Create and initialize struct records.
- **3.4.** Store or pass the records through the program’s dynamic structure.
- **3.5.** Use the record data in a calculation, search, or displayed summary.

### Task 4: Overload Stream Operators

- **4.1.** Overload `operator<<` for each required object.
- **4.2.** Overload `operator>>` for each required object.
- **4.3.** Make insertion produce useful theme-related output.
- **4.4.** Make extraction collect or assign meaningful object data.
- **4.5.** Use the overloaded operators in the running program for every object type.

### Task 5: Protect Object Transformations

- **5.1.** Include `<cassert>`.
- **5.2.** Use an assertion to protect a transformation method’s precondition.
- **5.3.** Use a second assertion for an internal invariant such as a valid index, size, or nonnegative result.
- **5.4.** Add comments identifying the assumptions checked by the assertions.
- **5.5.** Make the asserted conditions meaningful to the theme and program state.

### Task 6: Manage a Dynamic Collection

- **6.1.** Create a dynamic-memory object or class that stores a collection of theme-related values.
- **6.2.** Allocate the collection with `new`.
- **6.3.** Grow or shrink it by allocating replacement storage and copying the needed values.
- **6.4.** Add at least one operation besides resizing, such as insert, remove, search, or summarize.
- **6.5.** Release all dynamic memory with the correct form of `delete`.

### Task 7: Validate Input and Use Object Extraction

- **7.1.** Prompt the user for object data appropriate to the theme.
- **7.2.** Use at least one overloaded extraction operator to collect object data.
- **7.3.** Detect failed or out-of-range input.
- **7.4.** Clear and recover from invalid input before trying again.
- **7.5.** Prevent invalid data from entering the object or dynamic collection.

### Task 8: Display a Dynamic-Memory Summary

- **8.1.** Display a summary of the dynamic collection in a bordered table.
- **8.2.** Include top, bottom, left, and right borders.
- **8.3.** Include clear column headings or row labels.
- **8.4.** Align the output with `setw` or similar formatting.
- **8.5.** Show at least three records or meaningful calculated values.

### Task 9: Organize the Program with Functions

- **9.1.** Create at least five programmer-defined functions or methods in total.
- **9.2.** Keep prototypes above `main()` and definitions below `main()` where applicable.
- **9.3.** Pass the data each function needs through parameters.
- **9.4.** Return at least one result instead of relying on global state.
- **9.5.** Keep `main()` focused on coordinating the program.

### Task 10: Enforce Self-Built Data Structures

- **10.1.** Do not include `<vector>` or `<array>`.
- **10.2.** Do not use maps, stacks, queues, or equivalent library containers.
- **10.3.** Do not hide the required collection inside a library data-structure class.
- **10.4.** Implement the collection with your own arrays, pointers, classes, structs, and helper functions.
- **10.5.** Test stream operators, dependencies, assertions, resizing, invalid input, output, and cleanup.

## Theme Selection Guidance

Choose a theme that naturally supports four collaborating objects and a collection of records. Examples include a reservation system, sports roster, museum catalog, laboratory sample tracker, game campaign manager, or equipment checkout system. You may choose another theme that makes the object relationships meaningful.

## Submission Requirements

Submit the completed C++ source file through Canvas by **October 10, 2026**. Compile and test it with realistic and invalid input, verify that stream operators behave correctly, and confirm that all dynamic memory is released. Follow the syllabus for file naming, submission, and late-policy requirements.

## Final Reminder

The theme, object names, prompts, calculations, and output should be your own. Use AI for support with concepts or debugging, not to write the program.
