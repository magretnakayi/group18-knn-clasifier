#include "dataset.hpp"
#include "datapreprocessing.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Running Data Preprocessing Main Verification ---\n";
    
    vector<DataPoint> dataset = loadCSV("dataset.csv");
    if (dataset.empty()) {
        cerr << "Error: Could not load dataset.csv\n";
        return 1;
    }

    cout << "Loaded " << dataset.size() << " records successfully.\n";
    cout << "Before Preprocessing (First Record Feature 0): " << dataset[0].features[0] << "\n";

  // Apply normalization using the function from preprocessing.hpp
    normalizeDataset(dataset);
    cout << "After Normalization (First Record Feature 0): " << dataset[0].features[0] << "\n";

    cout << "Preprocessing verification completed successfully!\n";
    return 0;
    cout << "Preprocessing verification completed successfully!\n";
    return 0;
}
