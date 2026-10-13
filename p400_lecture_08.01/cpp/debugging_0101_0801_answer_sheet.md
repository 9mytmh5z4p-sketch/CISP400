# Debugging 01.01–08.01: Answer Sheet

1. **Bug:** The search loop starts at index `1` and skips the first item.  
   **Fix:** Start the loop at index `0`.

2. **Bug:** Student ID validation accepts IDs longer than four digits.  
   **Fix:** Require `studentId.length() == 4` and verify every character is a digit.

3. **Bug:** Checkout allows an item with zero available quantity.  
   **Fix:** Require `item->quantity > 0` before decrementing it.

4. **Bug:** Return allows an item with no active checkout.  
   **Fix:** Require `item->checkedOut > 0` before decrementing it.

5. **Bug:** Late-fee calculation performs integer division.  
   **Fix:** Multiply `daysLate` directly by `dailyRate`.

6. **Bug:** The sort comparator orders names in descending order.  
   **Fix:** Compare names with `<` for ascending order.

7. **Bug:** The discount subtracts the percentage as a dollar amount.  
   **Fix:** Multiply the rate by `1.0 - percentage`.

8. **Bug:** Available quantity is calculated from checked-out quantity.  
   **Fix:** Sum each item’s `quantity` field.

9. **Bug:** A pointer is sent directly to `operator<<`, so the stream prints its address.  
   **Fix:** Dereference the pointer with `*reportItem` before streaming it.

10. **Bug:** A pointer is dereferenced before checking whether it is `nullptr`.  
    **Fix:** Check `item != nullptr` before accessing `item->active`.
