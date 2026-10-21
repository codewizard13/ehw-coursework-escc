<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren


# Week 10 Reading AI Tutorial: Operator Overloading, Enumerations, and Interface Design

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Use enum/enum class to represent named states.
*   Explain operator overloading.
*   Implement one simple overloaded operator.
*   Recognize when operator overloading improves or harms readability.
*   Design a small class interface consistently.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1. Enumerations

An enumeration gives meaningful names to a finite set of choices.

```cpp
enum class Status {
    Pending,
    Active,
    Complete
};

Status current = Status::Active;
```

`enum class` is generally safer than an unscoped enum because its names stay inside the enumeration's scope.

## 2. Why Overload Operators?

Operator overloading lets user-defined classes participate in familiar syntax when that syntax has a natural meaning. For example, adding two `Time` or `Fraction` objects can be clearer as `a + b` than as `a.add(b)`.

## 3. A Simple + Overload

```cpp
class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    Counter operator+(const Counter& other) const {
        return Counter(value + other.value);
    }

    int getValue() const {
        return value;
    }
};
```

The operator function returns a new object rather than modifying either original object.

## 4. Keep Meaning Predictable

Do not overload an operator with a surprising meaning. If `+` deletes data or prints a report, the interface will confuse readers. The goal is readable, unsurprising code.

## Guided Practice Before Graded Work

1.  Create an enum class for a three- or four-state process.
2.  Use a switch statement with the enum values.
3.  Create a small class holding one numeric value.
4.  Overload + to combine two objects naturally.
5.  Test that the original objects remain unchanged after addition.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Enums](https://www.w3schools.com/cpp/cpp_enum.asp)
*   [TutorialsPoint — C++ Operator Overloading](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   enums
*   operator overloading (use the playlist/search within the playlist if present)

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

- ENUMS in C++ explained easy: https://www.youtube.com/watch?v=Fqn4pSRH6Ec
- C++ overloaded functions explained: https://www.youtube.com/watch?v=LZd5LhfnYsk&t=9s (not operator overloading)

## Preparing for This Week's Programming Assignment

Week 10 should use enums and one straightforward overloaded operator. You are not expected to overload many operators or learn template metaprogramming.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  Why are named enum values clearer than unexplained integers?
2.  When does operator overloading improve readability?
3.  What should operator+ normally return in a value-like class?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

> **Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”
