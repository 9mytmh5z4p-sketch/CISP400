/* Generated from inventory.csv. Keep the lecture/topic source of truth in inventory.csv. */
window.P400_INVENTORY = {
  "01.01": ["Course Overview", "Parts of a C++ Program", "Toolset", "Common Elements", "Syllabus Reconnaissance", "Class Expectations", "Top Matter", "Instructor Role", "The main() Function", "Course Placement at FLC", "Coding Exercise 1-1", "Reciprocal Interview", "Success Team Bingo", "Advice Cards"],
  "01.02": ["Course Framing", "CISP 360 Review: Variables and Conditionals", "Iteration", "Functions", "Programming Exercise", "Pointers Preview", "Desk Check", "Coding for Reuse", "Success Team Bingo", "References", "Logging Function"],
  "02.01": ["Pointers and the Address Operator", "Arrays and Pointers", "Course Framing", "Debugging Exercise", "Desk Check", "Homework Preflight", "Initializing Pointers", "Pointer Arithmetic", "Pointer Motivation and Memory Addresses", "Programming Exercise", "Reference Variables", "References", "Review Wrap-Up"],
  "02.02": ["Comparing Pointers", "Pointers to Constants and Constant Pointers", "Course Framing", "Debugging Exercises", "Desk Check", "Desk Checks", "Pointers as Function Parameters", "Function Pointers", "Pointer Variables in Memory", "Programming Exercise", "Returning and Reassigning Pointers", "Lecture Wrap-Up"],
  "03.01": ["Course Framing", "Desk Check", "Dynamic Memory Allocation", "Homework Peer Review", "C++ Memory Model and Pointer Review", "Programming Exercise", "Pseudo-Dynamic Arrays", "Real Dynamic Arrays", "Lecture Wrap-Up"],
  "03.02": ["Abstract Data Types", "Classes and Methods", "Classes and Objects", "Course Framing", "Encapsulation and Abstraction", "Homework Peer Review", "Programming Exercise: Colorize", "Programming Exercise: Dynamic Array Operations", "Programming Exercise: Dynamic Arrays", "Programming Exercise: Returning a Struct", "Structures"],
  "04.01": ["Methods and Member Functions", "Difference Between Method and Function", "Access Specifiers", "Private Member Functions", "Methods as an Interface", "Setters and Getters", "Setters Increase Reliability", "Getters"],
  "04.02": ["Constructors and Constructor Overloading", "Course Framing", "Course Wrap-Up", "Destructors"],
  "05.01": ["Desk Check", "Enumerated Data Types", "Pointers to Objects", "Selecting Members of Objects", "Arrays of Objects", "Dynamic Arrays", "Course Wrap-Up", "Homework and Peer Review"],
  "05.02": ["Dependency Relationships", "Desk Check", "Arrays of Objects on the Stack and Heap", "Resource Acquisition Is Initialization", "Programming Exercise"],
  "06.01": ["Adapter Pattern"],
  "06.02": ["C-Strings and Character Arrays", "C-String Library Functions", "String and Numeric Conversions", "Writing C-String Handling Functions"],
  "07.01": ["The this Pointer and Constant Member Functions", "Static Members", "Operator Overloading", "Friends of Classes"],
  "07.02": ["Operator Overloading", "Friends of Classes", "Stream Operators", "Advanced Friendship Patterns"],
  "08.01": ["Moving & Copying Use Case", "Copy Constructors and Memberwise Assignment", "Shallow Copies and the Serialization Problem", "Exercise"],
  "08.02": ["Structured Debugging", "Rule of Five", "Deep Copy", "Rvalue References and Move Operations"],
  "09.01": ["Functors", "Range-Based Loops and std::for_each", "Activities and Desk Check", "Invariants and Assertions", "Invariant Lab"],
  "09.02": ["Functor Review", "Lambda Expressions", "Captures and Closures", "Lambdas with STL Algorithms", "Lambda Lab"],
  "10.01": ["Lambda and Functor Review", "Type Conversion Operators", "Conversion Constructors", "Object Conversions", "Conversion Safety", "Operator Chaining", "Unit Testing"],
  "10.02": ["Conversion Constructors", "First-Class Objects", "Object Conversions", "Conversion Safety"],
  "11.01": ["Conversion Review", "Class Relationships", "Aggregation and Composition", "Relationship Applications", "Exception Basics"],
  "11.02": ["Is-a Versus Has-a", "Inheritance Syntax", "Inheritance Access Control", "Base Class Construction", "Construction and Destruction Order"],
  "12.01": ["Overriding Functions", "Calling Base Class Functions", "Multiple Inheritance", "The Diamond Problem"],
  "12.02": ["Polymorphic Data Structures", "Overriding Functions", "Inheritance and Data Structures", "Inheritance Applications"],
  "13.01": ["Inheritance and Arrays", "Arrays of Class Objects", "Inheritance Design", "Aggregation Review"],
  "13.02": ["Virtual Functions", "Type Compatibility", "override and final", "Virtual Destructors", "Object Slicing"],
  "14.01": ["Abstract Base Classes", "Pure Virtual Functions", "Polymorphic Data Structures", "Dynamic Casting"],
  "14.02": ["Exception Hierarchies", "Custom Exception Classes", "Catch Order", "Exception Safety"],
  "15.01": ["Why STL Was Invented", "std::vector", "Vectors of Vectors", "Algorithms with Lambdas"],
  "15.02": ["Function Templates", "Template Arguments", "Class Templates Preview"],
  "16.01": ["Fill In the Missing Code", "Object-Oriented Programming", "Defining Member Functions", "Creating and Using Objects", "Introduction to Classes", "Abstract Data Types - Part 2"],
  "16.02": ["Destructor", "Constructor Overloading", "Parameterized Constructor", "Default Constructor", "What is a Constructor"],
  "17.01": ["Vectors of Objects", "Arrays of Objects"],
  "TBD": ["std::function and Callbacks", "Function Templates", "Class Templates"]
};

/* Lectures whose topics are recorded in inventory.csv but were not taught.
   The calendar and course map leave these off the meeting schedule.
   12.02 and 13.01 were merged into 13.02 and 14.01 on Nov 4, 2026. */
window.P400_NOT_TAUGHT = {};

/* Fall 2026 meeting order. The calendar, course map, and index.html place these lectures,
   in this order, on the Tuesday/Thursday meetings that are not cancelled.
   10.02 was merged into 10.01. 12.02 and 13.01 were merged into 13.02 and 14.01.
   15.02 (templates) runs before 15.01 (STL) so the course ends with the STL. */
window.P400_SCHEDULE = [
  "01.01", "01.02", "02.01", "02.02", "03.01", "03.02", "04.01", "04.02", "05.01", "05.02",
  "06.01", "06.02", "07.01", "07.02", "08.01", "08.02", "09.01", "09.02", "10.01", "11.01",
  "11.02", "12.01", "13.02", "14.01", "14.02", "15.02", "15.01"
];

window.P400_LECTURE_TITLES = {
  "01.01": "Course Introduction",
  "01.02": "C++ Programming Review",
  "02.01": "Intro to Pointers",
  "02.02": "Working with Pointers",
  "03.01": "Dynamic Memory",
  "03.02": "Programming Exercise III",
  "04.01": "OOP I",
  "04.02": "Methods and Constructors",
  "05.01": "Class Relationships and Object Arrays",
  "05.02": "Dependencies, Object Arrays, and RAII",
  "06.01": "Anonymous Objects and Adapter Pattern",
  "06.02": "C-Strings and Conversions",
  "07.01": "More OOP: The this Pointer, Static Members, Operators, and Friends",
  "07.02": "Operator Overloading, Friends, and Streams",
  "08.01": "Shallow Copies",
  "08.02": "Deep Copies and Move Operations",
  "09.01": "Functors, for_each, and Invariants",
  "09.02": "Functors to Lambdas",
  "10.01": "Type Conversion, Conversion Safety, Operator Chaining, and Unit Testing",
  "10.02": "Converting Constructors and Object Conversions",
  "11.01": "Class Relationships, Composition, and Exception Basics",
  "11.02": "Inheritance Basics",
  "12.01": "Overriding and Multiple Inheritance",
  "12.02": "Polymorphic Data Structures and Inheritance Applications",
  "13.01": "Inheritance and Arrays",
  "13.02": "Polymorphism and Virtual Functions",
  "14.01": "Abstract Classes and Polymorphic Data Structures",
  "14.02": "Exception Hierarchies and Safety",
  "15.01": "The Standard Template Library: Why STL Was Invented",
  "15.02": "Function Templates",
  "16.01": "Classes and Member Functions",
  "16.02": "Constructors and Destructors",
  "17.01": "Arrays and Vectors of Objects"
};
