CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 2: Data Types, Constants, Operators, Expressions, and Numeric Calculations

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Choose suitable numeric data types.
*   Use const for values that should not change.
*   Build arithmetic expressions using C++ operators.
*   Apply operator precedence correctly.
*   Format simple numeric results for a console application.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. Numeric Types and Precision

Use `int` when a value is always a whole number, such as quantity or number of students. Use `double` for values that may contain a fractional part, such as price, tax rate, or average.

```
int quantity = 3;
double unitPrice = 19.95;
double subtotal = quantity * unitPrice;
```

If both operands of integer division are integers, C++ discards the fractional portion. For example, `5 / 2` produces `2`. To obtain `2.5`, at least one operand must be floating-point: `5.0 / 2`.

## 2\. Constants

A constant is a named value that should not change while the program runs. Use `const` to communicate that intent.

```
const double TAX_RATE = 0.09;
double tax = subtotal * TAX_RATE;
```

Constants reduce mistakes and make programs easier to maintain. If the tax rate changes, you update one named value instead of hunting through the program for repeated numbers.

## 3\. Arithmetic Operators and Precedence

The main arithmetic operators are `+`, `-`, `*`, `/`, and `%`. The remainder operator `%` works with integers and returns the remainder from division.

```
int totalMinutes = 135;
int hours = totalMinutes / 60;
int minutes = totalMinutes % 60;
```

Multiplication, division, and remainder are evaluated before addition and subtraction. Parentheses make intended grouping explicit.

```
double average = (score1 + score2 + score3) / 3.0;
```

## 4\. Building a Calculation in Stages

```
double price;
int quantity;
const double TAX_RATE = 0.09;

cout << "Price: ";
cin >> price;
cout << "Quantity: ";
cin >> quantity;

double subtotal = price * quantity;
double tax = subtotal * TAX_RATE;
double total = subtotal + tax;

cout << "Subtotal: $" << subtotal << endl;
cout << "Tax: $" << tax << endl;
cout << "Total: $" << total << endl;
```

Breaking a calculation into named intermediate values makes the program easier to read and test.

## Guided Practice Before Graded Work

1.  Predict the value of 10 + 4 \* 3, then verify it in C++.
2.  Compare 5 / 2 with 5.0 / 2.
3.  Convert a number of inches into feet and remaining inches using / and %.
4.  Build a subtotal, tax, and total calculation using a named constant.
5.  Test the calculation with at least three different input sets.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Data TypesLinks to an external site.](https://www.w3schools.com/cpp/cpp_data_types.asp)
*   [W3Schools — C++ OperatorsLinks to an external site.](https://www.w3schools.com/cpp/cpp_operators.asp)
*   [W3Schools — C++ ConstantsLinks to an external site.](https://www.w3schools.com/cpp/cpp_constants.asp)
*   [W3Schools — C++ MathLinks to an external site.](https://www.w3schools.com/cpp/cpp_math.asp)
*   [TutorialsPoint — C++ Data TypesLinks to an external site.](https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm)
*   [TutorialsPoint — C++ Constants/LiteralsLinks to an external site.](https://www.tutorialspoint.com/cplusplus/cpp_constants_literals.htm)
*   [TutorialsPoint — C++ OperatorsLinks to an external site.](https://www.tutorialspoint.com/cplusplus/cpp_operators.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   Variables and basic data types
*   Arithmetic operators
*   Type conversion / numeric expressions

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

The Week 2 Purchase Total Calculator should be solvable entirely with input, variables, constants, arithmetic operators, and output. Do not add decision statements or loops unless your instructor explicitly asks you to.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  Why can integer division surprise a beginner?
2.  When should a value be declared const?
3.  What is the result of 17 % 5?
4.  Why is (a + b + c) / 3.0 safer than dividing by 3 when an average can be fractional?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”