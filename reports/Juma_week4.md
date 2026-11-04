/*Precision, Recall & F1 implementation
1.	Overview
Precision, Recall & F1 implements a specialized evaluation module inheriting from the polymorphic EvaluationMetric base class to compute precision, recall, and harmonic mean F1-score performance metrics relative to a specific target class.
2.	Architectural & Algorithmic Flow
Data Ingestion & Pointer Allocation: Accepts actual and predicted label arrays via raw pointers (int*) or STL vectors (std::vector<int>), alongside a target class identifier, dynamically allocating heap memory for safe internal tracking.
Contingency Tallying: Utilizes a helper routine to traverse label arrays, calculating fundamental True Positive (TP), False Positive (FP), and False Negative (FN) counts for the specified target class.
Metric Computation: Evaluates precision as $\frac{TP}{TP + FP}$ and recall as $\frac{TP}{TP + FN}$ (with built-in zero-division checks), subsequently combining them into the F1-score.
Memory Lifecycle Management (Rule of Three): Implements a custom destructor (~PrecisionRecallF1()), deep copy constructor, and overloaded assignment operator (operator=) to guarantee safe pointer management and prevent heap corruption or double-free errors.
3.	Error Handling & Edge Cases
 Validates incoming data parameters upon construction, throwing standard std::invalid_argument exceptions if null pointers are supplied, if dataset sizes are $\le 0$, if vectors are empty, or if actual and predicted vector sizes mismatch.
4.	Next Week Integration Plans
 Next week, I will implement a dedicated test harness with synthetic binary and multi-class evaluation data to rigorously verify metric calculations and report output, create clear code examples demonstrating how to instantiate PrecisionRecallF1 using model outputs from the KNN classification pipeline, and integrate final evaluation routines into main.cpp.
5.	AI Declaration 
AI tools were used to help understand what this specific part of the project works and how to link it to the other parts of the project which guided me during the implementation and design.
*/
