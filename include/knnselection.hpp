#ifndef NEIGHBOR_SELECTION_HPP
#define NEIGHBOR_SELECTION_HPP



#include "knnsearch.hpp"
#include <vector>


using namespace std;
int selectMajorityLabel(const vector<Neighbor>& sortedNeighbors, int k);
#endif
