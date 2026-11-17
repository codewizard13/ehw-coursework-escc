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



---

## 🧪 Planned Test Coverage

1. Calculate statistics for mixed whole-number and decimal scores: `90, 100, 100, 85.5, 46`.
2. Identify a tied highest score: `85, 90, 98.5, 98.5, 76.5`.
3. Identify a tied lowest score: `90, 62.5, 38, 38, 98`.
4. Process scores containing both boundary values, 0 and 100: `0, 76, 2, 100, 98.5`.
5. Calculate statistics when all scores are identical: `100, 100, 100, 100, 100`.
6. Identify a single highest and lowest score: `92.6, 73, 79, 78.5, 90.5`.




