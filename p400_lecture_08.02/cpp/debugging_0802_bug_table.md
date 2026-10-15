# Debugging 0802 Bug Table

The snippets below are intentionally shown without their surrounding code. Line numbers refer to `debugging_0802.cpp`.

| Bug | Line(s) | What the error is | Out-of-context code |
|---|---:|---|---|
| 1 | 264–266 | An array is released with the scalar form of `delete`. | `BusinessAccount::~BusinessAccount() {`<br>`    delete transactions;`<br>`}` |
| 2 | 268–274 | The copy constructor copies the pointer, so both accounts share one transaction array. | `transactions(other.transactions),`<br>`transactionCount(other.transactionCount),`<br>`capacity(other.capacity) {` |
| 3 | 277–280 | Copy assignment does not detect self-assignment before releasing the current array. | `BusinessAccount& BusinessAccount::operator=(`<br>`    const BusinessAccount& other) {`<br>`    delete[] transactions;` |
| 4 | 281–286 | Copy assignment assigns the source pointer instead of creating an independent copy. | `owner = other.owner;`<br>`accountNumber = other.accountNumber;`<br>`balance = other.balance;`<br>`transactions = other.transactions;` |
| 5 | 291–298 | The move constructor takes the pointer but leaves the source account pointing at the same array. | `BusinessAccount::BusinessAccount(BusinessAccount&& other) noexcept`<br>`    : owner(move(other.owner)),`<br>`      transactions(other.transactions),`<br>`      transactionCount(other.transactionCount),`<br>`      capacity(other.capacity) {`<br>`}` |
| 6 | 300–306 | Move assignment overwrites the destination pointer without releasing the destination’s existing array. | `BusinessAccount& BusinessAccount::operator=(`<br>`    BusinessAccount&& other) noexcept {`<br>`    if (this != &other) {`<br>`        owner = move(other.owner);`<br>`        transactions = other.transactions;` |
| 7 | 303–309 | Move assignment leaves the source account pointing at and describing the transferred array. | `owner = move(other.owner);`<br>`accountNumber = other.accountNumber;`<br>`balance = other.balance;`<br>`transactions = other.transactions;`<br>`transactionCount = other.transactionCount;`<br>`capacity = other.capacity;` |
| 8 | 339–342 | The capacity check waits until after the array is already full, allowing an out-of-bounds write. | `void BusinessAccount::record(const string& type, double amount) {`<br>`    if (transactionCount > capacity) {`<br>`        grow();`<br>`    }` |
| 9 | 321–324 | The withdrawal test accepts an amount of exactly zero. | `bool BusinessAccount::withdraw(double amount) {`<br>`    if (amount < 0.0 || amount > balance) {`<br>`        return false;`<br>`    }` |
| 10 | 362–371 | The output operator prints the transaction-array address but omits the transaction details. | `ostream& operator<<(ostream& output,`<br>`                    const BusinessAccount& account) {`<br>`    output << "Owner: " << account.owner << '\\n';`<br>`    output << "Account number: " << account.accountNumber << '\\n';`<br>`    output << "Balance: $" << account.balance << '\\n';`<br>`    output << "Transaction storage: "`<br>`           << static_cast<const void*>(account.transactions) << '\\n';`<br>`    return output;`<br>`}` |
