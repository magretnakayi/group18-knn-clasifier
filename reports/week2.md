     Week 2 Report
 Dataset Loading Implementation
Overview
For this week, I developed the core dataset ingestion module for our team's K-Nearest Neighbors (KNN) C++ project. The primary goal was to create a robust parser that reads our group's shared `dataset.csv` file, processes each row, and structures the data so that other team members can easily use it for preprocessing, distance calculations, and classification.
Implementation Details
	Data Structure (`DataPoint`): Defined a clean struct containing a `std::vector<double>` for storing feature attributes and an `int` for the class label.
	-CSV Ingestion Logic (`loadCSV`):  - Opens `dataset.csv` directly from the main project root directory using `std::ifstream`.
                                                                 - Automatically skips the header row using `std::getline`.
                                                                - Parses comma-separated values line-by-line using `std::stringstream`.
	Error Handling & Safety: Added try-catch blocks utilizing `std::stod` to gracefully catch malformed numbers, unexpected column counts, or missing files, throwing descriptive runtime errors instead of crashing.
Next week’s plans
             With the core dataset loading backend fully written and verified, next week's focus will involve wiring up the execution harness (`main.cpp`), adding unit tests, and creating usage examples for the rest of the team. 
                                                                                                                                                                                                                                                                                                         