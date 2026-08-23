# Homework Assignment 2: Personalized C++ Program with Objects, Structs, Assertions, and Dynamic Arrays

## Assignment Overview

Create a complete C++ program based on a creative theme of your choice. Your program must use objects with dependencies, a struct, assertions, and a self-built dynamic array in one coherent scenario. Everyone must meet the same technical requirements, but your theme, prompts, names, calculations, and output design should be personalized.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment.
- Include a source-file header and a Program Greeting.
- Use function prototypes above `main()` and definitions below `main()`.
- Keep `main()` as the coordinator and avoid global variables.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or any library container or data-structure class. Build the required structures yourself with classes or structs, ordinary arrays, pointers, and helper functions.
- The program must produce logically consistent output.

## Technical Requirements: 10 Required Tasks

### Task 1: Establish a Personalized Program

- **1.1.** Choose a single theme that gives every object and operation a natural role.
- **1.2.** Add a source-file header with your name, assignment name, and a two- to three-sentence description.
- **1.3.** Display a Program Greeting at the start with your name, program title or theme, and purpose.
- **1.4.** Personalize prompts, identifiers, calculations, and output wording.
- **1.5.** Integrate the requirements into one working program rather than isolated examples.

### Task 2: Create Objects with Dependencies

- **2.1.** Create at least three programmer-defined objects.
- **2.2.** Give each object a clear theme-related responsibility.
- **2.3.** Establish dependency relationships in which one object uses another object’s services or data.
- **2.4.** Use the objects together in at least one complete program operation.
- **2.5.** Display enough theme-related output to show how the objects cooperate.

### Task 3: Define and Use a Struct

- **3.1.** Define at least one struct with a meaningful theme-related name.
- **3.2.** Give the struct at least two related data members.
- **3.3.** Create and initialize at least one struct value.
- **3.4.** Use the struct as part of an object, array, or dynamic-array record.
- **3.5.** Display or process the struct data in a meaningful operation.

### Task 4: Protect Transformations with Assertions

- **4.1.** Include the `<cassert>` library.
- **4.2.** Use at least two `assert` statements.
- **4.3.** Place an assertion in or immediately before a transformation method to check a precondition.
- **4.4.** Place another assertion to check an internal assumption such as a valid index, nonnegative amount, or expected size.
- **4.5.** Add a brief comment before each assertion identifying the assumption being checked.

### Task 5: Build a Dynamic Array Structure

- **5.1.** Create a programmer-defined dynamic-memory function or class that owns a pointer and a current size or capacity.
- **5.2.** Allocate storage with `new` and store theme-appropriate records in it.
- **5.3.** Grow or shrink the storage by allocating a new array, copying the needed values, and releasing the old storage.
- **5.4.** Call the growth or shrink operation when the program needs a changed capacity.
- **5.5.** Release all owned dynamic memory correctly when the structure is finished.

### Task 6: Validate Input Robustly

- **6.1.** Prompt for text and numeric data that fit the theme.
- **6.2.** Detect at least one failed numeric input operation.
- **6.3.** Clear the failed stream state and remove invalid input before prompting again.
- **6.4.** Check at least one theme-appropriate range, set, or format condition.
- **6.5.** Repeat the prompt until valid input is received and do not process rejected data.

### Task 7: Use Objects and Functions Together

- **7.1.** Define function prototypes above `main()`.
- **7.2.** Create at least five programmer-defined functions or methods in total.
- **7.3.** Pass objects or struct values through parameters when that is the clearest design.
- **7.4.** Return at least one calculated or processed result to the caller.
- **7.5.** Keep each function or method focused on one clear responsibility.

### Task 8: Display a Bordered Table

- **8.1.** Display the processed records or summary in a table with a visible top border.
- **8.2.** Include a visible bottom, left, and right border.
- **8.3.** Add clear column headings or row labels.
- **8.4.** Align columns with `setw` or another formatting technique.
- **8.5.** Display at least three meaningful values or records.

### Task 9: Add a Repeatable Program Flow

- **9.1.** Provide a menu or repeat prompt that lets the user perform the central operation again.
- **9.2.** Validate the menu or repeat response.
- **9.3.** Preserve or intentionally reset the correct program state between runs.
- **9.4.** Display updated results after another run.
- **9.5.** Exit cleanly when the user chooses to stop.

### Task 10: Enforce the Data-Structure Restriction

- **10.1.** Do not include `<vector>` or `<array>`.
- **10.2.** Do not use maps, stacks, queues, or equivalent library containers.
- **10.3.** Do not substitute another library data-structure class for the required self-built structure.
- **10.4.** Implement storage and resizing with your own arrays, pointers, classes, structs, and helper functions.
- **10.5.** Test object dependencies, assertions, resizing, invalid input, output, and cleanup.

## Theme Selection Guidance

Choose a theme that naturally supports several collaborating objects and a growing or shrinking collection of records. Examples include a clinic intake system, inventory tracker, event registration tool, game roster, repair shop manager, or mission planner. You may choose any other theme that makes the required relationships useful.

## Submission Requirements

Submit the completed C++ source file through Canvas by **September 26, 2026**. Compile and test it with realistic and invalid input, confirm that assertions represent real assumptions, and verify that all dynamic memory is released. Follow the syllabus for file naming, submission, and late-policy requirements.

## Final Reminder

The theme and program design should be yours. Use AI only for conceptual support, error interpretation, or review; do not use AI to write the program for you.
