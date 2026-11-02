#include "distance.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

double DistanceCalculator::calculateEuclideanDistance(const DataPoint& p1, const DataPoint& p2) {
    // Access features directly since DataPoint is a struct with public members
    const auto& features1 = p1.features;
    const auto& features2 = p2.features;

    // Verify dimensional consistency before computation
    if (features1.size() != features2.size()) {
        cout << "Error: Dimension mismatch in distance calculation ("
             << features1.size() << " vs " << features2.size() << ")." << endl;
        throw invalid_argument("Vector dimensions must match for Euclidean distance calculation.");
    }

    double sumOfSquares = 0.0;
    for (size_t i = 0; i < features1.size(); ++i) {
        double diff = features1[i] - features2[i];
        sumOfSquares += diff * diff;
    }

    return sqrt(sumOfSquares);
}