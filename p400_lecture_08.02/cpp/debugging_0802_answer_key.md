# Debugging 0802 Answer Key

`PersonalAccount` is the reference implementation. `BusinessAccount` contains exactly ten intentional defects.

## Bug 1: Mismatched deallocation

Line 265 releases an array with `delete`:

```cpp
delete transactions;
```

The constructor allocates an array with `new Transaction[capacity]`, so the destructor must use:

```cpp
delete[] transactions;
```

Using the wrong form is undefined behavior.

## Bug 2: Copy constructor shares the transaction array

Lines 268–274 copy the pointer instead of allocating independent storage and copying the transactions.

The copy constructor should allocate an array with `other.capacity`, copy each transaction, and then store the copied transaction count and capacity. `PersonalAccount` lines 117–127 show the intended pattern.

Because the two objects share the same pointer, changing one account can change the other, and both objects eventually try to release the same allocation.

## Bug 3: Copy assignment does not protect against self-assignment

Line 279 deletes the destination array before determining whether the source and destination are the same object.

The function should begin with:

```cpp
if (this != &other) {
    // Replace the destination resource.
}
```

Without the check, `account = account;` destroys the resource and then tries to read from it.

## Bug 4: Copy assignment shares the transaction array

Line 284 assigns the source pointer directly:

```cpp
transactions = other.transactions;
```

Copy assignment must allocate replacement storage and copy each transaction before releasing the old destination storage. The destination and source must own separate arrays.

## Bug 5: Move constructor does not reset the moved-from account

The move constructor takes the pointer on line 295 but leaves the source pointing to the same array.

After taking ownership, it must reset the source:

```cpp
other.transactions = nullptr;
other.transactionCount = 0;
other.capacity = 0;
```

The source should remain valid and empty after the move.

## Bug 6: Move assignment does not release the destination resource

Lines 302–309 overwrite `transactions` without first releasing the array already owned by the destination.

The function must release the destination resource before taking ownership:

```cpp
delete[] transactions;
```

The release belongs inside the `if (this != &other)` block and before the new pointer is assigned.

## Bug 7: Move assignment does not reset the moved-from account

Line 306 takes the source pointer, but lines 307–308 leave the source counts unchanged.

After the transfer, reset the source pointer, transaction count, capacity, balance, and account number as shown in the correct move assignment at lines 178–182.

## Bug 8: Transaction capacity check uses the wrong boundary

Line 340 uses:

```cpp
if (transactionCount > capacity) {
```

The array must grow when the count is already equal to the capacity:

```cpp
if (transactionCount == capacity) {
```

With the current condition, the program writes one element past the end of the array when the array is full.

## Bug 9: Zero-dollar withdrawals are accepted

Line 322 checks for an amount less than zero:

```cpp
if (amount < 0.0 || amount > balance) {
```

The condition should reject zero as well:

```cpp
if (amount <= 0.0 || amount > balance) {
```

The account should record only positive withdrawals.

## Bug 10: `operator<<` prints the pointer but not the transactions

Lines 362–371 print account information and the transaction-array address, but they omit the transaction loop.

The output operator should use the same loop as `PersonalAccount` lines 245–248 so that it displays each transaction’s type and amount. Printing the pointer address is useful diagnostic information, but it is not a complete account report.

