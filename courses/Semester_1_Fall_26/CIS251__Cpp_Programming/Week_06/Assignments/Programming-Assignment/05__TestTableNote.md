### 🔢 Test Table

# Week 6 Programming Assignment - Arrays, Strings, and Sequential Data Processing

Because there was no input and all the data was fixed in this assignment, testing consisted of:
 
-  Ensuring the for loop was set up correctly. For instance, if I had used `i = 1` instead of `i = 0` we would have had an off-by-one error
  
-  Ensuring the sizeof() function and the array length calculation were correct. If I had used `sizeof(quiz_scores)` for array_len instead of `sizeof(quiz_scores) / sizeof(double)` the loop would have ran too many times

- For the `append()` statement, I originally tried this syntax, which failed: `string report_heading = "Grade Report for: ".append(student_name)`  — that is legal in JavaScript for instance, but apparently not in C++. I also tried wrapping the "Grade ..." string in parentheses and it also failed to compile. Finally, I discovered that I could use the `append()` function by assigning the string literal to the variable `report_heading`, then appending onto that variable. You can also append strings using the `+` concatenation operator.

