#ifndef PRECISIONRECALLF1_HPP
#define PRECISIONRECALLF1_HPP

#include "modelevaluation.hpp" 
#include <vector>

class PrecisionRecallF1 : public EvaluationMetric {
private:
    int* actual_labels;     // Pointer array for true dataset labels
    int* predicted_labels;  // Pointer array for model predicted labels
    int data_size;          // Total size of the evaluated dataset
    int target_class;       // The specific class being evaluated (positive class)

public:
    // Constructor taking raw arrays via pointers, target class, and size
    PrecisionRecallF1(const int* actual, const int* predicted, int size, int target_class);
    
    // Overloaded constructor for STL vectors
    PrecisionRecallF1(const std::vector<int>& actual, const std::vector<int>& predicted, int target_class);
    PrecisionRecallF1(const PrecisionRecallF1& other);
    PrecisionRecallF1& operator=(const PrecisionRecallF1& other);

    // Destructor to clean up pointer memory safely
    ~PrecisionRecallF1();

    // Polymorphic override to calculate F1-Score (or primary metric)
    double calculate(const std::vector<int>& actual, const std::vector<int>& predicted) override;

      void displayReport(const std::vector<int>& actual, const std::vector<int>& predicted) override;

    // Specific metric accessors
    double calculatePrecision() const;
    double calculateRecall() const;
    double calculateF1Score() const;
};

#endif 
