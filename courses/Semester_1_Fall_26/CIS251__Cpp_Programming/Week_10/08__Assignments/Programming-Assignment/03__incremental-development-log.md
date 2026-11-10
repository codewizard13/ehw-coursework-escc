# 🛠️ Incremental Development Log

## 📘 Assignment Information

- **Course:** CIS-251 — C++ Programming
- **Assignment:** Week 10 — Operator Overloading, Enumerations, and Interface Design
- **Author:** Eric L. Hepperle
- **Program:** Distance class, version 1.03
- **Updated:** November 10, 2026

## 📋 Initial Design and Planning

I created the initial `Distance` class and chose to calculate the distance traveled between two endpoints as `abs(end - start)`. My design included constructors, a display method, an enum for unit selection, and one overloaded arithmetic operator following the required **Tutorials Point** `Box` example.

The intended meaning of addition is total travel distance: two trips of eight units should total sixteen units even when their endpoint directions differ.

The separate algorithm document describes the implementation approach.

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

## 🧪 v1.03 Test Results

All expected results match the latest console output. Entries omit the common `Distance: ` prefix.

| Test | Input or operation | Expected and observed result | Status |
| --- | --- | --- | --- |
| 1 | Default construction: `Distance d1;` | `ABS (0.00 - 0.00) = 0.00 inches` | Pass |
| 2 | `Distance d2(2.0, 10.0);` | `ABS (10.00 - 2.00) = 8.00 inches` | Pass |
| 3 | `Distance d3(4.0, 20.0);` | `ABS (20.00 - 4.00) = 16.00 inches` | Pass |
| 4 | `Distance d4 = d2 + d3;` | `ABS (24.00 - 0.00) = 24.00 inches` | Pass |
| 5 | `Distance d5 = d2 + Distance(3, 6);` | `ABS (11.00 - 0.00) = 11.00 inches` | Pass |
| 6 | `Distance d6 = d2 + d3 + d4;` | `ABS (48.00 - 0.00) = 48.00 inches` | Pass |
| 7 | `Distance d7(2, 1);` | `ABS (1.00 - 2.00) = 1.00 inch` | Pass |
| 8 | `Distance d8(4.0, -10.0, foot);` | `ABS (-10.00 - 4.00) = 14.00 feet` | Pass |
| 9 | `Distance d9(3.0, 2, mile);` | `ABS (2.00 - 3.00) = 1.00 mile` | Pass |
| 10 | `Distance d10 = Distance(2, 10) + Distance(10, 2);` | `ABS (16.00 - 0.00) = 16.00 inches` | Pass |
| 11a | `Distance a(0, 2, foot);` | `ABS (2.00 - 0.00) = 2.00 feet` | Pass |
| 11b | `Distance b(0, 3, foot);` | `ABS (3.00 - 0.00) = 3.00 feet` | Pass |
| 11c | `Distance c = a + b;` | `ABS (5.00 - 0.00) = 5.00 feet` | Pass |

Test 11 contains three displayed results, so the 11 numbered tests produce 13 result rows.

### Coverage and Evidence Limits

- Cases cover default zero distance, ordinary distances, reversed and negative endpoints, temporary objects, chained addition, and selected unit labels.
- Test 10 now checks that opposite travel directions do not cancel accumulated distance.
- Test 11 checks that same-unit addition retains feet.
- Fractional endpoints, singular foot, plural miles, and mixed-unit behavior were not exercised in the recorded run.
- The program uses hard-coded constructor arguments, not interactive input.

## 📌 Design Decisions and Limitations

- Individual trip distance is the absolute endpoint difference.
- Addition sums distance magnitudes and represents the result with endpoints from zero to the total.
- Addition assumes matching operand units, retains the left operand's unit, and performs no unit conversion or mixed-unit validation.
- Public constructors and methods provide the interface; private members prevent direct access from `main()`.
- No additional operators, getters/setters, frameworks, or defensive validation were added.

## 🤖 AI Assistance and Independent Decisions

I created the initial class and absolute-difference calculation. I used Perplexity to clarify scope and access rules, refine unit display, review the required operator model, identify targeted corrections, and organize comments, commit messages, and documentation.

AI initially recommended endpoint-based addition, which produced an inappropriate zero-distance result for opposite-direction trips. I identified and challenged that mismatch with the intended travel-distance meaning. After reviewing alternatives, I selected magnitude addition with result endpoints from zero to the total.

I compiled and ran the earlier recorded revision and checked its console results. Final implementation and submission decisions are mine.

## 📎 Documentation Basis

This retrospective log is based on the drafts, decisions, corrections, and console output recorded in this chat. It follows Dr. Rosalyn Warren's November 9 clarification that concise development notes, implementation order, testing, and correction history are sufficient; intermediate screenshots are optional. It accompanies rather than replaces the source, algorithm, test table, and compilation/execution evidence.
