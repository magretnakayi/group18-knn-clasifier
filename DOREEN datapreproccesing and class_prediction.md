GROUP 18 – INDIVIDUAL WEEK 1 CONTRIBUTION REPORT

Member: NYAMWIIJA DOREEN
Group: 18
Project: Implementation of the K-Nearest Neighbors (KNN) Classification Algorithm Using C++
Week: 1
Assigned Tasks: Data Preprocessing and Class Prediction

1. Introduction

This report presents my individual contribution to the Group 18 Machine Learning project during Week 1. The project focuses on implementing the K-Nearest Neighbors (KNN) classification algorithm using C++.

My assigned tasks are data preprocessing and class prediction. Data preprocessing prepares the dataset for use by the algorithm, while class prediction determines the class of a new data point using information obtained from its nearest neighbors.

During the first week, I focused on understanding these concepts, identifying their main operations, and exploring how they can be implemented in C++.

2. Data Preprocessing

2.1 Definition

Data preprocessing is the process of cleaning, checking, and preparing raw data before it is used by a machine learning algorithm. It is important in KNN because the algorithm relies on distance calculations to identify the nearest data points. Poorly prepared data may lead to incorrect classifications.

2.2 Major Data Preprocessing Operations

The following operations were identified as important for preparing the dataset:

Handling missing values: Identifying missing feature values and deciding whether to remove affected records or replace the missing values using an appropriate method.

Checking duplicate records: Identifying repeated observations that may unnecessarily influence classification results.

Data validation: Checking that records contain the expected features and that numerical values and class labels are valid.

Data type consistency: Ensuring that numerical features and class labels are represented in suitable and consistent formats.

Preparing features and labels: Ensuring that each observation's features remain correctly associated with its corresponding class label.

Feature scaling is also important because features with larger numerical ranges can dominate distance calculations. Since scaling is assigned to another group member, my preprocessing component will coordinate with that component.

2.3 Proposed C++ Implementation

A dataset can be represented using a structure containing numerical features and a class label.

#include <string>
#include <vector>

struct DataPoint {
    std::vector<double> features;
    std::string label;
};

The structure stores the numerical features of an observation and its corresponding class label. Preprocessing functions can then inspect and prepare the records before they are used by the KNN algorithm.

3. Class Prediction

3.1 Definition

Class prediction is the process of assigning a class label to a new data point based on the labels of its nearest neighbors. In KNN, the nearest-neighbor search identifies the closest observations, and the prediction process uses their class labels to determine the most appropriate class.

3.2 How Class Prediction Works

The process involves the following steps:

Receive a new data point whose class is unknown.

Obtain the K nearest neighbors from the neighbor-search component.

Examine the class labels of the selected neighbors.

Use the voting results to determine the predicted class.

Return the predicted class label.

For example, suppose the three nearest neighbors of a new data point have the following labels:

Neighbor

Class

Neighbor 1

A

Neighbor 2

A

Neighbor 3

B

Class A receives two votes, while Class B receives one vote. Therefore, the predicted class is Class A.

3.3 Proposed C++ Implementation

A possible function interface for class prediction is:

#include <string>
#include <vector>

std::string predictClass(
    const std::vector<std::string>& neighborLabels
);

The function is intended to receive the labels of the selected neighbors and return the predicted class. Its final implementation will depend on the common interfaces agreed upon by the group.

The function will coordinate with the members responsible for nearest-neighbor search, majority voting, and tie handling.

4. Progress Achieved During Week 1

During Week 1, I focused on researching and understanding my assigned components. The progress made included:

Understanding the importance of data preprocessing in machine learning.

Identifying common data quality problems and methods of handling them.

Understanding how KNN uses the labels of nearest neighbors to predict a class.

Identifying the expected inputs and outputs of the assigned components.

Exploring suitable C++ data structures and possible function interfaces.

This work provides a foundation for implementing the assigned components in the following weeks.

5. Challenges Identified

The main challenges identified include:

Handling missing, invalid, or inconsistent data without unnecessarily losing useful information.

Coordinating the preprocessing component with feature scaling and other components.

Ensuring that class prediction correctly uses the results from neighbor selection and voting.

Agreeing on common function interfaces and data structures to avoid integration errors.

These challenges will be addressed through further research, communication with group members, and systematic testing.

6. Plans for Week 2

During Week 2, I plan to:

Begin implementing the data preprocessing functions in C++.

Develop checks for missing and invalid data.

Begin implementing the class prediction function.

Coordinate with the relevant group members to agree on common interfaces.

Develop test cases to verify the correctness of both components.

Integrate and review the completed functions with the rest of the project.

7. Conclusion

During Week 1, I developed an understanding of data preprocessing and class prediction in the KNN classification algorithm. Data preprocessing ensures that the dataset is suitable for analysis, while class prediction uses the labels of the nearest neighbors to classify a new observation.

The knowledge gained provides a foundation for implementing and testing my assigned components in C++. Successful integration will require coordination with other group members and proper verification of the results.

8. Declaration on the Use of Artificial Intelligence

AI tools were used as reference assistants to clarify data preprocessing, class prediction, and unfamiliar C++ concepts, and to help organize this report. The concepts and code examples will be reviewed and verified during implementation.
