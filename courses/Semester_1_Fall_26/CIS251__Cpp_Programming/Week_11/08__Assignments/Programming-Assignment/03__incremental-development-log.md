# 🛠️ Incremental Development Log

## 📘 Assignment Information

- Course: CIS-251 — C++ Programming
- Assignment: Week 11 — Exceptions, Error Handling, and Robust Programs
- Author: Eric L. Hepperle
- Program: Divide By Zero Error Handling, version 1.01

## 📋 Initial Design and Planning

Selected **safe division** to demonstrate routine numeric input validation with decisions and **division-by-zero** handling with `try`/`throw`/`catch`.

The planned program reads a numerator and denominator, rejects nonnumeric input, and either displays the quotient or reports division by zero.


## 🏗️ Incremental Implementation

### 1. Add Program Structure and Numerator Validation

- Added `<iostream>`, `<stdexcept>`, and `using namespace std;`.
- Added start and end program banners.
- Declared `numerator` and `denominator` as `double` variables initialized to `0.0`.
- Added the numerator prompt and an `if` statement to check whether input succeeds.
- Added an input-error message and `return 1` for unsuccessful input.
- Displayed the accepted numerator to verify this stage.

### 2. Add Denominator Validation

- Copied the numerator input-validation code and adapted the variable references and messages for the denominator.

### 3. Add Try-Catch Block for Divide by Zero

- Commented out the numerator and denominator debugging output to declutter the console.
- Added a `try` block checking whether the denominator equals `0.0`.
  - First snag: VS Code flagged missing parentheses around the `if` condition. I thought they might be optional, like braces around a single-statement body—but nope! Added the parentheses and resolved that error.
- Added a thrown `runtime_error` object for division by zero.
  - Second snag: the compiler wanted a matching `catch` block. Adding one with an empty body cleared that complaint.
- Set up the catch parameter as `const runtime_error& e`: a reference avoids copying the exception, while `const` prevents modifying it through that reference—a neat trick!
- Added the label `"Runtime Error"` followed by `e.what()` to display the message supplied when creating the exception.

### 4. Calculate and Print Quotient for Non-Zero Denominators

- IN the try block created new double `quotient` as `numerator / denominator`, then output that to console

## 🧪 Testing

### Step 1 — Numerator Input Validation

- Accepted correctly: `1`, `0`, `6`, `200`, `-3`, `.05`, `2.5`, and `-2.5`.
- Returned the expected input-validation error: `[sp]^Z`, `!`, `a`, `A`, `apple`, `"3"`, `` `3` ``, `'3'`, and `:3`.
- All reported tests behaved as expected.

### Step 2 — Denominator Input Validation

- Temporarily commented out numerator entry and validation to test denominator input in isolation.
- Accepted correctly: `1`, `0`, `122`, `3.45`, and `-2.0009`.
- Returned the expected input-validation error: `[sp]^Z`, `!`, `a`, `A`, and `apple`.
- All reported tests behaved as expected.

### Step 3 — Division-by-Zero Exception Handling

- Tested exception handling only; calculating and displaying the quotient has not been implemented yet.
- Entered numerator `9` and denominator `2`: no error was reported.
- Entered numerator `9` and denominator `0`: the exception was thrown, caught, and reported as expected.
- Entered numerator `0` and denominator `0`: the exception was also thrown, caught, and reported.
- That last result made me pause: shouldn’t any number divided by itself equal `1`? It turns out that rule excludes zero! The `0/0` test exposed a gap in my understanding, not a bug in the program. No code correction was needed.

### Step 4 — Quotient Calculation and Division-by-Zero Handling

- Calculated and displayed correctly:
  - `90 / -.00001 = -9e+06`
  - `10 / 2 = 5`
  - `-3 / 1.5 = -2`
  - `100 / 50 = 2`
  - `290 / 48 = 6.04167`
  - `.00045 / .00005 = 9`
  - `-7 / -7 = 1`

- Returned the expected runtime error: `9 / 0`, `0 / 0`, `1 / 0`, `.0005 / 0`, `-2.005 / 0`, and `23000 / 0`.
- All reported tests behaved as expected.