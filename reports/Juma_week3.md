1. Objective

This week I wrote the main script, usage example, and unit tests for the KNN Search module of our group’s C++ K-Nearest Neighbors project. These build on our dataset loader and distance metrics, and check that distances are computed and sorted correctly into Neighbor objects.

2. What I Did
Main script (src/knnsearch_main.cpp): Loads the dataset, runs findNearestNeighbors on a query vector, and prints the distances and labels.
Example (examples/example_knnsearch.cpp): A short standalone example showing teammates how to use the search function.
Unit tests (tests/test_knnsearch.cpp): Uses simple coordinate data and assert to check that neighbors are sorted correctly and labels are right.
Folder structure: Kept files organized in src/, tests/, and examples/ for clean version control on GitHub.

3. Challenges and Solutions
Function naming: The distance function (calculateEuclideanDistance) had to match our dataset’s vector format. I fixed this by checking the header includes and parameter types.
Compiling multiple files: Building several source files together caused path problems. I solved this by using -Iinclude and compiling from the project root.

4. Tools Used
Language: C++17
Compiler: g++ (MinGW-w64)
Environment: VS Code on Windows, Git Bash / PowerShell
Version control: Git and GitHub
5. Results

I compiled with this command from the project root:

g++ src/knnsearch_main.cpp src/knn_search.cpp src/dataset.cpp src/distance.cpp -Iinclude -o knnsearch_main.exe

Running ./knnsearch_main.exe printed the nearest neighbors in order, along with their distances and class labels.

6. Next Week
I will work on the evaluation metrics for our classifier: precision, recall, and F1 score. These will let us measure how well the KNN predictions match the true labels.

7. AI Declaration
I used AI to help with lambda sorting syntax and to check the multi-file compile flags.
All other work was done, tested, and approved by me and my group members.
8. Conclusion

The KNN search main script, example, and unit tests are finished and working. All tests pass, giving us a reliable base for the classifier.