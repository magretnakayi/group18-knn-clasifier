#include "dataset.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << " KNN Pipeline: Dataset Loading Example " << endl;

    string path = "dataset.csv";
    vector<DataPoint> myData = loadCSV(path);

    if (myData.empty()) {
        cerr << "Failed to load data. Exiting example." << endl;
        return 1;
    }

    cout << "\nSuccessfully loaded " << myData.size() << " rows." << endl;
    cout << "Showing the first data point details:" << endl;
    cout << " - Label: " << myData[0].label << endl;
    cout << " - Feature Count: " << myData[0].features.size() << endl;

    return 0;
}