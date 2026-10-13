
#ifndef PREPROCESSING_HPP
#define PREPROCESSING_HPP

#include "dataset.hpp"
#include <vector>
using namespace std;
// Normalizes features using Min-Max scaling
void normalizeDataset(vector<DataPoint>& data);

#endif