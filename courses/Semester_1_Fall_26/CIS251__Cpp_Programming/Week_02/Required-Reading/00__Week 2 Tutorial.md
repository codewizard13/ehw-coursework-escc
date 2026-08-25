<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# CIS 251 - C++ Programming:  Week 2: Variables, Data Types, and Operators

## ⭐ Week 2: Variables, Data Types, and Operators

### _Understanding how C++ stores and manipulates information_

##  1. What You Will Learn This Week

By the end of Week 2, you will be able to:

*   Declare and initialize variables
    
*   Choose appropriate data types
    
*   Use arithmetic and assignment operators
    
*   Understand identifiers and naming rules
    
*   Apply best practices for readable, meaningful code
    
*   Write programs that perform calculations using user‑provided values
    

## 🌟 2. Required Reading & Study Resources

### 📘 W3Schools

*   **C++ Variables** `https://www.w3schools.com/cpp/cpp_variables.asp` [(w3schools.com in Bing)Links to an external site.](https://www.bing.com/search?q=%22https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_variables.asp%22)
    
*   **C++ Data Types** `https://www.w3schools.com/cpp/cpp_data_types.asp` [(w3schools.com in Bing)Links to an external site.](https://www.bing.com/search?q=%22https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_data_types.asp%22)
    
*   **C++ Operators** `https://www.w3schools.com/cpp/cpp_operators.asp` [(w3schools.com in Bing)Links to an external site.](https://www.bing.com/search?q=%22https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_operators.asp%22)
    

### 📘 TutorialsPoint

*   **C++ Data Types** `https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm` [(tutorialspoint.com in Bing)Links to an external site.](https://www.bing.com/search?q=%22https%3A%2F%2Fwww.tutorialspoint.com%2Fcplusplus%2Fcpp_data_types.htm%22)
    
*   **C++ Operators** `https://www.tutorialspoint.com/cplusplus/cpp_operators.htm` [(tutorialspoint.com in Bing)Links to an external site.](https://www.bing.com/search?q=%22https%3A%2F%2Fwww.tutorialspoint.com%2Fcplusplus%2Fcpp_operators.htm%22)
    

### 📘 CppInstitute Essentials 1

*   **Module:** Variables, Data Types, and Operators [https://cppinstitute.org/cpp-essentials-1Links to an external site.](https://cppinstitute.org/cpp-essentials-1)
    

## 🌟 3. Instructor Explanation (Full Tutorial)

### 🔹 What are variables?

Variables are **containers** that store information your program needs.

cpp

```
int age = 21;
double gpa = 3.8;
char grade = 'A';
bool isEnrolled = true;
```

### 🔹 Choosing the correct data type

*   **int** → whole numbers
    
*   **double** → decimal numbers
    
*   **char** → single characters
    
*   **bool** → true/false
    

### 🔹 Identifiers (variable names)

Rules:

*   Must start with a letter or underscore
    
*   Cannot contain spaces
    
*   Cannot be a C++ keyword
    
*   Should be meaningful
    

Good:

cpp

```
double monthlyPayment;
```

Bad:

cpp

```
double mp;
```

### 🔹 Assignment and arithmetic operators

cpp

```
int x = 10;
int y = 3;

int sum = x + y;
int diff = x - y;
int product = x * y;
double quotient = x / y;
```

### 🔹 Combined assignment

cpp

```
x += 5;   // x = x + 5
y *= 2;   // y = y * 2
```

### 🔹 Why this matters

Variables and operators are the **foundation** of all computation. Every program you write — from calculators to AI‑assisted tools — relies on them.

## 🌟 4. Required Videos (Embedded)

### ▶️ Bro Code — Variables & Data Types (#3)

**Embed this video in Canvas:** [https://www.youtube.com/watch?v=BDxRhhs36ns&list=PL0lo9MOBetEHvO-spzKBAITkkTqv4RvNlLinks to an external site.](https://www.youtube.com/watch?v=BDxRhhs36ns&list=PL0lo9MOBetEHvO-spzKBAITkkTqv4RvNl)[![](/images/play_overlay.png)](https://www.youtube.com/watch?v=BDxRhhs36ns&list=PL0lo9MOBetEHvO-spzKBAITkkTqv4RvNl)

### ▶️ Bro Code — C++ Operators

**Embed this video in Canvas:** [https://www.youtube.com/watch?v=S3nx34WFXjI&list=PLZPZq0r\_RZOMHoXIcxze\_lP97j2Ase2onLinks to an external site.](https://www.youtube.com/watch?v=S3nx34WFXjI&list=PLZPZq0r_RZOMHoXIcxze_lP97j2Ase2on)[![](/images/play_overlay.png)](https://www.youtube.com/watch?v=S3nx34WFXjI&list=PLZPZq0r_RZOMHoXIcxze_lP97j2Ase2on)

## 🌟 5. Practice Examples

### Example 1 — Declaring variables

cpp

```
int students = 25;
double temperature = 98.6;
char section = 'B';
bool passed = true;
```

### Example 2 — Using operators

cpp

```
int a = 12;
int b = 5;

cout << "Sum: " << a + b << endl;
cout << "Difference: " << a - b << endl;
cout << "Product: " << a * b << endl;
cout << "Quotient: " << a / b << endl;
```

### Example 3 — Combined assignment

cpp

```
int score = 50;
score += 10;  // now 60
score *= 2;   // now 120
```

## 🌟 6. Required Practice Exercises

### ✔️ Exercise 1 — Declare variables

Create variables for:

*   Your first name
    
*   Your age
    
*   Your height
    
*   Your favorite number
    

Print them using `cout`.

### ✔️ Exercise 2 — Math program

Ask the user for two numbers. Compute:

*   Sum
    
*   Difference
    
*   Product
    
*   Quotient
    
*   Remainder
    

### ✔️ Exercise 3 — Salary calculator

Ask the user for:

*   Hourly wage
    
*   Hours worked
    

Compute weekly pay.