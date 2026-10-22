#include "dataset.hpp"
#include "knn_search.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testKnnSearch() {
    vector<DataPoint> testData = {
        { {0.0, 0.0}, 0 },
        { {1.0, 1.0}, 0 },
        { {5.0, 5.0}, 1 }
    };

    vector<double> query = {0.2, 0.2};
    vector<Neighbor> neighbors = findNearestNeighbors(testData, query);

    assert(!neighbors.empty());
    // The closest point should be {0.0, 0.0} with distance roughly 0.2828
    assert(neighbors[0].label == 0);
    assert(neighbors[0].distance < neighbors[2].distance);

    cout << "KNN Search Unit Test Passed Successfully!\n";
}

int main() {
    cout << "Running KNN Search Tests...\n";
    testKnnSearch();
    cout << "All KNN Search Tests Passed!\n";
    return 0;
}

