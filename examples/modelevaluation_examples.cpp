#include <iostream>
#include <vector>
#include "classpredictor.hpp"
#include "modelevaluation.hpp"
#include<dataset.hpp>
#include <algorithm>
#include "distance.hpp"

using namespace std;

int main() {
    cout << "=== Model Evaluation Example ===" << endl;

    int train_s = 4, test_s = 2, num_f = 2, k = 1;

    double** train_feat = new double*[train_s]{
        new double[2]{2.0, 2.0}, new double[2]{2.1, 1.9},
        new double[2]{10.0, 10.0}, new double[2]{10.2, 9.8}
    };
    int* train_lbl = new int[4]{1, 1, 2, 2};

    double** test_feat = new double*[test_s]{
        new double[2]{2.05, 2.0}, new double[2]{10.1, 9.9}
    };
    int* test_lbl = new int[2]{1, 2};

    // Convert raw training arrays to vector<DataPoint> for ClassPredictor
    vector<DataPoint> train_data;
    for (int i = 0; i < train_s; ++i) {
        vector<double> f;
        for (int j = 0; j < num_f; ++j) f.push_back(train_feat[i][j]);
        train_data.push_back(DataPoint{f, train_lbl[i]});
    }
    // 2. Predict a label for every test point
    int* predicted_lbl = new int[test_s];
    for (int i = 0; i < test_s; ++i) {
        DataPoint query{ vector<double>(test_feat[i], test_feat[i] + num_f), test_lbl[i] };

        // distance from the test point to every training point
        vector<pair<double, int>> dist;   // (distance, label)
        for (const DataPoint& tr : train_data)
            dist.push_back({ DistanceCalculator::calculateEuclideanDistance(query, tr), tr.label });
        sort(dist.begin(), dist.end());

        // keep the k nearest and let them vote
        vector<int> nLabels;
        vector<double> nDists;
        for (int j = 0; j < k && j < (int)dist.size(); ++j) {
            nLabels.push_back(dist[j].second);
            nDists.push_back(dist[j].first);
        }
        ClassPredictor predictor(nLabels, nDists);
        predicted_lbl[i] = predictor.predict();
    }

    // 3. Evaluate actual vs predicted labels using ModelEvaluator
    ModelEvaluator evaluator(test_lbl, predicted_lbl, test_s);

    cout << "Model Accuracy Score: " << (evaluator.calculate() * 100.0) << "%" << endl;
    evaluator.displayReport();

    // Cleanup heap allocations
    for (int i = 0; i < train_s; ++i) delete[] train_feat[i];
    delete[] train_feat;
    delete[] train_lbl;

    for (int i = 0; i < test_s; ++i) delete[] test_feat[i];
    delete[] test_feat;
    delete[] test_lbl;
    delete[] predicted_lbl;

    return 0;
}