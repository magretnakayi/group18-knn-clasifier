#ifndef CONFUSIONMATRIX_HPP
#define CONFUSIONMATRIX_HPP
#include <vector>
class ConfusionMatrix {
private:
    int* actual_labels;     // Pointer array for true dataset labels
    int* predicted_labels;  // Pointer array for model predicted labels
    int data_size;          // Total size of the evaluated dataset
public:
    // Constructor taking raw arrays via pointers
    ConfusionMatrix(const int* actual, const int* predicted, int size);
    // Overloaded constructor for STL vectors
    ConfusionMatrix(const std::vector<int>& actual, const std::vector<int>& predicted);
    // Rule of Three: Deep copy constructor and assignment operator
    ConfusionMatrix(const ConfusionMatrix& other);
    ConfusionMatrix& operator=(const ConfusionMatrix& other);
    // Destructor to clean up pointer memory safely
    ~ConfusionMatrix();
    // Calculates and displays the confusion matrix stats (True Positives, False Positives, etc.)
    void computeAndDisplay(int positive_class) const;
};
#endif // CONFUSION_MATRIX_HPP
