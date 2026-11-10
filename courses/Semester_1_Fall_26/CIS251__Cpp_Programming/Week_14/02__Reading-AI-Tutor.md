<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren


# Week 14 Reading Tutorial & AI Tutor

CIS 251: C++ Programming · Fall 2026 · Dr. Rosalyn Warren

# Week 14: AI-Assisted C++ Development with Google AI Studio

**Purpose:** This page is your primary weekly tutorial. The external resources are supplemental. If you cannot reach every external site, study this page carefully, type and run the examples, complete the practice tasks, and use the AI Tutor for explanations.

## Learning Objectives

*   Use AI as a tutor/reviewer rather than an answer generator.
*   Write precise prompts that include requirements and constraints.
*   Evaluate AI-generated C++ for correctness and course alignment.
*   Generate test ideas and debugging hypotheses.
*   Document AI assistance transparently.

**How to study this page:** Read one section at a time. Before running each code example, predict what it will do. Then type it yourself rather than copying it. Modify at least one value or condition and observe the effect.

## 1. AI Does Not Replace Programming Knowledge

Generative AI can explain code, suggest tests, identify possible defects, and propose refactoring. It can also produce code that is incorrect, outdated, unnecessarily complex, or inconsistent with an assignment. Your C++ knowledge is what allows you to judge the output.

## 2. A Strong Prompt

A useful prompt states the task, context, constraints, and desired kind of help.

```
I am a beginning C++ student. My program uses only concepts through
classes, vectors, file I/O, and exceptions. Do not introduce libraries
or techniques outside those topics.

Here is my requirement: [paste requirement]

Here is my current code: [paste code]

Identify two likely logic errors. Explain each error and suggest a small
test that would expose it. Do not rewrite the entire program.
```

## 3. Verify Every Suggestion

When AI proposes a change, ask: Does it compile? Does it meet the stated requirement? Does it introduce a concept we have not learned? Does it change correct behavior? Can I explain every changed line?

Never submit code you cannot explain.

## 4. AI Assistance Log

For substantial AI use, record: the prompt, the useful part of the response, what you accepted or rejected, how you verified it, and what you changed yourself. This makes your development process transparent and demonstrates judgment rather than copy/paste behavior.

## Guided Practice Before Graded Work

1.  Ask AI Studio to explain one compiler error from an old exercise.
2.  Ask it to generate five edge-case tests for a familiar program.
3.  Give it a deliberately flawed 10-line program and ask for clues rather than a rewrite.
4.  Reject one unnecessary suggestion and explain why.
5.  Write one AI-log entry documenting the interaction and verification.

## Optional/Supplemental External Readings

The tutorial above contains the required conceptual explanation. Use these resources for another explanation and additional examples:

*   [Google AI Studio](https://aistudio.google.com/)
*   [Google AI for Developers — AI Studio Quickstart](https://ai.google.dev/gemini-api/docs/ai-studio-quickstart)
*   [Google AI for Developers — Prompt Design Strategies](https://ai.google.dev/gemini-api/docs/prompting-strategies)

## Instructional Videos

For the embedded Bro Code playlist, focus on the following lesson topics this week:

*   Review prior C++ topics as needed; AI work this week must stay within concepts already learned.

### Bro Code — C++ Tutorial Playlist

Use this playlist as a second explanation of the week's concepts. Watch the lessons named in the checklist below; pause frequently and type the examples yourself.

## Preparing for This Week's Programming Assignment

The Week 14 assignment should evaluate and improve C++ code using AI Studio as a documented assistant. AI must not introduce a new C++ framework or solve the assignment wholesale.

**Readiness rule:** You should be able to complete the guided-practice tasks without copying a finished solution before beginning the graded programming assignment.

## Self-Check

Answer these in your own words before moving to graded work. If you cannot answer one, return to the relevant section or ask the AI Tutor for an explanation.

1.  Why can AI-generated code be risky even when it looks professional?
2.  What four kinds of information make a prompt more useful?
3.  How can a student verify an AI debugging suggestion?
4.  What belongs in an AI assistance log?

## CIS 251 AI Tutor

**Use the tutor to learn, not to replace your work.** Ask it to explain a concept, trace a small example, help interpret a compiler error, or quiz you. Do not ask it to complete the graded assignment for you.

**Useful prompts:** “Explain this concept in simpler terms.” “Give me a new practice problem like the example.” “Trace this code line by line.” “Explain this compiler error without writing my assignment.”