#include "majorityvoting.hpp"
#include <map>
#include <stdexcept>
#include <algorithm>
#include <limits>

using namespace std;

// Constructor from raw pointers
MajorityVoting::MajorityVoting(const int* labels, const double* distances, int k) : k_size(k) {
    if (k_size <= 0 || labels == nullptr || distances == nullptr) {
        throw invalid_argument("Invalid k size or null pointers supplied to MajorityVoting.");
    }
    
    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];
    for (int i = 0; i < k_size; ++i) {
        neighbor_labels[i] = labels[i];
        neighbor_distances[i] = distances[i];
    }
}

// Direct Constructor from dataset.csv DataPoints (Extracts labels and distances straight from dataset rows)
MajorityVoting::MajorityVoting(const vector<DataPoint>& nearest_neighbors, const vector<double>& distances) {
    if (nearest_neighbors.empty() || nearest_neighbors.size() != distances.size()) {
        throw invalid_argument("Neighbors and distances vectors cannot be empty and must match in size.");
    }

    k_size = static_cast<int>(nearest_neighbors.size());
    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];

    for (int i = 0; i < k_size; ++i) {
        neighbor_labels[i] = nearest_neighbors[i].label; // Pulls label from DataPoint
        neighbor_distances[i] = distances[i];            // Pulls distance from the parallel vector
    }
}

// Copy Constructor (Deep Copy)
MajorityVoting::MajorityVoting(const MajorityVoting& other) : k_size(other.k_size) {
    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];
    for (int i = 0; i < k_size; ++i) {
        neighbor_labels[i] = other.neighbor_labels[i];
        neighbor_distances[i] = other.neighbor_distances[i];
    }
}

// Assignment Operator (Deep Copy)
MajorityVoting& MajorityVoting::operator=(const MajorityVoting& other) {
    if (this != &other) {
        delete[] neighbor_labels;
        delete[] neighbor_distances;
        
        k_size = other.k_size;
        neighbor_labels = new int[k_size];
        neighbor_distances = new double[k_size];
        for (int i = 0; i < k_size; ++i) {
            neighbor_labels[i] = other.neighbor_labels[i];
            neighbor_distances[i] = other.neighbor_distances[i];
        }
    }
    return *this;
}

// Destructor
MajorityVoting::~MajorityVoting() {
    delete[] neighbor_labels;
    delete[] neighbor_distances;
}

// Core prediction method tallying votes with built-in distance tie-breaking
int MajorityVoting::predictClass() const {
    map<int, int> vote_counts;

    for (int i = 0; i < k_size; ++i) {
        vote_counts[neighbor_labels[i]]++;
    }

    int predicted_class = neighbor_labels[0];
    int max_votes = -1;
    vector<int> tied_classes;

    // Find the winning vote count and track ties
    for (const auto& [label, count] : vote_counts) {
        if (count > max_votes) {
            max_votes = count;
            predicted_class = label;
            tied_classes.clear();
            tied_classes.push_back(label);
        } else if (count == max_votes) {
            tied_classes.push_back(label);
        }
    }

    // Resolve ties using the closest neighbor distance from dataset.csv
    if (tied_classes.size() > 1) {
        double min_distance = numeric_limits<double>::max();
        for (int i = 0; i < k_size; ++i) {
            int current_label = neighbor_labels[i];
            for (int candidate : tied_classes) {
                if (current_label == candidate && neighbor_distances[i] < min_distance) {
                    min_distance = neighbor_distances[i];
                    predicted_class = current_label;
                }
            }
        }
    }

    return predicted_class;
}
