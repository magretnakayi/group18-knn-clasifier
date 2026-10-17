#ifndef DISTANCE_HPP
#define DISTANCE_HPP

#include "dataset.hpp"
#include <vector>

class DistanceCalculator {
public:
    // Computes the Euclidean distance between two DataPoint feature vectors
    static double calculateEuclideanDistance(const DataPoint& p1, const DataPoint& p2);
};

#endif // DISTANCE_HPP