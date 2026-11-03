#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

// true runs the unit tests, false runs the gradebook program
const bool RUN_TESTS = true;

const int CAPACITY = 5;

// A gradebook stores up to CAPACITY exam scores.
// Class invariant: 0 <= count <= CAPACITY and every stored score is 0 to 100.
class Gradebook {
private:
    int scores[CAPACITY] = {};
    int count = 0;
    void checkInvariant() const;

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

// Test helpers
bool check(bool condition, const string& testName);
bool closeEnough(double actual, double expected, double tolerance);
int runTests();

// Unit tests
bool testNewGradebookIsEmpty();
bool testAddScoreIncreasesSize();
bool testRemoveLastDecreasesSize();
bool testHighestScoreIncludesLastElement();
bool testAverageOfThreeScores();
bool testOneScore();
bool testFullGradebook();
bool testScoresAtLimits();
bool testCurveNeverExceeds100();

int main() {
    if (RUN_TESTS) {
        int failures = runTests();
        return failures == 0 ? 0 : 1;
    }

    runProgram();
    return 0;
}

// ---------- Test helpers ----------

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
    bool (*tests[])() = {
        testNewGradebookIsEmpty,
        testAddScoreIncreasesSize,
        testRemoveLastDecreasesSize,
        testHighestScoreIncludesLastElement,
        testAverageOfThreeScores,
        testOneScore,
        testFullGradebook,
        testScoresAtLimits,
        testCurveNeverExceeds100
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
// Every expected value was worked out by hand.

bool testNewGradebookIsEmpty() {
    Gradebook book;
    return check(book.size() == 0, "a new gradebook is empty");
}

bool testAddScoreIncreasesSize() {
    Gradebook book;
    book.addScore(88);
    return check(book.size() == 1, "addScore increases the size by one");
}

bool testRemoveLastDecreasesSize() {
    Gradebook book;
    book.addScore(70);
    book.addScore(80);
    book.removeLast();
    return check(book.size() == 1, "removeLast decreases the size by one");
}

bool testHighestScoreIncludesLastElement() {
    // Arrange: build a gradebook whose largest score is last
    Gradebook book;
    book.addScore(88);
    book.addScore(72);
    book.addScore(95);
    book.addScore(99);

    // Act: call the function under test
    int result = book.highestScore();

    // Assert: check the result against the value worked out by hand
    return check(result == 99, "highestScore includes the last score");
}

bool testAverageOfThreeScores() {
    Gradebook book;
    book.addScore(90);
    book.addScore(85);
    book.addScore(75);

    // 250 / 3 = 83.333..., which a double cannot store exactly
    return check(closeEnough(book.average(), 83.333, 0.001), "average of 90 85 75 is about 83.333");
}

bool testOneScore() {
    Gradebook book;
    book.addScore(77);
    bool averageOk = closeEnough(book.average(), 77.0, 0.001);
    return check(averageOk && book.highestScore() == 77, "one score is both the average and the highest");
}

bool testFullGradebook() {
    Gradebook book;
    book.addScore(60);
    book.addScore(70);
    book.addScore(100);
    book.addScore(80);
    book.addScore(90);
    return check(book.size() == CAPACITY, "a gradebook holds exactly CAPACITY scores");
}

bool testScoresAtLimits() {
    Gradebook book;
    book.addScore(0);
    book.addScore(100);
    bool averageOk = closeEnough(book.average(), 50.0, 0.001);
    return check(averageOk && book.highestScore() == 100, "scores of exactly 0 and 100 are handled");
}

bool testCurveNeverExceeds100() {
    Gradebook book;
    book.addScore(99);
    book.addScore(50);
    book.applyCurve(5);

    // Capped curve: 100 and 55, so the average is 77.5
    return check(closeEnough(book.average(), 77.5, 0.001), "a curve never pushes a score past 100");
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
    finalExam.addScore(95);
    finalExam.addScore(64);
    report("Final exam", finalExam);

    midterm.applyCurve(5);
    report("Midterm after a 5 point curve", midterm);

    Gradebook makeup;
    if (makeup.size() > 0) {
        report("Makeup exam", makeup);
    } else {
        cout << "Makeup exam\n  No scores recorded\n\n";
    }
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

void Gradebook::checkInvariant() const {
    assert(count >= 0 && count <= CAPACITY && "count is out of range");
    for (int i = 0; i < count; i++) {
        assert(scores[i] >= 0 && scores[i] <= 100 && "a stored score is outside 0 to 100");
    }
}

void Gradebook::addScore(int score) {
    assert(count < CAPACITY && "addScore on a full gradebook");
    assert(score >= 0 && score <= 100 && "score must be between 0 and 100");
    scores[count] = score;
    count++;
    checkInvariant();
}

void Gradebook::removeLast() {
    assert(count > 0 && "removeLast on an empty gradebook");
    count--;
    checkInvariant();
}

void Gradebook::applyCurve(int points) {
    for (int i = 0; i < count; i++) {
        if (scores[i] + points > 100) {
            scores[i] = 100;
        } else {
            scores[i] += points;
        }
    }
    checkInvariant();
}

double Gradebook::average() const {
    assert(count > 0 && "average of an empty gradebook");
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    return total / count;
}

int Gradebook::highestScore() const {
    assert(count > 0 && "highestScore of an empty gradebook");
    int best = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }
    return best;
}

int Gradebook::size() const {
    return count;
}

void Gradebook::print() const {
    for (int i = 0; i < count; i++) {
        cout << scores[i] << ' ';
    }
    cout << '\n';
}
