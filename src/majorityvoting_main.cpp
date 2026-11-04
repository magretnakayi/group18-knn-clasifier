#include <iostream>
#include "majorityvoting.hpp"

using namespace std;

int main() {
    cout << "=== KNN Majority Voting Driver ===" << endl;

   int k = 5;
int* labels = new int[k]{4, 2, 4, 1, 4};
double* distances = new double[k]{0.1, 0.5, 0.2, 0.8, 0.3}; // Provide corresponding distances

try {
    MajorityVoting voter(labels, distances, k); // Pass all 3 parameters!
    int predicted = voter.predictClass();       // Note: function name is predictClass()
    cout << "Predicted Plurality Class: " << predicted << endl;
} catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}

delete[] labels;
delete[] distances; // Clean up distances too
return 0;
}