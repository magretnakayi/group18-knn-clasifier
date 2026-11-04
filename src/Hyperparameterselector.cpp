#include "HyperparameterSelector.hpp"
#include "ClassPrediction.hpp"
#include "distance.hpp"
#include <stdexcept>
#include <algorithm>

using namespace std;

// Constructor using raw pointers and arrays
HyperparameterSelector::HyperparameterSelector(const int* candidates, int count) : num_candidates(count) {
    if (num_candidates <= 0 || candidates == nullptr) {
        throw invalid_argument("Invalid candidate count or null pointer supplied to HyperparameterSelector.");
    }

    k_candidates = new int[num_candidates];
    for (int i = 0; i < num_candidates; ++i) {
        if (candidates[i] <= 0) {
            throw invalid_argument("K candidate values must be greater than zero.");
        }
        k_candidates[i] = candidates[i];
    }
}

// Overloaded constructor for STL vectors
HyperparameterSelector::HyperparameterSelector(const vector<int>& candidates) {
    num_candidates = static_cast<int>(candidates.size());
    if (num_candidates == 0) {
        throw invalid_argument("Candidates vector cannot be empty.");
    }

    k_candidates = new int[num_candidates];
    for (int i = 0; i < num_candidates; ++i) {
        if (candidates[i] <= 0) {
            throw invalid_argument("K candidate values must be greater than zero.");
        }
        k_candidates[i] = candidates[i];
    }
}

// Copy Constructor (Deep Copy)
HyperparameterSelector::HyperparameterSelector(const HyperparameterSelector& other) : num_candidates(other.num_candidates) {
    k_candidates = new int[num_candidates];
    for (int i = 0; i < num_candidates; ++i) {
        k_candidates[i] = other.k_candidates[i];
    }
}

// Assignment Operator (Deep Copy)
HyperparameterSelector& HyperparameterSelector::operator=(const HyperparameterSelector& other) {
    if (this != &other) {
        delete[] k_candidates;

        num_candidates = other.num_candidates;
        k_candidates = new int[num_candidates];
        for (int i = 0; i < num_candidates; ++i) {
            k_candidates[i] = other.k_candidates[i];
        }
    }
    return *this;
}

// Destructor cleaning up pointer memory
HyperparameterSelector::~HyperparameterSelector() {
    delete[] k_candidates;
}

// Evaluates candidate k values against validation data to find the optimal hyperparameter
int HyperparameterSelector::optimizeK(const vector<DataPoint>& train_data, const vector<DataPoint>& val_data) const {
    if (train_data.empty() || val_data.empty()) {
        throw invalid_argument("Training and validation datasets must not be empty.");
    }

    int best_k = k_candidates[0];
    double best_accuracy = -1.0;

    // Loop through each candidate k using pointer traversal
    for (int i = 0; i < num_candidates; ++i) {
        int current_k = k_candidates[i];
        int correct_predictions = 0;

        // Evaluate validation set performance for the current k
        for (const auto& val_point : val_data) {
            vector<pair<double, int>> distances_and_labels;

            // Calculate distance from validation point to all training points from dataset.csv
            for (const auto& train_point : train_data) {
                double dist = calculateEuclideanDistance(val_point.features, train_point.features);
                distances_and_labels.push_back({dist, train_point.label});
            }

            // Sort distances to find nearest neighbors
            sort(distances_and_labels.begin(), distances_and_labels.end());

            // Extract top k labels and distances
            vector<int> current_labels;
            vector<double> current_distances;
            int actual_k = min(current_k, static_cast<int>(distances_and_labels.size()));

            for (int j = 0; j < actual_k; ++j) {
                current_distances.push_back(distances_and_labels[j].first);
                current_labels.push_back(distances_and_labels[j].second);
            }

            // Predict class using your standalone ClassPredictor module
            ClassPredictor predictor(current_labels, current_distances);
            int predicted_class = predictor.predict();

            if (predicted_class == val_point.label) {
                correct_predictions++;
            }
        }

        // Calculate validation accuracy
        double accuracy = static_cast<double>(correct_predictions) / val_data.size();

        // Update optimal k if current accuracy is strictly higher
        if (accuracy > best_accuracy) {
            best_accuracy = accuracy;
            best_k = current_k;
        }
    }

    return best_k;
}

