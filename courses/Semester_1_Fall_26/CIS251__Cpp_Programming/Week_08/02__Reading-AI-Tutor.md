<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren

# Week 8: Classes, Objects, Encapsulation, Constructors, and Methods

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain the relationship between a class and an object.
*   Define data members and member functions.
*   Use private data to support encapsulation.
*   Create constructors that initialize objects.
*   Create and use multiple objects.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. From Procedural to Object-Oriented Design

Object-oriented programming groups related data and behavior together. A **class** is a blueprint; an **object** is one instance created from that blueprint.

For a bank account, data might include owner and balance, while behavior might include deposit, withdraw, and display.

## 2\. Defining a Class

```cpp
class BankAccount {
private:
    string owner;
    double balance;

public:
    void setOwner(string name) {
        owner = name;
    }

    double getBalance() const {
        return balance;
    }
};
```

`private` members cannot be accessed directly from outside the class. Public methods provide a controlled interface.

## 3\. Constructors

```cpp
class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string name, double startingBalance) {
        owner = name;
        balance = startingBalance;
    }

    void display() const {
        cout << owner << ": $" << balance << endl;
    }
};

BankAccount account("Jordan", 250.00);
```

A constructor has the same name as the class and no return type. It runs automatically when an object is created.

## 4\. Designing Responsibilities

A good class protects its own valid state. For example, a deposit method can reject a negative deposit rather than allowing outside code to edit the balance directly.

```cpp
void deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}
```

## Guided Practice Before Graded Work

1.  Create a Student class with private name and score fields.
2.  Add a constructor.
3.  Add getters and a display method.
4.  Create two Student objects in main().
5.  Add one validation rule inside a method.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Classes and Objects](https://www.w3schools.com/cpp/cpp_classes.asp)
*   [W3Schools — C++ Class Methods](https://www.w3schools.com/cpp/cpp_class_methods.asp)
*   [W3Schools — C++ Constructors](https://www.w3schools.com/cpp/cpp_constructors.asp)
*   [W3Schools — C++ Encapsulation](https://www.w3schools.com/cpp/cpp_encapsulation.asp)
*   [TutorialsPoint — C++ Classes and Objects](https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   classes and objects
*   constructors
*   getters and setters / encapsulation

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

- https://www.youtube.com/watch?v=S3nx34WFXjI

### C++ Programming All-in-One — OOP Section (supplemental)
- https://www.youtube.com/watch?v=_bYFu9mBnr4&t=29938s

## Preparing for This Week's Programming Assignment

The Week 8 assignment should be your first class-based program. Its problem domain may be new, but every required programming technique—private fields, constructors, methods, validation, objects—has been practiced here.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  What is the difference between a class and an object?
2.  Why keep data members private?
3.  When is a constructor executed?
4.  What is the purpose of a getter?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”