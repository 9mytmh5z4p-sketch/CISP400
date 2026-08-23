# Homework Assignment 4: Personalized C++ Program with Lambdas, Conversions, and Dynamic Data

## Assignment Overview

Create a complete C++ program based on a creative theme of your choice. Your program must use dependent objects, a lambda or functor, a conversion constructor or operator, overloaded stream operators, and a self-built dynamic collection.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment.
- Include a source-file header and a Program Greeting.
- Use prototypes above `main()` and definitions below `main()`.
- Keep `main()` as the coordinator and do not use global variables.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or any library container or data-structure class. Build required structures yourself with arrays, pointers, classes, structs, and helper functions.
- The program must produce logically consistent output.

## Technical Requirements: 10 Required Tasks

### Task 1: Establish a Personalized Program

- **1.1.** Choose one unifying theme for all objects and operations.
- **1.2.** Add a source-file header with your name, assignment name, and a two- to three-sentence description.
- **1.3.** Display a Program Greeting with your name, title or theme, and purpose.
- **1.4.** Personalize prompts, identifiers, calculations, and output wording.
- **1.5.** Connect every requirement to a meaningful part of the same program.

### Task 2: Create Dependent Objects

- **2.1.** Create at least four programmer-defined objects.
- **2.2.** Give each object a distinct theme-related responsibility.
- **2.3.** Establish dependency relationships among the objects.
- **2.4.** Use those objects together in at least one complete program workflow.
- **2.5.** Display results that show how the objects cooperate.

### Task 3: Use a Lambda or Functor

- **3.1.** Create at least one lambda expression or functor.
- **3.2.** Give it a theme-related task such as filtering, scoring, comparing, or transforming data.
- **3.3.** Pass the data it needs through parameters or captured local values.
- **3.4.** Call it during a real program operation.
- **3.5.** Display or use its result in a meaningful calculation, decision, or report.

### Task 4: Add a Conversion Feature

- **4.1.** Choose one object that has a meaningful primitive representation.
- **4.2.** Add a conversion constructor or conversion operator involving `int`, `float`, or `string`.
- **4.3.** Make the conversion direction clear from the declaration and use.
- **4.4.** Use the conversion in a real program operation.
- **4.5.** Display or process the converted value in a way that fits the theme.

### Task 5: Overload Stream Operators

- **5.1.** Overload `operator<<` for each required object.
- **5.2.** Overload `operator>>` for each required object.
- **5.3.** Make insertion display useful theme-related information.
- **5.4.** Make extraction collect or assign meaningful object data.
- **5.5.** Use both overloaded operators in the running program for every object type.

### Task 6: Manage Dynamic Data

- **6.1.** Create a dynamic-memory object or class for a collection of theme-related values.
- **6.2.** Allocate storage with `new` and track its size or capacity.
- **6.3.** Grow or shrink the collection by allocating replacement storage and copying values.
- **6.4.** Add an operation such as insert, remove, search, filter, or summarize.
- **6.5.** Release all owned memory with the correct form of `delete`.

### Task 7: Validate Input and Protect Assumptions

- **7.1.** Prompt for text and numeric data that fit the theme.
- **7.2.** Detect at least one failed input operation and recover with `cin.clear()` and `cin.ignore()` when needed.
- **7.3.** Check at least one range, set, or format condition.
- **7.4.** Include at least two assertions for meaningful assumptions or invariants.
- **7.5.** Prevent rejected input from entering objects, calculations, or the dynamic collection.

### Task 8: Display a Dynamic-Memory Summary

- **8.1.** Display the dynamic collection or its summary in a bordered table.
- **8.2.** Include visible top, bottom, left, and right borders.
- **8.3.** Include clear headings or labels.
- **8.4.** Align columns with `setw` or another formatting tool.
- **8.5.** Display at least three records or meaningful calculated results.

### Task 9: Organize the Program with Functions

- **9.1.** Create at least five programmer-defined functions or methods.
- **9.2.** Place prototypes above `main()` and definitions below `main()` where applicable.
- **9.3.** Keep `main()` as the coordinator rather than the location of all logic.
- **9.4.** Pass data through parameters and return values instead of global state.
- **9.5.** Give each function or method one clear responsibility.

### Task 10: Enforce Self-Built Data Structures

- **10.1.** Do not include `<vector>` or `<array>`.
- **10.2.** Do not use maps, stacks, queues, or equivalent library containers.
- **10.3.** Do not replace the required dynamic structure with another library class.
- **10.4.** Implement storage with your own arrays, pointers, classes, structs, and helper functions.
- **10.5.** Test the lambda or functor, conversion, stream operators, resizing, validation, output, and cleanup.

## Theme Selection Guidance

Choose a theme that gives a lambda or functor and an object conversion a natural purpose. Examples include a shipping estimator, game score manager, recipe converter, transit planner, media catalog, or event analytics tool. You may choose another theme that supports the requirements clearly.

## Submission Requirements

Submit the completed C++ source file through Canvas by **October 24, 2026**. Compile and test it with realistic and invalid input, verify conversions and overloaded operators, and confirm that all dynamic memory is released. Follow the syllabus for file naming, submission, and late-policy requirements.

## Final Reminder

The theme and implementation should be yours. Use AI for explanations, debugging support, or review, not to write the program.
