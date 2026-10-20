// debugging_0802.cpp
// Student debugging program for Lecture 08.02.
// The program contains exactly ten intentional defects.

#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct Transaction {
    string type;
    double amount;
};

class PersonalAccount {
public:
    PersonalAccount(const string& owner, int accountNumber,
                    int capacity = 4);
    ~PersonalAccount();

    PersonalAccount(const PersonalAccount& other);
    PersonalAccount& operator=(const PersonalAccount& other);

    PersonalAccount(PersonalAccount&& other) noexcept;
    PersonalAccount& operator=(PersonalAccount&& other) noexcept;

    void deposit(double amount);
    bool withdraw(double amount);

    double getBalance() const;
    int getTransactionCount() const;

    friend ostream& operator<<(ostream& output,
                               const PersonalAccount& account);

private:
    void record(const string& type, double amount);
    void grow();

    string owner;
    int accountNumber;
    double balance;
    Transaction* transactions;
    int transactionCount;
    int capacity;
};

class BusinessAccount {
public:
    BusinessAccount(const string& owner, int accountNumber,
                    int capacity = 4);
    ~BusinessAccount();

    BusinessAccount(const BusinessAccount& other);
    BusinessAccount& operator=(const BusinessAccount& other);

    BusinessAccount(BusinessAccount&& other) noexcept;
    BusinessAccount& operator=(BusinessAccount&& other) noexcept;

    void deposit(double amount);
    bool withdraw(double amount);

    double getBalance() const;
    int getTransactionCount() const;

    friend ostream& operator<<(ostream& output,
                               const BusinessAccount& account);

private:
    void record(const string& type, double amount);
    void grow();

    string owner;
    int accountNumber;
    double balance;
    Transaction* transactions;
    int transactionCount;
    int capacity;
};

void runPersonalAccountTests();
void runBusinessAccountTests();
void report(const string& label, bool result);

int main() {
    runPersonalAccountTests();
    runBusinessAccountTests();

    return 0;
}

PersonalAccount::PersonalAccount(const string& owner,
                                 int accountNumber,
                                 int capacity)
    : owner(owner),
      accountNumber(accountNumber),
      balance(0.0),
      transactions(new Transaction[capacity]),
      transactionCount(0),
      capacity(capacity) {
}

PersonalAccount::~PersonalAccount() {
    delete[] transactions;
}

PersonalAccount::PersonalAccount(const PersonalAccount& other)
    : owner(other.owner),
      accountNumber(other.accountNumber),
      balance(other.balance),
      transactions(new Transaction[other.capacity]),
      transactionCount(other.transactionCount),
      capacity(other.capacity) {
    for (int i = 0; i < transactionCount; i++) {
        transactions[i] = other.transactions[i];
    }
}

PersonalAccount& PersonalAccount::operator=(
    const PersonalAccount& other) {
    if (this != &other) {
        Transaction* replacement =
            new Transaction[other.capacity];

        for (int i = 0; i < other.transactionCount; i++) {
            replacement[i] = other.transactions[i];
        }

        delete[] transactions;

        owner = other.owner;
        accountNumber = other.accountNumber;
        balance = other.balance;
        transactions = replacement;
        transactionCount = other.transactionCount;
        capacity = other.capacity;
    }

    return *this;
}

PersonalAccount::PersonalAccount(PersonalAccount&& other) noexcept
    : owner(move(other.owner)),
      accountNumber(other.accountNumber),
      balance(other.balance),
      transactions(other.transactions),
      transactionCount(other.transactionCount),
      capacity(other.capacity) {
    other.accountNumber = 0;
    other.balance = 0.0;
    other.transactions = nullptr;
    other.transactionCount = 0;
    other.capacity = 0;
}

PersonalAccount& PersonalAccount::operator=(
    PersonalAccount&& other) noexcept {
    if (this != &other) {
        delete[] transactions;

        owner = move(other.owner);
        accountNumber = other.accountNumber;
        balance = other.balance;
        transactions = other.transactions;
        transactionCount = other.transactionCount;
        capacity = other.capacity;

        other.accountNumber = 0;
        other.balance = 0.0;
        other.transactions = nullptr;
        other.transactionCount = 0;
        other.capacity = 0;
    }

    return *this;
}

void PersonalAccount::deposit(double amount) {
    if (amount > 0.0) {
        balance += amount;
        record("deposit", amount);
    }
}

bool PersonalAccount::withdraw(double amount) {
    if (amount <= 0.0 || amount > balance) {
        return false;
    }

    balance -= amount;
    record("withdrawal", amount);
    return true;
}

double PersonalAccount::getBalance() const {
    return balance;
}

int PersonalAccount::getTransactionCount() const {
    return transactionCount;
}

void PersonalAccount::record(const string& type, double amount) {
    if (transactionCount == capacity) {
        grow();
    }

    transactions[transactionCount].type = type;
    transactions[transactionCount].amount = amount;
    transactionCount++;
}

void PersonalAccount::grow() {
    int newCapacity = capacity * 2;
    Transaction* replacement = new Transaction[newCapacity];

    for (int i = 0; i < transactionCount; i++) {
        replacement[i] = transactions[i];
    }

    delete[] transactions;
    transactions = replacement;
    capacity = newCapacity;
}

ostream& operator<<(ostream& output,
                    const PersonalAccount& account) {
    output << fixed << setprecision(2);
    output << "Owner: " << account.owner << '\n';
    output << "Account number: " << account.accountNumber << '\n';
    output << "Balance: $" << account.balance << '\n';
    output << "Transaction storage: "
           << static_cast<const void*>(account.transactions) << '\n';

    for (int i = 0; i < account.transactionCount; i++) {
        output << "  " << account.transactions[i].type
               << ": $" << account.transactions[i].amount << '\n';
    }

    return output;
}

BusinessAccount::BusinessAccount(const string& owner,
                                 int accountNumber,
                                 int capacity)
    : owner(owner),
      accountNumber(accountNumber),
      balance(0.0),
      transactions(new Transaction[capacity]),
      transactionCount(0),
      capacity(capacity) {
}

BusinessAccount::~BusinessAccount() {
    delete transactions;
}

BusinessAccount::BusinessAccount(const BusinessAccount& other)
    : owner(other.owner),
      accountNumber(other.accountNumber),
      balance(other.balance),
      transactions(other.transactions),
      transactionCount(other.transactionCount),
      capacity(other.capacity) {
}

BusinessAccount& BusinessAccount::operator=(
    const BusinessAccount& other) {
    delete[] transactions;

    owner = other.owner;
    accountNumber = other.accountNumber;
    balance = other.balance;
    transactions = other.transactions;
    transactionCount = other.transactionCount;
    capacity = other.capacity;

    return *this;
}

BusinessAccount::BusinessAccount(BusinessAccount&& other) noexcept
    : owner(move(other.owner)),
      accountNumber(other.accountNumber),
      balance(other.balance),
      transactions(other.transactions),
      transactionCount(other.transactionCount),
      capacity(other.capacity) {
}

BusinessAccount& BusinessAccount::operator=(
    BusinessAccount&& other) noexcept {
    if (this != &other) {
        owner = move(other.owner);
        accountNumber = other.accountNumber;
        balance = other.balance;
        transactions = other.transactions;
        transactionCount = other.transactionCount;
        capacity = other.capacity;
    }

    return *this;
}

void BusinessAccount::deposit(double amount) {
    if (amount > 0.0) {
        balance += amount;
        record("deposit", amount);
    }
}

bool BusinessAccount::withdraw(double amount) {
    if (amount < 0.0 || amount > balance) {
        return false;
    }

    balance -= amount;
    record("withdrawal", amount);
    return true;
}

double BusinessAccount::getBalance() const {
    return balance;
}

int BusinessAccount::getTransactionCount() const {
    return transactionCount;
}

void BusinessAccount::record(const string& type, double amount) {
    if (transactionCount > capacity) {
        grow();
    }

    transactions[transactionCount].type = type;
    transactions[transactionCount].amount = amount;
    transactionCount++;
}

void BusinessAccount::grow() {
    int newCapacity = capacity * 2;
    Transaction* replacement = new Transaction[newCapacity];

    for (int i = 0; i < transactionCount; i++) {
        replacement[i] = transactions[i];
    }

    delete[] transactions;
    transactions = replacement;
    capacity = newCapacity;
}

ostream& operator<<(ostream& output,
                    const BusinessAccount& account) {
    output << fixed << setprecision(2);
    output << "Owner: " << account.owner << '\n';
    output << "Account number: " << account.accountNumber << '\n';
    output << "Balance: $" << account.balance << '\n';
    output << "Transaction storage: "
           << static_cast<const void*>(account.transactions) << '\n';

    return output;
}

void runPersonalAccountTests() {
    cout << "Personal account tests\n";
    cout << "======================\n";

    PersonalAccount account("Avery Chen", 1001);
    account.deposit(100.00);
    account.deposit(25.00);
    account.withdraw(40.00);

    cout << account << '\n';

    PersonalAccount copied(account);
    copied.deposit(50.00);

    assert(account.getBalance() == 85.00);
    assert(copied.getBalance() == 135.00);

    PersonalAccount assigned("Jordan Lee", 2002);
    assigned.deposit(10.00);
    assigned = account;

    assert(assigned.getBalance() == 85.00);
    assert(assigned.getTransactionCount() ==
           account.getTransactionCount());

    PersonalAccount selfAssigned(account);
    double balanceBefore = selfAssigned.getBalance();
    int countBefore = selfAssigned.getTransactionCount();
    selfAssigned = selfAssigned;

    assert(selfAssigned.getBalance() == balanceBefore);
    assert(selfAssigned.getTransactionCount() == countBefore);

    PersonalAccount moved(move(account));
    assert(moved.getBalance() == 85.00);
    assert(account.getTransactionCount() == 0);

    PersonalAccount moveAssigned("Temporary", 3003);
    moveAssigned = move(moved);

    assert(moveAssigned.getBalance() == 85.00);
    assert(moved.getTransactionCount() == 0);

    cout << "Personal account tests completed.\n\n";
}

void runBusinessAccountTests() {
    cout << "Business account tests\n";
    cout << "======================\n";

    BusinessAccount account("Avery Chen", 1001);
    account.deposit(100.00);
    account.deposit(25.00);
    account.withdraw(40.00);

    cout << account << '\n';

    BusinessAccount copied(account);
    copied.deposit(50.00);

    report("Copy keeps the original balance", 
           account.getBalance() == 85.00);
    report("Copy receives its own deposit", 
           copied.getBalance() == 135.00);

    BusinessAccount assigned("Jordan Lee", 2002);
    assigned.deposit(10.00);
    assigned = account;

    report("Copy assignment preserves the balance", 
           assigned.getBalance() == 85.00);

    BusinessAccount selfAssigned(account);
    selfAssigned = selfAssigned;

    report("Self-assignment preserves the balance", 
           selfAssigned.getBalance() == 85.00);

    BusinessAccount moved(move(account));

    report("Moved-from account is empty", 
           account.getTransactionCount() == 0);

    BusinessAccount moveAssigned("Temporary", 3003);
    moveAssigned = move(moved);

    report("Move-assigned account has the balance", 
           moveAssigned.getBalance() == 85.00);
    report("Move source is empty", 
           moved.getTransactionCount() == 0);

    bool rejected = !moveAssigned.withdraw(0.00);
    report("Zero-dollar withdrawal is rejected", rejected);

    cout << "Business account tests completed.\n";
}

void report(const string& label, bool result) {
    cout << (result ? "PASS: " : "FAIL: ") << label << '\n';
}
