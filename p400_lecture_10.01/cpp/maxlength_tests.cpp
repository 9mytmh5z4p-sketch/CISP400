#include <iostream>
#include <string>
using namespace std;

// true runs the unit tests, false runs the program
const bool RUN_TESTS = true;

// A functor that checks whether input fits within a character limit
class MaxLength {
private:
    int limit;

public:
    MaxLength(int maxCharacters);
    bool operator()(const string& input) const;
};

void runProgram();
bool check(bool condition, const string& testName);
int runTests();

bool testAcceptsExactLimit();
bool testRejectsOneOverLimit();
bool testAcceptsEmptyString();

int main() {
    if (RUN_TESTS) {
        int failures = runTests();
        return failures == 0 ? 0 : 1;
    }

    runProgram();
    return 0;
}

// Print one test result and return whether it passed
bool check(bool condition, const string& testName) {
    if (condition) {
        cout << "PASS  " << testName << '\n';
    } else {
        cout << "FAIL  " << testName << '\n';
    }
    return condition;
}

// Run every test, keep going after a failure, and report the total
int runTests() {
    bool (*tests[])() = {
        testAcceptsExactLimit,
        testRejectsOneOverLimit,
        testAcceptsEmptyString
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

bool testAcceptsExactLimit() {
    MaxLength validUsername(8);
    return check(validUsername("abcdefgh"), "8 characters is accepted");
}

bool testRejectsOneOverLimit() {
    MaxLength validUsername(8);
    return check(!validUsername("abcdefghi"), "9 characters is rejected");
}

bool testAcceptsEmptyString() {
    MaxLength validUsername(8);
    return check(validUsername(""), "an empty string is accepted");
}

void runProgram() {
    MaxLength validUsername(8);

    string names[] = {"ada", "grace_hopper", "linus"};
    for (const auto& name : names) {
        if (validUsername(name)) {
            cout << name << ": accepted\n";
        } else {
            cout << name << ": too long\n";
        }
    }
}

MaxLength::MaxLength(int maxCharacters) : limit(maxCharacters) {}

// Count the characters, stopping as soon as the count passes the limit
bool MaxLength::operator()(const string& input) const {
    int count = 0;
    for (size_t i = 0; i < input.length(); i++) {
        count++;
        if (count > limit) {
            return false;
        }
    }
    return true;
}
