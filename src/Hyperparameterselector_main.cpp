#include <iostream>
#include <vector>
#include "hyperparameterselector.hpp"
#include "dataset.hpp"

using namespace std;

int main() {
    cout << "=== KNN Hyperparameter Driver ===" << endl;

    int train_s = 4, val_s = 2, num_f = 2;

    // Raw feature arrays for training
    double** train_feat = new double*[train_s]{
        new double[2]{3.0, 3.0}, new double[2]{3.2, 2.8},
        new double[2]{12.0, 12.0}, new double[2]{12.5, 11.8}
    };
    int* train_lbl = new int[4]{1, 1, 2, 2};

    // Raw feature arrays for validation
    double** val_feat = new double*[val_s]{
        new double[2]{3.1, 2.9}, new double[2]{12.1, 11.9}
    };
    int* val_lbl = new int[2]{1, 2};

    // Convert raw pointer data into std::vector<DataPoint> for optimizeK
   // Training data conversion loop
    vector<DataPoint> train_data;
    for (int i = 0; i < train_s; ++i) {
        vector<double> feats(train_feat[i], train_feat[i] + num_f);
        train_data.push_back(DataPoint{feats, train_lbl[i]});
    }

    // Validation data conversion loop
    vector<DataPoint> val_data;
    for (int i = 0; i < val_s; ++i) {
        vector<double> feats(val_feat[i], val_feat[i] + num_f);
        val_data.push_back(DataPoint{feats, val_lbl[i]}); 
    }
    // Candidate k values array
    int* candidates = new int[3]{1, 3, 5};

    try {
        // 1. Initialize selector with candidates pointer and count
        HyperparameterSelector selector(candidates, 3);

        // 2. Call optimizeK passing the vector datasets
        int best_k = selector.optimizeK(train_data, val_data);
        
        cout << "Optimal k Selected: " << best_k << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Clean up heap allocations
    for (int i = 0; i < train_s; ++i) delete[] train_feat[i];
    delete[] train_feat; 
    delete[] train_lbl;

    for (int i = 0; i < val_s; ++i) delete[] val_feat[i];
    delete[] val_feat; 
    delete[] val_lbl;

    delete[] candidates;

    return 0;
}