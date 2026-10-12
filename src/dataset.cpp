#include "dataset.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <iostream>

 using namespace std;

    vector<DataPoint> loadCSV(string filename) {
    vector<DataPoint> data;
    ifstream file(filename);

    if (!file) {
    throw runtime_error("Error: Could not open file " + filename);
    }

    string line;
    
    // Skip the header row
    if (!getline(file, line)) {
    throw runtime_error("Error: The file is empty.");
    }

    int lineNumber = 1;

    while (getline(file, line)) {
    ++lineNumber;
    
    if (line.empty()) continue;
    stringstream ss(line);
    string value;
    vector<double> values;

    while (getline(ss, value, ',')) {
    try {
    size_t used = 0;
    double number = stod(value, &used);
                
    if (used != value.size() || !isfinite(number)) {
    throw runtime_error("Invalid number");
    }
    values.push_back(number);
    } catch (...) {
    throw runtime_error("Bad value found on line " + to_string(lineNumber));
    }
    }
    if (values.size() != 4) {
    throw runtime_error("Wrong column count on line " + to_string(lineNumber));
    }
    double labelValue = values.back();
    values.pop_back();

    DataPoint point;
    point.features = move(values);
    point.label = static_cast<int>(labelValue);

    data.push_back(point);
    }

    file.close();
    return data;
}