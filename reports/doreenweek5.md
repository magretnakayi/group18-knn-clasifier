 Overview
The class prediction module is a Core KNN calculation engine that computes Euclidean distances, sorts neighbors, and delegates final label assignment.
2. Implementation Mechanics
Classprediction_main.cpp: The core prediction driver that initializes a training dataset on the heap, passes it to the predictor, and classifies an unseen test query point.
example_class_predictor.cpp: Standalone demonstration of single-point coordinate classification.
test_class_predictor.cpp: Unit test confirming that known geometric coordinate clusters classify into their correct expected labels.
3. Error Handling
Data Validation: Verifies training data pointers and feature dimensions upon initialization.
Dimension Safety: Throws std::invalid_argument or std::domain_error if query coordinate widths do not match training feature dimensions.
4. Conclusion
Serving as the computational core of the toolkit, the Class Predictor successfully integrates distance calculation, neighbor sorting, and strict memory safety via Rule-of-Three compliance, ensuring stable execution across datasets.


