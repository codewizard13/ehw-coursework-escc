/**
 * @brief Distance class with travel-distance addition and unit display,
 *    with strongly scoped Unit labels and documented AI-assisted refinement.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 14 Programming Assignment
 * @lesson_focus AI-Assisted C++ Development, Constrained Prompting,
 *    Output Verification, and AI Assistance Logging.
 *
 * @instructions AI-Assisted Review Lab: choose one completed Weeks
 *    5-13 program. In AI Studio, ask for (1) a plain-language explanation,
 *    (2) five test cases, and (3) a code review limited to concepts already
 *    covered in CIS 251. Verify every suggestion against course readings,
 *    reject/correct at least one questionable or unnecessary suggestion,
 *    and submit the revised program plus AI Assistance Log.
 *
 * @status Fully Working
 *
 * @par Lessons Learned
 * - Strong prompts specify task, context, course constraints, and exact help
 *   needed (e.g., explanation, tests, and logic-error clues without rewrites).
 * - Replacing the global plain enum with `enum class Unit` prevents name clashes
 *   and implicit integer conversions; qualified Unit::inch, Unit::foot, and
 *   Unit::mile values were verified in constructors and switch cases.
 * - Reversed endpoints are handled with ABS, and addition retains the left
 *   operand's unit label while assuming both operands use compatible units.
 * - A const function can only call other const functions, because C++ assumes
 *   a non-const function might change the object. (a type of promise)
 *
 * @par Notes & Limitations
 * - Extends the Week 10 Distance class baseline (v1.03) for Week 14 refactor
 *   based on AI review.
 *
 * @author Eric L. Hepperle
 * @date 2026-11-24
 * @updated 2026-11-25
 * @version 1.0
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <string>
#include <cmath> // Provides floating-point std::abs.
#include <iomanip>
using namespace std;

// Units
enum class Unit
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

  // Constructor: Initialize endpoints, calculate distance, and select a unit.
  Distance(double start, double end, Unit unit = Unit::inch)
  {
    this->start = start;
    this->end = end;
    this->dist = abs(end - start);
    this->unit = unit;
    this->unitTxt = setUnitText();
  }

  // Show the unit text
  string setUnitText() const
  {
    // Treat values within 0.005 of 1.0 as singular (matches 2-decimal display).
    bool isOne = abs(dist - 1.0) < 0.005;

    switch (unit)
    {
    case Unit::inch:
      return (isOne ? "inch" : "inches");
    case Unit::foot:
      return (isOne ? "foot" : "feet");
    case Unit::mile:
      return (isOne ? "mile" : "miles");
    }
    return "Error: unit unknown";
  }

  double unitToInch(Unit unit) const
  {
    if (unit == Unit::inch)
      return 1.0;
    if (unit == Unit::foot)
      return 12.0;

    // I mile is 63,360 inches
    return 63360.0;
  }

  double convertUnit(double value, Unit from, Unit to) const
  {
    return value * unitToInch(from) / unitToInch(to);
  }

  // Display the endpoint calculation and singular/plural unit label.
  void display() const
  {
    cout << "Distance: ABS (" << end << " - " << start << ") = ";
    cout << dist << " " << unitTxt << endl;
  }

  // Right operand converts to left operand's unit when units differ
  Distance operator+(const Distance &d) const
  {
    double rightDist = d.dist;

    if (this->unit != d.unit)
    {
      rightDist = convertUnit(d.dist, d.unit, this->unit);
    }

    return Distance(0.0, this->dist + rightDist, this->unit);
  }

private:
  double start = 0.00;
  double end = 0.00;
  Unit unit = Unit::inch;
  string unitTxt = "inches";
  double dist = 0.00;
};

int main()
{
  cout << "\n******** START DISTANCE CALC PROGRAM *****************************************\n";

  cout << "\nThe current file is:\t" << __FILE__ << endl;

  // Display numeric values with two decimal places.
  cout << setprecision(2) << fixed;

  // TEST 1: Default construction with zero-valued endpoints.
  cout << "\n***************** TEST 1 ******************\n";
  cout << "DESCRIPTION: Default construction (0.00, 0.00)\n";
  cout << "INPUTS: none/defaults\n";
  cout << "EXPECTED OUTPUT: " << "0.00 inches" << endl;
  Distance d1;
  d1.display(); // Expected distance: 0.00 inches

  // TEST 2: Initialize two double endpoints; use default inches.
  cout << "\n***************** TEST 2 ******************\n";
  cout << "DESCRIPTION: Initialize two double endpoints; use default inches\n";
  cout << "INPUTS: 2.0, 10.0\n";
  cout << "EXPECTED OUTPUT: " << "8.00 inches" << endl;
  Distance d2(2.0, 10.0);
  d2.display(); // Expected distance: 8.00 inches

  // TEST 3: Initialize a second nonzero distance.
  cout << "\n***************** TEST 3 ******************\n";
  cout << "DESCRIPTION: Initialize a second nonzero distance\n";
  cout << "INPUTS: 4.0, 20.0\n";
  cout << "EXPECTED OUTPUT: " << "16.00 inches" << endl;
  Distance d3(4.0, 20.0);
  d3.display(); // Expected distance: 16.00 inches

  // TEST 4: Add travel distances from two existing objects.
  cout << "\n***************** TEST 4 ******************\n";
  cout << "DESCRIPTION: Add travel distances from two existing objects\n";
  cout << "INPUTS: d4 = d2 + d3 = 8.00 + 16.00\n";
  cout << "EXPECTED OUTPUT: " << "24.00 inches" << endl;
  Distance d4 = d2 + d3;
  d4.display(); // Expected distance: 24.00 inches

  // TEST 5: Add an existing object and a temporary object.
  cout << "\n***************** TEST 5 ******************\n";
  cout << "DESCRIPTION: Add an existing object and a temporary object\n";
  cout << "INPUTS: d5 = d2 + Distance(3, 6) = 8.00 + 3.00 = 11.00\n";
  cout << "EXPECTED OUTPUT: " << "11.00 inches" << endl;
  Distance d5 = d2 + Distance(3, 6);
  d5.display(); // Expected distance: 11.00 inches

  // TEST 6: Chain addition across three objects.
  cout << "\n***************** TEST 6 ******************\n";
  cout << "DESCRIPTION: Chain addition across three objects\n";
  cout << "INPUTS: d6 = d2 + d3 + d4 = 8.00 + 16.00 + 24.00 = 48.00\n";
  cout << "EXPECTED OUTPUT: " << "48.00 inches" << endl;
  Distance d6 = d2 + d3 + d4;
  d6.display(); // Expected distance: 48.00 inches

  // TEST 7: Reversed endpoints and the singular inch label.
  cout << "\n***************** TEST 7 ******************\n";
  cout << "DESCRIPTION: Reversed endpoints and the singular inch label\n";
  cout << "INPUTS: 2, 1\n";
  cout << "EXPECTED OUTPUT: " << "1.00 inch" << endl;
  Distance d7(2, 1);
  d7.display(); // Expected distance: 1.00 inch

  // TEST 8: Negative endpoint and the plural feet label.
  cout << "\n***************** TEST 8 ******************\n";
  cout << "DESCRIPTION: Negative endpoint and the plural feet label\n";
  cout << "INPUTS: 4.0, -10.0, Unit::foot\n";
  cout << "EXPECTED OUTPUT: " << "14.00 feet" << endl;
  Distance d8(4.0, -10.0, Unit::foot);
  d8.display(); // Expected distance: 14.00 feet

  // TEST 9: Reversed endpoints and the singular mile label.
  cout << "\n***************** TEST 9 ******************\n";
  cout << "DESCRIPTION: Reversed endpoints and the singular mile label\n";
  cout << "INPUTS: 3.0, 2, Unit::mile\n";
  cout << "EXPECTED OUTPUT: " << "1.00 mile" << endl;
  Distance d9(3.0, 2, Unit::mile);
  d9.display(); // Expected distance: 1.00 mile

  // TEST 10: Add travel distances regardless of direction.
  cout << "\n***************** TEST 10 ******************\n";
  cout << "DESCRIPTION: Add travel distances regardless of direction\n";
  cout << "INPUTS: Distance(2, 10) + Distance(10, 2) = 8.00 + 8.00 = 16.00\n";
  cout << "EXPECTED OUTPUT: " << "16.00 inches" << endl;
  Distance d10 = Distance(2, 10) + Distance(10, 2);
  d10.display(); // Expected: ABS (16.00 - 0.00) = 16.00 inches

  // TEST 11: Add two feet-labeled objects and retain that unit.
  cout << "\n***************** TEST 11 ******************\n";
  cout << "DESCRIPTION: Add two feet-labeled objects and retain that unit\n";
  cout << "INPUTS: Distance a(0, 2, Unit::foot); Distance b(0, 3, Unit::foot);\n";
  cout << "EXPECTED OUTPUT:\n";
  cout << "  - a.display() = 2.00 feet\n";
  cout << "  - b.display() = 3.00 feet\n";
  cout << "c = a + b\n";
  cout << "  - c.display() = 5.00 feet\n";

  cout << "ACTUAL DISTANCE OUTPUT:\n";
  Distance a(0, 2, Unit::foot);
  Distance b(0, 3, Unit::foot);

  a.display(); // Expected distance: 2.00 feet
  b.display(); // Expected distance: 3.00 feet

  Distance c = a + b;
  c.display(); // Expected distance: 5.00 feet

  // TEST 12: Mixed units, foot then inch - expect result in feet.
  cout << "\n***************** TEST 12 ******************\n";
  cout << "DESCRIPTION: Mixed units, foot then inch - expect result in feet\n";
  cout << "INPUTS: Distance(0, 1, Unit::foot) + Distance(0, 6, Unit::inch)\n"
       << "        = 12.00 inches + 6.00 inches\n"
       << "        = 18.00 inches = 1.50 feet\n";
  cout << "EXPECTED OUTPUT: " << "1.50 feet" << endl;
  Distance d12 = Distance(0, 1, Unit::foot) + Distance(0, 6, Unit::inch);
  d12.display(); // Expected: 1.5 feet

  // TEST 13: Mixed units, inch then foot - expect result in inches.
  cout << "\n***************** TEST 13 ******************\n";
  cout << "DESCRIPTION: Mixed units, inch then foot - expect result in inches\n";
  cout << "INPUTS: Distance(0, 6, Unit::inch) + Distance(0, 1, Unit::foot)\n"
       << "        = 6.00 inches + 12.00 inches\n"
       << "        = 18.00 inches\n";
  cout << "EXPECTED OUTPUT: " << "18.00 inches" << endl;
  Distance d13 = Distance(0, 6, Unit::inch) + Distance(0, 1, Unit::foot);
  d13.display(); // Expected: 18.00 inches

  // TEST 14: Mixed units, mile then foot - expect result in miles.
  cout << "\n***************** TEST 14 ******************\n";
  cout << "DESCRIPTION: Mixed units, mile then foot - expect result in miles\n";
  cout << "INPUTS: Distance(1.5, 2.75, Unit::mile) + Distance(0, 6009, Unit::foot)\n"
       << "        = 1.25 miles + 1.14 miles\n"
       << "        = 2.39 miles\n";
  cout << "EXPECTED OUTPUT: " << "2.39 miles" << endl;
  Distance d14 = Distance(1.5, 2.75, Unit::mile) + Distance(0, 6009, Unit::foot);
  d14.display(); // Expected: 2.39 miles

  // TEST 15: Floating-point sum near 1.0 should use the singular label.
  cout << "\n***************** TEST 15 ******************\n";
  cout << "DESCRIPTION: Floating-point sum near 1.0 should use the singular label\n";
  cout << "INPUTS: Distance(0, 0.2, Unit::foot) + Distance(0, 0.7, Unit::foot) "
       << "+ Distance(0, 0.1, Unit::foot)\n"
       << "        = 0.20 + 0.70 + 0.10 = 1.00 (stored as 0.9999999999999999)\n";
  cout << "EXPECTED OUTPUT: " << "1.00 foot" << endl;
  Distance d15 = Distance(0, 0.2, Unit::foot) + Distance(0, 0.7, Unit::foot) + Distance(0, 0.1, Unit::foot);
  d15.display(); // Expected: 1.00 foot

  cout << "\n******** END PROGRAM *******************************************\n";

  return 0;
}