# Prompt for Programming Homework 4

## Context
You are helping design Homework Assignment 4 for an introductory C++ programming course. This is an at-home coding exercise where students will create a complete C++ program demonstrating the concepts they have learned.

Use the edited Homework Assignment 4 as the style and structure model. Preserve the instructor's concise assignment style. Do not add sections that were removed from the edited assignment.

## Assignment Philosophy
- **Student Choice on Theme**: Students select their own creative theme/scenario.
- **Required Technical Specifications**: All students must implement the same technical requirements regardless of theme.
- **Plagiarism Prevention**: The personalized theme, prompts, variable names, calculations, menu options, and output help distinguish student work.
- **No LLM Code Writing**: Students may use AI for understanding concepts but not for writing their code.
- **Comprehensive but Focused**: The assignment should emphasize decision-making, loops, menus, and multi-dimensional vectors.

## Required Technical Specifications

### Core C++ Concepts
This assignment covers material from lectures 07.01, 07.02, 08.01, and 08.02, plus reasonable review material from earlier homework.

Before creating the assignment, read `inventory.csv` from the p400 Lectures folder and use it as the source of truth for lecture topics. Use only rows whose `lecture` value is one of:

- `p400_lecture_07.01`
- `p400_lecture_07.02`
- `p400_lecture_08.01`
- `p400_lecture_08.02`

Do not use material from lectures after 08.02. Do not use topics from 09.01, 09.02, or any later lecture, even if those topics seem relevant.

Do not copy a lecture topic list into the final assignment. Use the inventory only to decide which concepts are appropriate for the 10 technical tasks.

## Required Assignment Sections

Create the final assignment with these sections, in this order:

1. Assignment title
2. Assignment Overview
3. Academic Integrity and AI Use
4. Common Program Standards (CPS)
5. Technical Requirements: 10 Required Tasks
6. Submission Requirements
7. Late Policy
8. Final Reminder

Do not add separate sections for source file header, program greeting, source file header template, program greeting requirements, theme selection guidance, theme examples, or output format. Those were intentionally removed from the edited assignment.

## Common Program Standards (CPS)

Include the following CPS section exactly as written:

```markdown
## Common Program Standards (CPS)

Your program must meet the following standards in addition to the tasks assigned in this homework:

1. Your program must compile in a linux environment with a compiler running C++17 or greater. Onlinegdb is the only compiler I know of that does *NOT* meet this standard.
2. Your program must produce logically consistent output. i.e. no logic errors.
3. Your program must include a source file header. See earlier assignments for examples.
4. Your program must include a program greeting. See earlier assignments for examples.
5. You cannot use .h include files as they are for C, not C++.
6. Functions must use function prototypes. Functions go below main().
7. Your plagiarism score box cannot be red or darker.
8. Global variables are not permitted unless they are constants.
```

The source file header and program greeting are CPS requirements only. Do not count them as technical tasks. Do not provide a source file header template. Do not provide a program greeting example.

## Technical Requirements

Create exactly 10 required coding tasks.

The technical requirements must:

- Include six tasks based on lectures 07.01, 07.02, 08.01, and 08.02.
- Include four tasks that may come from earlier homework material, general course standards, or broadly useful C++ programming practice.
- Use `inventory.csv` to identify the topics for those four lectures.
- Do not use topics from lectures after 08.02.
- Focus on C++ programming concepts, not setup items.
- Avoid using the source file header or program greeting as tasks.
- Use clear, student-facing language.
- Be precise about what students must code.
- Give each of the 10 tasks exactly five enumerated subtasks.
- Number each subtask with the task number and subtask number, such as `1.1`, `1.2`, `1.3`, `1.4`, `1.5`, then `2.1` through `2.5`, and so on.
- Make every subtask directly verifiable by reading, compiling, or running the submitted program.
- Avoid subjective subtasks such as "make the code easy to read," "write clean code," "use good style," or "make the output look nice" unless the requirement includes a concrete observable behavior.

The 10 tasks should draw from the following requirements as appropriate:

- Review arithmetic calculations, `static_cast`, named constants, and formatted output.
- Review function-centered design, parameters, return values, `void` functions, and reference parameters.
- Use compound conditions and range checking.
- Use nested `if` statements for multi-level decisions.
- Use the conditional operator in a meaningful way.
- Use a `switch` statement for menu or category selection.
- Use a `while` loop for validation or repeated processing.
- Use a `do-while` loop for a menu that runs at least once.
- Use a `for` loop for counted repetition.
- Use nested loops for grid/table/repeated row-column output.
- Use a multi-dimensional vector to store related data.
- Use loops to process the multi-dimensional vector.
- Include a simple text-based graph, chart, grid, or visual display generated with loops.
- Include a menu-driven section with meaningful choices.

Do not require classes, structs, file I/O, pointers, recursion, or material beyond the listed lectures.

The final task list must be concrete enough that the instructor can check each subtask as present or absent. For example, prefer "Use `fixed` and `setprecision` when displaying a decimal result" over "Format output clearly."

## Task Approval Workflow

Before writing or revising the final assignment task section, use an approval cycle.

First, propose only the list of 10 task titles. Do not include subtasks yet. The task list must follow these rules:

- Exactly 10 coding tasks.
- Six tasks should be based on lectures 07.01, 07.02, 08.01, and 08.02, using `inventory.csv` as the source of truth.
- Four tasks may come from earlier homework material, general course standards, or broadly useful C++ programming practice.
- For every proposed task, display the lecture source or source category beside the task title.
- If the task comes from a specific lecture, list the lecture number, such as `Lecture 07.01`.
- If the task combines material from more than one lecture, list all relevant lecture numbers.
- If the task is a general course standard or review requirement, label it as `Review/general`.
- Avoid duplicate task focus unless the duplication is intentional and clearly different in purpose.
- Do not count the source file header or program greeting as tasks.

After proposing the 10 task titles, stop and wait for instructor approval or revision.

Once the instructor approves the task list, propose subtasks one task at a time.

For each task:

1. Show the task title.
2. Show the lecture source or source category for that task.
3. Propose exactly five numbered subtasks.
4. Number subtasks using decimal numbering, such as `1.1`, `1.2`, `1.3`, `1.4`, `1.5`.
5. Make every subtask directly verifiable by reading, compiling, or running the submitted program.
6. Avoid subjective subtasks such as "make the code easy to read," "write clean code," or "make the output look nice."
7. Stop and wait for instructor approval or requested changes before moving to the next task.

Do not write or revise the final assignment file until all 10 tasks and all 50 subtasks have been approved.

After all tasks and subtasks are approved, revise only the Technical Requirements section unless the instructor explicitly asks for additional changes. Preserve the Common Program Standards (CPS) and Late Policy exactly as written.

## Submission Requirements

Include a concise Submission Requirements section matching the edited assignment's style:

- Submit the completed program to Canvas by the due date listed in Canvas.
- Students must compile and run the program before submitting.
- Students must rename the source file from `.cpp` to `.txt`.
- Students must upload the `.txt` file to Canvas.
- Mention that the instructor will download submissions and compile/execute them.
- Mention that program output may be appended to the end of the submitted source file as a comment.
- Mention that programs that do not compile will receive significant point deductions.

## Late Policy

Include the following Late Policy section exactly as written:

```markdown
## Late Policy

A 50% deduction is automatically applied by Canvas when the due date passes and no submission has been received. If you submit the assignment later, that temporary deduction will be removed and replaced with the actual late penalty when I grade your work.

Late assignments are subject to a 3% per day late penalty. You may submit homework up to seven days after the due date, after which Canvas will close the assignment and no further submissions will be accepted.
```

## Final Reminder

End with a short Final Reminder section in the same style as the edited assignment:

- Reinforce that the assignment combines structure and choice.
- Remind students that the technical requirements are the same for everyone, but the theme and design should be theirs.
- Remind students that AI may be used only for support with concepts, error messages, or reviewing lecture ideas, not for writing code.

## Output Format

Create the assignment as a well-formatted markdown document that:

- Is clear and easy for students to follow.
- Uses headings, bullet points, and numbered task lists effectively.
- Emphasizes the required technical specifications.
- Encourages creativity within the required structure.
- Includes the CPS section exactly.
- Includes the Late Policy section exactly.
- Does not include removed sections: no separate source file header section, no source file header template, no separate program greeting section, no program greeting example, no theme selection guidance section, and no theme example list.
- If the instructor asks to revise tasks, follow the Task Approval Workflow before editing the final assignment.

The goal is to create an assignment that:

- Tests the covered material comprehensively.
- Gives students meaningful practice with loops and decisions.
- Requires a menu-driven program.
- Requires multi-dimensional data and nested loops.
- Allows for student creativity and personalization.
- Is clear enough that students know exactly what is required.
- Results in programs that compile, run, and demonstrate mastery of the covered concepts.
