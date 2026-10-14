Week 2 Report
 Data Preprocessing Module
Overview
For this week, I developed the data preprocessing module for our team's K-Nearest Neighbors (KNN) C++ project. Because KNN relies heavily on distance metrics, unnormalized features with larger numerical ranges would unfairly dominate the distance calculations. This module applies Min-Max normalization to scale all feature values between `0.0` and `1.0`.
Implementation Details
                 Min-Max Scaling (`normalizeDataset`):    Takes a reference to a `vector<DataPoint>` so it modifies the loaded data directly, Iterates dynamically through each feature column independently,  Safely handles edge cases where maximum and minimum values are identical to prevent division by zero.
                   Modularity: Kept separate in `include/preprocessing.hpp` and `src/preprocessing.cpp` so it integrates smoothly with our existing `dataset.hpp` architecture.
Next Steps
With the data preprocessing backend fully written and verified, next week's focus will involve wiring up the execution harness (`main.cpp`), adding unit tests, and creating usage examples for the rest of the team.
