/**
 * @brief Distance class with endpoint addition and unit display.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 10 Programming Assignment
 * @lesson_focus Operator Overloading, Enumerations, and Interface Design.
 *
 * @instructions Create a small Distance class with one arithmetic/comparison
 *    operator overloaded as modeled in the required material. Include an
 *    enum or enum class for a display/unit choice. Use only modeled operators.
 *
 * @status Fully Working.
 *
 * @par Lessons Learned
 * - The global Unit enum allows unqualified names such as foot and mile.
 * - Member functions access private data directly; getters and setters are
 *   not required for the current public interface.
 * - Chained addition returns intermediate Distance objects.
 *
 * @par Notes & Limitations
 * - The sample `Box` program used getters/setters, but that seemed beyond the
 *   scope of this assignment, and would add unnecessary complexity.
 *   Setting the member properties as private ensures the values
 *   can't be changed except upon initilizing a new Distance object. 
 * 
 * - Addition sums endpoints, then recalculates their absolute difference;
 *   it does not independently sum the original distance magnitudes.
 * - Results retain the left operand's unit; no unit conversion is performed.
 *
 * @author Eric L. Hepperle
 * @date 2026-11-07
 * @updated 2026-11-08
 * @version 1.02
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <string>
#include <iomanip>
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

  // Display the endpoint calculation and singular/plural unit label.
  void display()
  {
    cout << "Distance: ABS (" << end << " - " << start << ") = ";
    cout << dist << " ";

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

    cout << endl;
  }

  // Add endpoints, recalculate distance, and retain the left operand's unit.
  Distance operator+(const Distance &d)
  {
    Distance temp;
    temp.start = this->start + d.start;
    temp.end = this->end + d.end;
    temp.dist = abs(temp.end - temp.start);
    temp.unit = this->unit;
    return temp;
  }

private:
  double start = 0.0;
  double end = 0.0;
  Unit unit = inch;
  double dist = 0.0;
};

int main()
{
  cout << "\n******** START DISTANCE CALC PROGRAM *****************************************\n";

  // Display numeric values with two decimal places.
  cout << setprecision(2) << fixed;

  // TEST 1: Default construction with zero-valued endpoints.
  cout << "\n***************** TEST 1 ******************\n";
  Distance d1;
  d1.display(); // Expected distance: 0.00 inches

  // TEST 2: Initialize two double endpoints; use default inches.
  cout << "\n***************** TEST 2 ******************\n";
  Distance d2(2.0, 10.0);
  d2.display(); // Expected distance: 8.00 inches

  // TEST 3: Initialize a second nonzero distance.
  cout << "\n***************** TEST 3 ******************\n";
  Distance d3(4.0, 20.0);
  d3.display(); // Expected distance: 16.00 inches

  // TEST 4: Add endpoints from two existing objects.
  cout << "\n***************** TEST 4 ******************\n";
  Distance d4 = d2 + d3;
  d4.display(); // Expected distance: 24.00 inches

  // TEST 5: Add an existing object and a temporary object.
  cout << "\n***************** TEST 5 ******************\n";
  Distance d5 = d2 + Distance(3, 6);
  d5.display(); // Expected distance: 11.00 inches

  // TEST 6: Chain addition across three objects.
  cout << "\n***************** TEST 6 ******************\n";
  Distance d6 = d2 + d3 + d4;
  d6.display(); // Expected distance: 48.00 inches

  // TEST 7: Reversed endpoints and the singular inch label.
  cout << "\n***************** TEST 7 ******************\n";
  Distance d7(2, 1);
  d7.display(); // Expected distance: 1.00 inch

  // TEST 8: Negative endpoint and the plural feet label.
  cout << "\n***************** TEST 8 ******************\n";
  Distance d8(4.0, -10.0, foot);
  d8.display(); // Expected distance: 14.00 feet

  // TEST 9: Reversed endpoints and the singular mile label.
  cout << "\n***************** TEST 9 ******************\n";
  Distance d9(3.0, 2, mile);
  d9.display(); // Expected distance: 1.00 mile

  // TEST 10: Opposite endpoint differences cancel after addition.
  cout << "\n***************** TEST 10 ******************\n";
  Distance d10 = Distance(2, 10) + Distance(10, 2);
  d10.display(); // Expected: ABS (12.00 - 12.00) = 0.00 inches

  // TEST 11: Add two feet-labeled objects and retain that unit.
  cout << "\n***************** TEST 11 ******************\n";

  Distance a(0, 2, foot);
  Distance b(0, 3, foot);

  a.display(); // Expected distance: 2.00 feet
  b.display(); // Expected distance: 3.00 feet

  Distance c = a + b;
  c.display(); // Expected distance: 5.00 feet

  cout << "\n******** END PROGRAM *******************************************\n";

  return 0;
}