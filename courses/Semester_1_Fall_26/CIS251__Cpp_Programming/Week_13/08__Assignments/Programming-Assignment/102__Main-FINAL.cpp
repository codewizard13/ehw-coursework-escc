/**
 * @brief Vector-Based Score Analyzer — Week 13 C++ programming assignment:
 *        Integration: STL Containers, Algorithms, & Design Refactoring.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 13 Programming Assignment
 * @lesson_focus Integration: STL Containers, Algorithms, & Design Refactoring.
 *
 * @instructions Vector-Based Score Analyzer: refactor the Week 6 score
 *     analyzer to use std::vector. Use a range-based loop or iterator pattern
 *     and one standard algorithm shown in the readings. Compare the array and
 *     vector versions in comments.
 *
 * @par Comparing Wk 6 (array) version to this (vector) version:
 * - The main advantage of vectors over arrays is that vectors automatically
 *   resize and do their own memory management.
 * 
 * - Both versions scale linearly, (O(n)), with the number of scores.
 *   The original combines display, summation, and highest/lowest comparisons
 *   in one loop. The refactored version uses four passes: one for display and
 *   one each for `accumulate()`, `max_element()`, and `min_element()`. These
 *   extra passes add work but do not change the overall complexity. They also
 *   do not imply the program runs four times slower.
 * 
 * - Vectors add storage-management overhead, not inherently slower indexing.
 *   Like arrays, vectors store elements contiguously and provide constant-time
 *   indexed access. My vectors are initialized once and never resized, so
 *   repeated growth and reallocation are not a concern in this program.
 * 
 * - For five-score datasets, the additional work is small; the refactor
 *   prioritizes clarity and reusable testing rather than speed.
 *
 * @status WIP - Works. Versioning to 1.02 to finalize comments
 *
 * @author Eric L. Hepperle
 * @date 2026-11-17
 * @updated --
 * @version 1.01
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <string>
#include <iomanip>

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct TestCase
{
  string title;
  string description;
  vector<double> scores;
};

void printGradeReport(const vector<double> &scores,
                      double &ttl, double &avg, double &max, double &min);

int main()
{

    // Display program START in console
  cout << "\n******** START PROGRAM *********************************\n";

  // Naming note: Scores are the numeric values, grades are the letter values they correspond with in the A-F grading system
  // Define & init scores vector
  // vector<double> scores = {90, 100, 98.25, 85.5, 46};
  vector<TestCase> testHarness = {
      {"TEST CASE: 1", "Mixed decimal and int values", {90, 100, 98.25, 85.5, 46}},
      {"TEST CASE: 2", "Tied high score", {85, 90, 98.5, 98.5, 76.5}},
      {"TEST CASE: 3", "Tied low score", {90, 62.5, 38, 38, 98}},
      {"TEST CASE: 4", "Score set contains both boundaries (0 & 100)", {0, 76, 2, 100, 98.5}},
      {"TEST CASE: 5", "All scores identical", {100, 100, 100, 100, 100}}};

  // Define & init report string variables
  string student_name = "Eric Hepperle";
  string report_heading = "Grade Report for: ";
  report_heading.append(student_name);

  // Initialize report stats
  double highest = -999.0;
  double lowest = 999.0;
  double total = 0.0;
  double avg = 0.0;

  for (const auto &test : testHarness)
  {
    cout << "\n============ " << test.title << " ============\n";
    cout << "# " << test.description << "\n";
    cout << "--------------------------------------\n";
    printGradeReport(test.scores, total, avg, highest, lowest);
  }

  // Display program end in console
  cout << "\n******** END PROGRAM ***********************************\n";

  return 0;
}

void printGradeReport(const vector<double> &scores,
                      double &ttl, double &avg, double &max, double &min)
{

  // Display the label for the scores
  cout << "Scores: ";

  // Loop through and display each score in single horizontal line
  //  - #GOTCHA: Apparently C++ doesn't have any sort of `join()` one-liner
  for (int i = 0; i < scores.size(); i++)
  {
    cout << scores[i];
    cout << (i == scores.size() - 1 ? "\n" : ", ");
  }

  cout << "======================================\n";

  // Calculate sum with accumulate algorithm
  ttl = accumulate(scores.begin(), scores.end(), 0.0);

  // Calculate avg
  avg = ttl / scores.size();

  // Get highest with algorithm
  max = *max_element(scores.begin(), scores.end());

  // Get lowest with algorithm
  min = *min_element(scores.begin(), scores.end());

  // Store current precision
  streamsize saved_precision = cout.precision();

  // Set precision to 2 decimal places
  cout << setprecision(2) << fixed;

  // Print stats to console
  cout << "Total: " << ttl << "\n";
  cout << "Average: " << avg << "\n";
  cout << "Highest Score: " << max << "\n";
  cout << "Lowest Score: " << min << "\n";

  // Restore the saved precision and notation
  cout << defaultfloat << setprecision(saved_precision);
}
