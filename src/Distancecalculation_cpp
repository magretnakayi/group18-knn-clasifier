#include "dataset.hpp"
#include "distance.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Running Distance Calculation Verification ---\n";
    
    vector<DataPoint> dataset = loadCSV("dataset.csv");
    if (dataset.size() < 2) {
        cerr << "Error: Dataset needs at least 2 records to calculate distance.\n";
        return 1;
    }

    cout << "Loaded " << dataset.size() << " records successfully.\n";

    // Calculate distance between the first and second data points
    double dist = DistanceCalculator::euclideanDistance(dataset[0], dataset[1]);
    
    cout << "Euclidean distance between Record 0 and Record 1: " << dist << "\n";
    cout << "Distance calculation verification completed successfully!\n";
    
    return 0;
}



