<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# CIS 251 - C++ Programming:  <br>  # Week 6 Reading Tutorial & AI Tutor

CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 6: Arrays and Strings

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Store multiple values in an array.
*   Use indexes safely.
*   Traverse arrays with loops.
*   Use std::string for text processing.
*   Combine loops, arrays, strings, and functions.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. Arrays

An array stores multiple values of the same type under one name. Each element has an index beginning at zero.

```
int scores[5] = {88, 92, 76, 95, 84};
cout << scores[0];   // 88
cout << scores[4];   // 84
```

For an array with five elements, valid indexes are 0 through 4. Accessing an index outside that range produces undefined behavior.

## 2\. Traversing an Array

```
int scores[5] = {88, 92, 76, 95, 84};
int total = 0;

for (int i = 0; i < 5; i++) {
    total += scores[i];
}

double average = total / 5.0;
```

The loop variable becomes the index. This pattern lets one small block process every element.

## 3\. Strings

`std::string` stores a sequence of characters and provides useful operations such as `length()` and indexing.

```
string name = "Rosalyn";
cout << name.length() << endl;
cout << name[0] << endl;
```

`cin >> name` normally stops at whitespace. Use `getline(cin, name)` when you need a full line containing spaces.

## 4\. Arrays with Functions

```
double average(const int values[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += values[i];
    }
    return static_cast<double>(total) / size;
}
```

Passing the size separately is important because a function generally cannot determine the number of array elements from the array parameter alone.

## Guided Practice Before Graded Work

1.  Create and display a five-element integer array.
2.  Calculate the sum and average with a loop.
3.  Find the largest value in an array using a running 'largest' variable.
4.  Read a full name with getline().
5.  Write a function that accepts an array and size and returns an average.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ ArraysLinks to an external site.](https://www.w3schools.com/cpp/cpp_arrays.asp)
*   [W3Schools — C++ StringsLinks to an external site.](https://www.w3schools.com/cpp/cpp_strings.asp)
*   [TutorialsPoint — C++ ArraysLinks to an external site.](https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm)
*   [TutorialsPoint — C++ StringsLinks to an external site.](https://www.tutorialspoint.com/cplusplus/cpp_strings.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   arrays
*   iterating over arrays
*   strings / getline

### Bro Code — C++ Array Iteration for Beginners

### Bro Code — C++ for-each Loop

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

The Week 6 assignment should ask you to store and process collections of values or text using arrays/strings, loops, and functions already learned.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  What is the first valid array index?
2.  What is the last valid index in an array of size 10?
3.  Why is getline useful?
4.  Why should an array-processing function receive a size parameter?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”