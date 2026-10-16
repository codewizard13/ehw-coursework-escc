<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren


# Week 9: Inheritance, Overriding, and Polymorphism

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain is-a relationships.
*   Create a derived class from a base class.
*   Use protected/public inheritance appropriately.
*   Override inherited behavior.
*   Explain runtime polymorphism at an introductory level.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. Inheritance

Inheritance lets a new class reuse and specialize another class. If `Student` is a kind of `Person`, then `Student` may derive from `Person`.

```cpp
class Person {
public:
    string name;
    void introduce() const {
        cout << "I am " << name << endl;
    }
};

class Student : public Person {
public:
    string major;
};
```

## 2\. Overriding Behavior

A derived class can provide its own version of inherited behavior. For true runtime polymorphism, the base function is declared `virtual`.

```cpp
class Shape {
public:
    virtual void describe() const {
        cout << "Generic shape" << endl;
    }
};

class Circle : public Shape {
public:
    void describe() const override {
        cout << "Circle" << endl;
    }
};
```

## 3\. Polymorphism

```cpp
Shape* s = new Circle();
s->describe();
delete s;
```

Because `describe()` is virtual, the `Circle` version executes even though the pointer type is `Shape*`. For this introductory course, focus on the idea: one common interface can represent different specialized objects.

## 4\. Inheritance vs Composition

Use inheritance for a genuine **is-a** relationship. Use composition for a **has-a** relationship. A `Car` has an `Engine`; a `Car` is not an `Engine`.

## Guided Practice Before Graded Work

1.  Create Person and Student classes using public inheritance.
2.  Add a field specific to Student.
3.  Override a virtual display/describe method.
4.  Use a base-class pointer or reference to call an overridden function.
5.  Write one is-a example and one has-a example from everyday life.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Inheritance](https://www.w3schools.com/cpp/cpp_inheritance.asp)
*   [W3Schools — C++ Polymorphism](https://www.w3schools.com/cpp/cpp_polymorphism.asp)
*   [TutorialsPoint — C++ Inheritance](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm)
*   [TutorialsPoint — C++ Polymorphism](https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   inheritance
*   method overriding
*   virtual functions / polymorphism

### C++ Inheritance — Constructors and Destructors in Base/Derived Classes

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

Week 9 should extend an already familiar class design into a base/derived relationship. The assignment should not require unfamiliar GUI, database, networking, or external libraries.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  What does an is-a relationship mean?
2.  What keyword enables runtime polymorphism in a base class?
3.  What does override communicate?
4.  When is composition a better relationship than inheritance?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”