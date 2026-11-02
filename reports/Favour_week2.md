1. Overview
The KNN selection module processes the sorted neighbor collection to isolate the top-$k$ nearest instances for downstream classification.
2. Architectural & Algorithmic Flow 
Parameter Validation: Receives the fully sorted list of neighbor structures and the target parameter $k$. 
Subset Extraction: Iterates through the ordered list up to $k$ indices (or up to the total available training size if $k$ exceeds dataset bounds) to extract the closest neighboring instances. 
Data Packaging: Forwards the isolated subset of nearest neighbors to the downstream voting mechanism. 
 3. Error Handling & Edge Cases
      	It safely handles scenarios where $k$ is greater than the total number of available training samples by clamping the selection limit to the dataset size.
4. AI use
AI tools were referenced for minor syntax checks and markdown formatting and the Core logic and implementation was done by me with help from my group members

