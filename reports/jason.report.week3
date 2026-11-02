Feature scaling implementation (Data Preprocessing module)

1. Overview and Objective
This week I worked on the feature scaling part of the Data Preprocessing module (Part B) of our group’s modular C++ K-Nearest Neighbors (KNN) project. KNN depends on distance calculations, so features with large values would dominate features with small values. Scaling puts all features on a comparable range before classification.

2. What Was Accomplished
•	Min-Max Normalization (minMaxNormalize): Rescales each feature to the range [0, 1] using x′ = (x − min) / (max − min).
•	Standard Scaling (standardScale): Rescales each feature to have a mean of 0 and a standard deviation of 1 using z = (x − μ) / σ.
•	Integration: Both functions are called through the DataPreprocessor class and work directly on the dataset (a vector of DataPoint), so other team members can apply them with a single call after loading the CSV.

3. Tools and Environment Used
•	Language: C++17 (std::vector, std::iostream)
•	Compiler: g++ (MinGW-w64 toolchain)
•	Environment: Visual Studio Code on Windows, Git Bash / PowerShell, with Git and GitHub for version control

4. Verification
The scaling was checked in two ways. A unit test runs Min-Max normalization on the values 10, 20 and 30 and confirms they become 0.0, 0.5 and 1.0. The main verification script also prints the first feature value before preprocessing, after Min-Max normalization and after Standard Scaling, and it ran without runtime errors.

5. Next Week’s Plans
After successfully finalizing the feature scaling, examples, and tests, I will move on to the next major phase of our KNN pipeline: implementing the hyperparameter selection

6. AI Declaration
[Write here what AI was used for in the scaling code, or state that none was used.] The rest of the work was done and approved by me and my group members.

7. Conclusion
Min-Max Normalization and Standard Scaling are implemented and working through the DataPreprocessor class. Min-Max is covered by a passing unit test, and Standard Scaling is confirmed through the printed output. The scaled data is ready for the distance calculations in the next phase.
