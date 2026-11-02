#include "dataset.hpp"
#include "knnsearch.hpp"
#include "knnselection.hpp"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void testNeighborSelection() {
    // Create mock sorted neighbors (distance, label) matching your Neighbor struct
    vector<Neighbor> testNeighbors = {
        {0.5, 0},
        {1.4, 0},
        {7.0, 1},
        {14.1, 1}
    };

    int k = 2;

    // Test the submitted selectMajorityLabel function directly
    int majorityLabel = selectMajorityLabel(testNeighbors, k);

    // Assert that the majority label of the top 2 neighbors (0 and 0) is 0
    assert(majorityLabel == 0);

    cout << "Neighbor Selection Unit Test Passed Successfully!\n";
}

int main() {
    cout << "Running Neighbor Selection Tests...\n";
    testNeighborSelection();
    cout << "All Neighbor Tests Passed!\n";
    return 0;
}