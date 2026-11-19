# 🛠️ Incremental Development Log

## 📘 Assignment Information

- Course: CIS-251 — C++ Programming
- Assignment: Week 13 — Integration: STL Containers, Algorithms, & Design Refactoring
- Author: Eric L. Hepperle
- Program: Vector Score List Analyzer, v 1.01

## 📋 Initial Design and Planning

I used my Assignment 6 Score List Analyzer as the foundation for a vector-based version that preserves the original purpose: displaying quiz scores and reporting their total, average, highest, and lowest values. The original program earned 83/100, primarily because I omitted the required five-case test table. This revision also addressed the instructor’s recommendations for local variables, explicit initialization, and AI-use documentation.

The plan was to replace the fixed array with `std::vector`, incorporate standard algorithms and a range-based loop, and keep the implementation within the assignment’s introductory scope. One unexpected challenge was organizing each test’s title, description, and scores together. A `struct` ended up saving the day by grouping those fields into a single test record, making the harness much cleaner than the individual test calls I started with.

## 🏗️ Incremental Implementation

### 1. Refactor Score Storage and Calculations

- I replaced the fixed score array with `vector<double>` and kept the report variables local to `main()`. I explicitly initialized the total and average to `0.0` and used decimal literals for the highest and lowest sentinel values.

- I replaced the manual accumulation and comparison logic with:
  - `accumulate()` for the total.
  - `max_element()` for the highest score.
  - `min_element()` for the lowest score.

- The average remained the total divided by the number of scores. During development, I corrected an accidental use of `min_element()` for the highest score.

### 2. Extract the Grade Report Function

- I moved score display, calculations, and statistics output into `printGradeReport()`. This allowed multiple datasets to use the same reporting logic instead of repeating code.

- The function receives the scores by constant reference and updates the statistics through reference parameters. It displays scores on one comma-separated line and formats the calculated statistics to two decimal places.

### 3. Build the Test Harness

- I first ran tests through individual function calls, then replaced those calls with a `TestCase` struct containing a title, description, and score vector.

- A `vector<TestCase>` now stores five test records. A range-based loop processes each record using `const auto &test`, prints its identifying information, and passes its scores to `printGradeReport()`.

- I removed the temporary debugging output and superseded manual test calls.

## 💡 Learnings and Challenges

### Accumulator Type Affects Decimal Results

- My initial call used an integer starting value:

  ```cpp
  total = accumulate(scores.begin(), scores.end(), 0);
  ```

- This caused fractional values to be lost during accumulation. Changing the initial value to `0.0` made the accumulator a `double` and preserved the decimal portion:

  ```cpp
  total = accumulate(scores.begin(), scores.end(), 0.0);
  ```

- The correction affected the accumulation type—not decimal division. Adding two-decimal output formatting alone could not recover the fractions already lost during calculation.

### Keep Delimiter Formatting Simple

- I considered using `accumulate()` or additional library features to join the scores into a formatted string.

- Instead, I retained a straightforward loop that prints a comma after every score except the last. This kept the display logic simple and within scope.

### Reset Formatting Between Reports

- After the first report, subsequent score lists inherited the fixed two-decimal formatting intended for the statistics.

- I resolved this by saving the current precision before formatting the statistics, then restoring that precision and selecting `defaultfloat` afterward:

  ```cpp
  // Store current precision.
  streamsize saved_precision = cout.precision();

  // Format statistics to two decimal places.
  cout << setprecision(2) << fixed;

  // Print statistics.

  // Restore saved precision and reset floating-point notation.
  cout << defaultfloat << setprecision(saved_precision);
  ```

- `defaultfloat` resets the floating-point notation; the saved precision must be restored separately.

### Group Test Data with a Struct

- My attempted `vector<vector<double>> testCase`  initializer could not accommodate both score vectors and descriptive strings.

- Google Gemini suggested a `TestCase` struct, which solved the problem by grouping each test’s information into one record:
  - Title.
  - Description.
  - Score vector.

- I incorporated the struct into the working harness and used a constant-reference range-based loop to process the records without copying them.

## 🧪 Final Test Coverage

The completed harness runs these five datasets through the same reporting function:

1. Mixed whole-number and decimal scores: `90, 100, 98.25, 85.5, 46`.
2. Tied highest score: `85, 90, 98.5, 98.5, 76.5`.
3. Tied lowest score: `90, 62.5, 38, 38, 98`.
4. Both boundary values, 0 and 100: `0, 76, 2, 100, 98.5`.
5. All identical scores: `100, 100, 100, 100, 100`.

The harness displays each test’s results for comparison; it does not automatically evaluate pass/fail. The required test table documents input, expected results, actual results, and pass/fail separately.

## ✅ Final Status

The program is complete and working. It uses vector-based score storage, three standard algorithms, a reusable reporting function, and a structured five-case test harness. The final implementation replaces repeated manual test calls with one range-based execution loop.