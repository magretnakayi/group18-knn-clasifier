#include <iostream>
#include "ConfusionMatrix.hpp"
using namespace std;
int main() {
    cout << "=== KNN Confusion Matrix Driver ===" << endl;
    int num_samples = 5;
    int num_classes = 3; // Classes: 0, 1, 2
    // Allocate true and predicted label arrays on the heap
    int* true_labels = new int[num_samples]{0, 1, 2, 1, 0};
    int* pred_labels = new int[num_samples]{0, 1, 1, 1, 0};
    try {
        ConfusionMatrix cm(true_labels, pred_labels, num_samples, num_classes);
        cout << "Displaying Confusion Matrix [Rows: Actual, Cols: Predicted]:" << endl;
        cm.printMatrix();
        double accuracy = cm.getAccuracy();
        cout << "-> Overall Accuracy: " << (accuracy * 100.0) << "%" << endl;
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
