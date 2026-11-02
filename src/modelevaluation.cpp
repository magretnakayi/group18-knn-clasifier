#include "ModelEvaluation.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor using raw pointers and arrays
ModelEvaluator::ModelEvaluator(const int* actual, const int* predicted, int size) : data_size(size) {
    if (data_size <= 0 || actual == nullptr || predicted == nullptr) {
        throw invalid_argument("Invalid data size or null pointers supplied to ModelEvaluator.");
    }

    actual_labels = new int[data_size];
    predicted_labels = new int[data_size];

    for (int i = 0; i < data_size; ++i) {
        actual_labels[i] = actual[i];
        predicted_labels[i] = predicted[i];
    }
}

// Overloaded constructor for STL vectors
ModelEvaluator::ModelEvaluator(const vector<int>& actual, const vector<int>& predicted) {
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
ModelEvaluator::ModelEvaluator(const ModelEvaluator& other) : data_size(other.data_size) {
    actual_labels = new int[data_size];
    predicted_labels = new int[data_size];

    for (int i = 0; i < data_size; ++i) {
        actual_labels[i] = other.actual_labels[i];
        predicted_labels[i] = other.predicted_labels[i];
    }
}

// Assignment Operator (Deep Copy)
ModelEvaluator& ModelEvaluator::operator=(const ModelEvaluator& other) {
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
ModelEvaluator::~ModelEvaluator() {
    delete[] actual_labels;
    delete[] predicted_labels;
}

// Polymorphic calculate method computing model accuracy via vector input
double ModelEvaluator::calculate(const vector<int>& actual, const vector<int>& predicted) {
    if (actual.empty() || actual.size() != predicted.size()) {
        throw invalid_argument("Vectors must not be empty and must match in size.");
    }

    int correct = 0;
    for (size_t i = 0; i < actual.size(); ++i) {
        if (actual[i] == predicted[i]) {
            correct++;
        }
    }
    return static_cast<double>(correct) / actual.size();
}

// Polymorphic report display method via vector input
void ModelEvaluator::displayReport(const vector<int>& actual, const vector<int>& predicted) {
    double accuracy = calculate(actual, predicted);
    cout << "=== KNN Model Evaluation Report ===" << endl;
    cout << "Total Evaluated Points: " << actual.size() << endl;
    cout << "Model Accuracy:         " << (accuracy * 100.0) << "%" << endl;
}

// Convenience method using internal heap arrays
double ModelEvaluator::calculate() const {
    int correct = 0;
    for (int i = 0; i < data_size; ++i) {
        if (actual_labels[i] == predicted_labels[i]) {
            correct++;
        }
    }
    return static_cast<double>(correct) / data_size;
}

// Convenience method report display using internal heap arrays
void ModelEvaluator::displayReport() const {
    double accuracy = calculate();
    cout << "=== KNN Model Evaluation Report ===" << endl;
    cout << "Total Evaluated Points: " << data_size << endl;
    cout << "Model Accuracy:         " << (accuracy * 100.0) << "%" << endl;
}
