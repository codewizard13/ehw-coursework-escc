# Distance Class Code Review

---

## You

I am a beginning C++ student. My program uses only concepts through
classes, vectors, file I/O, and exceptions. Do not introduce libraries
or techniques outside those topics.

Here is my requirement: 

Give me (1) a plain-language explanation, (2) five test cases, and (3) a code review limited to concepts already covered in CIS 251, based on the draft code as context.


Here is my current code:

```cpp
/**
 * @brief Distance class with travel-distance addition and unit display.
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
 * - Rationale: The sample `Box` program used getters/setters, but that seemed beyond the
 *   scope of this assignment, and would add unnecessary complexity.
 *   Setting the member properties as private ensures the values
 *   can't be changed except upon initilizing a new Distance object.
 * 
 * - Public constructors and methods provide the needed interface without
 *   getters/setters; private members prevent direct access from main().
 * - Addition sums travel distances regardless of endpoint direction.
 * - Result endpoints run from zero to the total distance; they do not
 *   represent the original trip positions.
 * - Addition assumes matching units and retains the left operand's unit;
 *   no unit conversion or mixed-unit validation is performed.
 *
 * @author Eric L. Hepperle
 * @date 2026-11-07
 * @updated 2026-11-10
 * @version 1.03
 *
 * @see https://github.com/codewizard13
 */

#include <iostream>
#include <cmath> // Provides floating-point std::abs.
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

  // TEST 4: Add travel distances from two existing objects.
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

  // TEST 10: Add travel distances regardless of direction.
  cout << "\n***************** TEST 10 ******************\n";
  Distance d10 = Distance(2, 10) + Distance(10, 2);
  d10.display(); // Expected: ABS (16.00 - 0.00) = 16.00 inches

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
```

Identify two likely logic errors. Explain each error and suggest a small
test that would expose it. Do not rewrite the entire program.

---

## AI Studio

### 1. Plain-Language Explanation

This program models a `Distance` object that stores a starting point, an ending point, a measurement unit (`inch`, `foot`, or `mile`), and the non-negative distance between those two points.

- **Unit Selection (`enum Unit`):** Defines three named constants—`inch`, `foot`, and `mile`—so the program can label distances with readable words instead of plain numbers.
- **Creating a `Distance` Object (Constructors):**
  - The default constructor (`Distance()`) creates a distance initialized to `0.0` through `0.0` in `inch`es.
  - The parameterized constructor (`Distance(start, end, unit)`) saves the two endpoints, calculates the non-negative distance between them using `abs(end - start)`, and records the unit (defaulting to `inch` if none is provided).
- **Displaying Results (`display()`):** Prints the formula `ABS (end - start) = dist` followed by the unit name. It uses a `switch` statement and the `? :` operator to choose the singular word (`inch`, `foot`, `mile`) when `dist` equals `1.0`, or the plural word otherwise.
- **Adding Distances (`operator+`):** Allows two `Distance` objects to be added with `+` (including chained additions like `d2 + d3 + d4`). It adds the two `dist` values together, stores the result in a new `Distance` object running from `0.0` to the combined total, and keeps the left-hand object's unit.
- **Testing (`main()`):** Configures `cout` to display two decimal places (`setprecision(2) << fixed`) and runs 11 tests covering default objects, reversed endpoints, negative coordinates, singular/plural labels, and addition.

---

### 2. Five Test Cases

| Test Case | Input / Setup | Expected Output | What It Verifies |
| :--- | :--- | :--- | :--- |
| **1. Default Construction** | `Distance d1;`<br>`d1.display();` | `Distance: ABS (0.00 - 0.00) = 0.00 inches` | Verifies default member values (`0.0`, `inch`) and plural label for `0.00`. |
| **2. Reversed Endpoints & Singular Label** | `Distance d2(5.0, 4.0, mile);`<br>`d2.display();` | `Distance: ABS (4.00 - 5.00) = 1.00 mile` | Verifies `abs(end - start)` stays positive when `start > end` and outputs singular `mile`. |
| **3. Negative Endpoint** | `Distance d3(4.0, -10.0, foot);`<br>`d3.display();` | `Distance: ABS (-10.00 - 4.00) = 14.00 feet` | Verifies distance calculation across zero with a negative endpoint and plural `feet`. |
| **4. Chained Addition (Matching Units)** | `Distance d4 = Distance(0, 2, foot) + Distance(0, 3, foot) + Distance(0, 1, foot);`<br>`d4.display();` | `Distance: ABS (6.00 - 0.00) = 6.00 feet` | Verifies `operator+` returns a valid temporary `Distance` so multiple `+` operations can be chained while keeping `foot`. |
| **5. Mixed-Unit Addition (Boundary / Error Case)** | `Distance d5 = Distance(0, 1, foot) + Distance(0, 6, inch);`<br>`d5.display();` | Should convert to `1.50 feet` (or reject mismatched units with an exception). *Currently outputs `7.00 feet`.* | Tests whether `operator+` handles incompatible units safely. |

---

### 3. Code Review (CIS 251 Scope)

**What Works Well**
- **Encapsulation:** Keeping `start`, `end`, `unit`, and `dist` `private` protects the data from accidental modification outside the class, while in-class initializers (`= 0.0`, `= inch`) keep the default constructor clean.
- **Parameter Passing:** Passing `const Distance &d` by constant reference in `operator+` avoids making an unnecessary copy of the right-hand object.
- **Readability:** The `switch` statement for `Unit` and the 11 structured test blocks in `main()` make the intended behavior easy to follow.

**Areas to Improve (Within CIS 251 Topics)**
1. **Mark non-modifying member functions `const`:** Neither `display()` nor `operator+` changes the object it is called on. Writing `void display() const` and `Distance operator+(const Distance &d) const` allows `const Distance` objects to use them without compiler errors.
2. **Use `enum class` instead of global `enum`:** Because `enum Unit` is unscoped, the names `inch`, `foot`, and `mile` exist globally across the whole file. If another variable or enum later uses the name `foot`, it will cause a name collision. Using `enum class Unit` (written as `Unit::inch`, `Unit::foot`, `Unit::mile`) avoids this problem.
3. **Avoid silent failure on mismatched units:** Since you have covered exceptions, `operator+` could check `if (this->unit != d.unit)` and `throw` an error (or convert units) instead of silently producing an incorrect sum.
4. **Formatting dependency in `display()`:** `display()` relies on `main()` having called `cout << setprecision(2) << fixed;`. Moving or explicitly setting formatting if needed—or documenting that `display()` expects fixed two-decimal formatting—prevents surprises if `Distance` is used in a different program.
5. **Parameter naming vs. `this->`:** Using slightly different parameter names in the constructor (e.g., `startVal`, `endVal`, `unitChoice`) eliminates the need to write `this->` repeatedly and makes the code easier to read.

---

### 4. Two Likely Logic Errors

#### Logic Error 1: Unchecked Mixed-Unit Addition in `operator+`
- **Explanation:** In `operator+`, the line `temp.dist = this->dist + d.dist;` adds the raw numbers without checking `d.unit` or converting between inches, feet, and miles, and then forces `temp.unit = this->unit;`. Adding `1 foot` and `6 inches` yields `7.00 feet`. Reversing the order (`6 inches + 1 foot`) yields `7.00 inches`. Both answers are physically wrong and depend on operand order.
- **Small Test to Expose It:**
  ```cpp
  Distance a(0.0, 1.0, foot);
  Distance b(0.0, 6.0, inch);
  (a + b).display(); // Outputs 7.00 feet instead of 1.50 feet (or throwing an error)
  (b + a).display(); // Outputs 7.00 inches instead of 18.00 inches (order-dependent!)
  ```

#### Logic Error 2: Exact Floating-Point Comparison (`dist == 1.0`) in `display()`
- **Explanation:** `dist` is a `double`, and `display()` uses exact equality (`dist == 1.0`) to decide between singular and plural labels. Decimal fractions like `4.1` and `3.1` cannot be stored with exact base-10 precision in binary floating-point, so `abs(4.1 - 3.1)` evaluates slightly below `1.0` (`~0.99999999999999956`). Because `main()` formats numbers to two decimal places, the program prints `1.00`, yet `dist == 1.0` is `false`, outputting `"1.00 inches"` instead of `"1.00 inch"`. The same mismatch also happens for numbers like `1.001` that display as `1.00`. (Checking within a small tolerance such as `abs(dist - 1.0) < 0.005` fixes this for two-decimal display.)
- **Small Test to Expose It:**
  ```cpp
  Distance dEdge(3.1, 4.1, inch);
  dEdge.display(); // Outputs: Distance: ABS (4.10 - 3.10) = 1.00 inches
  ```
