#ifndef MAJORITYVOTING_HPP
#define MAJORITYVOTING_HPP

#include <vector>
#include "dataset.hpp" 
class MajorityVoting {
private:
    int* neighbor_labels;      // Pointer array for neighbor class labels
    double* neighbor_distances; // Pointer array for neighbor distances (used for tie-breaking)
    int k_size;                // Number of neighbors (k parameter)

public:
    // Constructor taking raw pointers (labels and distances)
    MajorityVoting(const int* labels, const double* distances, int k);

    // Direct Constructor taking your dataset's DataPoint vector and corresponding distances (extracted from dataset.csv)
    explicit MajorityVoting(const std::vector<DataPoint>& nearest_neighbors, const std::vector<double>& distances);

    // Rule of Three: Deep copy constructor and assignment operator for safe pointer management
    MajorityVoting(const MajorityVoting& other);
    MajorityVoting& operator=(const MajorityVoting& other);

    // Destructor to safely clean up pointer memory on the heap
    ~MajorityVoting();

    // Core prediction method implementing frequency voting and distance-based tie handling
    int predictClass() const;
};

#endif // MAJORITY_VOTING_HPP
