# Homework Assignment 2: Personalized C++ Program with Vectors and Functions

## Assignment Overview

For Homework Assignment 2, you will create a complete C++ program based on a creative theme of your choice. Your program should collect user input, use a vector, process values with functions, and display clear, logically correct results.

Everyone must meet the same technical requirements, but your theme, greeting, prompts, variable names, function names, calculations, and output wording should be personalized. This helps you practice the required C++ concepts while making your program distinct from your classmates' work.

Your program must compile, run, and produce output that makes sense for your chosen theme.

## Academic Integrity and AI Use

You may use AI tools to help explain concepts, review error messages, or understand lecture material. You may not use AI to write your program code for you.

Your submitted work should reflect your own thinking, theme, structure, variable names, calculations, functions, and output design. Personalized programs help reduce plagiarism similarity scores. The target plagiarism score is under 50%.

## Required Source File Header

Your program must begin with this source file header in a block comment:

```cpp
/*
 * Student Name: [Student's Full Name]
 * Date: [Submission Date]
 * Assignment: Homework Assignment 2
 * Program Description: [2-3 sentence description of what your program does]
 */
```

## Program Greeting

At the beginning of `main()`, call a distinct `ProgramGreeting` function. The greeting must display:

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

## Technical Requirements: 10 Required Tasks

Your program must complete all 10 tasks below.

### Task I: Create an IPO Model and Execution Trace Model

Before you begin coding, plan your program with an IPO Model and an Execution Trace Model. Include both completed models at the bottom of your source file inside block comments.

Your IPO Model must identify:

- **Input:** data entered by the user
- **Process:** calculations, vector operations, and function calls performed by the program
- **Output:** information displayed to the user

Use this format:

```cpp
/*
 * IPO Model
 *
 * Input:
 * - ...
 *
 * Process:
 * - ...
 *
 * Output:
 * - ...
 */
```

Your Execution Trace Model must show:

- Specific example input values
- Important variable changes
- At least one vector change, such as a value being added with `push_back`
- At least one function call, including the argument values and returned value or displayed action
- Expected output for that sample run

Use this format:

```cpp
/*
 * Execution Trace Model
 *
 * Sample Input:
 * - ...
 *
 * Variable and Vector Changes:
 * - ...
 *
 * Function Calls:
 * - ...
 *
 * Expected Output:
 * - ...
 */
```

### Task II: Include a Source File Header and Program Greeting Function

Place the required source file header at the very top of your `.cpp` file.

Create and use a `ProgramGreeting` function. This function should be a `void` function because its job is to display information, not calculate and return a value.

Your program must use function prototypes above `main()` and function definitions below `main()`.

### Task III: Use Arithmetic and `static_cast`

Use arithmetic calculations from the earlier homework material.

Your program must:

- Perform at least two meaningful calculations using user input
- Include at least one calculation where a decimal answer is needed
- Use `static_cast` to prevent an incorrect integer-division result
- Store at least one calculated result in a named variable
- Use at least one named constant where the value should not change

The calculations should fit your theme. Do not add disconnected arithmetic just to check a box.

### Task IV: Format Output Clearly

Use formatted output from the earlier homework material.

Your program must:

- Display results in a clean, readable format
- Use `fixed` and `setprecision` for decimal output
- Use `setw` for spacing
- Include at least one formatted table or aligned list
- Use labels that clearly describe the displayed values

The output should look intentional and should match your theme.

### Task V: Use Advanced Input Correctly

Collect both text input and numeric input from the user.

Your program must:

- Use `getline` for at least one full-line text value, such as a mission name, recipe title, route name, team name, or character name
- Use `cin >>` for numeric values
- Correctly handle the leftover newline when switching from `cin >>` to `getline`
- Include at least one basic input validation step for a numeric value

Your prompts should match your theme and clearly tell the user what to enter.

### Task VI: Use Random Numbers

Use random numbers in a way that fits your theme.

Your program must:

- Seed the random number generator once near the beginning of the program
- Generate at least one random number within a clear range
- Use the random value in a meaningful calculation, decision, or output message
- Make the range understandable from the code or output

For example, a travel planner might generate a random weather delay, or a game stats program might generate a bonus event.

### Task VII: Use a Vector

Use at least one `vector`.

Your program must:

- Include the correct library for vectors
- Declare a vector with an appropriate data type
- Add at least three values to the vector using `push_back`
- Use `.size()` somewhere meaningful
- Use `pop_back` only if it fits your program logic

The vector might store values such as fuel readings, scores, prices, ingredient amounts, energy readings, travel distances, or item weights.

### Task VIII: Use a Range-Based Loop

Use a range-based `for` loop to process values from your vector.

Your program must:

- Use a range-based `for` loop to process every value in the vector
- Use the loop for a meaningful purpose, such as calculating a total, finding an average, counting values, or displaying every value
- Use a clear loop variable name
- Avoid changing the vector inside the range-based loop

The range-based loop should be used when every value in the vector matters.

### Task IX: Use Function-Centered Architecture

Organize your program around functions instead of placing all logic inside `main()`.

Your program must:

- Include function prototypes above `main()`
- Define functions below `main()`
- Keep `main()` as the coordinator of the program
- Create at least four functions total, including `ProgramGreeting`
- Avoid nested function definitions
- Avoid global variables

Each function should have one clear job. Function names should describe what the function does or calculates.

### Task X: Pass Data To and From Functions

Use parameters, return values, and at least one vector parameter.

Your program must include:

- At least one function that takes one or more parameters
- At least one function that returns a calculated value
- At least one `void` function used for display or another action-only task
- At least one function that receives a vector as a parameter
- At least one place where a returned value is stored in a variable in `main()`

Design your functions around clear contracts: the function should receive the data it needs through parameters and should return or display exactly what its job requires.

## Theme Selection Guidance

Choose a theme that gives you natural reasons to collect several values, store repeated data in a vector, call functions, and display results.

Strong themes usually have:

- A clear scenario
- A personalized title
- One full-line text value
- Several numeric values
- A reason to process a collection
- A result that would be useful or interesting

Good theme examples:

- **Space Mission Calculator:** mission name, supply weights, fuel readings, random launch delay, total payload estimate
- **Recipe Nutrition Tracker:** recipe name, ingredient calorie values, servings, total calories, calories per serving
- **Road Trip Planner:** trip name, distances for each travel leg, fuel efficiency, total miles, estimated fuel cost
- **Fantasy Character Stats:** character name, item weights, ability scores, random bonus, total load or rating
- **Home Energy Calculator:** household name, appliance usage values, random peak-rate event, total and average usage
- **Event Budget Planner:** event name, category costs, guest count, total cost, cost per guest

Avoid themes that are too simple. A program that only asks for two numbers and adds them is not enough for this assignment.

## Program Structure Guidelines

Organize your program in a clear order:

1. Source file header
2. Include directives
3. `using namespace std;`
4. Function prototypes
5. `int main()`
6. Program greeting function call
7. Main input, calculation, function-call, and output coordination
8. `return 0;`
9. Function definitions
10. IPO Model block comment
11. Execution Trace Model block comment

Use comments to label major sections, but do not comment every single line. Comments should help the reader understand the purpose of each section.

## Submission Requirements

Submit your program through Canvas by the due date listed in Canvas.

Before submitting:

1. Make sure your program compiles without errors.
2. Run your program using realistic test input.
3. Check that the output is logically correct for your theme.
4. Save your completed source file.
5. Rename the file from `.cpp` to `.txt`.
6. Upload the `.txt` file to Canvas.

Example:

- Original file: `homework2.cpp`
- Submitted file: `homework2.txt`

Your instructor will download submissions, compile and execute them, and append program output to the end of the source file as a comment.

## Common Mistakes to Avoid

- Forgetting the source file header
- Writing the greeting directly in `main()` instead of calling a `ProgramGreeting` function
- Forgetting function prototypes above `main()`
- Defining a function inside another function
- Placing most of the program logic inside `main()`
- Using global variables instead of parameters and return values
- Mixing `cin >>` and `getline` without handling the leftover newline
- Forgetting to seed random numbers only once
- Forgetting `#include <vector>`
- Expecting a pass-by-value vector parameter to change the original vector
- Using integer division when a decimal answer is needed
- Putting the IPO Model or Execution Trace Model outside block comments
- Submitting the `.cpp` file instead of the required `.txt` file
- Letting AI write the code instead of writing it yourself

## Tips for Success

Start with your theme first. Decide what your program is supposed to help someone calculate, estimate, track, or summarize.

Plan the vector next. If your theme does not naturally have at least three values that can go into a vector, adjust the theme before you start coding.

Build in small steps. Make the greeting work first, then collect input, then add the vector, then add one function at a time.

Compile and run often. A program that is tested in small pieces is much easier to fix than a complete program tested only at the end.

Use realistic test values. If your result seems impossible for your theme, check your data types, arithmetic, division, vector contents, and function return values.

Make your program look like your work. Personalized names, prompts, labels, function names, and theme details will make your submission stronger and more original.
