#ifndef HYPERPARAMETER_SELECTOR_HPP
#define HYPERPARAMETER_SELECTOR_HPP

#include <vector>
#include "dataset.hpp"

class HyperparameterSelector {
private:
    int* k_candidates;     // Pointer-based array of candidate k values to test
    int num_candidates;    // Total number of candidate values

public:
    // Constructor taking a raw pointer array of k candidates
    HyperparameterSelector(const int* candidates, int count);
    
    // Overloaded constructor for STL vectors
    explicit HyperparameterSelector(const std::vector<int>& candidates);
    HyperparameterSelector(const HyperparameterSelector& other);
    HyperparameterSelector& operator=(const HyperparameterSelector& other);

    // Destructor to clean up pointer memory safely
    ~HyperparameterSelector();

    // Finds and returns the optimal k based on validation accuracy
    int optimizeK(const std::vector<DataPoint>& train_data, const std::vector<DataPoint>& val_data) const;
};

#endif 

