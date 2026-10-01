<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# CIS 251 - C++ Programming:  <br> Week 7 Reading Tutorial & AI Tutor

CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 7: References, Pointers, Addresses, and Memory

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain the relationship among variables, addresses, pointers, and references.
*   Use & to obtain an address and \* to dereference a pointer.
*   Use references for controlled pass-by-reference.
*   Recognize null pointers and basic pointer safety.
*   Connect pointers to arrays without relying on unsafe tricks.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. Memory Addresses

Every variable occupies a location in memory. The address-of operator `&` can obtain that address.

```
int number = 42;
cout << &number;
```

The exact address will vary from one run/system to another.

## 2\. Pointers

A pointer is a variable designed to store an address.

```
int number = 42;
int* ptr = &number;

cout << ptr << endl;   // address
cout << *ptr << endl;  // value at that address
```

The `*` in a declaration means “pointer to.” In an expression, `*ptr` dereferences the pointer to access the pointed-to value.

## 3\. References

```
void addOne(int& value) {
    value++;
}

int x = 5;
addOne(x);   // x becomes 6
```

A reference parameter lets a function operate on the caller's original variable. This differs from ordinary pass-by-value, which receives a copy.

## 4\. Pointer Safety

Do not dereference a pointer unless it points to a valid object. A pointer that intentionally points nowhere should be initialized to `nullptr`.

```
int* ptr = nullptr;
if (ptr != nullptr) {
    cout << *ptr;
}
```

## Guided Practice Before Graded Work

1.  Print the address of an integer.
2.  Create a pointer to that integer and display the value through the pointer.
3.  Change the original value through \*ptr.
4.  Write a pass-by-reference swap function.
5.  Initialize a pointer to nullptr and guard dereferencing with an if statement.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Pointers](https://www.w3schools.com/cpp/cpp_pointers.asp)
*   [W3Schools — C++ References](https://www.w3schools.com/cpp/cpp_references.asp)
*   [TutorialsPoint — C++ Pointers](https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm)
*   [TutorialsPoint — C++ References](https://www.tutorialspoint.com/cplusplus/cpp_references.htm)
*   [TutorialsPoint — Pointers vs Arrays](https://www.tutorialspoint.com/cplusplus/cpp_pointers_vs_arrays.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   memory addresses
*   pointers
*   references / pass by reference

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

Week 7 should assess basic pointer/reference understanding and safe use. It should not require advanced dynamic-memory structures or templates that have not been taught.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  What does &number mean in an expression?
2.  What does \*ptr mean when ptr already exists?
3.  How does pass-by-reference differ from pass-by-value?
4.  Why is nullptr safer than an uninitialized pointer?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”