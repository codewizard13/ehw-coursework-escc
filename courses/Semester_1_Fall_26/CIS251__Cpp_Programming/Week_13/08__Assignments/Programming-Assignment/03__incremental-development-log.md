# 🛠️ Incremental Development Log

## 📘 Assignment Information

- **Course:** CIS-251 — C++ Programming
- **Assignment:** Week 13 — Integration: STL Containers, Algorithms, & Design Refactoring
- **Author:** Eric L. Hepperle
- **Program:** Vector Score List Analyzer, v 1.0

## 📋 Initial Design and Planning

[#WIP]
I plan to use my **Assignment 6 Score List Analyzer** as the starting point and refactor it to use `std::vector` and STL features while preserving its original purpose: *displaying five quiz scores and reporting* their **total**, **average**, **highest**, and **lowest** values. The original program produced correct results, but I earned an 83/100 primarily because I omitted the required five-case test table. My plan addresses that feedback along with the instructor’s recommendations for variable scope, explicit initialization, and AI-use documentation. The program will remain a basic demonstration of the assigned concepts rather than a complex application.

- Replace the fixed array with a vector
- use a range-based loop or iterator pattern (probably a foreach)
- Incorporate one standard algorithm from the readings.
- Keep variables local to `main()` unless global is necessary
- explicitly initialize the decimal values to `0.0`, instead of relying on implicit init
- Compare the array and vector versions in comments.
- Include a test table with at least 5 different test cases

- The separate algorithm document describes the implementation approach.

## 🏗️ Incremental Implementation

### 1. Build the Initial ...

### 2. ...

### 3. ...

---

Learnings & Challenges ...

-  // Naming note: Scores are the numeric values, grades are the letter values they correspond with in the A-F grading system

- Originally I had this:

  total = accumulate(scores.begin(), scores.end(), 0);

  and it was truncating the total from 421.50 to 421

  I added setprecision(2) fixed and it was now displaying  2 decimal places, but it still had truncated the decimal part. Then I read the Fluen{C++} blog and found the actual solution. -- the `0` in the 3rd parameter is sort of like a seed -- by starting it as `0.0`, you tell the accumulate() function that you want to do decimal division.

-   // Loop through and display each score in single horizontal line
  //  - #GOTCHA: Apparently C++ doesn't have any sort of `join()` one-liner
  - I tried to use accumulate() as a join function, and it will join strings, but there's no built-in way to add a custom delimiter. Considered including headers for // #include <ranges>
// #include <string_view> to build a custom join() function, but it seemed like too much extra code and beyond the immedate scope of this assignment, so I didn't.

- In my printGradeReport() func, I noticed the first row of scores prints correctly (mixed decimals and ints), but every subsequent iteration has all numeric values as decimals. I decided to fix it by storing the current precision before I change precision to 2 (it is 6 by default, but I'm trying to account for if it might  been changed to something else at some point. Whatever value it is, this restores it correctly):

```
  // Store current precision
  streamsize saved_precision = cout.precision();

  // Set precision to 2 decimal places
  cout << setprecision(2) << fixed;

  // DO STUFF ...

  // Restore the saved precision and notation
  cout << defaultfloat << setprecision(saved_precision);
  ```

- #GOTCHA: I tried creating a mixed elmenent 2-dimensional vector to no avail -- though a 2-dim vector is definitely valid, not with mixed types, ex:

```
  vector<vector<double>> testHarness = {
      {{85, 90, 98.5, 98.5, 76.5}, "Test 1"},
      {{90, 62.5, 38, 38, 98}, "Test 2"}

  };

... 

  for (auto test : testHarness)
  {
    printGradeReport(test, total, avg, highest, lowest);
  }
  ```

Google Gemini provided this suggestion:

Using a struct is the cleanest way to bundle each test's label, description, and score set together into a single std::vector.
Defining a custom struct lets you use the range-based for loop required by your assignment while keeping all test metadata in one place.

-- Seems promising -- I'll let you know if it works

  // Naming note: Scores are the numeric values, grades are the letter values they correspond with in the A-F grading system ( I may have already noted this earlier)

- 
3. Loop Through With a Range-Based for Loop

Using const auto &test avoids copying each vector of scores on every iteration and directly satisfies your assignment's range-based loop requirement:
cpp
for (const auto &test : testHarness) {
    cout << "\n============ " << test.title << " ============\n";
    cout << "# " << test.description << "\n";
    cout << "--------------------------------------\n";
    printGradeReport(test.scores, total, avg, highest, lowest);
}

- Added .0 to highest and lowest sentinel values to be consistent about float usage
- CONFIRMING: Yes - the custom struct solved the mixed values issue!

---

## 🧪 Planned Test Coverage

1. Calculate statistics for mixed whole-number and decimal scores: `90, 100, 100, 85.5, 46`.
2. Identify a tied highest score: `85, 90, 98.5, 98.5, 76.5`.
3. Identify a tied lowest score: `90, 62.5, 38, 38, 98`.
4. Process scores containing both boundary values, 0 and 100: `0, 76, 2, 100, 98.5`.
5. Calculate statistics when all scores are identical: `100, 100, 100, 100, 100`.




