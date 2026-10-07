<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)

# Week 6 Programming Assignment — 


---

| Rubric Criterion | Score | Evaluation |
| --- | --- | --- |
| Program meets stated requirements and produces correct results | **40/40** | The program meets the core task. It stores five quiz scores in an array, traverses the array with a `for` loop, calculates the total and average, determines highest and lowest scores, and uses strings for the student's name and report heading. I independently compiled and ran the submitted `.cpp`; it compiled successfully with warnings enabled and produced **Total = 421.50, Average = 84.30, Lowest = 46.00, Highest = 100.00**, which are correct. |
| Correct use of C++ concepts taught in Week 6 | **25/25** | Strong demonstration of Week 6 concepts: a fixed `double` array, indexed sequential traversal, `sizeof` to determine array length, `std::string`, string `append()`, and loop-based accumulation/comparison. The implementation remains within the intended introductory C++ scope. |
| Testing, validation, and correction of errors | **7/20** | This is the major deficiency. The assignment explicitly requires a **test table with at least five test cases containing input, expected result, actual result, and pass/fail**. The submitted `05__TestTableNote.md` discusses testing concepts and debugging, but it does **not contain the required five-case test table**. The statement that little testing is necessary because the data is fixed does not eliminate the assignment requirement. Fixed datasets could still be changed temporarily to test normal, boundary, duplicate-high/low, decimal, and other cases. |
| Readability, organization, naming, and comments | **8/10** | The code is readable, well commented, and the output is clearly formatted. Names such as `quiz_scores`, `student_name`, `report_heading`, `highest`, and `lowest` are meaningful. The pseudocode is detailed and corresponds to the implementation. A minor design weakness is that the score array, totals, extrema, average, and array length are declared globally when they could be local to `main()`. Also, `total` should ideally be explicitly initialized to `0.0` rather than relying on global/static initialization. |
| Required submission evidence / AI transparency | **3/5** | Source code, pseudocode, a testing note, and execution screenshot are present. However, the required test table is missing, and I do not see an **AI Assistance Log or an explicit “No AI was used” statement** in the submitted materials. |
| **TOTAL** | **83/100** | **B** |

### Student Feedback

Eric, your actual C++ program is strong and correctly demonstrates the Week 6 concepts of arrays, strings, loops, and sequential data processing. The program compiled successfully and produced the correct total, average, lowest, and highest values. Your pseudocode is detailed, your variable names are meaningful, and your comments show that you understand issues such as array indexing, determining array length, and string concatenation. The primary deduction is for the required testing component. The assignment specifically requires **at least five documented test cases showing input, expected result, actual result, and pass/fail**. Your testing note explains what you checked and describes problems you corrected, but it does not substitute for the required test table. Even though the final program uses a fixed dataset, you could temporarily test five different arrays—for example, all identical scores, scores containing 0 and 100, decimal scores, a single highest value, and a single lowest value—and document the expected and actual calculations. Also, explicitly initialize accumulators such as `total` and keep variables local unless global scope is necessary. Finally, include an AI Assistance Log when AI is used or explicitly state that no AI was used.

**Final: 83/100 (B)**