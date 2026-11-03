#include "dataset.hpp"
#include "distance.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

void testEuclideanDistance() {
    DataPoint p1 = { {0.0, 0.0}, 0 };
    DataPoint p2 = { {3.0, 4.0}, 1 };

    double dist = DistanceCalculator::euclideanDistance(p1, p2);
    
    // Expected distance between (0,0) and (3,4) is 5.0
    assert(abs(dist - 5.0) < 1e-5);

    cout << "Euclidean Distance Unit Test Passed Successfully!\n";
}

int main() {
    cout << "Running Distance Calculation Tests...\n";
    testEuclideanDistance();
    cout << "All Distance Tests Passed!\n";
    return 0;
}
