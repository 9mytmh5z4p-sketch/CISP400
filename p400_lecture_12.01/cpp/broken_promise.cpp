// broken_promise.cpp
// SavingsAccount overrides withdraw() and drops the check
// that BankAccount promised.
#include <iostream>
using namespace std;

class BankAccount {
protected:
    double balance;

public:
    BankAccount(double start) : balance(start) { }
    double getBalance() const { return balance; }

    // the promise: never take out more than is there
    bool withdraw(double amount) {
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double start) : BankAccount(start) { }

    // charges a 2.00 fee, but forgot the check
    bool withdraw(double amount) {
        balance -= amount + 2.00;
        return true;
    }
};

int main() {
    BankAccount checking(50.00);
    SavingsAccount savings(50.00);

    checking.withdraw(100.00);
    savings.withdraw(100.00);

    cout << "Checking: " << checking.getBalance() << endl;
    cout << "Savings: " << savings.getBalance() << endl;
    return 0;
}
