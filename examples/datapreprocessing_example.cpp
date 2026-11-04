#include "../include/dataset.hpp"
#include "../include/datapreprocessing.hpp"
#include <iostream>

using namespace std;

int main() {
    // Load dataset for example
    vector<DataPoint> data = loadCSV("dataset.csv");
    if (data.empty()) {
        cout << "Failed to load dataset for preprocessing example.\n";
        return 1;
    }

    cout << " Preprocessing API Usage Example \n";
    cout << "Original Feature Value: " << data[0].features[0] << "\n";

    // Apply Min-Max Normalization
normalizeDataset(data);

    cout << "Normalized Feature Value [0, 1]: " << data[0].features[0] << "\n";

    return 0;
}

