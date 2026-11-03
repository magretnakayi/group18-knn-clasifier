#include <iostream>
#include <cassert>
#include "tiehandling.hpp"

using namespace std;

int main() {
    cout << "Running Tie Handling Tests..." << endl;

    int k = 4;
    int* labels = new int[k]{1, 2, 1, 2};
    double* distances = new double[k]{2.0, 0.8, 3.0, 4.0};

    TieHandler handler(labels, distances, k);
  // Pass the tied classes vector into breakTie() instead of calling resolveTieOrVote()
vector<int> tied_classes = {1, 2};
int result = handler.breakTie(tied_classes);

    assert(result == 2);
    cout << "[PASS] Tie Handling Test Completed Successfully!" << endl;

    delete[] labels;
    delete[] distances;

    return 0;
}
