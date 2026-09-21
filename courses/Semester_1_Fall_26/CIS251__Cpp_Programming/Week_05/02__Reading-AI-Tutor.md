<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# CIS 251 - C++ Programming:  <br>  Week 5 Reading Tutorial & AI Tutor

CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 5: Functions, Parameters, Return Values, and Program Decomposition

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain why functions improve program organization.
*   Write function prototypes and definitions.
*   Pass information with parameters.ZZ
*   Return a value from a function.
*   Distinguish local scope from broader scope.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. Decomposing a Problem

A function is a named block of code that performs one focused task. Instead of placing every operation inside `main()`, divide a program into meaningful units such as `getInput()`, `calculateTotal()`, and `displayResults()`.

## 2\. Functions That Return Values

```
double calculateTax(double subtotal, double rate) {
    return subtotal * rate;
}
```

The return type is `double`. The parameters receive values supplied by the caller. The `return` statement sends one value back.

```
double tax = calculateTax(100.0, 0.09);
```

## 3\. void Functions

```
void printHeading() {
    cout << "CIS 251 Calculator" << endl;
}
```

A `void` function performs an action but does not return a value.

## 4\. Prototypes and Scope

```
double calculateTax(double subtotal, double rate);

int main() {
    double tax = calculateTax(50.0, 0.09);
}

double calculateTax(double subtotal, double rate) {
    return subtotal * rate;
}
```

A prototype tells the compiler about the function before it is called. Variables declared inside a function are local to that function.

## Guided Practice Before Graded Work

1.  Convert a repeated calculation into a function.
2.  Write a void function that prints a menu.
3.  Write a function that accepts two numbers and returns the larger.
4.  Add prototypes above main() and definitions below main().
5.  Trace which values are local to each function.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Functions.](https://www.w3schools.com/cpp/cpp_functions.asp)
*   [W3Schools — C++ Function Parameters.](https://www.w3schools.com/cpp/cpp_function_param.asp)
*   [W3Schools — C++ Function Return Values.](https://www.w3schools.com/cpp/cpp_function_return.asp)
*   [TutorialsPoint — C++ Functions.](https://www.tutorialspoint.com/cplusplus/cpp_functions.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   user-defined functions
*   return values
*   parameters / arguments

### Bro Code — C++ User-Defined Functions (#15)

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

> Your Week 5 program should reorganize previously learned input, calculations, decisions, and/or loops into clear functions. Functions are the new concept; the underlying calculations should already be familiar.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  What is the difference between a parameter and an argument?
2.  When should a function return a value?
3.  What does void mean?
4.  Why might a prototype be needed?
5.  What is local scope?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”