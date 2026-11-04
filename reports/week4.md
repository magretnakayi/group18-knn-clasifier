KNN CLASSIFIER SUBSYSTEMS MODULATION REPORT
1. Overview
This week we handled the last 7 parts of the project that is majority voting, tie handling, class prediction, hyperparameter selection, model evaluation, confusion matrix, Precision Recall and F1where we started with the modulation part. We majorly made use of classes, pointers and arrays during the design of most parts

2. Implementation and Design
Majority Voting: This was handled by Nakayi Magret
	majorityvoting.hpp Design: Declares vote frequency aggregation structures and helper method signatures (e.g., mapping neighbor labels to frequency counts).
	majorityvoting.cpp Design: Implements traversal of $k$-nearest neighbor labels using pointer/vector iteration, accumulating vote counts into an associative std::map<int, int> to determine the plurality winner.
Tie Handling: This was handled by Nakayi Magret
	tiehandling.hpp Design: Declares deadlock detection signatures and proximity resolution checks for handling multi-class vote ties.
	tiehandling.cpp Design: Implements logic to detect when multiple candidate classes achieve identical maximum votes, scanning parallel distance arrays to find the tied candidate with the closest neighbor distance.
Class Prediction: This was handled by Nyamwiija Doreen
	Classprediction.hpp Design: Declares core prediction class structure, raw heap pointers (int* labels, double* distances, int size), constructors (raw arrays & vectors), and Rule of Three members (~ClassPredictor(), copy ctor, operator=).
	classprediction.cpp Design: Implements deep copy memory management, input validation, coordinates neighbor data ingestion, orchestrates voting/tie-breaking routines, and returns the final verified class label.
Hyperparameter Selection: this was handled by Ssewagudde Jason Samuel
	hyperparameter_selection.hpp: Declares candidate $k$ array storage, validation data pointers, Rule of Three methods, and optimization function interfaces.
	Hyperparameter_selection.cpp Design: Iterates through candidate $k$ values, partitions validation data, integrates distance calculations, and invokes prediction/evaluation routines to identify the optimal hyperparameter $k$.
Model Evaluation: This was handled by Nkangula Abdul Latif
	modelevaluation.hpp Design: Inherits from abstract base class EvaluationMetric. Declares polymorphic overrides for calculate() and displayReport(), heap label arrays, and Rule of Three support.
	modelevaluation.cpp Design: Implements deep copy lifecycle, computes overall classification accuracy via pointer traversal comparing actual vs. predicted labels, and outputs performance summaries.
Confusion Matrix: This was handled by Namukisa Favour E. Kiwuso
	confusionmatrix.hpp Design: Declares heap pointer arrays for actual and predicted labels, dataset size tracker, constructors supporting raw arrays and vectors, Rule of Three, and computeAndDisplay().
	confusionmatrix.cpp Design: Implements deep copy management, iterates through arrays using pointer indexing, and tallies binary classification outcomes: True Positives (TP), True Negatives (TN), False Positives (FP), and False Negatives (FN).
Precision, Recall & F1: This was handled by Kasule Juma Kasujja
	precisionrecallF1.hpp Design: Inherits from EvaluationMetric. Declares target class tracking, polymorphic overrides, Rule of Three, and specialized accessors (calculatePrecision(), calculateRecall(), calculateF1Score()).
	precisionrecallF1.cpp Design: Implements deep copy management, computes contingency counts, evaluates precision (TP / [TP + FP]) and recall (TP / [TP + FN]), derives the harmonic mean F1-score, and includes zero-division safeguards.
3. Challenges Faced and Solutions
The major challenge was developing a modular, high-performance C++ classification system required bridging the complexity of low-level manual resource management with robust algorithmic execution. Specifically, managing raw heap pointers across polymorphic inheritance hierarchies while executing complex spatial data operations such as majority voting, distance tie-resolution, and multi-metric evaluations exposed significant risks of memory leaks, segmentation faults, and runtime data corruption.
This was solved through the following structural design in different parts:
	Enforcing the Rule of Three universally across all heap-managing classes to guarantee independent memory ownership and eliminate double-free errors.
	Utilizing parallel array and vector structures to maintain separation of concerns, successfully tracking computed distances alongside labels without altering foundational data structs.
	Implementing a deterministic distance-based tie-breaking mechanism that inspects spatial proximity to resolve voting deadlocks cleanly.
	Applying defensive input validation and explicit zero-denominator safety checks across all evaluation modules to prevent runtime crashes.


4. Next Week's Plans
Next week we shall implement dedicated tests and examples with synthetic neighbor sets and edge-case voting splits to rigorously verify correct frequency tallying using DataPoint structures extracted from dataset.csv as well developing the primary driver program (main.cpp) for all these parts of our project
5. Conclusion
The implementation of the KNN classifier architecture successfully establishes a modular, memory-safe, and object-oriented pipeline. By combining robust heap lifecycle management with explicit majority voting, spatial tie-resolution, hyperparameter tuning, and polymorphic evaluation metrics, the system delivers reliable and mathematically sound classification performance.


6. AI Declaration
AI tools were used to help understand how these specific project parts function and how to link them together, which guided the implementation, memory safety design, and structure of the pipeline.
It also aided in correcting minor syntax errors 

