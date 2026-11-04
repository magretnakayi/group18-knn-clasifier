Class Prediction modulation and design
1.	Overview
Class Prediction processes the class labels and spatial distances of the $k$-nearest neighbors, translating geometric neighborhood data into a definitive class prediction through frequency tallying and resolving multi-class voting deadlocks via minimum-distance spatial proximity.
2.	Implementation and flow
Dataset Ingestion & Pointer Allocation: Accepts parallel std::vector<int> (labels) and std::vector<double> (distances) or raw pointer arrays (int*, double*), dynamically allocating heap memory for label and distance arrays based on runtime size $k$.
Frequency Tallying: Iterates through neighbor labels using pointer traversal, accumulating vote counts into standard associative structures (std::map<int, int>).
Plurality Evaluation & Deadlock Detection: Identifies the class holding the maximum vote count and checks for multi-class voting ties.
Proximity-Based Tie Resolution: Evaluates underlying Euclidean distances among tied candidate classes, iterating through stored neighbor arrays to award the final classification to the geometrically closest neighbor.
Memory Lifecycle Management (Rule of Three): Implements a custom destructor (~ClassPredictor()), deep copy constructor, and overloaded assignment operator (operator=) to guarantee safe pointer management and prevent heap corruption or double-free errors.
3.	Error Handling & Edge Cases 
Validates incoming data parameters upon construction, throwing standard std::invalid_argument exceptions if null pointers are supplied, if $k \le 0$, if the vectors are empty, or if the label and distance vectors do not match in size.
4.	Next Week Integration Plans
 Next week, I will implement a dedicated test harness with synthetic neighbor sets, create clear code examples demonstrating how to instantiate ClassPredictor using structures extracted from dataset.csv, and develop the primary driver program (main.cpp).

5.	AI Declaration
 AI tools were used to help understand what this specific part of the project works and how to link it to the other parts of the project which guided me during the implementation and design. It helped me to correct some small errors in my programs



