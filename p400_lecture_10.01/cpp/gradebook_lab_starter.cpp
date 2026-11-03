// gradebook_lab_starter.cpp -- starter file for the Unit Test Partner lab
//
// This is the buggy gradebook from the 09.01 Invariant Lab. Your job is to
// write unit tests that find its bugs. Do not fix the gradebook until your
// tests have shown you where the bugs are.
//
// check(), closeEnough(), and runTests() are test infrastructure. They are
// support code added for debugging purposes, not part of the Gradebook class
// or the gradebook program. Do not change them. Your tests call them.
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// true runs the unit tests, false runs the gradebook program
const bool RUN_TESTS = true;

const int CAPACITY = 5;

// A gradebook stores up to CAPACITY exam scores.
// Every score should be between 0 and 100.
class Gradebook {
private:
    int scores[CAPACITY] = {};
    int count = 0;

public:
    void addScore(int score);
    void removeLast();
    void applyCurve(int points);
    double average() const;
    int highestScore() const;
    int size() const;
    void print() const;
};

// Program functions
void runProgram();
void report(const string& label, const Gradebook& book);

// Test infrastructure: added for debugging, not part of the gradebook
bool check(bool condition, const string& testName);
bool closeEnough(double actual, double expected, double tolerance);
int runTests();

// Unit tests: add a prototype here for every test you write
bool testNewGradebookIsEmpty();

int main() {
    if (RUN_TESTS) {
        int failures = runTests();
        return failures == 0 ? 0 : 1;
    }

    runProgram();
    return 0;
}

// ---------- Test infrastructure ----------
// These three functions were added for debugging purposes. They are not part
// of the Gradebook class or the gradebook program, and you should not change
// them. Your tests call check() and closeEnough(); runTests() calls your tests.

// Print one test result and return whether it passed
bool check(bool condition, const string& testName) {
    if (condition) {
        cout << "PASS  " << testName << '\n';
    } else {
        cout << "FAIL  " << testName << '\n';
    }
    return condition;
}

// Doubles are compared within a tolerance, never with ==
bool closeEnough(double actual, double expected, double tolerance) {
    return fabs(actual - expected) <= tolerance;
}

// Run every test, keep going after a failure, and report the total
int runTests() {
    // Add the name of every test you write to this list
    bool (*tests[])() = {
        testNewGradebookIsEmpty
    };

    int total = 0;
    int failures = 0;
    for (auto test : tests) {
        total++;
        if (!test()) {
            failures++;
        }
    }

    cout << '\n' << total << " tests run, " << failures << " failed\n";
    return failures;
}

// ---------- Unit tests ----------
// Each test builds its own Gradebook, so no test can affect another.
// Work out every expected value by hand before you write the test.

// Sample test: shows the style. Write your own tests below it.
bool testNewGradebookIsEmpty() {
    // Arrange: build an empty gradebook
    Gradebook book;

    // Act: call the function under test
    int result = book.size();

    // Assert: a new gradebook holds no scores
    return check(result == 0, "a new gradebook is empty");
}

// ---------- The gradebook program ----------

void runProgram() {
    Gradebook midterm;
    midterm.addScore(88);
    midterm.addScore(72);
    midterm.addScore(95);
    midterm.addScore(99);
    report("Midterm", midterm);

    Gradebook finalExam;
    finalExam.addScore(81);
    finalExam.addScore(105);
    finalExam.addScore(64);
    report("Final exam", finalExam);

    midterm.applyCurve(5);
    report("Midterm after a 5 point curve", midterm);

    Gradebook makeup;
    report("Makeup exam", makeup);

    makeup.removeLast();
    cout << "Makeup size after removing a score: " << makeup.size() << '\n';
}

// Print a summary of one gradebook
void report(const string& label, const Gradebook& book) {
    cout << label << '\n';
    cout << "  Scores:  ";
    book.print();
    cout << "  Count:   " << book.size() << '\n';
    cout << "  Average: " << book.average() << '\n';
    cout << "  Highest: " << book.highestScore() << "\n\n";
}

// ---------- Gradebook member functions ----------

// Store a new score at the end of the gradebook
void Gradebook::addScore(int score) {
    scores[count] = score;
    count++;
}

// Remove the most recently added score
void Gradebook::removeLast() {
    count--;
}

// Add the same number of points to every score
void Gradebook::applyCurve(int points) {
    for (int i = 0; i < count; i++) {
        scores[i] += points;
    }
}

// Return the mean of all stored scores
double Gradebook::average() const {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    return total / count;
}

// Return the largest stored score
int Gradebook::highestScore() const {
    int best = scores[0];
    for (int i = 1; i < count - 1; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }
    return best;
}

// Return the number of stored scores
int Gradebook::size() const {
    return count;
}

// Print every stored score on one line
void Gradebook::print() const {
    for (int i = 0; i < count; i++) {
        cout << scores[i] << ' ';
    }
    cout << '\n';
}
