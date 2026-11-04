#include <iostream>
#include <iomanip>
#include "PrecisionRecallF1.hpp"

using namespace std;

int main() {
    cout << " KNN Performance Metrics Driver" << endl;

    int num_samples = 6;
    int num_classes = 2; // Binary classes: 0 and 1

    // Allocate true and predicted label arrays on the heap
    int* true_labels = new int[num_samples]{1, 0, 1, 1, 0, 0};
    int* pred_labels = new int[num_samples]{1, 0, 1, 0, 0, 1};

    try {
        PrecisionRecallF1 metrics(true_labels, pred_labels, num_samples, num_classes);
        
        cout << fixed << setprecision(2);
        cout << "Performance Report for Target Class 1:" << endl;
        cout << "-> Precision: " << (metrics.calculatePrecision() * 100.0) << "%" << endl;
        cout << "-> Recall:    " << (metrics.calculateRecall() * 100.0) << "%" << endl;
        cout << "-> F1-Score:  " << (metrics.calculateF1Score() * 100.0) << "%" << endl;
    } catch (const exception& e) {
        cout << "-> Status: Failed with exception: " << e.what() << endl;
        delete[] true_labels;
        delete[] pred_labels;
        return 1;
    }

    // Clean up heap allocations
    delete[] true_labels;
    delete[] pred_labels;
    return 0;
}
