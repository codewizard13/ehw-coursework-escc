# 🛠️ Incremental Development Log

## 📘 Assignment Information

- Course: CIS-251 — C++ Programming
- Assignment: Week 11 — Exceptions, Error Handling, and Robust Programs
- Author: Eric L. Hepperle
- Program: Divide By Zero Error Handling, version 1.01

## 📋 Initial Design and Planning

Selected safe division to demonstrate routine numeric input validation with decisions and division-by-zero handling with `try`/`throw`/`catch`.

The planned program reads a numerator and denominator, rejects nonnumeric input, and either displays the quotient or reports division by zero.

## 🏗️ Incremental Implementation

### 1. Add Program Structure and Numerator Validation

- Added `<iostream>`, `<stdexcept>`, and `using namespace std;`.
- Added start and end program banners.
- Declared `numerator` and `denominator` as `double` variables initialized to `0.0`.
- Added the numerator prompt and an `if` statement to check whether input succeeds.
- Added an input-error message and `return 1` for unsuccessful input.
- Displayed the accepted numerator to verify this stage.

## 🧪 Testing

### Step 1 — Numerator Input Validation

- Accepted correctly: `1`, `0`, `6`, `200`, `-3`, `.05`, `2.5`, and `-2.5`.
- Returned the expected input-validation error: `[sp]^Z`, `!`, `a`, `A`, `apple`, `"3"`, `` `3` ``, `'3'`, and `:3`.
- All reported tests behaved as expected.