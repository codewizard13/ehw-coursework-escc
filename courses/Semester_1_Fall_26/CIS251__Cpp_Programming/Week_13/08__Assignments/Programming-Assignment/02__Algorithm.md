## 📊 Pseudocode Algorithm

# WEEK 13 PROGRAMMING ASSIGNMENT — Integration: STL Containers, Algorithms, & Design Refactoring.

### 🏗️ Overview:

1. Include input-output (I/O) stream and I/O manipulation libraries
2. Declare an array of quiz scores
3. Create a function `getGradeReport()` to calculate and report the grade values
4. Foreach test set, get/print grade report



### 🧩 FUNCTION: `main()`:
5. Define a `quiz_scores` vector with five scores:
   - `90, 100, 100, 85.5, 46`

6. Declare four doubles in the `main()` scope: two sentinel values and two values initialized to `0.0`
   - double highest = -999;
   - double lowest = 999;
   - double total = 0.0;
   - double avg = 0.0;
7. Define strings for `student_name` and `report_heading`
8. Use `.append()` to concatenate the student name at the end of the report_heading

### 🧩 FUNCTION: Define `getGradeReport()`:

8.5 Print all quiz scores. the program intro in console should look like this, SO FAR, with basic program decoration:

```
******** START PROGRAM *********************************
Grade Report for: Eric Hepperle
Scores: 90, 100, 100, 85.5, 46
=================================
```


9. Foreach quiz score in the `quiz_scores` vector (use range based for loop),
   - total += current quiz score
   - // do I need to dereference, because vector iterators are pointers, right??
   - Calculate `highest` as if current score greater than highest, then set highest to current score
   - Calculate `lowest` as if current score lower than lowest, then set lowest to current score
- END LOOP

10. Display a divider decoration

11. Calculate `avg` as total / length of vector

12. Set precision to 2 decimals fixed

13. Display output stats for total, avg, lowest, highest


14. END function

### 🧪 Initialize and Run Tests

6. Start the program, display the opening message, and configure numeric output to use two decimal places. Before each numbered test, display its test-number heading.



### 🏁 Finish

18. Display the end-program message and end the program.

```
******** END PROGRAM ***********************************
```