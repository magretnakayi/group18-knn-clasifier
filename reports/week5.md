

Week 5 Report

 Testing and examples of the last 7 modules
1. Overview
This week’s report details the comprehensive testing, driver programs, and metric evaluations for the last parts of our project i.e Majority Voting, Tie Handling, Class Prediction, Hyperparameter Selection, Model Evaluation, Confusion Matrix, and Precision/Recall/F1-Score analysis. The overall pipeline emphasizes memory safety through low-level pointer management, object-oriented abstractions, explicit edge-case defense, and reliable performance diagnostics.


2. Team Contributions
2.1 Majority Voting & Tie Handling
Contributor: Nakayi Magret
Implementation Details:
Majority Voting: Plurality calculation engine that aggregates frequency counts among $k$-nearest neighbor labels using custom dynamic arrays and dynamic memory allocation.
Tie Handling: Provides a distance-based fallback mechanism when multiple candidate classes receive equal votes, preventing classification blind spots and maintaining high algorithmic consistency.
Testing & Driver Mechanics: Primary execution drivers establish ambiguous voting scenarios and pass sample neighbor arrays. Automated unit tests (assert) verify that winning classes match expected outputs under both normal and tied conditions.
Error Handling: Verifies that $k > 0$ and checks for nullptr across both label and distance arrays. Throws std::invalid_argument for dimension conflicts or allocation failures, safely caught within driver blocks.
2.2	Class Prediction
Contributor: Nyamwiija Doreen
Translates geometric neighborhood data (labels and spatial distances) into definitive class predictions. Accepts both raw pointer arrays (int*, double*) and standardized containers (std::vector). Dynamically allocates memory based on runtime $k$. Iterates through neighbor labels via pointer traversal, accumulating vote tallies into associative structures (std::map<int, int>). In the case of deadlocks, it triggers proximity-based tie resolution by evaluating underlying Euclidean distances to award the classification to the geometrically closest candidate
Error Handling: Validates parameters upon construction, throwing std::invalid_argument if null pointers are supplied, if $k \le 0$, or if vector/array dimensions do not match.

2.3 Hyperparameter Selection
Contributor: Ssewagudde Jason Samuel
Implementation Details:
Automates the model-tuning phase by systematically identifying the optimal value of $k$. Iterates through candidate k arrays, evaluates performance over validation coordinate matrices, and selects the hyperparameter value that maximizes classification accuracy.
Testing & Driver Mechanics
 Driver scripts feed training, validation splits, and candidate arrays into the selector. Unit tests confirm that candidate filtering correctly isolates the top-performing k.
Error Handling
Validates candidate array pointers, checks candidate counts (> 0), and ensures validation sample counts are valid, throwing std::invalid_argument upon misconfiguration.
2.4 Model Evaluation
Contributor: Nkangula Abdul Latif
Implementation Details
Inherits from an abstract base class EvaluationMetric (overriding calculate() and displayReport()). Evaluates trained model predictions against unseen test datasets via pointer traversal to compute overall percentage accuracy.
Testing & Driver Mechanics
 Coordinates dataset splits, predictor instantiation, and summary output reporting via std::cout. Unit tests verify that baseline clean splits meet performance thresholds (e.g., 100% accuracy on ideal sets).
Error Handling
Performs null check validation on test data pointers. Implements division-by-zero protection, returning 0.0 accuracy and logging clear warnings if empty test splits are encountered.
 2.5 Confusion Matrix Diagnostics
Contributor: Namukisa Favour E. Kiwuso
Implementation Details:
Constructs a multi-class confusion matrix grid allocated on the heap. Tracks binary and multi-class outcomes—True Positives (TP), True Negatives (TN), False Positives (FP), and False Negatives (FN)—to provide intuitive visual performance tracking and error analysis.
Testing & Driver Mechanics
 Includes dedicated unit testing asserting that diagonal matrix totals equal total correct predictions, alongside standalone example scripts printing formatted performance grids.
Error Handling
Enforces strict boundary validation (0 <= label < num_classes) to eliminate out-of-bounds array access. Throws std::out_of_range if invalid label indices are supplied
2.6 Precision, Recall & F1-Score
Contributor: Kasule Juma Kasujja
Implementation Details:
	Extends EvaluationMetric to compute detailed statistical performance metrics Precision,) and the harmonic mean score
Testing & Driver Mechanics
 Driver and test routines compare computed precision, recall, and F1 values against hand-calculated mathematical baselines.
Error Handling
 Implements explicit zero-denominator protection prior to division operations, defaulting metrics to 0.0 to avoid program crashes or NaN values, alongside strict input pointer validation.

3. Challenges Faced and Technical Solutions
3.1	Manual Resource & Pointer Management in Polymorphic Hierarchies
Challenge: Managing dynamic heap pointers across polymorphic inheritance hierarchies created potential risks of memory leaks, dangling pointers, and double-free exceptions.
Solution: Applied the Rule of Three universally across all heap-managing classes (Class Predictor, Model Evaluation, Confusion Matrix, etc.), ensuring explicit deep copies and clean destructors.

3.2	Voting Ties & Classification Deadlocks
Challenge: Equal vote tallies among multiple candidate classes could lead to non-deterministic predictions.
Solution: Designed a deterministic spatial proximity check within the Tie handling and Class Prediction modules, scanning parallel distance arrays to resolve ties using the minimum Euclidean distance neighbor.
3.3	Input Boundary Security
Challenge: Out-of-bounds indices or null pointers passed into dynamic neighbor or confusion matrix arrays.
Solution: Introduced mandatory input validation upon class construction and method invocation, enforcing scalar checks ($k > 0$, label range checks) and throwing standardized C++ exceptions (std: invalid argument, std:out_of_range).

4. Conclusion
The Week 5 finalization of the KNN Classifier Subsystem successfully delivers a robust, modular, and memory-safe C++ architecture. By pairing dynamic memory management (Rule of Three) with low-level algorithmic logic—spanning plurality voting, Euclidean tie resolution, hyper parameter optimization, and deep performance metric evaluation (Confusion Matrix, Precision/Recall/F1)—the system provides accurate, crash-resistant, and verifiable classification capabilities.


5. AI Declaration
AI assistance was utilized to aid in understanding structural interactions between modules, guiding safe C++ heap memory patterns (Rule of Three), troubleshooting minor compilation errors

