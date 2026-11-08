/**
 * @brief Distance Class — Week 10 C++ programming assignment:
 *        Operator Overloading, Enumerations, & Interface Design.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 10 Programming Assignment
 * @lesson_focus OOP: Inheritance, Overriding, and Polymorphism.
 *
 * @instructions Distance Class: create a small Distance class and overload one
 *    arithmetic/comparison operator exactly as modeled in the required
 *    material. Add an enum or enum class for a display/unit choice. Do not
 *    implement operators not covered in the examples.
 *
 * @status Fully Working
 *
 * @author Eric L. Hepperle
 * @date 2026-11-07
 * @updated --
 * @version 1.0
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Distance
{
private:
  // Private properties go here

public:
  enum Unit
  {
    inch,
    foot,
    mile
  };

  double start = 0.0;
  double end = 0.0;
  Unit unit = inch;
  double dist = 0.0;

  Distance()
  {
    // Default member initializers above supply the values
  }

  Distance(double start, double end)
  {
    this->start = start;
    this->end = end;
    this->dist = abs(end - start);
  }

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

  // Overloading + operator to add 2 Distance objects.
  Distance operator+(const Distance &d)
  {
    Distance temp;
    temp.start = this->start + d.start;
    temp.end = this->end + d.end;
    temp.dist = this->dist + d.dist;
    return temp;
  }
};

int main()
{

  // cout << "\n***************** TEST 1 ******************\n";
  cout << "\n******** START DISTANCE CALC PROGRAM *****************************************\n";

  cout << setprecision(2) << fixed;

  // TEST 1: Empty constructor
  cout << "\n***************** TEST 1 ******************\n";
  Distance d1;
  d1.display(); // 0.00 inches

  // TEST 2: 2 floats
  cout << "\n***************** TEST 2 ******************\n";
  Distance d2(2.0, 10.0);
  d2.display(); // 8.00 inches

  // TEST 3: 2 more floats
  cout << "\n***************** TEST 3 ******************\n";
  Distance d3(4.0, 20.0);
  d3.display(); // 16.00 inches

  // TEST 4: Add 2 Distances objects
  cout << "\n***************** TEST 4 ******************\n";
  Distance d4 = d2 + d3;
  d4.display(); // 24.00 inches

  // TEST 5: Add 1 new distance object with 2 inline int args
  cout << "\n***************** TEST 5 ******************\n";
  Distance d5 = d2 + Distance(3, 6);
  d5.display(); // 11.00 inches

  // TEST 6: Add 3 Distance objects
  cout << "\n***************** TEST 6 ******************\n";
  Distance d6 = d2 + d3 + d4;
  d6.display(); // 48.00 inches

  cout << "\n******** END PROGRAM *******************************************\n";

  return 0;
}
