#include "tiehandling.hpp"
#include <stdexcept>
#include <limits>
#include <algorithm>

using namespace std;

// Direct Constructor from dataset.csv DataPoints and distances
TieHandler::TieHandler(const vector<DataPoint>& nearest_neighbors, const vector<double>& distances) {
    if (nearest_neighbors.empty() || nearest_neighbors.size() != distances.size()) {
        throw invalid_argument("Neighbors and distances cannot be empty and must match in size.");
    }

    k_size = static_cast<int>(nearest_neighbors.size());
    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];

    for (int i = 0; i < k_size; ++i) {
        neighbor_labels[i] = nearest_neighbors[i].label; // Pulls label from CSV row
        neighbor_distances[i] = distances[i];            // Pulls distance from parallel vector
    }
}
// Copy Constructor (Deep Copy)
TieHandler::TieHandler(const TieHandler& other) : k_size(other.k_size) {
    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];

    for (int i = 0; i < k_size; ++i) {
        neighbor_labels[i] = other.neighbor_labels[i];
        neighbor_distances[i] = other.neighbor_distances[i];
    }
}

// Assignment Operator (Deep Copy)
TieHandler& TieHandler::operator=(const TieHandler& other) {
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

// Destructor cleaning up heap memory
TieHandler::~TieHandler() {
    delete[] neighbor_labels;
    delete[] neighbor_distances;
}

// Resolves voting ties by scanning neighbor records for the minimum distance among tied candidates
int TieHandler::breakTie(const vector<int>& tied_classes) const {
    if (tied_classes.empty()) {
        throw invalid_argument("Tied classes list cannot be empty.");
    }

    int winning_class = tied_classes[0];
    double min_distance = numeric_limits<double>::max();

    // Iterate through pointer arrays representing neighbors from dataset.csv
    for (int i = 0; i < k_size; ++i) {
        int current_label = neighbor_labels[i];
        
        // Check if this neighbor's label is one of the tied candidates
        for (int candidate : tied_classes) {
            if (current_label == candidate && neighbor_distances[i] < min_distance) {
                min_distance = neighbor_distances[i];
                winning_class = current_label;
            }
        }
    }

    return winning_class;
}

