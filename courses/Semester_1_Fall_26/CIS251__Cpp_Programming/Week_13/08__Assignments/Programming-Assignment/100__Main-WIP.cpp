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
#include <vector>
#include <iomanip>

// #include <ranges>
// #include <string_view>

using namespace std;

void printGradeReport(const vector<double>& grades);

int main()
{

  // Define grades vector
  vector<double> grades;

  grades = {90, 100, 100, 85.5, 46};

  // Call helper function
  printGradeReport(grades);

  // cout << *grades.begin();

  cout << grades.at(3);




  return 0;
}

void printGradeReport(const vector<double>& grades) {

  cout << "End printGradeReport()\n";
}

