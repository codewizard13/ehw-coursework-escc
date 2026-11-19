## 📊 Pseudocode Algorithm

# WEEK 13 PROGRAMMING ASSIGNMENT — Integration: STL Containers, Algorithms, & Design Refactoring

### 🏗️ Overview

1. Include libraries for console output, strings, formatting, vectors, numeric operations, and algorithms.
2. Declare use of the standard namespace.
3. Define a `TestCase` structure containing a title, description, and score vector.
4. Declare `printGradeReport()` to calculate and display each dataset’s statistics.
5. Run five labeled tests through the same reporting function.

### 🧩 FUNCTION: `main()`

1. Display a blank line followed by the opening banner:

   ```text
   ** START PROGRAM **
   ```

2. Initialize a `vector<TestCase>` containing five test records:

   | Test | Description | Scores |
   |---|---|---|
   | 1 | Mixed decimal and int values | `90, 100, 98.25, 85.5, 46` |
   | 2 | Tied high score | `85, 90, 98.5, 98.5, 76.5` |
   | 3 | Tied low score | `90, 62.5, 38, 38, 98` |
   | 4 | Score set contains both boundaries (0 & 100) | `0, 76, 2, 100, 98.5` |
   | 5 | All scores identical | `100, 100, 100, 100, 100` |

3. Define the report strings:
   - Set `student_name` to `"Eric Hepperle"`.
   - Set `report_heading` to `"Grade Report for: "`.
   - Append the student’s name to the report heading.
   - Retain these strings from the original program; the current harness does not display them.

4. Initialize local statistics:
   - `highest = -999.0`
   - `lowest = 999.0`
   - `total = 0.0`
   - `avg = 0.0`

5. Execute the test harness as described below.

### 🧪 Initialize and Run Tests

1. Use a range-based loop to access each test by constant reference: `const auto &test`.

2. For each test:
   - Display a blank line, its title, its description, and a divider.
   - Call `printGradeReport(test.scores, total, avg, highest, lowest)`.

   Example heading:

   ```text
   ============ TEST CASE: 1 ============
   # Mixed decimal and int values
   --------------------------------------
   ```

3. End the loop after all five tests have been processed.

### 🧩 FUNCTION: `printGradeReport()`

1. Receive:
   - A nonempty score vector by constant reference.
   - References to the total, average, highest, and lowest variables.

2. Display `Scores: `.

3. Use an indexed loop to display the scores on one line:
   - Print the current score.
   - Print a comma and space unless it is the last score.
   - After the last score, print a newline.

4. Display a divider.

5. Calculate the total using `accumulate()`:
   - Process the range from `scores.begin()` to `scores.end()`.
   - Use `0.0` as the initial accumulator value.
   - Assign the result to `ttl`.

6. Calculate the average:
   - `avg = ttl / scores.size()`

7. Determine the highest and lowest scores:
   - Use `max_element()` and dereference its returned iterator to assign `max`.
   - Use `min_element()` and dereference its returned iterator to assign `min`.

8. Save the current console precision.

9. Set output to fixed notation with two decimal places.

10. Display:
    - Total.
    - Average.
    - Highest score.
    - Lowest score.

11. Restore the saved precision and reset floating-point notation with `defaultfloat`.

12. Return control to the test loop in `main()`.

### 🏁 Finish

1. After the test loop, display a blank line followed by the closing banner:

   ```text
   ** END PROGRAM **
   ```

2. Return `0` to end the program.