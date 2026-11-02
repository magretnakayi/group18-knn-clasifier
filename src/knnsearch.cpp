#include "knnsearch.hpp"
#include "distance.hpp"
#include <algorithm>
using namespace std;
using distance::calculateEuclideanDistance;
vector<Neighbor> findNearestNeighbors(const vector<DataPoint>& trainData, const vector<double>& query) {
    vector<Neighbor> neighbors;
    for (const auto& sample : trainData) {
        double dist = calculateEuclideanDistance(sample.features, query);
        neighbors.push_back({dist, sample.label});
    }
    sort(neighbors.begin(), neighbors.end(), [](const Neighbor& a, const Neighbor& b) {
        return a.distance < b.distance;
    });
return neighbors;
}
