GROUP 18 WEEK 1 REPORT
TITLE
 Implementation of the K-Nearest Neighbors (KNN) Classification Algorithm Using C++  
 1.0 Introduction
This report presents the progress made by Group 18 during the first week of the Machine Learning project. The project focuses on implementing the K-Nearest Neighbors (KNN) classification algorithm using C++.
KNN is a supervised machine learning algorithm that classifies a new data point based on the classes of its nearest neighbors in a dataset. The algorithm involves several stages, including dataset loading, data preprocessing, feature scaling, distance calculation, neighbor selection, class prediction, and model evaluation.
During the first week, the group focused on understanding the project requirements, allocating tasks among members, establishing an initial project directory structure, and planning the implementation process. These activities provide a foundation for the development, integration, and testing of the classification algorithm.
2.0 Objectives
1. To understand the principles and operation of the K-Nearest Neighbors algorithm.
2. To identify the major components required to implement KNN using C++.
3. To allocate responsibilities among group members.
4. To establish an organized project directory structure for managing source code, header files, datasets, tests, and reports.
5. To plan the implementation and integration of the individual algorithm components.
6. To identify appropriate measures for evaluating the performance of the completed model.
3.0 Activities Undertaken
3.1 Understanding the KNN Algorithm
                  The group identified the main stages involved in implementing the KNN classification algorithm. These include loading the dataset, preprocessing the data, scaling the features, calculating distances, selecting the nearest neighbors, searching for the K nearest neighbors, performing majority voting, handling ties, predicting classes, and evaluating the model.
                The group also recognized the importance of selecting an appropriate value of K because it influences the classification results. Hyperparameter selection will be addressed during model development and evaluation.
 3.2 Allocation of Project Tasks
          To promote teamwork and ensure that all major components of the algorithm are covered, the project was divided into thirteen parts and allocated among the six group members.
Group Member	Parts to handle
Nakayi Magret	 Dataset loading, Majority voting, Tie handling
Nyamwiiza Doreen	 Data preprocessing, Class prediction
Ssewagudde Jason Samuel	 Feature scaling, Hyperparameter selection
Nkangula Abdul Latif	Distance calculation, Model evaluation
Namukisa Favour E. Kiwuso	Neighbor selection, Confusion matrix
Kasule Juma	K-nearest neighbors search,  Precision, Recall, and F1-score

              This allocation establishes individual responsibilities and provides a basis for monitoring each member's contribution. Members will coordinate their work to ensure that the individual components can be integrated into one functional KNN program.
3.3 Establishment of the Project Directory Structure
                 The group established an initial project directory structure to organize the files required for developing the KNN classification algorithm using C++. The structure separates different categories of project files to improve organization, simplify development, and support future testing and documentation.
       Repository folder structure created was as below with their functions:
	Group18-KNN: This our major folder that contained the following sub folders and file.
	.Vscode: Contains project-specific Visual Studio Code configuration files.
	Examples: Stores example programs and demonstrations related to the project.
	Include: Stores C++ header files containing declarations, function prototypes, and shared definitions.
	Reports: Stores project reports and other documentation.
	Root directory: Contains files organized under this directory; its specific purpose depends on its contents.
	Src: Stores C++ source files implementing the different components of the KNN algorithm.
	Tests: Stores test programs and test cases used to verify the correctness of the implementation.
	Dataset: Represents the dataset file intended for use in developing and evaluating the classification model.
The directory structure provides a starting point for organizing source code, supporting files, test cases, and documentation as the project progresses. The contents of each directory will be expanded as the relevant components are implemented.
 3.4 Planning the Implementation
                  The group identified C++ as the programming language for implementing the KNN algorithm. The implementation will be divided into manageable components corresponding to the tasks assigned to individual members.
                     The development process will involve preparing the dataset, implementing distance calculations, identifying the nearest neighbors, predicting the class of a new data point, and evaluating the model.
                The group also recognized the importance of agreeing on common function interfaces, data structures, and naming conventions to simplify the integration of code written by different members.
3.5 Identification of Evaluation Measures
                  The group identified the confusion matrix, precision, recall, and F1-score as important measures for evaluating the classification model.
                    The confusion matrix will summarize correct and incorrect predictions. Precision will measure the proportion of positive predictions that are correct, while recall will measure the proportion of actual positive cases correctly identified. The F1-score will combine precision and recall into a single measure.
                   These measures will be used to assess the model's performance after implementation and testing.
4.0 Progress Achieved During Week 1
      The main progress made during the first week was establishing the organizational foundation for the project.
     The group identified the main stages of the KNN algorithm and allocated responsibilities for the thirteen project components among the six members. An initial project directory structure was also established to organize the development environment, examples, header files, reports, source code, tests, and dataset.
     In addition, the group identified the intended evaluation measures and outlined the activities required for implementation.
        At the end of Week 1, the project had an initial directory structure and a task allocation plan to guide further development. The implementation status of individual algorithm components will be documented as the group completes and tests them.
 5.0 Challenges Identified
            The group identified several challenges that may arise during the implementation process.
1.	Each member needs to understand the mathematical and programming concepts associated with their assigned component to ensure that it is implemented correctly.
2.	The dataset must be properly formatted, loaded, and checked for missing or unsuitable values before it can be used reliably.
3.	Features with different numerical ranges may affect distance calculations. Appropriate scaling will therefore be considered during preprocessing.
4.	Because the project is divided among several members, differences in function definitions, data structures, and naming conventions may cause integration difficulties.
5.	The group must verify that distance calculations, neighbor selection, class predictions, and evaluation metrics produce correct results.
The group intends to address these challenges through communication, individual research, code reviews, testing, and coordinated integration.
Plans for Week 2
During the second week, the group plans to move from initial project organization towards implementation.
The planned activities are:
1)	Inspect and prepare the dataset for use in the KNN algorithm.
2)	Review the project directory structure and ensure that files are stored in appropriate locations.
3)	Begin implementing the components assigned to individual members.
4)	Develop and test the distance calculation and feature scaling components.
5)	Establish common interfaces for communication between source files.
6)	Write test cases to verify the correctness of individual functions.
7)	Coordinate the integration of completed components.
8)	Update the project documentation and record progress.
9)	Review each member's contribution and identify any difficulties requiring further attention.
These activities will help the group progress towards developing a functional KNN classification program.
7.0 Conclusion
       During Week 1, Group 18 established the foundation for implementing the K-Nearest Neighbors classification algorithm using C++. The group identified the main stages of the algorithm, allocated responsibilities among the six members, created an initial project directory structure, and identified the measures that will be used to evaluate the model.
                   The directory structure provides a starting point for organizing source code, header files, datasets, tests, examples, and reports. The task allocation also establishes individual responsibilities and supports coordinated development.
                           The next stage will focus on dataset preparation, implementation of the assigned components, and testing. Effective teamwork, proper documentation, and systematic verification will be essential for developing a functional KNN classification program.
8.0 Declaration on the Use of Artificial Intelligence
AI tools were used as a reference assistant to help understand the project, unfamiliar C++ concepts and debug syntax rules.
