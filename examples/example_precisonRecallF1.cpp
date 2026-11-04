#include <iostream>
#include "PrecisionRecallF1.hpp"

using namespace std;

int main() {
    cout << "Performance Metrics Example " << endl;

    int num_samples = 5;
    int num_classes = 2;

    int* true_labels = new int[num_samples]{1, 1, 0, 1, 0};
    int* pred_labels = new int[num_samples]{1, 0, 0, 1, 1};

    PrecisionRecallF1 metrics(true_labels, pred_labels, num_samples, num_classes);
    
    int target = 1;
    cout << "Metrics for Class " << target << ":" << endl;
    cout << "Precision: " << metrics.calculatePrecision() << endl;
    cout << "Recall:    " << metrics.calculateRecall() << endl;
    cout << "F1-Score:  " << metrics.calculateF1Score() << endl;

    delete[] true_labels;
    delete[] pred_labels;

    return 0;
}
