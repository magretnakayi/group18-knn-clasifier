#include "dataset.hpp"
#include "datapreprocessing.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testMinMaxNormalization() {
    vector<DataPoint> testData = {
        { {10.0, 2.0}, 0 },
        { {20.0, 4.0}, 1 },
        { {30.0, 6.0}, 0 }
    };

    normalizeDataset(testData);

    assert(testData[0].features[0] == 0.0);
    assert(testData[2].features[0] == 1.0);
    assert(testData[1].features[0] == 0.5);

    cout << "Min-Max Normalization Unit Test Passed Successfully!\n";
}

int main() {
    cout << "Running Data Preprocessing Tests...\n";
    testMinMaxNormalization();
    cout << "All Preprocessing Tests Passed!\n";
    return 0;
}
