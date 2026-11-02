
# Confusion Matrix implementation and design

## 1. Overview

Confusion Matrix evaluates classification performance by comparing true dataset labels against model predictions, calculating fundamental evaluation metrics (True Positives, True Negatives, False Positives, and False Negatives) for a specified target class.

## 2. Architectural & Algorithmic Flow

- **Data Ingestion & Pointer Allocation:** Accepts actual and predicted labels via raw pointer arrays (int*) or STL vectors (std::vector<int>), validating matching dataset sizes and dynamically allocating heap memory for safe internal storage.
- **Matrix Computation:** Traverses the evaluated label arrays using pointer indexing, tallying counts for True Positives (TP), True Negatives (TN), False Positives (FP), and False Negatives (FN) relative to the target positive class.
- **Report Generation:** Formats and prints a structured performance summary highlighting individual classification outcome counts.
- **Memory Lifecycle Management (Rule of Three):** Implements a custom destructor (~Confusion Matrix()), deep copy constructor, and overloaded assignment operator (operator=) to guarantee safe pointer management and prevent heap corruption or double-free errors.

## 3. Edge Cases handling

Validates incoming data parameters upon construction, throwing standard std::invalid argument exceptions if null pointers are supplied, if dataset sizes are ≤ 0, if vectors are empty, or if actual and predicted vector sizes mismatch.

## 4. Next Week Integration Plans

Next week, I will implement a dedicated test harness with synthetic binary and multi-class label vectors to rigorously verify correct contingency tallying, create clear code examples demonstrating how to instantiate Confusion Matrix using classification outputs from the KNN pipeline, and integrate final performance reporting routines into main.cpp.

## 5. AI Declaration

AI tools were used to help understand what this specific part of the project works and how to link it to the other parts of the project which guided me during the implementation and design. Cs
