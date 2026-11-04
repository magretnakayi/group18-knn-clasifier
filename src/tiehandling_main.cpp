#include <iostream>
#include "tiehandling.hpp"

using namespace std;

int main() {
    cout << "=== KNN Tie Handling Driver ===" << endl;

    int k = 4;
    int* labels = new int[k]{7, 9, 7, 9};
    double* distances = new double[k]{4.5, 1.1, 5.0, 2.3};
try {
    TieHandler handler(labels, distances, k);
    
    // Pass a vector containing the classes that are tied (e.g., classes 7 and 9)
    vector<int> tied_classes = {7, 9};
    int resolved = handler.breakTie(tied_classes);
    
    cout << "Resolved Winning Class Label: " << resolved << endl;
} catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}

    delete[] labels;
    delete[] distances;

    return 0;
}
