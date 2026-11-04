GROUP 18 PROJECT PROGRESS REPORT
1. Overview
This progress report summarizes the architectural development and implementation progress of the modular C++ K-Nearest Neighbors (KNN) classification system. The project strictly adheres to modular programming principles, separating code into include/ header files, src/ implementation files, tests/ unit testing files, examples/ demonstration drivers, and individual component progress reports.
During this week, the group focused on verifying each module independently. Every group member authored their module's main execution driver (_main.cpp), unit test suite (_test.cpp), demonstration example (_example.cpp), and weekly progress report (_week3.md).
2. Implementation Tools
C++ (C++11 / C++17 Standard): Programming Language
	Purpose & Application: Core execution environment providing object-oriented structure, high performance, and standard memory management.
GCC / MinGW Toolchain: Compiler & Build Tools
	Purpose & Application: Used for compiling local source files, linking modules, and generating native performance executables (gcc/g++).
Visual Studio Code (VS Code): Integrated Development Environment
	Purpose & Application: Primary workspace for multi-file C++ development, inline debugging, terminal operations, and source control management.
Git & GitHub: Version Control & Collaboration
	Purpose & Application: Branch-based collaboration workflow, source tracking, pull requests, and commit attribution management across team branches.
Standard Template Library (STL): Built-in Libraries
	Purpose & Application: Utilized high-level containers (std::vector), standard mathematical functions (std::sqrt), stream handlers (std::ifstream, std::stringstream), and assertion utilities (cassert).
3. Component Implementation & Driver Coverage Summary
Module & Member	Main Driver(_main.cpp)	Unit Test (_test.cpp)	Example (_example.cpp)	Report (_week3.md)
Dataset Loading

(Nakayi Magret)	src/dataset_main.cpp

Executes standalone CSV parsing, skips headers, and prints parsed DataPoint count.	tests/test_dataset.cpp

Uses cassert to verify non-empty file loading and feature vector dimensions.	examples/example_dataset.cpp

Demonstrates how to load a CSV dataset and access individual records.	reports/magret_week3.md

Documents file streams, CSV line tokenization, and vector allocations.
Data Preprocessing

(Nyamwiija Doreen)	src/datapreprocessing_main.cpp
Runs quality checks on loaded dataset records to catch corrupt values.	tests/datapreprocessing_test.cpp
Asserts feature dimension consistency across all sample vectors in a dataset.	examples/datapreprocessing_example.cpp
Shows how to filter corrupt or missing feature rows before feature scaling.	reports/doreenweek3.md
Outlines vector validation checks, dimension assertions, and fixes.
Feature Scaling
(Ssewagudde Jason Samuel)	src/featurescaling_main.cpp

Applies Min-Max normalization to map feature values into [0.0, 1.0].	tests/featurescaling_test.cpp
Asserts scaled outputs remain within [0.0, 1.0] and checks zero-range bounds.	examples/featurescaling_example.cpp
Prints raw feature values side-by-side with Min-Max scaled values.	reports/jason_week3.md
Details normalization math, min/max bounds checking, and safeguards.
Distance Calculation

(Nkangula Abdul Latif)	src/distance_main.cpp

Calculates multi-dimensional Euclidean distance between target and reference points.	tests/distance_test.cpp

Asserts mathematical correctness using known 2D and 3D coordinate distances.	examples/distance_example.cpp

Demonstrates step-by-step distance calculation between two feature vectors.	reports/abdul_week3.md

Covers Euclidean distance loops, std::sqrt optimization, and tests.
KNN Search

(Kasule Juma Kasujja)	src/knnsearch_main.cpp

Scans dataset points, computes distances, and builds an ordered proximity array.	tests/knnsearch_test.cpp

Asserts that proximity query results are sorted in ascending distance order.	examples/knnsearch_example.cpp

Executes a query and prints the sorted distance-label pairs for nearest samples	
KNN selection

(Namukisa Favour E. Kiwuso)	Rc/knnselection_main.cpp
Executes selectMajorityLabel over sorted neighbors to perform knn selection.
	tests/knnselection_test.cpp


Asserts correct majority class prediction using mock neighbor arrays and knn values.
	examples/knnselection_example.cpp


Demonstrates extracting top knn neighbors and outputting the predicted class label.
	
3. Challenges Faced & Resolutions
We have encountered and resolved several technical problems as shown below
a)	Interface Mismatch with Pre-Existing Headers
Challenge: Integrating newly implemented main drivers and test harnesses with locked, pre-submitted header interfaces (dataset.hpp, knnselection.hpp) caused compilation errors when functions expected exact struct member access or free function signatures rather than class wrappers.
Resolution: Refactored all local *_main.cpp, *_test.cpp, and *_example.cpp files across every module branch to strictly adhere to the pre-defined header function signatures without modifying core locked contracts.
b)	Git Merge Conflicts and Repository Cleanup
Challenge: Syncing personal feature branches across different local developer environments frequently staged untracked binary executables, editor artifact files  and out-of-scope files from other members during branch merges.
Resolution: Performed branch resets, cleaned working trees of compiled binaries, and explicitly staged only the four required deliverables per member (_main.cpp, _test.cpp, _example.cpp, and _week3.md) before committing and pushing clean branches to GitHub.
c)	Isolated Component Testing with Assertions
Challenge: Verifying that modules functioned reliably in isolation prior to system-wide pipeline assembly, without triggering linker errors for unmerged external code.
Resolution: Designed standalone test suites (_test.cpp) utilizing the C++ <cassert> library and lightweight mock data structures (mock feature vectors and Neighbor arrays) to validate mathematical correctness, boundary limits, and zero-range edge cases independently.
4. Conclusion
Our group has successfully achieved all target milestones for this development phase. Every module—spanning Dataset Loading, Data Preprocessing, Feature Scaling, Distance Calculation, KNN Search, and Neighbor Selection—has been fully implemented and verified with its dedicated driver set (_main.cpp, _test.cpp, _example.cpp) and documented in individual member progress reports (_week3.md). All member branches have been cleaned, tested, and pushed to the team's remote GitHub repository.

5. Next week’s plans
	Having completed the first six parts of our project, we shall start the the next parts of our project next week that is majority voting, tie handling, class prediction, hyper parameter selection, model evaluation, confusion matrix and precision starting with the header files and the modulation of each part by the different group embers as assigned


