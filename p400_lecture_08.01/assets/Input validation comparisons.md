Input validation comparisons

1. Range checking conditions (`x >= min && x <= max`)
2. Whitelist loop conditions (`while input != "Sue" && input != "Dan"`)
3. Blacklist loop conditions (`while input == "Bob"`)
4. Null / empty check (`if str.length() == 0`)
5. Whitespace-only check (counting blank characters vs. string length)
6. Type failure check (`if !(cin >> x)`)
7. cin stream clearing and flushing (after a type mismatch failure)
8. isDirty flag pattern (boolean that any failed check can flip to true)
9. Do-while reprompt loop (guarantees at least one prompt before checking)
10. Character classification checks (`isupper()`, `islower()`, `isdigit()`)
11. getline() vs cin (for capturing full strings including spaces)
12. Constants for bounds (`MIN_PLAYERS`, `MAX_PLAYERS` instead of magic numbers)