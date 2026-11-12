<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren


# Week 12 Reading Tutorial & AI Tutor

CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 12: File Input/Output and Persistent Data

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Explain persistence.
*   Write text to a file with ofstream.
*   Read text from a file with ifstream.
*   Check whether a file opened successfully.
*   Process file records using loops and familiar string/numeric techniques.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1\. Persistence

Variables disappear when a program ends. A file allows information to persist so it can be used during a later run.

## 2\. Writing Files

```cpp
#include <fstream>

ofstream outputFile("scores.txt");

if (outputFile) {
    outputFile << "Jordan 92" << endl;
    outputFile << "Taylor 88" << endl;
    outputFile.close();
}
```

> - **#GOTCHA:** The above is technically ***illegal*** in C++. You have to encapsulate the if statement in `int main()` for it to work. Here is the minimum correct MVP version:

```cpp
// Eric Hepperle - Working Example
#include <iostream>
#include <fstream>
using namespace std;

ofstream outputFile("scores.txt");

int main()
{

    if (outputFile)
    {
        outputFile << "Jordan 92" << endl;
        outputFile << "Taylor 88" << endl;
        outputFile.close();
    }

    return 0;
}
```

An `ofstream` is an output file stream. Always verify that the stream opened successfully before relying on it.

## 3\. Reading Files

```cpp
ifstream inputFile("scores.txt");
string name;
int score;

if (inputFile) {
    while (inputFile >> name >> score) {
        cout << name << ": " << score << endl;
    }
    inputFile.close();
}
```

The extraction expression itself becomes false when the expected data can no longer be read, making it suitable as the loop condition.

## 4\. File Locations and Testing

Relative file names such as `scores.txt` are interpreted relative to the program's working directory. If a file appears to be missing, verify where the program is running. Test with an existing file, a missing file, and multiple records.

## Guided Practice Before Graded Work

1.  Write two lines to a text file.
2.  Open the file manually to confirm its contents.
3.  Read the file back into the program.
4.  Handle a missing file with an error message.
5.  Read several numeric records and calculate a total or average.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [W3Schools — C++ Files](https://www.w3schools.com/cpp/cpp_files.asp)
*   [TutorialsPoint — C++ Files and Streams](https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   file input/output / fstream
*   reading records with loops

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

Week 12 should persist information using text files and techniques already mastered: variables, loops, functions, classes, and validation. No database system is required.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  What is persistence?
2.  Which stream type writes to a file?
3.  Which stream type reads from a file?
4.  Why must a program check whether a file opened?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”