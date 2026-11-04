MAJORITY VOTING AND TIEHANDLING TESTING AND EXAMPLES REPORT
1. Overview 
Majority voting module determines the most frequent (plurality) class label among the k nearest neighbors.
Tie handling module resolves frequency ties when multiple classes receive an equal number of votes among the k neighbors.
2. Implementation and design of files
a. Majority voting
Majority voting_main.cpp: Acts as the primary execution driver. Allocates sample neighbor labels on the heap, instantiates the voter object, and outputs the winning plurality class using cout.
example_majority_voting.cpp: Provides a standalone usage script demonstrating how custom neighbor arrays are passed to the voting module.
test_majority_voting.cpp: Utilizes assertions (assert) to verify that the voting module correctly identifies the majority class under controlled inputs.
b. Tie handling
Tiehandling_main.cpp: Executes the tie-breaking driver, establishing an ambiguous voting scenario to demonstrate conflict resolution on the console.
example_tie_handling.cpp: Standalone example showcasing distance-based tie resolution with sample console logs.
test_tie_handling.cpp: Validates that tie-handling fallback logic correctly triggers and resolves equal-vote disputes using assertions.


3. Error Handling Strategies
a. Majority voting
Bounds & Pointer Validation: Verifies that k > 0 and the incoming label pointer is not null (nullptr).
Exception Safety: Throws std::invalid_argument upon detecting invalid dimensions or null pointers, caught safely in the driver block with console logs (cout).
b. Tie handling
Pointer Integrity: Checks for null pointers on both label and distance arrays.
Dimension Matching: Ensures k bounds are respected; throws std::invalid_argument if memory allocation fails or data parameters conflict
4. Conclusion
The Majority Voting module successfully delivers a lightweight, pointer-based plurality calculation engine. By managing frequency arrays dynamically on the heap, it fulfills core design constraints while ensuring robust input validation and safe error handling.
The Tie Handling module provides a dependable fallback mechanism for ambiguous voting outcomes. By integrating distance metrics directly into vote resolution, it prevents classification blind spots and maintains high algorithmic consistency.
