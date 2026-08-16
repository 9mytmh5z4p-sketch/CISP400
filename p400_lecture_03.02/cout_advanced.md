# Advanced Output Formatting with `cout`

::: notes
Target duration: ~20 minutes - Advanced formatting techniques
Prerequisites: Students should know basic cout, variables, and newlines
:::

## Agenda

Today's topics:

- Escape sequences and special characters
- Creating formatted output
- Common output patterns
- Best practices for readable output
- Practical formatting examples

::: notes
This builds on the basic cout lecture. Students should already be comfortable with cout <<, variables, and endl/\n.
:::

<!-- Slide 1 -->

## Escape Sequences

**Escape sequences** use backslash `\` to create special characters:

| Sequence | Meaning | Example |
|----------|---------|---------|
| `\n` | Newline | `"Line 1\nLine 2"` |
| `\t` | Tab (indent) | `"Name:\tValue"` |
| `\"` | Double quote | `"She said \"Hi\""` |
| `\\` | Backslash | `"C:\\folder\\file"` |

**Why use them:** Create formatting without multiple cout statements.

::: notes
Emphasize that \n is the same as endl but can be embedded in strings. Show how \t creates aligned columns.
:::

<!-- Slide 2 -->

## Tab Character Example

Tabs create aligned columns:

```cpp
cout << "Column1\tColumn2\tColumn3" << endl;
cout << "Value1\tValue2\tValue3" << endl;
cout << "A\tB\tC" << endl;
```

**Output:**
```
Column1    Column2    Column3
Value1     Value2     Value3
A          B          C
```

**Use case:** Creating simple tables or aligned data.

::: notes
Explain that tabs align to preset positions (typically every 8 characters). This isn't pixel-perfect but works for simple alignment.
:::

<!-- Slide 3 -->

## Quote and Backslash Examples

**Displaying quotes in text:**
```cpp
cout << "He said, \"Hello!\"" << endl;
```
**Output:** `He said, "Hello!"`

**Displaying file paths:**
```cpp
cout << "File: C:\\Documents\\file.txt" << endl;
```
**Output:** `File: C:\Documents\file.txt`

**Rule:** Every `\` you want to display needs to be written as `\\`

<!-- Slide 4 -->

## Combining Multiple Escape Sequences

```cpp
cout << "Name:\t\"Alice\"\nAge:\t25\nCity:\t\"Boston\"" << endl;
```

**Output:**
```
Name:   "Alice"
Age:    25
City:   "Boston"
```

**Tip:** This makes code more compact but can be harder to read. Use judgment.

::: notes
Show students that you can break this into multiple cout statements if it's clearer. Readability matters more than being clever.
:::

<!-- Slide 5 -->

## Pattern: Headers and Footers

Create visual structure with decorative lines:

```cpp
cout << "===========================" << endl;
cout << "    Student Information    " << endl;
cout << "===========================" << endl;
cout << "Name: Alice" << endl;
cout << "Grade: A" << endl;
cout << "===========================" << endl;
```

**Output:**
```
===========================
    Student Information    
===========================
Name: Alice
Grade: A
===========================
```

<!-- Slide 6 -->

## Pattern: Labels and Values

Align labels for readability:

```cpp
string item = "Laptop";
double price = 899.99;
int quantity = 2;

cout << "Item:     " << item << endl;
cout << "Price:    $" << price << endl;
cout << "Quantity: " << quantity << endl;
cout << "Total:    $" << (price * quantity) << endl;
```

**Output:**
```
Item:     Laptop
Price:    $899.99
Quantity: 2
Total:    $1799.98
```

::: notes
Point out the extra spaces after "Item:" to align the values. In a future lecture, we'll learn better ways to do this with formatting functions.
:::

<!-- Slide 7 -->

## Pattern: Building Complex Sentences

Break complex output into manageable pieces:

```cpp
string name = "Bob";
int hours = 5;
string project = "Website";

cout << "Employee " << name;
cout << " worked " << hours << " hours";
cout << " on the " << project << " project";
cout << " this week." << endl;
```

**Output:**
```
Employee Bob worked 5 hours on the Website project this week.
```

**Alternative:** Can also use one long chained statement.

<!-- Slide 8 -->

## Displaying Calculations

The calculation happens before display:

```cpp
int length = 10;
int width = 5;

cout << "Rectangle dimensions: " << length << " x " << width << endl;
cout << "Area: " << (length * width) << " square units" << endl;
cout << "Perimeter: " << (2 * length + 2 * width) << " units" << endl;
```

**Output:**
```
Rectangle dimensions: 10 x 5
Area: 50 square units
Perimeter: 30 units
```

**Note:** Parentheses ensure calculation happens first.

<!-- Slide 9 -->

## Best Practice: Clear and Readable Output

**Poor formatting:**
```cpp
cout << name << age << city << endl;
```
**Output:** `Alice25Boston` (confusing!)

**Good formatting:**
```cpp
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
cout << "City: " << city << endl;
```
**Output:**
```
Name: Alice
Age: 25
City: Boston
```

**Rule:** Always label your output so users understand what they're seeing.

<!-- Slide 10 -->

## Best Practice: Use Blank Lines

Organize output into logical sections:

```cpp
cout << "=== Personal Info ===" << endl;
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
cout << endl;  // Blank line

cout << "=== Contact Info ===" << endl;
cout << "Email: " << email << endl;
cout << "Phone: " << phone << endl;
```

**Benefit:** Makes output easier to scan and understand.

<!-- Slide 11 -->

## Complete Example: Receipt Formatter

```cpp
#include <iostream>
using namespace std;

int main()
{
    string store = "Bob's Electronics";
    string item1 = "Keyboard", item2 = "Mouse";
    double price1 = 49.99, price2 = 24.99;
    double tax = 0.08;
    
    double subtotal = price1 + price2;
    double taxAmount = subtotal * tax;
    double total = subtotal + taxAmount;
    
    cout << "================================" << endl;
    cout << "      " << store << endl;
    cout << "================================" << endl;
    cout << endl;
    
    cout << item1 << "\t\t$" << price1 << endl;
    cout << item2 << "\t\t$" << price2 << endl;
    cout << "--------------------------------" << endl;
    cout << "Subtotal:\t\t$" << subtotal << endl;
    cout << "Tax (8%):\t\t$" << taxAmount << endl;
    cout << "--------------------------------" << endl;
    cout << "TOTAL:\t\t\t$" << total << endl;
    cout << "================================" << endl;
    
    return 0;
}
```

::: notes
Walk through this example showing how escape sequences, alignment, and blank lines work together to create professional-looking output. Point out the use of \t for alignment and the decorative lines for structure.
:::

<!-- Slide 12 -->

## Common Formatting Mistakes

**Mistake 1: Forgetting spaces in labels**
```cpp
cout << "Name:" << name;  // Output: Name:Alice
cout << "Name: " << name; // Output: Name: Alice (better)
```

**Mistake 2: Inconsistent alignment**
```cpp
cout << "Name: " << name << endl;
cout << "Age:" << age << endl;  // Misaligned!
```

**Mistake 3: Too much on one line**
```cpp
cout << "Name: " << name << " Age: " << age << " City: " << city;
// Hard to read - use multiple lines instead
```

<!-- Slide 13 -->

## Practical Exercise

Create a program that displays a student report card with:

- Student name and ID
- Three course names with grades
- GPA calculation
- Proper formatting with headers, alignment, and spacing

**Use:** Escape sequences, labels, calculations, and blank lines.

::: notes
This exercise combines all the techniques from this lecture. Students should create something that looks professional and is easy to read. Review solutions in class to discuss different formatting approaches.
:::

<!-- Slide 14 -->
