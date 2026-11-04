#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include "majorityvoting.hpp"
#include "dataset.hpp"

using namespace std;

void runTests() {
    cout << "Running Majority Voting Tests..." << endl;

    // Test 1: Vector Constructor & Prediction
    {
        vector<DataPoint> points = { { {1.0, 2.0}, 2 }, { {1.1, 2.1}, 1 }, { {1.2, 2.2}, 2 } };
        vector<double> distances = { 0.1, 0.2, 0.3 };

        MajorityVoting voter(points, distances);
        assert(voter.predictClass() == 2); // Fixed from predictPlurality() to predictClass()
        cout << "[PASS] Test 1: Standard Plurality Win" << endl;
    }

    // Test 2: Raw Pointer Constructor and Deep Copy (Rule of Three)
    {
        int k = 5;
        int* raw_labels = new int[k]{5, 5, 1, 3, 5};
        double* raw_distances = new double[k]{0.1, 0.2, 0.3, 0.4, 0.5}; // Provided distances

        MajorityVoting voter1(raw_labels, raw_distances, k); // Passed all 3 parameters
        MajorityVoting voter2 = voter1;
        
        assert(voter2.predictClass() == 5); // Fixed method name
        cout << "[PASS] Test 2: Raw Pointer Constructor & Copy" << endl;

        delete[] raw_labels;
        delete[] raw_distances;
    }

    // Test 3: Exception Handling for Empty Vectors
    {
    bool exception_thrown = false;
    try {
    vector<DataPoint> empty_points;
    vector<double> empty_distances;
    MajorityVoting voter(empty_points, empty_distances);
    } catch (const invalid_argument&) {
    exception_thrown = true;
    }
    assert(exception_thrown);
    cout << "[PASS] Test 3: Exception Handling Verified" << endl;
    }
}

int main() {
    runTests();
    return 0;
}