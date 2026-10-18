#ifndef KNNSEARCH_HPP
#define KNNSEARCH_HPP

#include "dataset.hpp"
#include <vector>

using namespace std;

struct Neighbor {
    double distance;
    int label;
};

vector<Neighbor> findNearestNeighbors(const vector<DataPoint>& trainData, const vector<double>& query);

#endif