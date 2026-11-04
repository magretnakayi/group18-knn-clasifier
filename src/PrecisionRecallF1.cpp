#include "PrecisionRecallF1.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

// Constructor using raw pointers and arrays
PrecisionRecallF1::PrecisionRecallF1(const int* actual, const int* predicted, int size, int target_class) 
    : data_size(size), target_class(target_class) {
    if (data_size <= 0 || actual == nullptr || predicted == nullptr) {
        throw invalid_argument("Invalid data size or null pointers supplied to PrecisionRecallF1.");
    }

    actual_labels = new int[data_size];
    predicted_labels = new int[data_size];

    for (int i = 0; i < data_size; ++i) {
        actual_labels[i] = actual[i];
        predicted_labels[i] = predicted[i];
    }
}

// Overloaded constructor for STL vectors
PrecisionRecallF1::PrecisionRecallF1(const vector<int>& actual, const vector<int>& predicted, int target_class) 
    : target_class(target_class) {
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
PrecisionRecallF1::PrecisionRecallF1(const PrecisionRecallF1& other) 
    : data_size(other.data_size), target_class(other.target_class) {
    actual_labels = new int[data_size];
    predicted_labels = new int[data_size];

    for (int i = 0; i < data_size; ++i) {
        actual_labels[i] = other.actual_labels[i];
        predicted_labels[i] = other.predicted_labels[i];
    }
}

// Assignment Operator (Deep Copy)
PrecisionRecallF1& PrecisionRecallF1::operator=(const PrecisionRecallF1& other) {
    if (this != &other) {
        delete[] actual_labels;
        delete[] predicted_labels;

        data_size = other.data_size;
        target_class = other.target_class;
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
PrecisionRecallF1::~PrecisionRecallF1() {
    delete[] actual_labels;
    delete[] predicted_labels;
}

// Helper method to compute True Positives, False Positives, and False Negatives
void computeCounts(const int* actual, const int* predicted, int size, int target_class, int& tp, int& fp, int& fn) {
    tp = 0;
    fp = 0;
    fn = 0;

    for (int i = 0; i < size; ++i) {
        if (actual[i] == target_class && predicted[i] == target_class) {
            tp++;
        } else if (actual[i] != target_class && predicted[i] == target_class) {
            fp++;
        } else if (actual[i] == target_class && predicted[i] != target_class) {
            fn++;
        }
    }
}

// Calculates Precision: TP / (TP + FP)
double PrecisionRecallF1::calculatePrecision() const {
    int tp = 0, fp = 0, fn = 0;
    computeCounts(actual_labels, predicted_labels, data_size, target_class, tp, fp, fn);

    if (tp + fp == 0) return 0.0; // Prevent division by zero
    return static_cast<double>(tp) / (tp + fp);
}

// Calculates Recall: TP / (TP + FN)
double PrecisionRecallF1::calculateRecall() const {
    int tp = 0, fp = 0, fn = 0;
    computeCounts(actual_labels, predicted_labels, data_size, target_class, tp, fp, fn);

    if (tp + fn == 0) return 0.0; // Prevent division by zero
    return static_cast<double>(tp) / (tp + fn);
}

// Calculates F1-Score: 2 * (Precision * Recall) / (Precision + Recall)
double PrecisionRecallF1::calculateF1Score() const {
    double precision = calculatePrecision();
    double recall = calculateRecall();

    if (precision + recall == 0.0) return 0.0; // Prevent division by zero
    return 2.0 * (precision * recall) / (precision + recall);
}

// Polymorphic calculate override returns the F1-Score as the primary composite metric
double PrecisionRecallF1::calculate(const vector<int>& actual, const vector<int>& predicted) {
    return calculateF1Score();
}

// Polymorphic report display method
void PrecisionRecallF1::displayReport(const vector<int>& actual, const vector<int>& predicted) {
    double precision = calculatePrecision();
    double recall = calculateRecall();
    double f1 = calculateF1Score();

    cout << fixed << setprecision(4);
    cout << "=== Precision, Recall & F1 Report (Target Class: " << target_class << ") ===" << endl;
    cout << "Precision: " << precision << endl;
    cout << "Recall:    " << recall << endl;
    cout << "F1-Score:  " << f1 << endl;
}
