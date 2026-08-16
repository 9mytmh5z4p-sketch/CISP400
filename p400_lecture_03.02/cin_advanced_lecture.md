# Advanced Input Handling with `cin`

::: notes
~15 min
:::


## Introduction

In the basic `cin` lecture, we learned how to read single words and numbers. But real programs need to handle more complex input scenarios:

- Reading full sentences with spaces
- Handling invalid input gracefully
- Mixing different input methods
- Clearing the input buffer

Today we'll learn the advanced techniques professional programmers use.

<!-- Slide 1 -->

---

## The Whitespace Problem Revisited

Remember: `cin >>` stops reading at the first whitespace (space, tab, or newline).

```cpp
string fullName;

cout << "What is your full name? ";
cin >> fullName;  // User types: John Smith

cout << "Your name is " << fullName << endl;
```

**Output:** `Your name is John`

**What happened?** 
- `cin >>` captured "John" and stopped at the space
- "Smith" is left in the input buffer, waiting to be read


<!-- Slide 2 -->

---

## Solution: `getline()`

`getline()` reads an entire line of input, including spaces, until the Enter key is pressed.

**Syntax:**
```cpp
getline(cin, variableName);
```

**Example:**
```cpp
string fullName;

cout << "What is your full name? ";
getline(cin, fullName);  // Reads the entire line

cout << "Your name is " << fullName << endl;
```

**Output:** `Your name is John Smith`

**Key difference:** `getline()` reads everything until the newline character (`\n`).

<!-- Slide 3 -->

---

## `cin >>` vs `getline()`

| Aspect | `cin >>` | `getline()` |
|------|---------|-------------|
| Whitespace handling | Stops at first whitespace | Reads entire line until newline |
| Newline behavior | Leaves newline in input buffer | Removes newline from buffer |
| Best use case | Single words or numeric input | Sentences or multi-word input |
| Typical input type | Tokens | Full lines |
| Syntax | `cin >> variable;` | `getline(cin, variable);` |
| Common pitfall | Can cause skipped input when mixed with `getline()` | Requires buffer cleanup if preceded by `cin >>` |

<!-- Slide 4 -->

---

## The Mixing Problem

**This code has a bug:**

```cpp
int age;
string fullName;

cout << "Enter your age: ";
cin >> age;  // User types: 25 [Enter]

cout << "Enter your full name: ";
getline(cin, fullName);  // Doesn't wait for input!

cout << "Name: " << fullName << endl;
```

**Output:**
```
Enter your age: 25
Enter your full name: Name: 
```

**What went wrong?** The newline from pressing Enter after `25` was left in the buffer, and `getline()` immediately read it as an empty line!

<!-- Slide 5 -->

---

## Solution: `cin.ignore()`

`cin.ignore()` clears unwanted characters from the input buffer.

**Syntax:**
```cpp
cin.ignore(count, delimiter);
```

- `count` - maximum number of characters to ignore
- `delimiter` - stop ignoring when this character is found

**Common usage:**
```cpp
cin.ignore(1000, '\n');  // Ignore up to 1000 chars or until newline
```

**Even better (using limits):**
```cpp
#include <limits>
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```

This ignores everything up to and including the newline.

<!-- Slide 6 -->

---

## Fixed Example with `cin.ignore()`

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int age;
    string fullName;
    
    cout << "Enter your age: ";
    cin >> age;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear buffer
    
    cout << "Enter your full name: ";
    getline(cin, fullName);
    
    cout << "Name: " << fullName << endl;
    cout << "Age: " << age << endl;
    
    return 0;
}
```

**Now it works correctly!**

<!-- Slide 7 -->

---

## Handling Invalid Input

What happens when the user enters text when you expect a number?

```cpp
int number;
cout << "Enter a number: ";
cin >> number;  // User types: "hello"
```

**Result:** `cin` enters a **fail state** and `number` contains garbage or remains unchanged.

**How to detect this:**
```cpp
if (cin.fail()) {
    cout << "Invalid input!" << endl;
}
```

**The stream is now broken** - all subsequent `cin` operations will fail until you fix it!

<!-- Slide 8 -->

---

## Clearing the Fail State

When `cin` fails, you need to:
1. Clear the error flags
2. Remove the bad input from the buffer

```cpp
int number;
cout << "Enter a number: ";
cin >> number;

if (cin.fail()) {
    cout << "Invalid input! Please enter a number." << endl;
    
    cin.clear();  // Clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Remove bad input
    
    // Now cin is ready to try again
}
```

<!-- Slide 9 -->

---

## Complete Input Validation Example

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int number;
    bool validInput = false;
    
    while (!validInput) {
        cout << "Enter a positive number: ";
        cin >> number;
        
        if (cin.fail()) {
            cout << "Error: That's not a number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (number <= 0) {
            cout << "Error: Number must be positive!" << endl;
        }
        else {
            validInput = true;
        }
    }
    
    cout << "You entered: " << number << endl;
    return 0;
}
```

<!-- Slide 10 -->

---

## Common Patterns: Reading Multiple Lines

```cpp
string address;
string city;
string state;

cout << "Enter your street address: ";
getline(cin, address);

cout << "Enter your city: ";
getline(cin, city);

cout << "Enter your state: ";
getline(cin, state);

cout << "\nYour address:\n";
cout << address << endl;
cout << city << ", " << state << endl;
```

**When to use:** Forms, surveys, any multi-line text input.

<!-- Slide 11 -->

---

## Reading Until a Sentinel Value

A **sentinel value** is a special input that signals "stop reading."

```cpp
int sum = 0;
int number;

cout << "Enter numbers to sum (enter -1 to stop):\n";

cin >> number;
while (number != -1) {
    sum += number;
    cin >> number;
}

cout << "Total sum: " << sum << endl;
```

**Common sentinel values:** -1, 0, "quit", "exit", empty string

<!-- Slide 12 -->

---

## Best Practices for Input Handling

## 1. Always Validate Input
Never trust that users will enter valid data.

## 2. Use `cin.ignore()` When Mixing Input Methods
Clear the buffer after `cin >>` before using `getline()`.

## 3. Provide Clear Error Messages
Tell users exactly what went wrong and what they should enter.

## 4. Give Users Another Chance
Use loops to allow re-entry of invalid input.

## 5. Use Appropriate Input Methods
- `cin >>` for single words/numbers
- `getline()` for sentences/multi-word input

<!-- Slide 13 -->

---

## Quick Reference

## Reading single word/number:
```cpp
int age;
cin >> age;
```

## Reading full line:
```cpp
string name;
getline(cin, name);
```

## Mixing cin >> and getline():
```cpp
cin >> age;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, name);
```

## Checking for errors:
```cpp
if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
```

<!-- Slide 14 -->

---

## Practice Exercises

::: notes
These exercises build on the advanced concepts.
:::

## Exercise 1: Complete Registration Form

Write a program that asks for:
- First name (single word)
- Last name (single word)
- Full address (multiple words)
- Age (number with validation)

Use appropriate input methods for each field.

## Exercise 2: Validated Calculator

Write a calculator that:
- Asks for two numbers (with validation)
- Asks for an operation (+, -, *, /)
- Validates all input and allows re-entry
- Displays the result

## Exercise 3: Text Processor

Write a program that reads multiple lines of text (use a sentinel like "DONE") and counts the total number of words entered.

<!-- Slide 15 -->
