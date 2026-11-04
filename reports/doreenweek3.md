Data preprocessing implementation and testing (Main, Examples, and Tests)
1. Overview and Objective
This week, my main goal was to design, implement, and verify the core execution scripts, usage examples, and automated unit tests for the Data Preprocessing module (Part B) of our group’s modular C++ K-Nearest Neighbors (KNN) classification project. Building directly on top of our feature-scaling logic, I focused entirely on setting up the main verification entry point (src/preprocessing_main.cpp), sample usage scripts (examples/example_preprocessing.cpp), and automated unit tests (tests/test_datapreprocessing.cpp) to ensure the normalization and standard scaling functions integrate smoothly and execute correctly.
2. Work Accomplished
•	Main Verification Script (src/preprocessing_main.cpp): Developed the primary entry-point script utilizing using namespace std; to load our dataset, invoke Min-Max Normalization and Standard Scaling, and print out formatted before-and-after comparisons in the terminal.
•	Usage Examples (examples/example_preprocessing.cpp): Created a clean, standalone example script demonstrating how team members can easily call and apply the preprocessing features in other parts of the codebase.
•	implemented tests./tests_datapreprocessing .cppusing assertions to verify preprocessing results.
3. Challenges Encountered and How I Solved Them
1.	Multi-File Compilation Pathing:
o	Challenge: Compiling the main execution files and test files together with the preprocessing and dataset source files from the root directory caused linker errors due to relative path mismatches.
o	The Solution: Standardized our multi-file build commands using explicit include flags (-Iinclude) and compiling directly from the project root.
2.	Verification Assertions Setup:
o	Challenge: Handling floating-point precision comparisons inside unit test assertions when validating scaled decimal outputs.
o	The Solution: Configured exact threshold bounds in test_datapreprocessing.cpp to validate Min-Max normalization ranges (0.0, 0.5, and 1.0) reliably.
4. Tools and Environment Used
•	Language: C++17 (std::vector, cassert, std::iostream, using namespace std;)
•	Compiler: g++ (MinGW-w64 toolchain)
5. Verification Results and Output
After configuring our compilation path from the root directory (g++ src/preprocessing_main.cpp src/datapreprocessing.cpp src/dataset.cpp -Iinclude -o preprocessing_main.exe), the main program compiled and ran successfully,displaying the scaled feauture values without runtime errors
6. Next week’s plans
implement the class predicton component of the KNN algorithm in C++ to classify new data points based on the majority class of their nearest neighbors
7. AI declaration
•	AI tools were referenced for minor syntax structuring on unit test assertion blocks .
•	The rest of the work was done, tested, and approved by me and my group members.
8. Conclusion
The preprocessing main execution scripts, usage examples, and unit tests were successfully implemented, tested, and verified. The test suites pass cleanly, and the main runner accurately demonstrates scaled dataset transformations ready for the next phase of our KNN classifier.






