
Majority Voting & Tie-Handling design and implementation progress report
1.	OVERVIEW
Majority Voting: Processes the class labels of the $k$-nearest neighbors, translating geometric neighborhood data into a preliminary class prediction through frequency tallying.
Tie Handling: Resolves multi-class voting deadlocks by evaluating spatial proximity among tied candidate classes, awarding the final prediction to the closest neighbor derived from dataset.csv.

2.DESIGN AND IMPLEMENTATION
Majority Voting:
Dataset Ingestion & Pointer Allocation: Accepts sliced DataPoint structures derived directly from dataset.csv, dynamically allocating heap memory for label and distance arrays via raw pointers (int*, double*) based on runtime size $k$.
Frequency Tallying: Iterates through neighbor labels using pointer traversal, accumulating vote counts into standard associative structures (std::map<int, int>).
Plurality Evaluation & Deadlock Detection: Identifies the class holding the maximum vote count and checks for multi-class voting ties.
Tie Handling :
Candidate Filtering: Captures tied classes sharing identical maximum vote counts from the frequency evaluation phase.
Spatial Proximity Resolution: Iterates through the stored neighbor distance arrays to evaluate underlying Euclidean distances among tied candidates, awarding the final classification to the geometrically closest neighbor.
Shared Memory Lifecycle Management. Implements custom destructors (~MajorityVoting(), ~TieHandler()), deep copy constructors, and overloaded assignment operators (operator=) across both classes to guarantee safe pointer management and prevent heap corruption or double-free errors.
3.	ERROR HANDLING & EDGE CASES
Majority Voting: 
Validates initialization arguments upon construction, throwing standard std::invalid_argument exceptions if null pointers are supplied, if $k \le 0$, or if the incoming neighbor dataset slice is empty.
Tie Handling: 
Validates runtime parameters during construction and method execution, throwing standard std::invalid_argument exceptions if pointer arrays are null, if $k \le 0$, or if the input list of tied classes passed to breakTie() contains no elements.
4.	Next Week Integration Plans
 Next week, I will implement a dedicated test harness with synthetic neighbor sets and edge-case voting splits/ties to rigorously verify correct frequency tallying and spatial tie-breaking logic, create clear code examples demonstrating how to instantiate MajorityVoting and TieHandler using DataPoint structures extracted from dataset.csv, and develop the primary driver program (main.cpp) for each part
5.	AI Declaration 
AI tools were used to help understand what this specific part of the project works and how to link it to the other parts of the project which guided me during the implementation and design.
