
#include "datapreprocessing.hpp"
#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

void normalizeDataset(vector<DataPoint>& data) {
    if (data.empty()) {
   throw runtime_error("Error: Cannot normalize an empty dataset.");
    }

    size_t numFeatures = data[0].features.size();
    if (numFeatures == 0) {
    throw runtime_error("Error: No features found in dataset records.");
    }

    // Apply Min-Max normalization column by column
    for (size_t j = 0; j < numFeatures; ++j) {
    double minimum = data[0].features[j];
    double maximum = data[0].features[j];

    for (const auto& point : data) {
    minimum = min(minimum, point.features[j]);
    maximum = max(maximum, point.features[j]);
    }

   for (auto& point : data) {
    if (maximum == minimum) {
    point.features[j] = 0.0;
    } else {
    point.features[j] = (point.features[j] - minimum) / (maximum - minimum);
 }
    }
}
}
