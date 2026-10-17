#include "featurescaling.hpp"
#include <algorithm>
#include <cstddef>

using namespace std;

void scaleFeatures(vector<DataPoint>& dataset) {
    if (dataset.empty() || dataset[0].features.empty()) return;

    size_t numFeatures = dataset[0].features.size();

    // Start min and max from the first row's value for EACH feature
    vector<double> minVals(dataset[0].features);
    vector<double> maxVals(dataset[0].features);

    // Find the min and max of every feature column
    for (const auto& point : dataset) {
        for (size_t i = 0; i < numFeatures; ++i) {
            minVals[i] = min(minVals[i], point.features[i]);
            maxVals[i] = max(maxVals[i], point.features[i]);
        }
    }

    // Apply Min-Max normalization: (x - min) / (max - min)
    for (auto& point : dataset) {
        for (size_t i = 0; i < numFeatures; ++i) {
            if (maxVals[i] - minVals[i] != 0.0) {
                point.features[i] = (point.features[i] - minVals[i]) / (maxVals[i] - minVals[i]);
            } else {
                // Constant column: avoid division by zero
                point.features[i] = 0.0;
            }
        }
    }
}
