#ifndef MODELEVALUATION_HPP
#define MODELEVALUATION_HPP

#include <vector>

// Abstract Base Class demonstrating Polymorphism for Evaluation Metrics
class EvaluationMetric {
public:
    virtual ~EvaluationMetric() {}
    virtual double calculate(const std::vector<int>& actual, const std::vector<int>& predicted) = 0;
    virtual void displayReport(const std::vector<int>& actual, const std::vector<int>& predicted) = 0;
};

// Concrete Derived Class for Model Accuracy Evaluation
class ModelEvaluator : public EvaluationMetric {
private:
    int* actual_labels;      // Pointer array for actual dataset labels
    int* predicted_labels;   // Pointer array for model predicted labels
    int data_size;           // Total number of evaluated points

public:
    // Constructor taking raw arrays via pointers
    ModelEvaluator(const int* actual, const int* predicted, int size);
    
    // Overloaded constructor for STL vectors
    ModelEvaluator(const std::vector<int>& actual, const std::vector<int>& predicted);

    // Rule of Three: Deep copy constructor and assignment operator
    ModelEvaluator(const ModelEvaluator& other);
    ModelEvaluator& operator=(const ModelEvaluator& other);

    // Destructor to clean up pointer memory safely
    ~ModelEvaluator();

    // Polymorphic overrides using vectors
    double calculate(const std::vector<int>& actual, const std::vector<int>& predicted) override;
    void displayReport(const std::vector<int>& actual, const std::vector<int>& predicted) override;

    // Overloads using internal heap-allocated arrays for convenience
    double calculate() const;
    void displayReport() const;
};

#endif // MODEL_EVALUATION_HPP
