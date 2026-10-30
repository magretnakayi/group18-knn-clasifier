#include "ClassPredictor.hpp"
#include <map>
#include <stdexcept>
#include <limits>

using namespace std;

// Constructor using pointers and raw arrays
ClassPredictor::ClassPredictor(const int* labels, const double* distances, int k) : k_size(k) {
    if (k_size <= 0 || labels == nullptr || distances == nullptr) {
        throw invalid_argument("Invalid k size or null pointers supplied to ClassPredictor.");
    }

    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];

    for (int i = 0; i < k_size; ++i) {
  neighbor_labels[i] = labels[i];
  neighbor_distances[i] = distances[i];
    }
}

// Overloaded constructor for STL vectors
ClassPredictor::ClassPredictor(const vector<int>& labels, const vector<double>& distances) {
    if (labels.size() != distances.size() || labels.empty()) {
  throw invalid_argument("Labels and distances vectors must be equal in size and non-empty.");
    }

    k_size = static_cast<int>(labels.size());
    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];

    for (int i = 0; i < k_size; ++i) {
   neighbor_labels[i] = labels[i];
   neighbor_distances[i] = distances[i];
    }
}

// Copy Constructor (Deep Copy)
ClassPredictor::ClassPredictor(const ClassPredictor& other) : k_size(other.k_size) {
    neighbor_labels = new int[k_size];
    neighbor_distances = new double[k_size];

    for (int i = 0; i < k_size; ++i) {
   neighbor_labels[i] = other.neighbor_labels[i];
   neighbor_distances[i] = other.neighbor_distances[i];
    }
}

// Assignment Operator (Deep Copy)
ClassPredictor& ClassPredictor::operator=(const ClassPredictor& other) {
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
ClassPredictor::~ClassPredictor() {
    delete[] neighbor_labels;
    delete[] neighbor_distances;
}

// Predicts the final class label for a query point using frequency tallying and distance-based tie-breaking
int ClassPredictor::predict() const {
    map<int, int> vote_frequency;

    // Tally frequency votes using pointer traversal over the nearest neighbors
    for (int i = 0; i < k_size; ++i) {
   vote_frequency[neighbor_labels[i]]++;
    }

    int predicted_class = neighbor_labels[0]; 
    int max_votes = -1;
    vector<int> tied_classes;

    // Scan frequencies to identify winners and track any voting ties
    for (auto const& [class_label, count] : vote_frequency) {
  if (count > max_votes) {
  max_votes = count;
   predicted_class = class_label;
   tied_classes.clear();
  tied_classes.push_back(class_label);
   } else if (count == max_votes) {
   tied_classes.push_back(class_label);
   }
    }

    // If a voting tie occurs, resolve it using proximity (picking the class with the closest neighbor distance)
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
