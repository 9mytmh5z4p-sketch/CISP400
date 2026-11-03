#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

const int ROSTER_SIZE = 6;

// A student's name and course score
class Student {
private:
    string name;
    int score;

public:
    Student(string studentName, int studentScore);
    string getName() const;
    int getScore() const;
    void addPoints(int points);
};

void runRoster(ostream& out);
void printRoster(ostream& out, const Student roster[], int size);
char letterGrade(int score);
void checkOutput(const string& actual);

int main() {
    // Run every job, capturing the output so it can be checked
    ostringstream captured;
    runRoster(captured);

    cout << captured.str();
    checkOutput(captured.str());

    return 0;
}

// Run every roster job, writing all output to out
void runRoster(ostream& out) {
    Student roster[ROSTER_SIZE] = {
        {"Ada", 88}, {"Linus", 64}, {"Grace", 93},
        {"Alan", 55}, {"Barbara", 79}, {"Dennis", 71}
    };
    int passing = 70;
    int curve = 3;
    int honorsMinimum = 90;

    out << "Roster\n";
    printRoster(out, roster, ROSTER_SIZE);

    // The lambda only reads passing, so it captures passing by value
    int passed = count_if(begin(roster), end(roster),
        [passing](const Student& student) {
            return student.getScore() >= passing;
        });
    out << "Passing: " << passed << '\n';

    // The lambda only reads passing, so it captures passing by value
    Student* firstFail = find_if(begin(roster), end(roster),
        [passing](const Student& student) {
            return student.getScore() < passing;
        });

    if (firstFail != end(roster)) {
        out << "First failing: " << firstFail->getName() << '\n';
    } else {
        out << "Everyone passed\n";
    }

    // The lambda only reads curve, so it captures curve by value.
    // The Student& parameter is what lets it change each student.
    for_each(begin(roster), end(roster),
        [curve](Student& student) {
            student.addPoints(curve);
        });

    // The comparator needs no outside data, so it captures nothing
    sort(begin(roster), end(roster),
        [](const Student& a, const Student& b) {
            return a.getScore() > b.getScore();
        });

    out << "\nAfter a " << curve << " point curve, highest first\n";
    printRoster(out, roster, ROSTER_SIZE);

    // The lambda only reads honorsMinimum, so it captures it by value
    int honorsCount = count_if(begin(roster), end(roster),
        [honorsMinimum](const Student& student) {
            return student.getScore() >= honorsMinimum;
        });
    out << "Honors: " << honorsCount << '\n';

    // Kept as a loop: five results in one pass fit no single algorithm
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;
    for (const Student& student : roster) {
        switch (letterGrade(student.getScore())) {
            case 'A': countA++; break;
            case 'B': countB++; break;
            case 'C': countC++; break;
            case 'D': countD++; break;
            default:  countF++; break;
        }
    }
    out << "A: " << countA << "  B: " << countB << "  C: " << countC
         << "  D: " << countD << "  F: " << countF << '\n';

}

Student::Student(string studentName, int studentScore)
    : name(studentName), score(studentScore) {}

string Student::getName() const {
    return name;
}

int Student::getScore() const {
    return score;
}

void Student::addPoints(int points) {
    score += points;
}

// Print each student's name and score on its own line
void printRoster(ostream& out, const Student roster[], int size) {
    // Streams cannot be copied, so the lambda must capture out by reference
    for_each(roster, roster + size,
        [&out](const Student& student) {
            out << "  " << student.getName() << ' ' << student.getScore() << '\n';
        });
}

// Convert a numeric score to a letter grade
char letterGrade(int score) {
    if (score >= 90) {
        return 'A';
    }
    if (score >= 80) {
        return 'B';
    }
    if (score >= 70) {
        return 'C';
    }
    if (score >= 60) {
        return 'D';
    }
    return 'F';
}

// Output check: do not change anything below this line.

// The exact output of the original roster_loops.cpp
const string EXPECTED_OUTPUT = R"(Roster
  Ada 88
  Linus 64
  Grace 93
  Alan 55
  Barbara 79
  Dennis 71
Passing: 4
First failing: Linus

After a 3 point curve, highest first
  Grace 96
  Ada 91
  Barbara 82
  Dennis 74
  Linus 67
  Alan 58
Honors: 2
A: 2  B: 1  C: 1  D: 1  F: 1
)";

// Compare the program's output with the original output, line by line
void checkOutput(const string& actual) {
    istringstream expectedLines(EXPECTED_OUTPUT);
    istringstream actualLines(actual);
    string expectedLine;
    string actualLine;
    int lineNumber = 0;

    while (true) {
        bool haveExpected = static_cast<bool>(getline(expectedLines, expectedLine));
        bool haveActual = static_cast<bool>(getline(actualLines, actualLine));
        lineNumber++;

        if (!haveExpected && !haveActual) {
            cout << "\nOutput check: PASS. The output matches the original exactly.\n";
            return;
        }

        if (!haveExpected || !haveActual || expectedLine != actualLine) {
            cout << "\nOutput check: FAIL at line " << lineNumber << '\n';
            cout << "  Expected: " << (haveExpected ? expectedLine : "(no more lines)") << '\n';
            cout << "  Actual:   " << (haveActual ? actualLine : "(no more lines)") << '\n';
            return;
        }
    }
}
