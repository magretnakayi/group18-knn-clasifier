Model Evaluation implementation report
1.	Overview
Model Evaluation implements an object-oriented evaluation framework leveraging an abstract base class (EvaluationMetric) for polymorphism to compute model accuracy and generate comprehensive performance summary reports comparing actual dataset labels against model predictions.
2.	Architectural & Algorithmic Flow
Data Ingestion & Pointer Allocation: Accepts actual and predicted labels via raw pointer arrays (int*) or STL vectors (std::vector<int>), validating matching sizes and dynamically allocating heap memory for internal storage.
Accuracy Computation: Traverses label arrays to tally correct classifications, dividing by total evaluated points to compute overall decimal accuracy.
Report Generation: Formats and outputs structured performance metrics, including total evaluated points and percentage-based model accuracy.
Memory Lifecycle Management (Rule of Three): Implements a custom destructor (~ModelEvaluator()), deep copy constructor, and overloaded assignment operator (operator=) to guarantee safe pointer management and prevent heap corruption or double-free errors.
3.	Error Handling
 Validates incoming data parameters upon construction and method execution, throwing standard std::invalid_argument exceptions if null pointers are supplied, if data sizes are $\le 0$, if vectors are empty, or if actual and predicted vector sizes mismatch.
4.	Next Week Integration Plans
 Next week, I will implement a dedicated test harness with synthetic evaluation vectors to rigorously verify metric calculations and report formatting, create clear code examples demonstrating how to instantiate ModelEvaluator using outputs from the KNN classification pipeline, and integrate final evaluation routines into main.cpp.
5.	AI Declaration 
AI tools were referenced to help understand what this specific part of the project works and how to link it to the other parts of the project which guided me during the implementation and design.

