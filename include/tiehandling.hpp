#ifndef TIEHANDLING_HPP
#define TIEHANDLING_HPP

#include <vector>
#include "dataset.hpp" 

class TieHandler {
private:
    int* neighbor_labels;      // Pointer array storing the neighbor class labels
    double* neighbor_distances; // Pointer array storing corresponding neighbor distances
    int k_size;                // Number of neighbors (k)

public:
    // Constructor taking raw pointers to labels, distances, and k size
    TieHandler(const int* labels, const double* distances, int k);

    // Direct Constructor taking dataset's DataPoint vector and corresponding distances (extracted from dataset.csv)
    explicit TieHandler(const std::vector<DataPoint>& nearest_neighbors, const std::vector<double>& distances);

    // Rule of Three: Deep copy constructor and assignment operator for safe pointer management
    TieHandler(const TieHandler& other);
    TieHandler& operator=(const TieHandler& other);

    // Destructor to clean up heap-allocated pointer arrays safely
    ~TieHandler();

    // Resolves voting ties by picking the tied class with the minimum distance neighbor from dataset records
    int breakTie(const std::vector<int>& tied_classes) const;
};

#endif // TIE_HANDLER_HPP
