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
 * @par Notes:
 * - The main advantage of vectors over arrays is that vectors automatically
 *   resize and do their own memory management.
 *
 * @status WIP - WORKS, but doesn't implement a range-based loop.
 *    NEXT: Implement foreach loop in test harness.
 *
 * @author Eric L. Hepperle
 * @date 2026-11-17
 * @updated --
 * @version 1.0
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

void printGradeReport(const vector<double> &scores,
                      double &ttl, double &avg, double &max, double &min);

int main()
{

  // Naming note: Scores are the numeric values, grades are the letter values they correspond with in the A-F grading system
  // Define & init scores vector
  vector<double> scores = {90, 100, 98.25, 85.5, 46};

  // Define & init report string variables
  string student_name = "Eric Hepperle";
  string report_heading = "Grade Report for: ";
  report_heading.append(student_name);

  // Initialize report stats
  double highest = -999;
  double lowest = 999;
  double total = 0.0;
  double avg = 0.0;



  // Display program start in console
  cout << "******** START PROGRAM *********************************\n\n";
  cout << report_heading << endl;

  // TEST 1: Mixed decimal and int values
  cout << "\n============ TEST CASE: 1 ============\n";
  cout << "#   Mixed decimal and int values\n";
  cout << "--------------------------------------\n";
  printGradeReport(scores, total, avg, highest, lowest);

  // TEST 2: Tied high score
  cout << "\n============ TEST CASE: 2 ============\n";
  cout << "#   Tied high score\n";
  cout << "--------------------------------------\n";
  printGradeReport({85, 90, 98.5, 98.5, 76.5}, total, avg, highest, lowest);

  // TEST 3: Tied low score
  cout << "\n============ TEST CASE: 3 ============\n";
  cout << "#   Tied low score\n";
  cout << "--------------------------------------\n";
  printGradeReport({90, 62.5, 38, 38, 98}, total, avg, highest, lowest);

  // TEST 4: Score set contains both boundaries (0 & 100)
  cout << "\n============ TEST CASE: 4 ============\n";
  cout << "#   Score set contains both boundaries (0 & 100)\n";
  cout << "--------------------------------------\n";
  printGradeReport({0, 76, 2, 100, 98.5}, total, avg, highest, lowest);

// TEST 5: Mixed decimal and int values
  cout << "\n============ TEST CASE: 5 ============\n";
  cout << "#   All scores identical\n";
  cout << "--------------------------------------\n";
  printGradeReport({100, 100, 100, 100, 100}, total, avg, highest, lowest);


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
