#include <iostream>
#include <string>
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

void printRoster(const Student roster[], int size);
char letterGrade(int score);

int main() {
    Student roster[ROSTER_SIZE] = {
        {"Ada", 88}, {"Linus", 64}, {"Grace", 93},
        {"Alan", 55}, {"Barbara", 79}, {"Dennis", 71}
    };
    int passing = 70;
    int curve = 3;
    int honorsMinimum = 90;

    cout << "Roster\n";
    printRoster(roster, ROSTER_SIZE);

    // The lambda only reads passing, so it captures passing by value
    int passed = count_if(begin(roster), end(roster),
        [passing](const Student& student) {
            return student.getScore() >= passing;
        });
    cout << "Passing: " << passed << '\n';

    // The lambda only reads passing, so it captures passing by value
    Student* firstFail = find_if(begin(roster), end(roster),
        [passing](const Student& student) {
            return student.getScore() < passing;
        });

    if (firstFail != end(roster)) {
        cout << "First failing: " << firstFail->getName() << '\n';
    } else {
        cout << "Everyone passed\n";
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

    cout << "\nAfter a " << curve << " point curve, highest first\n";
    printRoster(roster, ROSTER_SIZE);

    // The lambda only reads honorsMinimum, so it captures it by value
    int honorsCount = count_if(begin(roster), end(roster),
        [honorsMinimum](const Student& student) {
            return student.getScore() >= honorsMinimum;
        });
    cout << "Honors: " << honorsCount << '\n';

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
    cout << "A: " << countA << "  B: " << countB << "  C: " << countC
         << "  D: " << countD << "  F: " << countF << '\n';

    return 0;
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
void printRoster(const Student roster[], int size) {
    // The lambda needs no outside data, so it captures nothing
    for_each(roster, roster + size,
        [](const Student& student) {
            cout << "  " << student.getName() << ' ' << student.getScore() << '\n';
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
