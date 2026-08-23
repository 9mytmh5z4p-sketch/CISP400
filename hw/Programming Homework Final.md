# Final Programming Assignment: Genetic Algorithm Robots

## Assignment Overview

Create a C++ simulation of a population of robots that evolves strategies for collecting energy on a grid. Each robot uses sensor readings to select movement actions through a chromosome of genes. Robots that collect more energy survive longer and contribute genes to later generations.

This project is based on the genetic-algorithm robot experiment described in the assignment handout. Your program must implement the same simulation model and required rules below. You may personalize names, output wording, constants, display style, and optional enhancements, but do not replace the genetic-algorithm robot project with an unrelated AI application.

The project will be introduced in late October and is due on the last day of class. Use the time between introduction and the deadline to build and test the simulation incrementally.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment and compile with warnings enabled, including `-Wall`.
- Include a source-file header with the program name, your name, date, and course.
- Display a Program Greeting as soon as the program runs.
- Place function prototypes above `main()` and function definitions below `main()`.
- Give each function one clear responsibility and pass data through parameters and return values.
- Do not use global variables. Use named constants for values that should not change.
- Use C++ libraries rather than C-only headers unless a C library feature has not been ported to C++.
- Do not use non-standard compiler extensions.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or any equivalent library container or data-structure class. Build the required maps, populations, chromosomes, and statistics with ordinary arrays, pointers, classes, structs, and helper functions.
- Do not use smart pointers for the required dynamic-memory work.
- Use whole-line comments for major logic and specification sections. End-of-line comments are permitted only beside variable declarations.
- Add a brief comment below each function signature explaining what the function does.

## Technical Requirements: 10 Program Tasks

Treat each task as a substantial program function or functional subsystem. The tasks follow the actual simulation pipeline: create the map, create robots, sense and move, evaluate fitness, reproduce, mutate, run generations, and aggregate results.

### Task 1: Create and Display the Main Grid

Your program must:

- **1.1.** Add a source-file header containing the program name, your name, date, and course.
- **1.2.** Display a Program Greeting that identifies the genetic-algorithm robot simulation and its objective.
- **1.3.** Create a 10 x 10 grid using a self-built representation such as a built-in two-dimensional array or your own class and dynamic storage.
- **1.4.** Populate approximately 40 percent of the grid squares with batteries and represent open and wall cells distinctly.
- **1.5.** Create a function that initializes and, if desired, displays the grid; use a newly generated map for each robot run.

### Task 2: Represent Robot Sensors, Genes, and Actions

Your program must:

- **2.1.** Represent four sensors that read the adjacent North, South, East, and West squares.
- **2.2.** Represent the sensor states for no object, wall, battery, and do not care.
- **2.3.** Represent a robot chromosome containing exactly 16 genes.
- **2.4.** Represent each gene with five codes: four sensor-match codes and one action code.
- **2.5.** Represent the five permitted actions: move North, South, East, West, or in a random direction.

### Task 3: Create and Initialize the Robot Population

Your program must:

- **3.1.** Create a population of 200 robots for the initial generation.
- **3.2.** Randomly generate the sensor-to-action mappings for the first population only.
- **3.3.** Give every new robot five units of starting power.
- **3.4.** Give every robot a turn counter and fitness or energy-collection value initialized for its run.
- **3.5.** Create a function that initializes the population and stores the robots using your own arrays, pointers, classes, and helper functions.

### Task 4: Read Sensors and Select a Robot Action

Your program must:

- **4.1.** Create a function that reads the four adjacent map locations for the current robot position.
- **4.2.** Encode the sensor readings using the program’s defined sensor-state codes.
- **4.3.** Compare the current four-sensor state against the robot’s 16 genes.
- **4.4.** Execute the action from the first gene whose four sensor codes match exactly.
- **4.5.** Execute the sixteenth gene when no earlier gene matches, and support the random-direction action.

### Task 5: Move a Robot and Manage Energy

Your program must:

- **5.1.** Create a function that performs one robot turn and attempts the selected movement.
- **5.2.** Subtract one power unit for every movement attempt, including an invalid move into a wall or outside the grid.
- **5.3.** Keep the robot in its original square after an invalid movement.
- **5.4.** Add five power units when the robot successfully enters a square containing a battery and consume that battery.
- **5.5.** Continue turns until the robot runs out of energy and record the number of turns the robot survives.

### Task 6: Run a Generation and Calculate Fitness

Your program must:

- **6.1.** Run every robot in the current population through its own randomly generated map.
- **6.2.** Reset each robot’s run-specific position, power, turn count, and harvested-energy value before its run.
- **6.3.** Record a fitness value based on the total power or energy harvested by each robot.
- **6.4.** Record the number of turns each robot survives.
- **6.5.** Calculate and save the population’s average fitness for the completed generation.

### Task 7: Select Parents and Reproduce the Next Population

Your program must:

- **7.1.** Sort or rank the population by fitness so the highest-performing robots can be selected.
- **7.2.** Remove or exclude the lowest-performing 50 percent of the population from reproduction.
- **7.3.** Pair the surviving robots in descending fitness order, beginning with the highest two, then the next two, and so forth.
- **7.4.** Create two children from each parent pair while keeping the population at 200 robots.
- **7.5.** Give each child genes from both parents, with each parent contributing half of the 16 genes or an equivalent documented swap scheme.

### Task 8: Mutate Genes and Manage Dynamic Storage

Your program must:

- **8.1.** Apply a 5 percent mutation chance to individual gene swaps during reproduction.
- **8.2.** When a mutation occurs, randomly change one code in the affected gene.
- **8.3.** Create helper functions to grow, shrink, copy, or replace any dynamic array used for robots, genes, maps, or generation statistics.
- **8.4.** Implement deep-copy behavior for any class that owns dynamic memory, using a copy constructor or overloaded assignment operator.
- **8.5.** Release all dynamically allocated memory correctly and do not substitute `<vector>`, `<array>`, or another library container.

### Task 9: Run Multiple Generations and Track Evolution

Your program must:

- **9.1.** Create a function that repeats the generation process for a user-selected or named number of generations.
- **9.2.** Use randomly generated genes only for the first population; later populations must come from reproduction and mutation.
- **9.3.** Preserve and display the average fitness value for every completed generation.
- **9.4.** Track a meaningful generation-level result such as best fitness, average turns survived, or best robot genes.
- **9.5.** Include at least one lambda or functor, one assertion, and one exception path in meaningful simulation or validation work.

### Task 10: Aggregate and Display Results Across Generations

Your program must:

- **10.1.** Create a function that aggregates the saved results across all generations.
- **10.2.** Display the average fitness score for each generation after the simulation completes.
- **10.3.** Display the best-performing robot or generation result with enough information to explain its success.
- **10.4.** Display a bordered summary table with visible top, bottom, left, and right borders; a console graph of average fitness is optional.
- **10.5.** Test compilation with `-Wall`, map generation, sensor matching, invalid movement, battery consumption, population size, reproduction, mutation, multiple generations, exception handling, and memory cleanup.

## Required Specification Comments

Use a whole-line comment immediately before the principal code for each required specification. Number comments by task and subtask, and add a short description. For example:

```cpp
// Specification 4.3 - Compare the sensor state against each gene
```

Do not place all specification comments at the top of the source file. Comment the first location where each specification is implemented. Use the following command before submitting to verify that the comments are visible:

```text
grep -i "specification" homework.cpp
```

## Optional Enhancements

Optional enhancements may include obstacles, predator robots, two-square vision, robot memory, a console fitness graph, robots with multiple partners, adjustable mutation rates, or tracking how many generations a specific robot survives. An enhancement must remain consistent with the genetic-algorithm robot simulation and must not replace the required behavior.

## Submission Requirements

Submit the completed C++ source file through Canvas by **December 17, 2026, the last day of class**. Before uploading, compile with `-Wall`, run the simulation, verify that the population remains at 200 robots, check the fitness output, test invalid movement and edge conditions, confirm that the program produces no compiler warnings, and verify that all dynamic memory is released. Rename the source file from `.cpp` to `.txt` only when preparing the Canvas upload. Do not submit a PDF, compressed archive, or separate report.

**No late final-project submissions are possible.** The assignment closes on the last day of class, and work submitted after December 17, 2026, cannot be accepted.

## Final Reminder

The project is a genetic-algorithm robot simulation. Build the grid, sensors, genes, robot behavior, fitness calculation, reproduction, mutation, and generation-level output in that order. The purpose is to observe whether a population of robots develops increasingly successful strategies for collecting energy.
