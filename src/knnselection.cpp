#include "knnselection.hpp"
#include <map>
using namespace std;
int selectMajorityLabel(const vector<Neighbor>& sortedNeighbors, int k) {
    map<int, int> classCounts;
    int winningLabel = -1;
    int maxVotes = -1;
    for (int i = 0; i < k && i < static_cast<int>(sortedNeighbors.size()); ++i) {
        int label = sortedNeighbors[i].label;
        classCounts[label]++;
 if (classCounts[label] > maxVotes) {
            maxVotes = classCounts[label];
            winningLabel = label;
        }
    }
    return winningLabel;
}

