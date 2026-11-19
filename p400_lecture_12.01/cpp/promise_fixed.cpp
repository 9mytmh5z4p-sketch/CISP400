// promise_fixed.cpp
// SavingsAccount keeps BankAccount's promise by calling the base version.
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;       // private again: SavingsAccount no longer touches it

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

    // adds the 2.00 fee, then lets BankAccount do the checking
    bool withdraw(double amount) {
        return BankAccount::withdraw(amount + 2.00);
    }
};

int main() {
    SavingsAccount savings(50.00);

    bool big = savings.withdraw(100.00);
    cout << "100.00: " << (big ? "paid" : "refused")
         << ", balance " << savings.getBalance() << endl;

    bool small = savings.withdraw(20.00);
    cout << "20.00: " << (small ? "paid" : "refused")
         << ", balance " << savings.getBalance() << endl;
    return 0;
}
