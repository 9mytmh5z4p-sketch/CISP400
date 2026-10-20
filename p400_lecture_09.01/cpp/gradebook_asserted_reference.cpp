#include <iostream>
#include <cassert>
#include <string>
using namespace std;

const int CAPACITY = 5;

// A gradebook stores up to CAPACITY exam scores.
// Every score should be between 0 and 100.
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

void report(const string& label, const Gradebook& book);

int main() {
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

    return 0;
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

// Class invariant: 0 <= count <= CAPACITY and every stored score is 0 to 100.
// Each member function that changes the object checks it before returning.
void Gradebook::checkInvariant() const {
    assert(count >= 0 && count <= CAPACITY && "count is out of range");
    for (int i = 0; i < count; i++) {
        assert(scores[i] >= 0 && scores[i] <= 100 && "a stored score is outside 0 to 100");
    }
}

// Store a new score at the end of the gradebook
void Gradebook::addScore(int score) {
    // Preconditions: there is room, and the caller passed a legal score.
    // Checking before the write stops a bad value from ever entering the object.
    assert(count < CAPACITY && "addScore on a full gradebook");
    assert(score >= 0 && score <= 100 && "score must be between 0 and 100");
    scores[count] = score;
    count++;
    checkInvariant();
}

// Remove the most recently added score
void Gradebook::removeLast() {
    // Precondition: there must be a score to remove, or count would go negative.
    assert(count > 0 && "removeLast on an empty gradebook");
    count--;
    checkInvariant();
}

// Add the same number of points to every score
void Gradebook::applyCurve(int points) {
    for (int i = 0; i < count; i++) {
        scores[i] += points;
    }
    // A curve must not push any score past 100, so recheck the invariant.
    checkInvariant();
}

// Return the mean of all stored scores
double Gradebook::average() const {
    // Precondition: an average needs at least one score; otherwise we divide by zero.
    assert(count > 0 && "average of an empty gradebook");
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    return total / count;
}

// Return the largest stored score
int Gradebook::highestScore() const {
    // Precondition: there must be a score to compare.
    assert(count > 0 && "highestScore of an empty gradebook");
    int best = scores[0];
    for (int i = 1; i < count - 1; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }
    // Postcondition: the result is at least as large as every stored score.
    // If the loop skipped an element, this check finds it.
    for (int i = 0; i < count; i++) {
        assert(best >= scores[i] && "highestScore missed a larger score");
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
