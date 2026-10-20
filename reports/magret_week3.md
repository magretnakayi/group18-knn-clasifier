WEEK 3 REPORT
 Dataset loading implementation and testing
1. Overview and Objective
This week, my main goal was to finalize, structure, and verify the Dataset Loading module for our group’s modular C++ K-Nearest Neighbors (KNN) classification project. Instead of keeping everything in one messy script, we needed to split our code cleanly into header and source files (include/ and src/) which I handled last week. I therefore aimed at setting up automated tests, usage examples and my main function, and ensure our CSV dataset (dataset.csv) could be parsed accurately without compilation errors.
2. What Was Accomplished
•	Modular Code Refactoring: Created a clean separation of concerns by putting our DataPoint structure definition and loadCSV function declaration inside include/dataset.hpp, and writing the actual file-parsing logic inside src/dataset.cpp.
•	Main Verification Script: Developed src/dataset_main.cpp as our primary entry point to test reading the dataset, checking for empty files, and printing record previews.
•	Skeleton Population: Added unit test files (tests/test_dataset.cpp) and example snippets (examples/example_dataset.cpp) to help our team members integrate the module easily.
•	Directory Structure Setup: Kept our project organized across src/, include/, tests/, and examples/ folders for clean version control on GitHub.
3. Challenges Encountered and How I Solved Them
1.	Code Runner Extension Errors:
	Chanllenge: When trying to run files using the VS Code "Code Runner" play button, I kept getting errors.
	The Solution. I solved this by abandoning Code Runner for multi-file builds and compiling directly from the project root terminal.
2.	Function Name Consistency:
	Challenge: Minor naming mismatches such as loadDataset and loadCSV across headers and main files which brought errors in my main_dataset.cpp
	The solution: I standardized all references to loadCSV so the compiler linked everything seamlessly.
4. Tools and Environment Used
•	Language: C++17 (std::vector, std::ifstream, std::stringstream)
•	Compiler: g++ (MinGW-w64 toolchain)
•	Environment: Visual Studio Code on Windows, Git Bash / PowerShell terminal
•	Version Control: Git and GitHub repository tracking
5. Verification Results and Output 
 	After fixing our compilation paths from the root directory (g++ src/dataset_main.cpp src/dataset.cpp -Iinclude -o dataset.exe), running ./dataset.exe produced the following successful output:
 
6. Next week’s plans
	After successfully completing my dataset loading module, I will start my nxt task which is majority voting where I will also handle the modulation part first.
7. AI declaration
	AI tools were referenced for small syntax errors
	I also used it to help me on how to run my files since my code runner was outing errors

The rest of the work was done, tested and approved by me and my group members
8. Conclusion
The dataset loading module was successfully tested, and verified. The code successfully reads CSV datasets into memory, builds feature vectors, and parses target class labels.

