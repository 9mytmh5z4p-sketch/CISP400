#include <iostream>
#include <string>
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

// A functor that answers whether a student's score is at least a minimum
class ScoreAtLeast {
private:
    int minimum;

public:
    ScoreAtLeast(int minimumScore);
    bool operator()(const Student& student) const;
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

    cout << "Roster\n";
    printRoster(roster, ROSTER_SIZE);

    // Count the students at or above the passing score
    int passed = 0;
    for (int i = 0; i < ROSTER_SIZE; i++) {
        if (roster[i].getScore() >= passing) {
            passed++;
        }
    }
    cout << "Passing: " << passed << '\n';

    // Find the first student below the passing score
    int firstFail = -1;
    for (int i = 0; i < ROSTER_SIZE; i++) {
        if (roster[i].getScore() < passing) {
            firstFail = i;
            break;
        }
    }

    if (firstFail != -1) {
        cout << "First failing: " << roster[firstFail].getName() << '\n';
    } else {
        cout << "Everyone passed\n";
    }

    // Add the curve to every student's score
    for (int i = 0; i < ROSTER_SIZE; i++) {
        roster[i].addPoints(curve);
    }

    // Sort from highest score to lowest with a selection sort
    for (int i = 0; i < ROSTER_SIZE - 1; i++) {
        int best = i;
        for (int j = i + 1; j < ROSTER_SIZE; j++) {
            if (roster[j].getScore() > roster[best].getScore()) {
                best = j;
            }
        }
        Student temp = roster[i];
        roster[i] = roster[best];
        roster[best] = temp;
    }

    cout << "\nAfter a " << curve << " point curve, highest first\n";
    printRoster(roster, ROSTER_SIZE);

    // Count the honors students with a functor
    ScoreAtLeast honors(90);
    int honorsCount = 0;
    for (int i = 0; i < ROSTER_SIZE; i++) {
        if (honors(roster[i])) {
            honorsCount++;
        }
    }
    cout << "Honors: " << honorsCount << '\n';

    // Tally the letter grades in one pass
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;
    for (int i = 0; i < ROSTER_SIZE; i++) {
        switch (letterGrade(roster[i].getScore())) {
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

ScoreAtLeast::ScoreAtLeast(int minimumScore) : minimum(minimumScore) {}

bool ScoreAtLeast::operator()(const Student& student) const {
    return student.getScore() >= minimum;
}

// Print each student's name and score on its own line
void printRoster(const Student roster[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "  " << roster[i].getName() << ' ' << roster[i].getScore() << '\n';
    }
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
