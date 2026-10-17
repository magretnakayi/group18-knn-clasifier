                                                  1. Overview
The KNN search module evaluates geometric proximity across all training instances relative to a given query point, producing a sorted neighbor hierarchy.

 2. Implementation Details
    	 Dataset Iteration: Scans through every sample instance in the training dataset repository.
Metric Invocation: Calls the distance calculation module to compute the exact distance from the query point to each training sample.
Pair Binding: Packages computed distances alongside their corresponding class labels into lightweight custom `Neighbor` structures.
Proximity Sorting: Sorts the resulting collection of neighbors in ascending order using custom comparator logic, ensuring the closest instances appear at the beginning of the list.
3. Error handling
    	Manages empty training sets gracefully by returning an empty neighbor collection to prevent segmentation faults during lookup.
4. AI importance
AI tools were referenced during the modulation of my program and handled minor syntax errors

                                                                                                                                                                                                                                                               