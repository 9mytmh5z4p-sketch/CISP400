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
