#include "dataset.hpp"
#include "knn_search.hpp"
#include <iostream>

using namespace std;

int main() {
    vector<DataPoint> data = loadCSV("dataset.csv");
    if (data.empty()) {
        cerr << "Not enough data for KNN search example.\n";
        return 1;
    }

    cout << "--- KNN Search API Usage Example ---\n";
    vector<double> query = data[0].features;
    vector<Neighbor> neighbors = findNearestNeighbors(data, query);

    cout << "Closest neighbor distance: " << neighbors[0].distance << "\n";
    cout << "Closest neighbor label: " << neighbors[0].label << "\n";

    return 0;
}
