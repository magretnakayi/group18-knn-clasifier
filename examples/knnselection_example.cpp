#include "dataset.hpp"
#include "knnsearch.hpp"
#include "knnselection.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << " KNN Neighbor Selection Example \n";

    // Create sample sorted neighbors (distance, label)
    vector<Neighbor> sampleNeighbors = {
        {0.2, 1},
        {0.5, 1},
        {1.1, 0},
        {2.5, 0}
    };

    int k = 3;
    cout << "Evaluating top " << k << " neighbors for majority class label...\n";

    // Call the submitted selectMajorityLabel function
    int majorityLabel = selectMajorityLabel(sampleNeighbors, k);

    cout << "Resulting Majority Class Label: " << majorityLabel << "\n";
    cout << " Example Completed Successfully \n";

    return 0;
}