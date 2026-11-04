#include <iostream>
#include "ConfusionMatrix.hpp"
using namespace std;
int main() {
    cout << "=== Confusion Matrix Example ===" << endl;
    int num_samples = 4;
    int num_classes = 2; // Binary classes: 0, 1
    int* true_labels = new int[num_samples]{1, 0, 1, 0};
    int* pred_labels = new int[num_samples]{1, 1, 1, 0};
    ConfusionMatrix cm(true_labels, pred_labels, num_samples, num_classes);
    cout << "Confusion Matrix Output:" << endl;
    cm.printMatrix();
    cout << "Accuracy Score: " << (cm.getAccuracy() * 100.0) << "%" << endl;
    delete[] true_labels;
    delete[] pred_labels;
    return 0;
}