#include <iostream>
#include "classpredictor.hpp" // Make sure filename matches your header file

using namespace std;

int main() {
    cout << "=== Class Predictor Example ===" << endl;

    int k = 3;

    // Based on your header: constructor takes (const int* labels, const double* distances, int k)
    int* sample_labels = new int[4];
    sample_labels[0] = 10;
    sample_labels[1] = 10;
    sample_labels[2] = 20;
    sample_labels[3] = 20;

    double* sample_distances = new double[4];
    sample_distances[0] = 0.2;
    sample_distances[1] = 0.4;
    sample_distances[2] = 2.0;
    sample_distances[3] = 2.5;

    // Instantiate matching your hpp constructor
    ClassPredictor predictor(sample_labels, sample_distances, k);
    
    // predict() takes 0 arguments based on your hpp definition
    cout << "Predicted Class: " << predictor.predict() << endl;

    // Clean up dynamic memory
    delete[] sample_labels; 
    delete[] sample_distances;

    return 0;
}
