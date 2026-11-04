#include <iostream>
#include "tiehandling.hpp"

using namespace std;

int main() {
    cout << "=== Tie Handling Example ===" << endl;

    int k = 4;
    int* labels = new int[k]{1, 2, 1, 2};
    double* distances = new double[k]{2.5, 1.2, 3.1, 4.0};

    TieHandler handler(labels, distances, k);
    // Pass a vector containing the tied classes
    vector<int> tied_classes = {1, 2};
    cout << "Winning Class via Proximity: " << handler.breakTie(tied_classes) << endl;

    delete[] labels;
    delete[] distances;

    return 0;
}
