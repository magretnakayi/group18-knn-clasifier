Group 18 Project Progress Week 2 Report
Modular C++ KNN Classifier
1. Project Overview
This report summarizes the architectural development and implementation progress of the modular C++ K-Nearest Neighbors (KNN) classification system. The project strictly adheres to modular programming principles, separating code into include/ header files, src/ implementation files, and individual component documentation for the first 6 parts of our project
2. Implementation tools
Tool 	Category	Purpose & Application
C++ (C++11 / C++17 Standard)	Programming Language	Core execution environment providing object-oriented structure, high performance, and standard memory management.
GCC / MinGW Toolchain	Compiler & Build Tools	Used for compiling local source files, linking modules, and generating native performance executables (gcc/g++).
Visual Studio Code (VS Code)	Integrated Development Environment	Primary workspace for multi-file C++ development, inline debugging, terminal operations, and source control management.
Git & GitHub	Version Control & Collaboration	Branch-based collaboration workflow, source tracking, pull requests, and commit attribution management across team branches.




3. Component Implementation Summary
Module / Component	Member Assigned	Purpose	Implementation Details
 Dataset Loading


(dataset.hpp / dataset.cpp)	Nakayi Magret	Handles raw data ingestion by reading CSV files from disk.	Opens data files using std::ifstream, safely skips header rows, tokenizes comma-separated lines via std::stringstream, converts string representations to numerical values, and structures records into DataPoint objects containing feature vectors and class labels.
 Data Preprocessing
(preprocessing.hpp / preprocessing.cpp)	Nyamwiija Doreen	Performs structural validation and data hygiene.	Inspects the loaded dataset to verify feature vector dimensions against a baseline standard, filtering out corrupted or empty rows to prevent runtime errors during downstream calculations.
 Feature Scaling

(featurescaling.hpp / featurescaling.cpp)	Ssewagudde Jason Samuel	Normalizes numerical attributes to prevent range-based bias.	Applies Min-Max normalization to scale feature dimensions uniformly between 0.0 and 1.0, incorporating safeguards to handle zero-range columns and avoid division-by-zero errors.
 Distance Calculation

(distance.hpp / distance.cpp)	Nkangula Abdul Latif	Computes geometric proximity between multi-dimensional vectors.	Calculates straight-line separation using the standard Euclidean distance formula combined with an efficient accumulator loop and square root evaluation (std::sqrt).
 KNN Search

(knnsearch.hpp / knnsearch.cpp)	Kasule Juma Kasujja	Scans the training set and constructs a sorted proximity hierarchy.	Computes distances from a given query point to every sample in the training set, pairs them with their respective class labels, and sorts the collection in ascending order to position closest neighbors first.
F. Neighbor Selection
(knnselection.hpp / knnselection.cpp)	Namukisa Favour E. Kiwuso	Isolates the top-k nearest instances from the sorted neighbor collection.	Extracts the specified number of nearest neighbors (k) from the ordered list to pass forward for final classification analysis.
4. Challenges faced and how we solved them
a)	Challenge: Difficulty in accessing the existing files 
Solution: This was resolved by members fetching these files from the origin (branch) which enabled them to access the required files
b)	Challenge: Integrating newly developed mathematical and distance modules with the locked, pre-submitted dataset.hpp interface presented member-access mismatches (e.g., direct struct member access vs. expected getter functions).
Solution: standardized module logic across the codebase to interact directly with defined public struct members (p1.features), preserving the integrity of fixed core interfaces without requiring architectural refactoring
c)	Challenge: Code exchange and multi-editor synchronization occasionally introduced non-standard UTF-8 hidden characters (such as non-breaking spaces) into header guards, triggering preprocessor parsing errors on #ifndef directives.
Solution: Standardized source code text formatting across developer environments by stripping non-printable characters and ensuring standard ANSI/UTF-8 encoding across all .hpp and .cpp files.
d)	Challenge: Incremental, modular C++ development across separate header and source files led to unresolved identifiers for standard stream I/O (std::cout) and standard exception handling (std::invalid_argument).
Solution: Enforced explicit, scoped header inclusion (<iostream>, <stdexcept>) across all implementation files to ensure robust stand-alone compilation and exception handling.

4. Next Week Plans
In the upcoming development cycle, our focus will shift from core modular architecture to system integration, validation, and demonstration. Specifically, we will implement:
	main.cpp Integration: Connecting all discrete modules (dataset, preprocessing, feature scaling, distance, knn search, neighbour selection into an executable pipeline.
	Unit Testing & Validation: Creating test harnesses to evaluate individual component performance and overall classification accuracy across diverse dataset configurations.
	Example Workflows: Providing clear usage examples and sample execution logs within project documentation to verify system reliability
Declaration of Assistance
AI tools were referenced solely for minor syntax checks, and markdown formatting assistance. All core architecture, modular design, and source code implementation were fully authored and verified by Group 18.


