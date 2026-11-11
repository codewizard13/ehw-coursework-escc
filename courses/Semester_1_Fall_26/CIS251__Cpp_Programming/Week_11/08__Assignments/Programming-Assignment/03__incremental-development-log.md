# 🛠️ Incremental Development Log

## 📘 Assignment Information

- **Course:** CIS-251 — C++ Programming
- **Assignment:** Week 11 — Exceptions, Error Handling, and Robust Programs
- **Author:** Eric L. Hepperle
- **Program:** Divide By Zero Error Handling, version 1.01

## 📋 Initial Design and Planning

I used Perplexity to help me unstand the scope of the program, and what was being asked. After independently testing and verifying his implementation, I decided it would be better for me rebuild the program from scratch to ensure I understood what it was doing. ... That's where I'm currently at.

My analysis reveaals THAT we include iostream like normal, but we also include a class/module/header we've never seen before caleed <stdexcept> -- this is necessary to be able to reference and use standard ready-made exception subclasses. Since we aren't creating custom exceptions we don't need <exception>.

We'll ask for and receive the numerator and output an error message and return the failure code '1' to exit the program if the input is not a number. Otherwise, we'll do a similar input validation for denominator. if the both validated, then we'll open a try block where we'll throw a runtime_error() with a custom message "Cannot divide by zero.", if the denominator is zero. Otherwise/we'll assign and output the quotient. We'll set up matching catch block that expects a const reference to a runtime_error() object - we use ref because the object is 'heavy' and it helps us work agile-ly with it. We use const to ensure the original object referenced is not changed. It's really a neat trick.

When the runtime_error is thrown it is caught in the catch block which will display a message saying "Division error: " and the what() details of the caught errorf, referenced as `e`. We then make sure to return error code 1 for failure. If nothign fails, the main function is terminated without error with a code of zero.

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
