## 📊 Pseudocode Algorithm

# WEEK 10 PROGRAMMING ASSIGNMENT — Operator Overloading, Enumerations, and Interface Design

### 🏗️ Define the Class and Units

1. Define an enumeration named `Unit` with three choices: inch, foot, and mile. These choices label distances; they do not convert values.

2. Define a `Distance` class with four private members:
   - `start`: starting endpoint, defaulting to zero.
   - `end`: ending endpoint, defaulting to zero.
   - `unit`: selected unit, defaulting to inch.
   - `dist`: travel distance, defaulting to zero.

3. Provide two ways to construct a distance:
   - With no arguments, retain the default member values.
   - With starting and ending endpoints and an optional unit:
     - Store the supplied endpoints.
     - Calculate `dist` as the absolute value of `end − start`.
     - Store the supplied unit, or inch if omitted.

4. Define a display operation:
   - Select the unit label:
     - Inch: use “inch” when `dist` equals one; otherwise, “inches.”
     - Foot: use “foot” when `dist` equals one; otherwise, “feet.”
     - Mile: use “mile” when `dist` equals one; otherwise, “miles.”
   - Display `Distance: ABS (end - start) = dist unit-label`.
   - Format all numeric values with two decimal places.

5. Define addition of two `Distance` objects:
   - Assume both operands use the same unit.
   - Create a new result object.
   - Set its `dist` to the sum of the operands’ stored travel distances.
   - Set its `start` to zero and its `end` to the combined distance.
   - Copy the left operand’s unit to the result.
   - Return the result without changing either operand.

### 🧪 Initialize and Run Tests

6. Start the program, display the opening message, and configure numeric output to use two decimal places. Before each numbered test, display its test-number heading.

7. Test default construction:
   - Create `d1` without arguments.
   - Display `d1`.
   - Expected: `ABS (0.00 - 0.00) = 0.00 inches`.

8. Test supplied endpoints with the default unit:
   - Create `d2` with start `2` and end `10`.
   - Display `d2`.
   - Expected: `ABS (10.00 - 2.00) = 8.00 inches`.

9. Test a second nonzero distance:
   - Create `d3` with start `4` and end `20`.
   - Display `d3`.
   - Expected: `ABS (20.00 - 4.00) = 16.00 inches`.

10. Test addition of existing objects:
    - Add `d2` and `d3`; store the result in `d4`.
    - Display `d4`.
    - Expected: `ABS (24.00 - 0.00) = 24.00 inches`.

11. Test addition with a temporary object:
    - Create a temporary distance with start `3` and end `6`.
    - Add it to `d2`; store the result in `d5`.
    - Display `d5`.
    - Expected: `ABS (11.00 - 0.00) = 11.00 inches`.

12. Test chained addition:
    - Add `d2` and `d3`, then add `d4` to that intermediate result.
    - Store the final result in `d6`.
    - Display `d6`.
    - Expected: `ABS (48.00 - 0.00) = 48.00 inches`.

13. Test reversed endpoints and the singular inch label:
    - Create `d7` with start `2` and end `1`.
    - Display `d7`.
    - Expected: `ABS (1.00 - 2.00) = 1.00 inch`.

14. Test a negative endpoint and the plural feet label:
    - Create `d8` with start `4`, end `−10`, and unit foot.
    - Display `d8`.
    - Expected: `ABS (-10.00 - 4.00) = 14.00 feet`.

15. Test reversed endpoints and the singular mile label:
    - Create `d9` with start `3`, end `2`, and unit mile.
    - Display `d9`.
    - Expected: `ABS (2.00 - 3.00) = 1.00 mile`.

16. Test addition of opposite-direction trips:
    - Create two temporary distances with endpoints `(2, 10)` and `(10, 2)`.
    - Add their travel distances; store the result in `d10`.
    - Display `d10`.
    - Expected: `ABS (16.00 - 0.00) = 16.00 inches`.

17. Test same-unit addition and unit retention:
    - Create `a` with start `0`, end `2`, and unit foot.
    - Create `b` with start `0`, end `3`, and unit foot.
    - Display `a`: `ABS (2.00 - 0.00) = 2.00 feet`.
    - Display `b`: `ABS (3.00 - 0.00) = 3.00 feet`.
    - Add `a` and `b`; store the result in `c`.
    - Display `c`: `ABS (5.00 - 0.00) = 5.00 feet`.

### 🏁 Finish

18. Display the end-program message and end the program.