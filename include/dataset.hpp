#ifndef DATASET_HPP
#define DATASET_HPP

#include <vector>
#include <string>

using namespace std;

struct DataPoint {
    vector<double> features;
    int label;
};

vector<DataPoint> loadCSV(const string& filename);

#endif
