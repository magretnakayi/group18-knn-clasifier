#ifndef CONFUSIONMATRIX_HPP
#define CONFUSIONMATRIX_HPP

#include <vector>

class ConfusionMatrix {
private:
    int* actual_labels;     // Pointer array for true dataset labels
    int* predicted_labels;  // Pointer array for model predicted labels
    int data_size;          // Total size of the evaluated dataset
    int num_classes;        // Number of classes (labels must be 0 .. num_classes-1)
    int** matrix;           // Heap grid: matrix[actual][predicted]

    // Validates the inputs, copies the labels and builds the matrix grid
    void init(const int* actual, const int* predicted, int size, int classes);
    // Frees every heap allocation owned by this object
    void release();

public:
    // Multi-class constructor taking raw arrays via pointers
    ConfusionMatrix(const int* actual, const int* predicted, int size, int classes);

    // Earlier constructors (class count is worked out from the largest label)
    ConfusionMatrix(const int* actual, const int* predicted, int size);
    ConfusionMatrix(const std::vector<int>& actual, const std::vector<int>& predicted);

    // Rule of Three: Deep copy constructor and assignment operator
    ConfusionMatrix(const ConfusionMatrix& other);
    ConfusionMatrix& operator=(const ConfusionMatrix& other);

    // Destructor to clean up pointer memory safely
    ~ConfusionMatrix();

    // Prints the grid (rows = actual, columns = predicted)
    void printMatrix() const;

    // Correct predictions (diagonal) divided by all predictions, between 0 and 1
    double getAccuracy() const;

    // Calculates and displays TP, TN, FP, FN for one target class
    void computeAndDisplay(int positive_class) const;
};

#endif // CONFUSIONMATRIX_HPP
