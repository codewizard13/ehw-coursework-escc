## 📊 Pseudocode Algorithm

# WEEK 14 PROGRAMMING ASSIGNMENT — AI-Assisted Review: Distance Class Refactor

### 🏗️ Overview

1. Include libraries for console output, strings, math, and output formatting.
2. Declare use of the standard namespace.
3. Define a scoped `Unit` enumeration with `inch`, `foot`, and `mile`.
4. Define a `Distance` class that:
   - Stores endpoints, an absolute distance, a unit, and a unit label.
   - Converts between units and adds distances.
   - Displays a formatted result.
5. Run fifteen labeled tests in `main()`, each printing its description, inputs, and expected output before the actual result.

### 🧩 ENUM: `Unit`

1. Define `enum class Unit` with three values:

   | Value | Meaning |
   |---|---|
   | `Unit::inch` | Inch |
   | `Unit::foot` | Foot |
   | `Unit::mile` | Mile |

2. Use a scoped enum so the names stay inside `Unit` and don't silently convert to integers.

### 🧩 CLASS: `Distance`

**Private members (with default values):**

1. `start = 0.00`
2. `end = 0.00`
3. `unit = Unit::inch`
4. `unitTxt = "inches"`
5. `dist = 0.00`

**Default constructor `Distance()`:**

1. Do nothing. The default member values apply.

**Constructor `Distance(start, end, unit = Unit::inch)`:**

1. Store `start` and `end`.
2. Calculate `dist = abs(end - start)`, so reversed endpoints still give a positive distance.
3. Store `unit`.
4. Set `unitTxt = setUnitText()`. This runs last, so the label reflects the final `dist` and `unit`.

### 🔤 FUNCTION: `setUnitText() const`

1. Calculate `isOne = abs(dist - 1.0) < 0.005`. This treats values within 0.005 of 1.0 as singular, which matches the two-decimal display and guards against floating-point error.
2. Select the label by `unit`:

   | Unit | Singular (`isOne`) | Plural |
   |---|---|---|
   | `inch` | `"inch"` | `"inches"` |
   | `foot` | `"foot"` | `"feet"` |
   | `mile` | `"mile"` | `"miles"` |

3. Return the chosen label.
4. If no case matches, return `"Error: unit unknown"`.

### 📏 FUNCTION: `unitToInch(unit) const`

1. If `unit` is `inch`, return `1.0`.
2. If `unit` is `foot`, return `12.0`.
3. Otherwise (mile), return `63360.0`.

### 🔄 FUNCTION: `convertUnit(value, from, to) const`

1. Calculate `value * unitToInch(from) / unitToInch(to)`.
2. Return the converted value.

### 🖥️ FUNCTION: `display() const`

1. Print `Distance: ABS (`, then `end`, then ` - `, then `start`, then `) = `.
2. Print `dist`, a space, and `unitTxt`, followed by a newline.

   Example output:

   ```text
   Distance: ABS (10.00 - 2.00) = 8.00 inches
   ```

### ➕ FUNCTION: `operator+(const Distance &d) const`

1. Set `rightDist = d.dist`.
2. If the two units differ:
   - Convert the right operand into the left operand's unit with `convertUnit(d.dist, d.unit, this->unit)`.
   - Store the result in `rightDist`.
3. Build the result with the constructor: `Distance(0.0, this->dist + rightDist, this->unit)`.
   - The constructor sets `dist` and refreshes `unitTxt`.
4. Return the new `Distance`.
5. Because the left operand's unit always wins, operand order can change the result unit.

### 🧩 FUNCTION: `main()`

1. Display a blank line followed by the opening banner:

   ```text
   ** START DISTANCE CALC PROGRAM **
   ```

2. Display the current file name using `__FILE__`.
3. Set output to fixed notation with two decimal places.
4. Run the tests described below, in order.
5. Display a blank line followed by the closing banner:

   ```text
   ** END PROGRAM **
   ```

6. Return `0`.

### 🧪 Initialize and Run Tests

**Output pattern for every test:**

1. Display a blank line and a `TEST n` banner.
2. Display `DESCRIPTION:`, `INPUTS:`, and `EXPECTED OUTPUT:` lines.
3. Create the `Distance` object or objects.
4. Call `display()` to show the actual result.

**Basic construction and labels:**

| Test | Description | Inputs | Expected |
|---|---|---|---|
| 1 | Default construction | none | `0.00 inches` |
| 2 | Two endpoints, default unit | `2.0, 10.0` | `8.00 inches` |
| 3 | Second nonzero distance | `4.0, 20.0` | `16.00 inches` |
| 7 | Reversed endpoints, singular inch | `2, 1` | `1.00 inch` |
| 8 | Negative endpoint, plural feet | `4.0, -10.0, foot` | `14.00 feet` |
| 9 | Reversed endpoints, singular mile | `3.0, 2, mile` | `1.00 mile` |

**Same-unit addition:**

| Test | Description | Inputs | Expected |
|---|---|---|---|
| 4 | Add two existing objects | `d2 + d3` | `24.00 inches` |
| 5 | Existing plus temporary object | `d2 + Distance(3, 6)` | `11.00 inches` |
| 6 | Chain three objects | `d2 + d3 + d4` | `48.00 inches` |
| 10 | Direction does not matter | `Distance(2, 10) + Distance(10, 2)` | `16.00 inches` |
| 11 | Two feet objects keep feet | `Distance(0, 2, foot) + Distance(0, 3, foot)` | `5.00 feet` |

For Test 11, also display `a` (`2.00 feet`) and `b` (`3.00 feet`) before showing the sum `c`.

**Mixed-unit addition and edge case:**

| Test | Description | Inputs | Expected |
|---|---|---|---|
| 12 | Foot then inch, result in feet | `Distance(0, 1, foot) + Distance(0, 6, inch)` | `1.50 feet` |
| 13 | Inch then foot, result in inches | `Distance(0, 6, inch) + Distance(0, 1, foot)` | `18.00 inches` |
| 14 | Mile then foot, result in miles | `Distance(1.5, 2.75, mile) + Distance(0, 6009, foot)` | `2.39 miles` |
| 15 | Floating-point sum near 1.0 | `0.2 + 0.7 + 0.1` feet | `1.00 foot` |

Notes on specific tests:

1. Test 12: 12 inches + 6 inches = 18 inches = 1.50 feet.
2. Test 13: 6 inches + 12 inches = 18 inches.
3. Test 14: 1.25 miles + about 1.14 miles = about 2.39 miles.
4. Test 15: the sum is stored as `0.9999999999999999`, and the tolerance check in `setUnitText()` still selects the singular label.

### 🏁 Finish

1. After Test 15, display a blank line followed by the closing banner.
2. Return `0` to end the program.