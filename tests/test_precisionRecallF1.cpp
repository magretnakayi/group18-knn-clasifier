#include <iostream>
#include <cassert>
#include "PrecisionRecallF1.hpp"

using namespace std;

int main() {
    cout << "Running Performance Metrics Tests..." << endl;

    int num_samples = 4;
    int num_classes = 2;

    // True: [1, 1, 0, 0], Pred: [1, 0, 0, 0]
    // TP = 1, FP = 0, FN = 1, TN = 2
    // Precision = 1 / (1 + 0) = 1.0
    // Recall = 1 / (1 + 1) = 0.5
    // F1 = 2 * (1.0 * 0.5) / (1.0 + 0.5) = 2/3 ≈ 0.6667
    int* true_labels = new int[num_samples]{1, 1, 0, 0};
    int* pred_labels = new int[num_samples]{1, 0, 0, 0};

    PrecisionRecallF1 metrics(true_labels, pred_labels, num_samples, num_classes);
    
    double precision = metrics.calculatePrecision();
    double recall = metrics.calculateRecall();
    
    assert(precision == 1.0);
    assert(recall == 0.5);
    cout << "[PASS] Precision & Recall Verification Passed Successfully!" << endl;

    delete[] true_labels;
    delete[] pred_labels;

    return 0;
}
