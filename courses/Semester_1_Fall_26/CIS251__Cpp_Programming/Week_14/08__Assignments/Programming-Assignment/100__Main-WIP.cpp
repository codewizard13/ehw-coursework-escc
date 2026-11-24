/**
 * @brief Distance class with travel-distance addition and unit display,
 *    with strongly scoped Unit labels and documented AI-assisted refinement.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 14 Programming Assignment
 * @lesson_focus AI-Assisted C++ Development, Constrained Prompting,
 *    Output Verification, and AI Assistance Logging.
 *
 * @instructions Evaluate and improve existing C++ code using Google AI Studio
 *    as a documented tutor/reviewer rather than an answer generator. Limit all
 *    analysis and suggestions to CIS 251 concepts (through classes, vectors,
 *    file I/O, and exceptions), verify every suggestion independently, and
 *    document substantial AI use in an AI Assistance Log.
 *
 * @status WIP
 *
 * @par Lessons Learned
 * - Strong prompts specify task, context, course constraints, and exact help
 *   needed (e.g., explanation, tests, and logic-error clues without rewrites).
 * - AI output can sound professional yet contain errors or out-of-scope C++,
 *   so every suggestion must be checked for compilation and course alignment.
 * - Replacing the global plain enum with enum class Unit prevents name clashes
 *   and implicit integer conversions; qualified Unit::inch, Unit::foot, and
 *   Unit::mile values were verified in constructors and switch cases.
 * - Reversed endpoints are handled with ABS, and addition retains the left
 *   operand's unit label while assuming both operands use compatible units.
 *
 * @par Notes & Limitations
 * - Extends the Week 10 Distance class baseline (v1.03) for Week 14 review.
 * - Constrained strictly to CIS 251 topics; no new frameworks, unlearned
 *   libraries, or wholesale AI rewrites permitted.
 * - Substantial AI interactions must be logged (prompt, useful output,
 *   accepted/rejected items, verification method, and self-authored edits).
 *
 * @author Eric L. Hepperle
 * @date 2026-11-24
 * @updated 2026-11-24
 * @version 1.1
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <cmath> // Provides floating-point std::abs.
#include <iomanip>
#include <vector>
using namespace std;

// Unit labels; selecting a unit does not convert endpoint values.
enum Unit
{
  inch,
  foot,
  mile
};

class Distance
{
public:
  Distance()
  {
    // Use the default member initializers.
  }

  // Initialize endpoints, calculate distance, and select a unit.
  Distance(double start, double end, Unit unit = inch)
  {
    this->start = start;
    this->end = end;
    this->dist = abs(end - start);
    this->unit = unit;
  }

  // Show the unit text
  void printUnitText()
  {
    switch (unit)
    {
    case inch:
      cout << (dist == 1.0 ? "inch" : "inches");
      break;
    case foot:
      cout << (dist == 1.0 ? "foot" : "feet");
      break;
    case mile:
      cout << (dist == 1.0 ? "mile" : "miles");
      break;
    }
  }

  // Display the endpoint calculation and singular/plural unit label.
  void display()
  {
    cout << "Distance: ABS (" << end << " - " << start << ") = ";
    cout << dist << " ";

    this->printUnitText();

    cout << endl;
  }

  // Add travel distances and retain the left operand's unit.
  // Assumes both operands use the same unit.
  Distance operator+(const Distance &d)
  {
    Distance temp;

    temp.dist = this->dist + d.dist;
    temp.start = 0.0;
    temp.end = temp.dist;
    temp.unit = this->unit;

    return temp;
  }

private:
  double start = 0.0;
  double end = 0.0;
  Unit unit = inch;
  double dist = 0.0;
};

struct TestCase
{
  string title;
  string descr;
  double start = 0.0;
  double end = 0.0;
  Unit myUnit = Unit::inch;
};

int main()
{
  cout << "\n******** START DISTANCE CALC PROGRAM *****************************************\n";

  cout << "\nThe current file is:\t" << __FILE__ << endl;

  // Display numeric values with two decimal places.
  cout << setprecision(2) << fixed;

  // Define datasets
  vector<TestCase> testHarness = {
      {"TEST CASE: 1", "Default construction (0, 0)"},
      {"TEST CASE: 2", "Initialize two double endpoints; use default inches", 2.0, 10.0},
  };

  // Loop through test harness
  for (const auto &test : testHarness)
  {
    cout << "\n============ " << test.title << " =============\n";
    cout << "Decription: " << test.descr << endl;
    cout << "INPUTS" << endl;
    cout << "- Start:  " << test.start << endl;
    cout << "- End:    " << test.end << endl;
    cout << "- Unit:   " << test.myUnit << endl;
  }

  // // TEST 1: Default construction with zero-valued endpoints.
  // cout << "\n***************** TEST 1 ******************\n";
  // Distance d1;
  // d1.display(); // Expected distance: 0.00 inches

  // // TEST 2: Initialize two double endpoints; use default inches.
  // cout << "\n***************** TEST 2 ******************\n";
  // Distance d2(2.0, 10.0);
  // d2.display(); // Expected distance: 8.00 inches

  // // TEST 3: Initialize a second nonzero distance.
  // cout << "\n***************** TEST 3 ******************\n";
  // Distance d3(4.0, 20.0);
  // d3.display(); // Expected distance: 16.00 inches

  // // TEST 4: Add travel distances from two existing objects.
  // cout << "\n***************** TEST 4 ******************\n";
  // Distance d4 = d2 + d3;
  // d4.display(); // Expected distance: 24.00 inches

  // // TEST 5: Add an existing object and a temporary object.
  // cout << "\n***************** TEST 5 ******************\n";
  // Distance d5 = d2 + Distance(3, 6);
  // d5.display(); // Expected distance: 11.00 inches

  // // TEST 6: Chain addition across three objects.
  // cout << "\n***************** TEST 6 ******************\n";
  // Distance d6 = d2 + d3 + d4;
  // d6.display(); // Expected distance: 48.00 inches

  // // TEST 7: Reversed endpoints and the singular inch label.
  // cout << "\n***************** TEST 7 ******************\n";
  // Distance d7(2, 1);
  // d7.display(); // Expected distance: 1.00 inch

  // // TEST 8: Negative endpoint and the plural feet label.
  // cout << "\n***************** TEST 8 ******************\n";
  // Distance d8(4.0, -10.0, foot);
  // d8.display(); // Expected distance: 14.00 feet

  // // TEST 9: Reversed endpoints and the singular mile label.
  // cout << "\n***************** TEST 9 ******************\n";
  // Distance d9(3.0, 2, mile);
  // d9.display(); // Expected distance: 1.00 mile

  // // TEST 10: Add travel distances regardless of direction.
  // cout << "\n***************** TEST 10 ******************\n";
  // Distance d10 = Distance(2, 10) + Distance(10, 2);
  // d10.display(); // Expected: ABS (16.00 - 0.00) = 16.00 inches

  // // TEST 11: Add two feet-labeled objects and retain that unit.
  // cout << "\n***************** TEST 11 ******************\n";

  // Distance a(0, 2, foot);
  // Distance b(0, 3, foot);

  // a.display(); // Expected distance: 2.00 feet
  // b.display(); // Expected distance: 3.00 feet

  // Distance c = a + b;
  // c.display(); // Expected distance: 5.00 feet

  cout << "\n******** END PROGRAM *******************************************\n";

  return 0;
}