# 🛠️ Incremental Development Log

## 📘 Assignment Information

- **Course:** CIS-251 — C++ Programming
- **Assignment:** Week 10 — Operator Overloading, Enumerations, and Interface Design
- **Author:** Eric L. Hepperle
- **Program:** Distance class, version 1.03

## 📋 Initial Design and Planning

I created the initial `Distance` class and chose to calculate the distance traveled between two endpoints as `abs(end - start)`. My design included constructors, a display method, an enum for unit selection, and one overloaded arithmetic operator following the required **Tutorials Point** `Box` example.

- The intended meaning of addition is **total travel distance**: two trips of eight units should total sixteen units even when their endpoint directions differ.

- The separate algorithm document describes the implementation approach.

## 🏗️ Incremental Implementation

### 1. Build the Initial Distance Class

- Added `start`, `end`, and `dist` members, a default constructor, a two-endpoint constructor, and `display()`.
- Used the absolute endpoint difference to calculate each trip's distance.
- Corrected an early constructor statement, `this->dist = dist`, which assigned the member to itself instead of calculating the distance.

### 2. Correct Enum Scope and Default Initialization

- Initially declared `Unit unit = inch` inside the default constructor. This created a local variable rather than a member, causing access errors in `display()`.
- Moved `unit` to class scope and used default member initializers: zero endpoints, zero distance, and inches.
- Later moved the enum to global scope so constructor calls could use unqualified names such as `foot` and `mile`.
- Clarified that a public nested enum was also possible, using qualified names such as `Distance::foot` outside the class.

### 3. Refine Display and Constructor Options

- Added an optional unit parameter to the endpoint constructor.
- Used `switch (unit)` to print readable unit names.
- Added singular/plural checks for inch/inches, foot/feet, and mile/miles.
- Added `<iomanip>`, `fixed`, and `setprecision(2)` for two-decimal output.

### 4. Add the Required Operator Pattern

- Implemented member `operator+` with a `const Distance&` parameter, a local result object, direct member assignments, and a returned result, following the required `Box` example's structure.
- Initially added both corresponding endpoints and stored distance magnitudes.
- Added tests for existing objects, a temporary object, and chained addition.

### 5. Make the Data Private

- Moved `start`, `end`, `unit`, and `dist` into the private section.
- Confirmed that the public constructors, `display()`, and member operator still supplied the needed interface.
- Kept direct member access inside the class, as demonstrated by the required model; no getters or setters were added.
- Corrected the documentation: private access prevents direct access from `main()`, but does not restrict changes exclusively to construction.

## 🔧 Troubleshooting Addition Semantics

### Original Display Inconsistency

The original operator correctly summed travel magnitudes, but its independently summed endpoints could contradict the displayed equation. For example, adding trips `(2, 10)` and `(10, 2)` produced endpoints `(12, 12)` and a stored distance of `16`, causing the display to claim `ABS(12 - 12) = 16`.

### Intermediate v1.02 Approach

An intermediate change summed endpoints and recalculated distance from them. The recorded run then showed `0.00 inches` for Test 10. This was consistent with that implementation, but not with the intended meaning of total travel distance.

I challenged that behavior because both trips cover eight units; reversing direction must not remove distance already traveled. The earlier zero-distance expectation was therefore superseded, not retained as the correct travel-distance result.

### Final v1.03 Approach

I selected a representation that preserves both total travel distance and a truthful displayed equation:

```cpp
temp.dist = this->dist + d.dist;
temp.start = 0.0;
temp.end = temp.dist;
temp.unit = this->unit;
```

The result represents cumulative travel from zero to the total distance, rather than the original trips' physical positions. Test 10 should now display:

```text
Distance: ABS (16.00 - 0.00) = 16.00 inches
```

The unit assignment also fixes the earlier behavior in which a default-constructed result retained inches even when both operands used feet.

## 🧹 Final Header and Comment Cleanup

- Replaced the unused `<string>` include with `<cmath>` to explicitly provide floating-point absolute-value support rather than rely on indirect inclusion.
- Updated comments and test expectations to reflect travel-distance addition, zero-to-total result endpoints, and the same-unit assumption without conversion or validation.

---
