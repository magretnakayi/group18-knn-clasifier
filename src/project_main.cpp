#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <exception>

#include "dataset.hpp"
#include "datapreprocessing.hpp"
#include "distance.hpp"
#include "knnsearch.hpp"
#include "knnselection.hpp"
#include "Hyperparameterselector.hpp"
#include "modelevaluation.hpp"
#include "ConfusionMatrix.hpp"
#include "PrecisionRecallF1.hpp"

using namespace std;

int main()
{
    try
    {
        cout << "\n";
        cout << "================================================\n";
        cout << "             GROUP 18 KNN CLASSIFIER\n";
        cout << "================================================\n";

        // 1. DATASET LOADING
        cout << "\n1. DATASET LOADING\n";

        vector<DataPoint> dataset = loadCSV("dataset.csv");

        if (dataset.empty())
        {
            cout << "Error: Could not load dataset.csv\n";
            return 1;
        }

        if (dataset.size() < 5 || dataset[0].features.empty())
        {
            cout << "Error: Insufficient dataset records or features.\n";
            return 1;
        }

        cout << "Dataset loaded successfully.\n";
        cout << "Total records: " << dataset.size() << endl;
        cout << "Number of features: "
             << dataset[0].features.size() << endl;


        // 2. DATA PREPROCESSING
        cout << "\n2. DATA PREPROCESSING\n";

        cout << "First feature before preprocessing: "
             << dataset[0].features[0] << endl;

        normalizeDataset(dataset);

        cout << "First feature after preprocessing: "
      << dataset[0].features[0] << endl;

        cout << "Preprocessing completed.\n";


        // 3. SHUFFLE DATASET
        mt19937 rng(42);
        shuffle(dataset.begin(), dataset.end(), rng);


        // 4. SPLIT DATASET
        cout << "\n3. DATASET SPLITTING\n";

        size_t trainSize = dataset.size() * 60 / 100;
        size_t validationSize = dataset.size() * 20 / 100;

        if (trainSize == 0 || validationSize == 0 ||
            trainSize + validationSize >= dataset.size())
        {
            cout << "Error: Dataset is too small to split.\n";
            return 1;
        }

        vector<DataPoint> trainData(
            dataset.begin(),
            dataset.begin() + trainSize
        );

        vector<DataPoint> validationData(
            dataset.begin() + trainSize,
            dataset.begin() + trainSize + validationSize
        );

        vector<DataPoint> testData(
            dataset.begin() + trainSize + validationSize,
            dataset.end()
        );

        cout << "Training records: " << trainData.size() << endl;
        cout << "Validation records: " << validationData.size() << endl;
        cout << "Testing records: " << testData.size() << endl;


        // 5. DISTANCE CALCULATION
        cout << "\n4. DISTANCE CALCULATION\n";

        double distance =
            DistanceCalculator::calculateEuclideanDistance(
                trainData[0], trainData[1]
            );

        cout << fixed << setprecision(4);
        cout << "Euclidean distance between two training records: "
             << distance << endl;


        // 6. HYPERPARAMETER SELECTION
        cout << "\n5. HYPERPARAMETER SELECTION\n";

        vector<int> kCandidates = {1, 3, 5};

        HyperparameterSelector selector(kCandidates);

        int bestK = selector.optimizeK(
            trainData, validationData
        );

        if (bestK <= 0)
        {
            cout << "Error: Invalid K value selected.\n";
            return 1;
        }

        bestK = min(bestK, static_cast<int>(trainData.size()));

        cout << "Optimal K selected: " << bestK << endl;


        // 7. KNN CLASSIFICATION AND PREDICTION
        cout << "\n6. KNN CLASSIFICATION\n";

        vector<int> actualLabels;
        vector<int> predictedLabels;

        for (const auto& query : testData)
        {
            vector<Neighbor> neighbors =
                findNearestNeighbors(trainData, query.features);

            if (neighbors.empty())
            {
                cout << "Error: No neighbours found.\n";
                return 1;
            }

            int currentK = min(
                bestK,
                static_cast<int>(neighbors.size())
            );

            // Majority voting and neighbour selection
            int prediction =
                selectMajorityLabel(neighbors, currentK);

            actualLabels.push_back(query.label);
            predictedLabels.push_back(prediction);
        }

        cout << "Classification completed.\n";
        cout << "Test records classified: "
             << actualLabels.size() << endl;


        // 8. MODEL EVALUATION
        cout << "\n7. MODEL EVALUATION\n";

        ModelEvaluator evaluator(actualLabels, predictedLabels);

        double accuracy =
            evaluator.calculate(actualLabels, predictedLabels);

        evaluator.displayReport(actualLabels, predictedLabels);

        cout << "Calculated accuracy: "
             << accuracy * 100 << "%\n";


        // 9. CONFUSION MATRIX
        cout << "\n8. CONFUSION MATRIX\n";

        ConfusionMatrix confusionMatrix(
            actualLabels, predictedLabels
        );

        confusionMatrix.printMatrix();

        confusionMatrix.computeAndDisplay(1);

        cout << "Confusion matrix accuracy: "
             << confusionMatrix.getAccuracy() * 100
             << "%\n";


        // 10. PRECISION, RECALL AND F1-SCORE
        cout << "\n9. PRECISION, RECALL AND F1-SCORE\n";

        PrecisionRecallF1 metrics(
            actualLabels,
            predictedLabels,
            1
        );

        metrics.displayReport(actualLabels, predictedLabels);

        cout << fixed << setprecision(4);

        cout << "Precision: "
             << metrics.calculatePrecision() << endl;

        cout << "Recall: "
             << metrics.calculateRecall() << endl;

        cout << "F1-score: "
             << metrics.calculateF1Score() << endl;


        // 11. FINAL RESULTS
        cout << "\n";
        cout << "================================================\n";
        cout << "             FINAL CLASSIFICATION RESULTS\n";
        cout << "================================================\n";

        cout << "Selected K: " << bestK << endl;
        cout << "Test samples: " << testData.size() << endl;
        cout << "Accuracy: " << accuracy * 100 << "%\n";
        cout << "Precision: " << metrics.calculatePrecision() << endl;
        cout << "Recall: " << metrics.calculateRecall() << endl;
        cout << "F1-score: " << metrics.calculateF1Score() << endl;

        cout << "================================================\n";
        cout << "          KNN PROGRAM COMPLETED SUCCESSFULLY\n";
        cout << "================================================\n";

    }
    catch (const exception& e)
    {
        cout << "\nProgram error: " << e.what() << endl;
        return 1;
    }

    return 0;
}