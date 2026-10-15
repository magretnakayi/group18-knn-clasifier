#include "dataset.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
vector<DataPoint> loadCSV(const string& filename) {
    vector<DataPoint> dataset;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return dataset;
    }
    string line;
    if (getline(file, line)) {}
    while (getline(file, line)) {
        if (line.empty()) continue;
    stringstream ss(line);
        string token;
        vector<double> values;
        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                values.push_back(stod(token));
            }
        }
        if (!values.empty()) {
            DataPoint point;
            point.label = static_cast<int>(values.back());
            values.pop_back();
            point.features = values;
            dataset.push_back(point);
        }
    }
    file.close();
    cout << "Successfully loaded " << dataset.size() << " samples from " << filename << endl;
    return dataset;
}
