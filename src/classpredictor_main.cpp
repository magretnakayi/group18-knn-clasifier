#include <iostream>
#include "classpredictor.hpp"

using namespace std;

int main() {
    cout << "=== KNN Classpredictor Driver ===" << endl;

    int num_s = 4, num_f = 2, k = 3;
    
    // Allocate training features (2D array)
    double** train_feat = new double*[num_s];
    train_feat[0] = new double[2]{0.0, 0.0};
    train_feat[1] = new double[2]{0.5, 0.5};
    train_feat[2] = new double[2]{10.0, 10.0};
    train_feat[3] = new double[2]{10.5, 10.5};

    // Allocate training labels safely without brace-init compiler errors
    int* train_lbl = new int[4];
    train_lbl[0] = 1;
    train_lbl[1] = 1;
    train_lbl[2] = 2;
    train_lbl[3] = 2;

    // Allocate query array
    double* query = new double[2]{0.2, 0.3};

    try {
        // Instantiate ClassPredictor using your constructor parameters 
        // (Note: Adjust arguments depending on whether your constructor takes 
        // labels, distances/features, and k)
        ClassPredictor predictor(train_lbl, train_feat[0], k); // Pass appropriate pointers based on your implementation

        // Call predict with 0 arguments as defined in your header file
        int predicted = predictor.predict();
        cout << "Predicted Class Label: " << predicted << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Clean up dynamic memory
    for (int i = 0; i < num_s; ++i) {
        delete[] train_feat[i];
    }
    delete[] train_feat;
    delete[] train_lbl;
    delete[] query;

    return 0;
}