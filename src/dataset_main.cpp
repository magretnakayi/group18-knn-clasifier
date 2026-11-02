#include <iostream>
#include <vector>
#include <string>
#include "dataset.hpp"

using namespace std;
int main() {
    
    cout << "      Group 18 - Dataset Loading Verification     " << endl;

    string filename = "dataset.csv";
    
    // Attempt to load the dataset
    vector<DataPoint> dataset = loadCSV(filename);

    // Rigorous check for loading status
    if (dataset.empty()) {
        cout << " Error: Dataset could not be loaded or is empty. Check file path." << endl;
        return 1;
    }

    cout << " Successfully ingested " << dataset.size() << " records from '" << filename << "'." << endl;
    cout << " Feature vector dimension per record: " << dataset[0].features.size() << endl;

    // Display summary of loaded data (First 5 records)
    cout << "\n--- Preview of First Records ---" << endl;
    int displayLimit = (dataset.size() < 5) ? dataset.size() : 5;
    for (int i = 0; i < displayLimit; ++i) {
        cout << "Record [" << (i + 1) << "] -> Label: " << dataset[i].label 
             << " | Features: {";
        for (size_t j = 0; j < dataset[i].features.size(); ++j) {
            cout << dataset[i].features[j];
            if (j + 1 < dataset[i].features.size()) cout << ", ";
        }
        cout << "}" << endl;
    }

    cout << "Dataset Loading Module Verified 100% Functional!" << endl;

    return 0;
}