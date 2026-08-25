<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# [ ] CIS 251 - C++ Programming:  Week 1 Reading Tutorial & AI Tutor

> Source: https://alabama.instructure.com/courses/198936/pages/week-1-reading-tutorial-and-ai-tutor?module_item_id=21192922


CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 1: C++ Foundations: Programs, Compilation, Output, Variables, and Input

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain the difference between source code, compilation, and execution.
*   Recognize the basic structure of a C++ console program.
*   Use cout to display text and values and cin to collect simple keyboard input.
*   Declare, initialize, and update variables using appropriate basic data types.
*   Compile and run a small C++ program in the required development environment.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. What C++ Is and How a Program Becomes Executable

C++ is a **compiled programming language**. You write human-readable source code, usually in a file ending in `.cpp`. A compiler translates that source code into machine instructions that the computer can execute. If the compiler finds a syntax error, it stops and reports an error instead of producing a working program.

Think of the process as: **write → compile → fix errors → run → test**. This cycle will be repeated throughout the course. A program that compiles is not automatically correct; it can still contain logic errors, so you must also test the output.

## 2\. The Smallest Useful C++ Program

```
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, CIS 251!" << endl;
    return 0;
}
```

`#include <iostream>` makes the standard input/output tools available. `main()` is the starting point of the program. Curly braces mark the body of the function. `cout` sends information to the console. A semicolon ends most C++ statements.

**Case matters.** `cout`, `Cout`, and `COUT` are different identifiers. C++ is case-sensitive.

## 3\. Variables and Basic Data Types

A variable is a named storage location. C++ requires each variable to have a type. Common beginner types are `int` for whole numbers, `double` for decimal values, `char` for one character, `bool` for true/false values, and `string` for text.

```
int age = 18;
double price = 12.95;
char grade = 'A';
bool enrolled = true;
string name = "Jordan";
```

Use meaningful names. `itemPrice` communicates more than `x`. Variable names cannot contain spaces and cannot begin with a digit.

## 4\. Keyboard Input and Console Output

```
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your first name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name
         << ". Next year you will be "
         << age + 1 << "." << endl;

    return 0;
}
```

The extraction operator `>>` moves keyboard input into a variable. The insertion operator `<<` sends values to `cout`. Notice that an expression such as `age + 1` can be placed directly in the output statement.

## Guided Practice Before Graded Work

1.  Create hello.cpp, compile it, and run it.
2.  Change the greeting and compile again.
3.  Add variables for your name, favorite whole number, and a decimal value; display all three.
4.  Ask the user for a name and age and display a complete sentence using both values.
5.  Intentionally remove one semicolon. Compile, read the error message, then repair it.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ SyntaxLinks to an external site.](https://www.w3schools.com/cpp/cpp_syntax.asp)
*   [W3Schools — C++ OutputLinks to an external site.](https://www.w3schools.com/cpp/cpp_output.asp)
*   [W3Schools — C++ VariablesLinks to an external site.](https://www.w3schools.com/cpp/cpp_variables.asp)
*   [W3Schools — C++ User InputLinks to an external site.](https://www.w3schools.com/cpp/cpp_user_input.asp)
*   [TutorialsPoint — C++ OverviewLinks to an external site.](https://www.tutorialspoint.com/cplusplus/cpp_overview.htm)
*   [TutorialsPoint — C++ Basic SyntaxLinks to an external site.](https://www.tutorialspoint.com/cplusplus/cpp_basic_syntax.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   Introduction / first program
*   Variables and basic data types
*   Console output
*   Keyboard input

### Bro Code — C++ Tutorial for Beginners

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

Your Week 1 programming work should use only the program structure, output, variables, simple arithmetic, and keyboard input taught above. You should not need conditions, loops, functions, arrays, or classes yet.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## 🔍 Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1. 🔍 What is the role of main()?
2. 🔍 What is the difference between source code and an executable program?
3. 🔍 Which type would you choose for a price? For a whole-number quantity?
4. 🔍 What do the << and >> operators do when used with cout and cin?
5. 🔍 Why can a program compile successfully but still be incorrect?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”