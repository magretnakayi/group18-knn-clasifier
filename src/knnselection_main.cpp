#include "dataset.hpp"
#include "knnsearch.hpp"
#include "knnselection.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Running Neighbor Selection Verification \n";
    
    vector<DataPoint> dataset = loadCSV("dataset.csv");
    if (dataset.empty()) {
        cout << "Error: Could not load dataset.csv\n";
        return 1;
    }

    cout << "Loaded " << dataset.size() << " records successfully.\n";

    // Using the first record's features as a query point to get neighbors first
    vector<double> queryPoint = dataset[0].features;
    int k = 3;

    // Get sorted neighbors using search module
    vector<Neighbor> neighbors = findNearestNeighbors(dataset, queryPoint);

    // Testing the submitted selectMajorityLabel function
    int majorityLabel = selectMajorityLabel(neighbors, k);

    cout << "Top " << k << " Nearest Neighbors evaluated.\n";
    cout << "Selected Majority Label: " << majorityLabel << "\n";

    cout << "Neighbor selection verification completed successfully!\n";
    return 0;
}