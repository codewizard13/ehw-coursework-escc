<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren


# Week 13 Reading Tutorial & AI Tutor

CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 13: STL Containers, Iterators, and Algorithms

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain why vector is often preferable to a fixed-size array.
*   Add, access, and remove vector elements.
*   Traverse containers safely.
*   Use selected standard algorithms.
*   Recognize the separation between data structures and algorithms in the STL.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1. The Standard Template Library

The STL provides reusable containers and algorithms. Instead of writing a custom dynamic collection for common tasks, you can use a tested standard container such as `vector`.

## 2. vector

```cpp
#include <vector>

vector<int> scores = {88, 92, 76};
scores.push_back(95);

for (int score : scores) {
    cout << score << endl;
}
```

A vector can grow as elements are added. `size()` reports the current number of elements.

## 3. Algorithms

```cpp
#include <algorithm>

sort(scores.begin(), scores.end());

auto found = find(scores.begin(), scores.end(), 92);
if (found != scores.end()) {
    cout << "92 found" << endl;
}
```

`begin()` and `end()` define the range processed by the algorithm. The `end()` iterator represents the position just after the last element.

## 4. Arrays vs vector

Use a fixed array when a fixed size is genuinely part of the problem and simplicity matters. Use `vector` when the number of items can change or when you want convenient standard operations.

## Guided Practice Before Graded Work

1.  Create a vector of five integers.
2.  Add two more with push\_back().
3.  Display all elements with a range-based for loop.
4.  Sort the vector.
5.  Search for a value with find() and test both found and not-found cases.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Data Structures and STL](https://www.w3schools.com/cpp/cpp_data_structures.asp)
*   [W3Schools — C++ Vectors](https://www.w3schools.com/cpp/cpp_vectors.asp)
*   [W3Schools — C++ Iterators](https://www.w3schools.com/cpp/cpp_iterators.asp)
*   [W3Schools — C++ Algorithms](https://www.w3schools.com/cpp/cpp_algorithms.asp)
*   [TutorialsPoint — C++ STL](https://www.tutorialspoint.com/cplusplus/cpp_stl_tutorial.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   vectors / STL containers
*   range-based loops
*   sorting/searching

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

Week 13 should refactor a familiar collection-processing problem to use vector and selected standard algorithms. It should not require unfamiliar advanced template syntax.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  How does vector differ from a fixed-size array?
2.  What does push\_back do?
3.  What range is represented by begin() and end()?
4.  What does find return when the item is absent?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”