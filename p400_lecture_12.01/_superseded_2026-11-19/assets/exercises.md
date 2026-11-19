Here are three C++ exercises designed for a classroom setting. They progress from basic data mapping to more complex grid manipulation using parallel arrays (multiple arrays where the same index relates to the same entity) and multidimensional arrays (matrices).

---

## Exercise 1: Student Grade Tracker (Parallel Arrays)
**Objective:** Learn to sync data across multiple arrays using a shared index.

**The Task:**
Create a program that stores the names of 5 students and their corresponding exam scores in two separate arrays. 
* `string names[5]`
* `int scores[5]`

**Requirements:**
1.  Prompt the user to enter a name and a score for each student.
2.  Calculate the average score of the class.
3.  Print a report showing each student's name and whether they are "Above Average" or "Below Average."

**Why this works:** It reinforces the concept that `names[i]` and `scores[i]` represent the same person, even though they are different data types.

---

## Exercise 2: Monthly Temperature Matrix (Multidimensional)
**Objective:** Process data across rows and columns in a 2D array.

**The Task:**
Imagine a city records the high temperature for 4 weeks (rows), with 7 days per week (columns). 
* `int temps[4][7]`

**Requirements:**
1.  Initialize the array with random temperatures between 60 and 100.
2.  Find and print the **highest temperature** of the entire month and which week/day it occurred on.
3.  Calculate the **average temperature for each week** individually.



**Why this works:** It teaches nested `for` loops—the outer loop handles the weeks, while the inner loop handles the days.

---

## Exercise 3: Inventory Management (Hybrid Approach)
**Objective:** Use parallel arrays to label and describe a multidimensional data set.

**The Task:**
A small shop sells 3 types of products (Apples, Bananas, Oranges). They track inventory across 3 different warehouse locations.

**Requirements:**
1.  Use a `string products[3]` array to store the names.
2.  Use an `int stock[3][3]` 2D array where `stock[i][j]` represents the quantity of `product[i]` at `location[j]`.
3.  **The Challenge:** Ask the user to input a product name. Search the `products` array for a match. If found, use that index to sum the total stock for that item across all three warehouses.



**Why this works:** This is a real-world logic puzzle. Students must use a search algorithm on a 1D array to find the correct "row" index to access the 2D array.

---

### Quick Syntax Refresher

**Parallel Arrays:**
```cpp
string names[] = {"Alice", "Bob"};
int ages[] = {22, 25}; // names[0] is Alice, ages[0] is 22
```

**Multidimensional Arrays:**
```cpp
int matrix[3][3] = {
    {1, 2, 3}, // Row 0
    {4, 5, 6}, // Row 1
    {7, 8, 9}  // Row 2
};
```