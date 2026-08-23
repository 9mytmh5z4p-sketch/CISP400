# Homework Assignment 5: Personalized C++ Program with Inheritance and Polymorphism

## Assignment Overview

Create a complete C++ program based on a creative theme of your choice. Your program must use aggregation or composition, an abstract base class with two child classes, polymorphic storage, a lambda or functor, a conversion feature, overloaded stream operators, and a self-built dynamic collection.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment.
- Include a source-file header and a Program Greeting.
- Use prototypes above `main()` and definitions below `main()`.
- Keep `main()` as the coordinator and do not use global variables.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or any library container or data-structure class. Build required structures yourself with arrays, pointers, classes, structs, and helper functions.
- The program must produce logically consistent output.

## Technical Requirements: 10 Required Tasks

### Task 1: Establish a Personalized Program

- **1.1.** Choose one unifying theme for the complete program.
- **1.2.** Add a source-file header with your name, assignment name, and a two- to three-sentence description.
- **1.3.** Display a Program Greeting with your name, title or theme, and purpose.
- **1.4.** Personalize prompts, identifiers, calculations, and output wording.
- **1.5.** Make each required relationship and operation useful within the same scenario.

### Task 2: Build Aggregation or Composition

- **2.1.** Create at least two objects with an aggregation or composition relationship.
- **2.2.** Give the related objects clear theme-based responsibilities.
- **2.3.** Make one object contain, own, or use the other object in a meaningful way.
- **2.4.** Use the relationship in at least one complete program operation.
- **2.5.** Display output that makes the relationship visible to the user.

### Task 3: Create an Abstract Base Class and Two Children

- **3.1.** Create a parent class that is an abstract base class.
- **3.2.** Give the parent at least one pure virtual function representing shared behavior.
- **3.3.** Create two child classes that inherit from the parent.
- **3.4.** Override the required virtual behavior in both child classes.
- **3.5.** Give the parent and children distinct, theme-appropriate responsibilities.

### Task 4: Use Polymorphic Storage

- **4.1.** Create a data structure that stores pointers to the child objects through the parent type.
- **4.2.** Use dynamic memory or another self-built pointer-based structure for that storage.
- **4.3.** Add at least one object of each child type to the structure.
- **4.4.** Traverse the structure through parent-type pointers and invoke virtual behavior.
- **4.5.** Display a report that demonstrates different child behavior through one interface.

### Task 5: Add a Lambda or Functor

- **5.1.** Create at least one lambda expression or functor.
- **5.2.** Give it a meaningful theme-related job such as filtering, ranking, scoring, or transforming.
- **5.3.** Supply its data through parameters or controlled local captures.
- **5.4.** Call it during a real program operation.
- **5.5.** Use its result in a decision, calculation, or displayed report.

### Task 6: Add a Conversion Feature

- **6.1.** Choose one object with a meaningful primitive representation.
- **6.2.** Add a conversion constructor or conversion operator involving `int`, `float`, or `string`.
- **6.3.** Make the conversion safe and appropriate for the object’s meaning.
- **6.4.** Use the conversion in a real program operation.
- **6.5.** Display or process the converted value in the chosen theme.

### Task 7: Overload Stream Operators and Validate Input

- **7.1.** Overload `operator<<` for each required object type.
- **7.2.** Overload `operator>>` for each required object type.
- **7.3.** Prompt for theme-appropriate object data and use extraction in the running program.
- **7.4.** Detect failed or out-of-range input, recover, and re-prompt.
- **7.5.** Use insertion to display meaningful object information in the final report.

### Task 8: Manage a Self-Built Dynamic Collection

- **8.1.** Create a dynamic-memory object or class with a pointer and size or capacity.
- **8.2.** Store polymorphic child objects or another required theme-related collection in it.
- **8.3.** Grow or shrink the collection by allocating replacement storage and copying or moving the needed pointers or values.
- **8.4.** Implement at least one additional operation such as insert, remove, search, filter, or summarize.
- **8.5.** Release every owned object and every allocated array correctly.

### Task 9: Display a Bordered Polymorphic Report

- **9.1.** Display a summary of the dynamic collection in a bordered table or report.
- **9.2.** Include visible top, bottom, left, and right borders.
- **9.3.** Include clear headings or labels.
- **9.4.** Use `setw` or another formatting technique to align the output.
- **9.5.** Display at least three meaningful records, results, or polymorphic actions.

### Task 10: Enforce Self-Built Data Structures and Test the Program

- **10.1.** Do not include `<vector>` or `<array>`.
- **10.2.** Do not use maps, stacks, queues, or equivalent library containers.
- **10.3.** Do not replace the required polymorphic collection with a library data-structure class.
- **10.4.** Implement storage with your own arrays, pointers, classes, structs, and helper functions.
- **10.5.** Test inheritance, polymorphism, relationships, conversion, stream operators, resizing, validation, output, and cleanup.

## Theme Selection Guidance

Choose a theme that naturally supports a parent category with two specialized child categories and a separate composed or aggregated object. Examples include a transportation planner, media library, game character manager, staffing system, animal-care system, or payment processor. You may choose another theme that makes the relationships clear and useful.

## Submission Requirements

Submit the completed C++ source file through Canvas by **November 7, 2026**. Compile and test it with realistic and invalid input, verify polymorphic behavior and object cleanup, and confirm that all dynamic memory is released. Follow the syllabus for file naming, submission, and late-policy requirements.

## Final Reminder

The theme, class names, relationships, prompts, calculations, and output should be your own. Use AI for conceptual support, debugging, or review, not to write the program.
