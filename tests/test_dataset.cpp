#include "dataset.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testLoadCSVValidFile() {
    cout << " testLoadCSV Valid File..." << endl;
    vector<DataPoint> dataset = loadCSV("dataset.csv");
    
    // Assert that the dataset is not empty
    assert(!dataset.empty() && "Dataset should not be empty!");
    
    // Assert that features and labels are parsed
    assert(!dataset[0].features.empty() && "Feature vector should not be empty!");
    
    cout << " testLoadCSVValidFile passed successfully!\n" << endl;
}

void testLoadCSVInvalidFile() {
    cout << " testLoadCSVInvalidFile..." << endl;
    // Try opening a file that doesn't exist
    vector<DataPoint> dataset = loadCSV("non_existent_file.csv");
    
    // Assert that the returned vector is empty
    assert(dataset.empty() && "Dataset should be empty for invalid files!");
    
    cout << " testLoadCSVInvalidFile passed successfully!\n" << endl;
}

int main() {
    cout << " RUNNING DATASET MODULE TESTS " << endl;
    
    testLoadCSVValidFile();
    testLoadCSVInvalidFile();
    
    cout << " ALL DATASET TESTS PASSED SUCCESSFULLY! " << endl;
    return 0;
}