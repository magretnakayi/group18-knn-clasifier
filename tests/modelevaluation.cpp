#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include "dataset.hpp"
#include "distance.hpp"
#include "classpredictor.hpp"
#include "modelevaluation.hpp"

using namespace std;

int main() {
    cout << "Running Model Evaluation Tests..." << endl;

    int k = 3;

    // Two clean, well-separated clusters
    vector<DataPoint> train = {
        { {1.0, 1.0}, 1 }, { {1.2, 0.8}, 1 },
        { {5.0, 5.0}, 2 }, { {5.2, 4.8},2 }
    };
    vector<DataPoint> test = {
        { {1.1, 1.0}, 1 }, { {5.1, 4.9}, 2 }
    };

    vector<int> actual, predicted;

    for (const DataPoint& t : test) {
        // distance from the test point to every training point
        vector<pair<double, int>> dist;   // (distance, label)
        for (const DataPoint& tr : train)
            dist.push_back({ DistanceCalculator::calculateEuclideanDistance(t, tr), tr.label });
        sort(dist.begin(), dist.end());

        // keep the k nearest and let them vote
        vector<int> nLabels;
        vector<double> nDists;
        for (int i = 0; i < k && i < (int)dist.size(); ++i) {
            nLabels.push_back(dist[i].second);
            nDists.push_back(dist[i].first);
        }
        ClassPredictor predictor(nLabels, nDists);

        predicted.push_back(predictor.predict());
        actual.push_back(t.label);
    }

    ModelEvaluator evaluator(actual, predicted);
    double accuracy = evaluator.calculate();

    assert(accuracy == 1.0); // Expecting 100% accuracy on clean test cases
    cout << "[PASS] Model Evaluation Test Completed Successfully (100% Accuracy Verified)!" << endl;

    return 0;
}