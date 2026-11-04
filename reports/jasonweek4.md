Hyperparameter Selection implementation and modulation
1.	Overview
Hyperparameter Selection manages and evaluates a collection of candidate kkk values against validation datasets derived from dataset.csv, systematically computing model accuracy via the ClassPredictor module to determine and return the optimal hyperparameter kkk.
2.	Architectural & Algorithmic Flow
Candidate Ingestion & Pointer Allocation: Accepts candidate kkk values via raw pointer arrays (int*) or STL vectors (std::vector<int>), validating that all values are strictly positive and dynamically allocating heap memory based on runtime size.
Validation Performance Loop: Iterates through each candidate kkk, evaluating prediction accuracy across validation data points by computing Euclidean distances against training samples.
Neighborhood Extraction & Prediction Integration: Sorts calculated distances, extracts the top-kkk nearest neighbor labels and distances, and delegates classification to the ClassPredictor module.
Accuracy Evaluation & Optimal Selection: Computes validation accuracy for each candidate kkk, tracking and updating the optimal hyperparameter value whenever a strictly higher accuracy is achieved.
Memory Lifecycle Management (Rule of Three): Implements a custom destructor (~HyperparameterSelector()), deep copy constructor, and overloaded assignment operator (operator=) to guarantee safe pointer management and prevent heap corruption or double-free errors.
3.	Error Handling
Validates incoming data parameters upon construction and method execution, throwing standard std::invalid_argument exceptions if null pointers are supplied, if candidate counts are ≤0\le 0≤0, if any candidate kkk value is less than or equal to zero, or if the training and validation datasets are empty.

4.	Next Week Integration Plans 
Next week, I will implement a dedicated test harness with synthetic training and validation sets to rigorously verify correct accuracy evaluation and optimal kkk selection, create clear code examples demonstrating how to instantiate HyperparameterSelector using data extracted from dataset.csv, and integrate the selector into the primary driver program (main.cpp).
5.	AI Declaration 
 AI tools were used to help understand what this specific part of the project works and how to link it to the other parts of the project which guided me during the implementation and design and were referenced in order to correct errors

