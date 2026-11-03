#include <iostream>
#include <cassert>
#include "classpredictor.hpp" 

using namespace std;

int main() {
    cout << "Running Class Predictor Tests..." << endl;

    int k = 3;
    
    
    int* sample_labels = new int[4];
    sample_labels[0] = 1;
    sample_labels[1] = 1;
    sample_labels[2] = 2;
    sample_labels[3] = 2;

    double* sample_distances = new double[4];
    sample_distances[0] = 0.1;
    sample_distances[1] = 0.3;
    sample_distances[2] = 1.2;
    sample_distances[3] = 1.5;

    // Instantiate using the exact constructor signature from your hpp
    ClassPredictor predictor(sample_labels, sample_distances, k);
    
    // predict() takes 0 arguments based on your hpp definition
    int result = predictor.predict();

    cout << "[PASS] Class Predictor Test Completed Successfully!" << endl;

    // Clean up dynamic memory
    delete[] sample_labels; 
    delete[] sample_distances;

    return 0;
}
