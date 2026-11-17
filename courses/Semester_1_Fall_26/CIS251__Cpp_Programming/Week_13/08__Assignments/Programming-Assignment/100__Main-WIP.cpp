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
 * @status WIP
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
  vector<double> scores = {90, 100, 100, 85.5, 46};

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

  printGradeReport(scores, total, avg, highest, lowest);

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

  cout << "=================================\n";

  // Calculate sum with accumulate algorithm
  ttl = accumulate(scores.begin(), scores.end(), 0.0);

  // Calculate avg
  avg = ttl / scores.size();

  // Get highest with algorithm
  max = *max_element(scores.begin(), scores.end());

  // Get lowest with algorithm
  min = *min_element(scores.begin(), scores.end());

  // Set precision to 2 decimal places
  cout << setprecision(2) << fixed;

  // Print stats to console
  cout << "Total: " << ttl << "\n";
  cout << "Average: " << avg << "\n";
  cout << "Highest Score: " << max << "\n";
  cout << "Lowest Score: " << min << "\n";
}
