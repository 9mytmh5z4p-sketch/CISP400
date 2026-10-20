#include <iostream>
#include <string>
#include <cassert>
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
    // This precondition requires a nonempty gradebook because the report computes an average and highest score.
    // If it is false, the report asks observers to operate on data that does not exist.
    assert(book.size() > 0 && "report requires at least one score");
    cout << label << '\n';
    cout << "  Scores:  ";
    book.print();
    cout << "  Count:   " << book.size() << '\n';
    cout << "  Average: " << book.average() << '\n';
    cout << "  Highest: " << book.highestScore() << "\n\n";
}

void Gradebook::checkInvariant() const {
    // This class invariant requires the number of stored scores to stay within the array bounds.
    // If it is false, member functions may read or write outside the gradebook's valid storage.
    assert(count >= 0 && count <= CAPACITY && "count must be between 0 and capacity");
    for (int i = 0; i < count; i++) {
        // This class invariant requires every stored score to remain in the valid score range.
        // If it is false, reports and later calculations use invalid grade data.
        assert(scores[i] >= 0 && scores[i] <= 100 && "stored scores must be between 0 and 100");
    }
}

// Store a new score at the end of the gradebook
void Gradebook::addScore(int score) {
    // This precondition requires the new score to be within the gradebook's valid range.
    // If it is false, the object will store invalid data.
    assert(score >= 0 && score <= 100 && "score must be between 0 and 100");
    // This precondition requires room for one more score in the fixed-size array.
    // If it is false, the assignment writes beyond the array.
    assert(count < CAPACITY && "gradebook must have capacity for a new score");
    scores[count] = score;
    count++;
    checkInvariant();
}

// Remove the most recently added score
void Gradebook::removeLast() {
    // This precondition requires at least one score before removing the last score.
    // If it is false, decrementing count creates an invalid gradebook state.
    assert(count > 0 && "cannot remove a score from an empty gradebook");
    count--;
    checkInvariant();
}

// Add the same number of points to every score
void Gradebook::applyCurve(int points) {
    // This precondition requires the curve amount to represent adding points.
    // If it is false, the operation changes scores in an unintended direction.
    assert(points >= 0 && "curve points must be nonnegative");
    for (int i = 0; i < count; i++) {
        scores[i] += points;
    }
    checkInvariant();
}

// Return the mean of all stored scores
double Gradebook::average() const {
    // This precondition requires at least one score because an average divides by count.
    // If it is false, the calculation divides by zero and has no meaningful result.
    assert(count > 0 && "cannot calculate an average for an empty gradebook");
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    // This postcondition requires the returned average to remain within the valid score range.
    // If it is false, the calculation or stored data produced an impossible result.
    assert(total / count >= 0 && total / count <= 100 && "average must be between 0 and 100");
    return total / count;
}

// Return the largest stored score
int Gradebook::highestScore() const {
    // This precondition requires at least one score because the first stored score initializes best.
    // If it is false, reading scores[0] accesses data outside the logical gradebook.
    assert(count > 0 && "cannot find a highest score in an empty gradebook");
    int best = scores[0];
    for (int i = 1; i < count - 1; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }
    // This postcondition requires the result to remain within the valid score range.
    // If it is false, the function returned an impossible score.
    assert(best >= 0 && best <= 100 && "highest score must be between 0 and 100");
    for (int i = 0; i < count; i++) {
        // This postcondition requires the result to be at least as large as every stored score.
        // If it is false, the function did not inspect or compare the complete gradebook.
        assert(best >= scores[i] && "highest score must be at least every stored score");
    }
    return best;
}

// Return the number of stored scores
int Gradebook::size() const {
    // This postcondition requires size to remain within the fixed array's valid bounds.
    // If it is false, callers may use an invalid count to access the gradebook.
    assert(count >= 0 && count <= CAPACITY && "size must be between 0 and capacity");
    return count;
}

// Print every stored score on one line
void Gradebook::print() const {
    for (int i = 0; i < count; i++) {
        cout << scores[i] << ' ';
    }
    cout << '\n';
}
