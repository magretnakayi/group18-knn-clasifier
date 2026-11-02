#include "dataset.hpp"
#include "distance.hpp"
#include <iostream>

using namespace std;

int main() {
    vector<DataPoint> data = loadCSV("dataset.csv");
    if (data.size() < 2) {
        cerr << "Not enough data for distance example.\n";
        return 1;
    }

    cout << "--- Distance API Usage Example ---\n";
    double d = DistanceCalculator::euclideanDistance(data[0], data[1]);
    cout << "Calculated Euclidean Distance: " << d << "\n";

    return 0;
}
