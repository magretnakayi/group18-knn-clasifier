#include "dataset.hpp"
#include "knn_search.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "Running KNN Search Verification \n";
    
    vector<DataPoint> dataset = loadCSV("dataset.csv");
    if (dataset.empty()) {
        cerr << "Error: Could not load dataset.csv\n";
        return 1;
    }

    cout << "Loaded " << dataset.size() << " records successfully.\n";

    // Use the feature vector of the first record as our query point
    vector<double> queryPoint = dataset[0].features;
    int k = 3;

    vector<Neighbor> neighbors = findNearestNeighbors(dataset, queryPoint);

    cout << "Top " << k << " Nearest Neighbors found for query:\n";
    for (int i = 0; i < k && i < static_cast<int>(neighbors.size()); ++i) {
        cout << "Neighbor " << i + 1 << " -> Distance: " << neighbors[i].distance 
             << ", Label: " << neighbors[i].label << "\n";
    }

    cout << "KNN Search verification completed successfully!\n";
    return 0;
}

s