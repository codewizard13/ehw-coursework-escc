<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> ### CIS 251 - C++ Programming:
> Fall 2026 · Dr. Rosalyn Warren

**Project Title:** The Object-Oriented Logic & Architecture Challenge

**Tools Required:** C++ Essentials 1 & 2 concepts, **Kiro** ([kiro.dev/students/terms-2026/](https://kiro.dev/students/terms-2026/)), and **NotebookLM**.

## Your Role: The Architect, Not the Typist

In this project, you have creative freedom to build an engaging application—such as a complex text-based strategy game, a specialized inventory tracker, a simulation tool, or a productivity dashboard.

However, there is one catch: **An AI can write syntax, but it cannot reason through a complex problem for you.**

You will use **Kiro** to assist with generating the code, but **you are the Lead Systems Architect**. Your grade will not be based on how fast the AI writes code, but on your **logical reasoning, system design, and problem-solving skills**. If your code contains logical flaws, edge-case crashes, or architecture you cannot explain, it will not pass. It must be entirely evident that _you_ drove the logic.

## Core Technical Requirements

To ensure your application requires real problem-solving and avoids overly simplistic scripts, it must include:

1.  **C++ Essentials 1 Foundation (Logic & Control):**
    
    *   Structured control flow (`if/else`, `switch`, loops) and robust input validation so user errors don't crash your app.
        
    *   Custom functions utilizing pass-by-reference and clean data structures (e.g., `vector`, `map`, or custom structs).
        
2.  **C++ Essentials 2 OOP Requirements (Must include at least two):**
    
    *   **Classes & Objects:** Clean encapsulation of data and member functions.
        
    *   **Inheritance:** A logical base class with specialized derived classes (e.g., a `Transaction` base class with `Deposit` and `Withdrawal` derived classes, or an `Entity` base class with `Player` and `Enemy` derived classes).
        
    *   **Polymorphism & Virtual Functions:** Dynamic behavior overridden across derived classes to solve a specific architectural problem.
        

## Project Deliverables

You will submit three distinct artifacts designed to prove your **logical thinking and problem-solving process**:

### 1. The NotebookLM Logical Explainer (Audio/Video Overview)

*   **What to do:** Create a dedicated Notebook in **NotebookLM**, and upload your pseudocode/logic blueprint, header files (`.h`), and source files (`.cpp`) as sources.
    
*   **The Task:** Generate and use NotebookLM’s audio/overview features to create an explainer that breaks down the _architectural logic_, class hierarchies, and design trade-offs of your application. (Submit your NotebookLM link or exported artifact).
    

### 2. A 2-Minute Screen Recording (Code, Live Run & The "Logic Fix")

*   **What to do:** Record your screen and voice-over walking through your project. Your video **must** cover three things:
    
    1.  **The Architecture:** Briefly show your object-oriented class structure (base vs. derived classes).
        
    2.  **The Logic & AI Correction:** Point out a specific moment where Kiro's first-draft code introduced a logical bug, edge-case failure, or inefficient design, and explain **how you used your own reasoning to fix the prompt or correct the logic.**
        
    3.  **The Live App:** Execute the program live to prove it compiles and runs cleanly.
        

### 3. A 1-Page Written Reflection (Focus on Problem-Solving)

*   **What to do:** Write a concise single-page reflection (PDF or Word doc) focusing on your cognitive journey:
    
    *   **The Problem Space:** What complex rules, data flows, or game mechanics did you model?
        
    *   **Logical Breakdown:** How did you break a large problem down into manageable classes, functions, and loops?
        
    *   **Critical Thinking & AI Oversight:** How did you guide Kiro? What logical errors did you catch and fix yourself, and what did you learn about software problem-solving?
        

## Grading Rubric (100 Points Total)

| **Component** | **Description** | **Points** |
| --- | --- | --- |
| **Problem Complexity & Logical Design** | The app solves a non-trivial problem with sound algorithmic logic, structured data flow, and well-thought-out class hierarchies. | **30 pts** |
| **Object-Oriented Architecture** | Effective use of C++ Essentials 2 concepts (encapsulation, inheritance, polymorphism) chosen deliberately for logical reasons. | **20 pts** |
| **Critical Thinking & AI Oversight** | Demonstrated ability to catch AI logic errors, handle edge cases, and refine code through active reasoning rather than blind copy-pasting. | **15 pts** |
| **NotebookLM Explainer** | Clear articulation of the architectural logic and design decisions using NotebookLM sources. | **10 pts** |
| **2-Minute Screen Recording** | Clear demonstration of the code, live execution, and a verbal breakdown of a specific logical hurdle or AI correction. | **15 pts** |
| **1-Page Writeup & Reflection** | Deep, honest reflection focusing on algorithmic problem-solving, debugging logic, and architectural trade-offs. | **10 pts** |