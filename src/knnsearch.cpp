#include "knnsearch.hpp"
#include "distance.hpp"
#include <algorithm>
using namespace std;

vector<Neighbor> findNearestNeighbors(const vector<DataPoint>& trainData, const DataPoint& query) {
    vector<Neighbor> neighbors;
    for (const auto& sample : trainData) {
        // Pass either full DataPoint objects or sample.features / query.features depending on your header definition
        double dist = DistanceCalculator::calculateEuclideanDistance(sample, query);
        neighbors.push_back({dist, sample.label});
    }
    sort(neighbors.begin(), neighbors.end(), [](const Neighbor& a, const Neighbor& b) {
        return a.distance < b.distance;
    });
return neighbors;
}
