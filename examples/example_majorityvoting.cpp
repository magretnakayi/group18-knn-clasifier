#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "majorityvoting.hpp"

using namespace std;

struct DataPoint {
    vector<double> features;
    int label;
};

int main() {
    cout << "Standalone Majority Voting Example " << endl;

vector<DataPoint> mock_neighbors = { 
    { {1.0, 1.0}, 1 }, 
    { {2.0, 2.0}, 2 }, 
    { {1.1, 1.1}, 1 }, 
    { {3.0, 3.0}, 3 }, 
    { {1.2, 1.2}, 1 } 
};
vector<double> mock_distances = { 0.1, 0.5, 0.2, 0.8, 0.3 };

try {
    // Pass BOTH vectors to match the header constructor
    MajorityVoting voter(mock_neighbors, mock_distances);
    
    // Call predictClass() instead of predictPlurality()
    int final_class = voter.predictClass();

    cout << "Neighbor Labels Ingested: {1, 2, 1, 3, 1}" << endl;
    cout << "Predicted Plurality Class: " << final_class << endl;
} catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}
   