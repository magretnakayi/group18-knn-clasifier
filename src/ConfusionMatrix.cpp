#include "ConfusionMatrix.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
// Constructor using raw pointers and arrays
ConfusionMatrix::ConfusionMatrix(const int* actual, const int* predicted, int size) : data_size(size) {
    if (data_size <= 0 || actual == nullptr || predicted == nullptr) {
        throw invalid_argument("Invalid data size or null pointers supplied to ConfusionMatrix.");
    }
    actual_labels = new int[data_size];
    predicted_labels = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        actual_labels[i] = actual[i];
        predicted_labels[i] = predicted[i];
    }
}
// Overloaded constructor for STL vectors
ConfusionMatrix::ConfusionMatrix(const vector<int>& actual, const vector<int>& predicted) {
    if (actual.size() != predicted.size() || actual.empty()) {
        throw invalid_argument("Actual and predicted vectors must be equal in size and non-empty.");
    }
    data_size = static_cast<int>(actual.size());
    actual_labels = new int[data_size];
    predicted_labels = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        actual_labels[i] = actual[i];
        predicted_labels[i] = predicted[i];
    }
}
// Copy Constructor (Deep Copy)
ConfusionMatrix::ConfusionMatrix(const ConfusionMatrix& other) : data_size(other.data_size) {
    actual_labels = new int[data_size];
    predicted_labels = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        actual_labels[i] = other.actual_labels[i];
        predicted_labels[i] = other.predicted_labels[i];
    }
}
// Assignment Operator (Deep Copy)
ConfusionMatrix& ConfusionMatrix::operator=(const ConfusionMatrix& other) {
    if (this != &other) {
        delete[] actual_labels;
        delete[] predicted_labels;
        data_size = other.data_size;
        actual_labels = new int[data_size];
        predicted_labels = new int[data_size];
        for (int i = 0; i < data_size; ++i) {
            actual_labels[i] = other.actual_labels[i];
            predicted_labels[i] = other.predicted_labels[i];
        }
    }
    return *this;
}
// Destructor cleaning up pointer memory
ConfusionMatrix::~ConfusionMatrix() {
    delete[] actual_labels;
    delete[] predicted_labels;
}
// Computes matrix counts and prints out performance results using pointer traversal
void ConfusionMatrix::computeAndDisplay(int positive_class) const {
    int tp = 0; // True Positive
    int tn = 0; // True Negative
    int fp = 0; // False Positive
    int fn = 0; // False Negative
    for (int i = 0; i < data_size; ++i) {
        if (actual_labels[i] == positive_class && predicted_labels[i] == positive_class) {
            tp++;
        } else if (actual_labels[i] != positive_class && predicted_labels[i] != positive_class) {
            tn++;
        } else if (actual_labels[i] != positive_class && predicted_labels[i] == positive_class) {
            fp++;
        } else if (actual_labels[i] == positive_class && predicted_labels[i] != positive_class) {
            fn++;
        }
    }
    cout << "=== Confusion Matrix Report (Target Class: " << positive_class << ") ===" << endl;
    cout << "True Positives (TP):  " << tp << endl;
    cout << "True Negatives (TN):  " << tn << endl;
    cout << "False Positives (FP): " << fp << endl;
    cout << "False Negatives (FN): " << fn << endl;
}
