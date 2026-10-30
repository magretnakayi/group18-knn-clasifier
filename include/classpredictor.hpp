#ifndef CLASSPREDICTOR_HPP
#define CLASSPREDICTOR_HPP

#include <vector>

class ClassPredictor {
private:
    int* neighbor_labels;        // Pointer array for neighbor class labels
    double* neighbor_distances;  // Pointer array for neighbor Euclidean distances
    int k_size;                  // Number of neighbors (k)

public:
    // Constructor taking raw arrays via pointers and k size
    ClassPredictor(const int* labels, const double* distances, int k);
    
    // Overloaded constructor for STL vectors
    ClassPredictor(const std::vector<int>& labels, const std::vector<double>& distances);
    ClassPredictor(const ClassPredictor& other);
    ClassPredictor& operator=(const ClassPredictor& other);

    // Destructor to free heap-allocated pointer memory safely
    ~ClassPredictor();

    // Core method to execute class prediction with built-in tie handling
    int predict() const;
};

#endif // CLASS_PREDICTOR_HPP


