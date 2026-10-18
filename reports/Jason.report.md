 1. Overview
The feature scaling module applies Min-Max normalization to standardize numerical attribute ranges, preventing features with larger absolute scales from dominating distance computations.
2. Architectural & Algorithmic Flow
Column-Wise Scan: Iterates across every feature index across all dataset rows to independently determine the global minimum ($min$) and maximum ($max$) values for each individual feature dimension.
Normalization Formula: Transforms each feature value ($x$) into a standardized range between $0.0$ and $1.0$ using the scaling equation.
Vector Transformation: Updates the internal feature vectors of all `DataPoint` objects in place with their normalized floating-point equivalents.
 3. Error Handling & essential Cases 3
Division-by-Zero Prevention: Implements conditional checks to detect constant feature columns where scaled values to $0.0$ to prevent floating-point exceptions.

4. Next Week Integration Plans
      Integration: Sequence scaling immediately after preprocessing in `main.cpp` to ensure training and test distributions are properly normalized.
     Test: Write assertions to verify that output feature values strictly fall within the $[0.0, 1.0]$ boundary as well as including relevant examples
Ai declaration
    AI tools were referenced solely for minor syntax checks and markdown formatting. Core logic and implementation authored by Group 18.
