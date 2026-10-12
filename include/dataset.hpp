#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include <vector>
using namespace std;


struct DataPoint {
    vector<double> features;
   int label;
};

vector<DataPoint> loadCSV(const std::string& filename);

#endif 