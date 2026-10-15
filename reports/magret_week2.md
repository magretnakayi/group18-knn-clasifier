WEEK 2  REPORT ABOUT DATASET LOADING
 1. Overview
     The dataset loading module is responsible for robust file parsing and raw data ingestion from persistent storage into structured C++ data representations (`DataPoint`). 
2. Architectural & Algorithmic Flow
      File Stream Handling: Opens the target CSV file utilizing `std::ifstream`, incorporating validation checks to detect missing or inaccessible files immediately.
      Header Management: Automatically detects and skips the initial header row to prevent non-numerical string evaluation errors.
    Tokenization & Parsing: Reads the file line-by-line, utilizing `std::stringstream` to split comma-separated values (CSV) into discrete text tokens.
    Type Conversion: Converts string tokens into numerical floating-point attributes (`double`) for features and integer identifiers for target class labels, packaging them into structured `DataPoint` instances.
 3. Error Handling & Edge Cases
	It handles malformed rows or missing delimiter fields by logging appropriate error messages to standard error (`std::cerr`).
	Ensures vector memory is pre-allocated where possible to optimize parsing performance over large datasets
4. Next week’s plans
	Pipeline Integration: Connect file loading directly to `main.cpp` to ingest real-world CSV datasets at runtime. 
	Test Harness: Develop unit tests to verify proper handling of missing files, malformed rows, and header skipping.
5. AI declaration
    AI tools were referenced solely for minor syntax checks and markdown formatting. Core logic and implementation authored by Group 18.
