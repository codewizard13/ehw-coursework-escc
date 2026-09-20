<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# CIS 251 - C++ Programming:  <br> Week 4 Overview - Loops, Repetition, and Algorithmic Tracing

CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 4: Loops and Repetition

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain initialization, condition, and update in a loop.
*   Use while, do-while, and for loops.
*   Build counters, accumulators, and sentinel loops.
*   Avoid common infinite-loop and off-by-one errors.
*   Trace loop execution manually.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. Why Loops Matter

A loop repeats a block of code while a condition remains true. Without loops, a program that processes 100 values might require 100 nearly identical statements. Loops let the algorithm describe repetition once.

## 2\. while and do-while

```
int count = 1;
while (count <= 5) {
    cout << count << endl;
    count++;
}
```

A `while` loop checks the condition before each iteration, so it may execute zero times. A `do-while` checks after the body, so it executes at least once.

```
int choice;
do {
    cout << "Enter 1 to continue or 0 to stop: ";
    cin >> choice;
} while (choice != 0);
```

## 3\. for Loops

```
for (int i = 0; i < 5; i++) {
    cout << "Iteration " << i << endl;
}
```

A `for` loop places initialization, condition, and update together and is especially useful when the number of repetitions is known.

## 4\. Counters and Accumulators

```
double total = 0.0;
for (int i = 1; i <= 3; i++) {
    double value;
    cin >> value;
    total += value;
}
cout << "Total: " << total;
```

A **counter** tracks how many events occurred. An **accumulator** stores a running total.

## Guided Practice Before Graded Work

1.  Trace a for loop from i=0 through i<4 on paper.
2.  Write a loop that prints 1 through 10.
3.  Write a loop that totals five entered prices.
4.  Write a sentinel loop that stops when the user enters -1.
5.  Create a menu that repeats until Exit is selected.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ While Loop](https://www.w3schools.com/cpp/cpp_while_loop.asp)
*   [W3Schools — C++ For Loop](https://www.w3schools.com/cpp/cpp_for_loop.asp)
*   [W3Schools — C++ Break and Continue](https://www.w3schools.com/cpp/cpp_break.asp)
*   [TutorialsPoint — C++ Loops](https://www.tutorialspoint.com/cplusplus/cpp_loop_types.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

> https://www.youtube.com/watch?v=-TkoO8Z07hI


*   while loops
*   do-while loops
*   for loops
*   break and continue

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

The Week 4 program should use repetition, counters/accumulators, and previously learned decisions. No functions or arrays are required unless the assignment explicitly states otherwise.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  Which loop is guaranteed to execute at least once?
2.  What three parts control a typical for loop?
3.  What causes an infinite loop?
4.  What is the difference between a counter and an accumulator?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”