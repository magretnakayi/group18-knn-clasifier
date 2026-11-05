#include <iostream>
#include <cassert>
#include "hyperparameterselector.hpp"

using namespace std;

int main() {
    cout << "Running Hyperparameter Tests..." << endl;

    int train_s = 4, val_s = 2, num_f = 2;
    double** train_feat = new double*[train_s]{
        new double[2]{2.0, 2.0}, new double[2]{2.2, 1.8},
        new double[2]{10.0, 10.0}, new double[2]{10.5, 9.8}
    };
    int* train_lbl = new int[4]{1, 1, 2, 2};
    double** val_feat = new double*[val_s]{
        new double[2]{2.1, 1.9}, new double[2]{10.2, 10.1}
    };
    int* val_lbl = new int[2]{1, 2};
    int* candidates = new int[2]{1, 3};

    HyperparameterSelector selector(candidates, 2);

    vector<DataPoint> t_data, v_data;
    for (int i = 0; i < train_s; ++i) { vector<double> f; for (int j = 0; j < num_f; ++j) f.push_back(train_feat[i][j]); t_data.push_back(DataPoint{f, train_lbl[i]}); }
    for (int i = 0; i < val_s; ++i) { vector<double> f; for (int j = 0; j < num_f; ++j) f.push_back(val_feat[i][j]); v_data.push_back(DataPoint{f, val_lbl[i]}); }

    int best_k = selector.optimizeK(t_data, v_data);
    assert(best_k == 1 || best_k == 3);
    cout << "[PASS] Test Completed Successfully!" << endl;

    for (int i = 0; i < train_s; ++i) delete[] train_feat[i];
    delete[] train_feat; delete[] train_lbl;
    for (int i = 0; i < val_s; ++i) delete[] val_feat[i];
    delete[] val_feat; delete[] val_lbl;
    delete[] candidates;

    return 0;
}
