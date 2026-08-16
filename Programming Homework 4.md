# Homework Assignment 4: Personalized C++ Program with Decisions, Loops, Menus, and 2D Data

## Assignment Overview

For Homework Assignment 4, you will create a complete C++ program based on a creative theme of your choice. Your program should collect user input, make decisions, validate ranges, repeat work with loops, display a menu, store related information in a multi-dimensional vector, and produce clear, logically correct output.

Everyone must meet the same technical requirements, but your theme, greeting, prompts, variable names, calculations, menu options, data categories, and output wording should be personalized. This helps you practice the required C++ concepts while making your program distinct from your classmates' work.

Your program must compile, run, and produce output that makes sense for your chosen theme.

## Academic Integrity and AI Use

You may use AI tools to help explain concepts, review error messages, or understand lecture material. You may not use AI to write your program code for you.

Your submitted work should reflect your own thinking, theme, structure, variable names, calculations, decisions, loops, and output design. Personalized programs help reduce plagiarism similarity scores. The target plagiarism score is under 50%.

## Required Source File Header

Your program must begin with this source file header in a block comment:

```cpp
/*
 * Student Name: [Student's Full Name]
 * Date: [Submission Date]
 * Assignment: Homework Assignment 4
 * Program Description: [2-3 sentence description of what your program does]
 */
```

The source file header is required, but it does not count as one of the 10 technical coding tasks.

## Program Greeting

At the beginning of `main()`, your program must display a distinct Program Greeting section. The greeting must display:

- Your name
- Your program title or theme
- A brief explanation of what the program does
- Personalized wording connected to your chosen theme

Example output format:

```text
================================
Welcome to [Program Name]
By: [Student Name]
================================
This program [brief description of what it does].
```

The program greeting is required, but it does not count as one of the 10 technical coding tasks.

## Technical Requirements: 10 Required Tasks

Your program must complete all 10 tasks below. Each task should fit naturally into your chosen theme. Do not add disconnected code just to check a box.

### Task 1: Use Functions and Parameters

Use function-centered program design from previous homework material.

Your program must:

- 1.1 Include function prototypes above `main()`.
- 1.2 Define functions below `main()`.
- 1.3 Keep `main()` as the coordinator of the program.
- 1.4 Create at least five functions total, not counting a greeting-only function.
- 1.5 Include at least one function that takes one or more parameters.
- 1.6 Include at least one function that returns a calculated or selected value.
- 1.7 Avoid global variables.

You may place your greeting in a function, but a greeting-only function does not satisfy any of the technical task requirements.

### Task 2: Format Output Clearly

Use formatted output from previous homework material.

Your program must:

- 2.1 Display results in a clean, readable format.
- 2.2 Use `fixed` and `setprecision` for decimal output when decimals are displayed.
- 2.3 Use `setw` for spacing in at least one report, table, menu, chart, or aligned list.
- 2.4 Use clear labels that describe the values being displayed.
- 2.5 Make the formatted output match your theme.

The output should look intentional and should help the user understand the result of the program.

### Task 3: Use Compound Conditions and Range Checking

Use compound conditions to decide whether input values are inside acceptable ranges.

Your program must:

- 3.1 Collect at least two numeric values from the user.
- 3.2 Check whether at least one value is inside a valid range using a compound condition.
- 3.3 Use `&&` or `||` in at least one meaningful condition.
- 3.4 Display a helpful message when a value is outside the expected range.
- 3.5 Prevent an out-of-range value from being used as though it were valid.

The ranges should make sense for your theme. For example, a rating, budget, score, quantity, time, distance, or category number can all have valid limits.

### Task 4: Use Nested `if` Statements

Use nested `if` statements when one decision depends on the result of another decision.

Your program must:

- 4.1 Include at least one nested `if` statement.
- 4.2 Make the outer decision check a broad condition or category.
- 4.3 Make the inner decision check a more specific condition.
- 4.4 Use the nested decision to produce a recommendation, status, warning, category, or result.
- 4.5 Make the nesting purposeful instead of replacing a simple one-level decision.

Good uses include rating a user choice after checking whether it is valid, assigning a recommendation after checking a category, or giving different warnings based on both status and severity.

### Task 5: Use the Conditional Operator

Use the conditional operator for a short either-or decision.

Your program must:

- 5.1 Use the conditional operator at least once.
- 5.2 Store the result of the conditional operator in a variable.
- 5.3 Use the stored result later in output or another decision.
- 5.4 Keep the conditional operator readable and limited to a simple choice.

Do not use the conditional operator for a long or complicated decision. Use an `if` statement when the decision needs multiple steps.

### Task 6: Use a `switch` Statement

Use a `switch` statement for a category, option, or menu-style selection.

Your program must:

- 6.1 Read a whole-number choice from the user.
- 6.2 Use a `switch` statement to respond to that choice.
- 6.3 Include at least three meaningful `case` labels.
- 6.4 Include a `default` case for unexpected choices.
- 6.5 Use `break` correctly to prevent unintended fall-through.

The choices should fit your theme. Avoid generic choices like "Option 1" unless the displayed text also explains what the option does.

### Task 7: Use a `while` Loop for Validation or Repeated Processing

Use a `while` loop when repetition depends on a condition.

Your program must:

- 7.1 Include at least one `while` loop.
- 7.2 Use the `while` loop for input validation, repeated processing, or continuing until a condition changes.
- 7.3 Update the loop condition inside the loop.
- 7.4 Display a helpful message when the loop asks the user to try again.
- 7.5 Avoid creating an infinite loop.

A strong use is asking again while a value is invalid, processing entries while the user wants to continue, or repeating until a limit is reached.

### Task 8: Use a `do-while` Loop for a Menu

Use a `do-while` loop for a menu-driven section that should run at least once.

Your program must:

- 8.1 Display a menu with at least three meaningful choices.
- 8.2 Place the menu inside a `do-while` loop.
- 8.3 Read the user's menu choice during each loop cycle.
- 8.4 Continue showing the menu until the user chooses to exit.
- 8.5 Use conditional logic or a `switch` statement to respond to the menu choice.
- 8.6 Include an exit choice that ends the menu cleanly.

Your menu should be part of the main purpose of the program, not a small add-on at the end.

### Task 9: Use a `for` Loop and a Text-Based Display

Use a `for` loop for counted repetition and generate a simple text-based display.

Your program must:

- 9.1 Include at least one `for` loop.
- 9.2 Use the `for` loop when the number of repetitions is known or controlled by a count.
- 9.3 Generate a simple text-based graph, chart, bar display, progress display, grid row, or repeated visual output.
- 9.4 Make the display connected to program data or user input.
- 9.5 Label the display clearly so the user understands what it represents.

For example, your program might display a bar chart of scores, a row of symbols for ratings, a weekly schedule grid, a progress tracker, or repeated category output.

### Task 10: Use Nested Loops and a Multi-Dimensional Vector

Use nested loops to process a multi-dimensional vector.

Your program must:

- 10.1 Declare and use at least one multi-dimensional vector.
- 10.2 Store related values in the multi-dimensional vector.
- 10.3 Use nested loops to visit the rows and columns of the vector.
- 10.4 Display the vector data in a readable table, grid, chart, or report.
- 10.5 Calculate at least one useful result from the vector data, such as a row total, column total, average, highest value, lowest value, or category summary.
- 10.6 Use labels or headings so the user can understand what each row and column represents.

The 2D data should fit your theme. For example, it could represent scores by round, expenses by category and week, inventory by shelf and item type, habits by day and activity, or ratings by player and category.

## Theme Selection Guidance

Choose a theme that gives you natural reasons to collect values, use decisions, repeat actions, display a menu, and organize information in rows and columns.

Strong themes usually have:

- A clear scenario
- A personalized title
- One or more full-line text values
- Several numeric values
- A reason to validate input ranges
- A reason to classify values or make recommendations
- A menu with meaningful choices
- A reason to repeat input or processing
- A reason to display a table, chart, graph, or grid
- A result that would be useful or interesting

Good theme examples:

- **Tournament Scoreboard:** track player scores across rounds, classify performance, and display a score grid
- **Restaurant Order Dashboard:** track menu choices, item quantities, category totals, and order recommendations
- **Fitness Progress Tracker:** track activities across days, validate effort ratings, and display progress bars
- **Study Planner:** track study time across subjects and days, classify workload, and recommend priorities
- **Travel Budget Planner:** track expenses across categories and trip days, validate budgets, and display spending charts
- **Game Stat Manager:** track character stats across levels, assign status messages, and display stat grids
- **Event Planning Assistant:** track guest groups, costs, choices, and readiness recommendations
- **Inventory Tracker:** track item counts across locations, flag low inventory, and display category summaries

Avoid themes that are too simple. A program that only asks for two numbers and prints a result is not enough for this assignment.

## Submission Requirements

Submit your completed program to Canvas by the due date listed in Canvas.

Before uploading:

1. Make sure your program compiles.
2. Run your program and confirm the output is logically correct.
3. Rename your source file from `.cpp` to `.txt`.
4. Upload the `.txt` file to Canvas.

Your instructor will download submissions and compile/execute them. Program output may be appended to the end of your submitted source file as a comment. Programs that do not compile will receive significant point deductions.

## Late Policy

A 50% deduction is automatically applied by Canvas when the due date passes and no submission has been received. If you submit the assignment later, that temporary deduction will be removed and replaced with the actual late penalty when I grade your work.

Late assignments are subject to a 3% per day late penalty. You may submit homework up to seven days after the due date, after which Canvas will close the assignment and no further submissions will be accepted.

## Final Reminder

This assignment is designed to give you structure and choice at the same time. The technical requirements are the same for everyone, but the theme and design should be yours. Use AI only for support with concepts, error messages, or reviewing lecture ideas. Do not use AI to write your program code.
