#include <iostream>
#include <string>
using namespace std;

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
    // Bug: 105 is outside the legal range of 0 to 100.
    // Symptom: the final exam showed a score of 105, which also raised its average and highest score.
    // Rule broken: the addScore precondition that every score is between 0 and 100.
    // Fix: enter a legal score. The value 95 is assumed to be what was meant, so confirm it against the original records.
    // finalExam.addScore(105);
    finalExam.addScore(95);
    finalExam.addScore(64);
    report("Final exam", finalExam);

    midterm.applyCurve(5);
    report("Midterm after a 5 point curve", midterm);

    Gradebook makeup;
    // Bug: report calls average and highestScore, which both need at least one score.
    // Symptom: with no scores, average divided by zero and printed nan, and highestScore printed a meaningless 0.
    // Rule broken: the average and highestScore precondition that count is greater than 0.
    // Fix: the caller checks for an empty gradebook before asking for statistics about it.
    // report("Makeup exam", makeup);
    if (makeup.size() > 0) {
        report("Makeup exam", makeup);
    } else {
        cout << "Makeup exam\n  No scores recorded\n\n";
    }

    // Bug: removeLast was called on a gradebook with no scores.
    // Symptom: count dropped to -1, so the gradebook reported a size of -1.
    // Rule broken: the removeLast precondition that count is greater than 0, which protects the class invariant 0 <= count <= CAPACITY.
    // Fix: the caller only removes a score when there is one to remove.
    // makeup.removeLast();
    if (makeup.size() > 0) {
        makeup.removeLast();
    }
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
        // Bug: the curve added points with no upper limit.
        // Symptom: the curved midterm turned 99 into 104.
        // Rule broken: the class invariant that every stored score is between 0 and 100.
        // Fix: add the points, but never let a score go above 100.
        // scores[i] += points;
        if (scores[i] + points > 100) {
            scores[i] = 100;
        } else {
            scores[i] += points;
        }
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
    // Bug: the loop stopped one element early, so the last score was never compared.
    // Symptom: the midterm reported 95 as the highest score instead of 99.
    // Rule broken: the postcondition that the result is at least as large as every stored score.
    // Fix: compare every score through index count - 1 by looping while i < count.
    // for (int i = 1; i < count - 1; i++) {
    for (int i = 1; i < count; i++) {
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
