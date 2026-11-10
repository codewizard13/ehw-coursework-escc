# 🛠️ Incremental Development Log

## 📘 Assignment Information

- **Course:** CIS-251 — C++ Programming
- **Assignment:** Week 10 — Operator Overloading, Enumerations, and Interface Design
- **Author:** Eric L. Hepperle
- **Program:** Distance class

## 📋 Purpose and Planning

The goal was to create a small `Distance` class, overload one operator using the required `Box` example, and use an enum to select a display unit.

My initial design used two endpoints, `start` and `end`, with distance calculated as `abs(end - start)`. I created the initial class and calculation, then refined individual features with AI assistance. The intended operations were construction, formatted display, and addition of two objects.

The accompanying algorithm describes the implemented approach. Its final Markdown version was organized after implementation; this retrospective log does not establish that a written algorithm existed before coding.

## 🏗️ Incremental Implementation and Corrections

1. **Build the initial class.** Added endpoints, a default constructor, a two-endpoint constructor, and `display()`. The first draft calculated the distance from the endpoints.
2. **Correct enum storage and initialization.** Initially declared `Unit unit = inch` inside the default constructor. This created a local variable, so `display()` could not access it as a member. Moved the declaration to class scope and used default member initializers. Also corrected the two-endpoint constructor's `dist` self-assignment to calculate the absolute endpoint difference.
3. **Refine output.** Added `switch (unit)` to display unit names, singular/plural checks, and `<iomanip>` formatting with `fixed` and `setprecision(2)`.
4. **Add the modeled operator.** Implemented member `operator+` with a `const Distance&` parameter, a local result object, direct member access, and a returned result, following the supplied `Box` structure. Added tests for two-object, temporary-object, and chained addition.
5. **Support unit selection and encapsulation.** Added an optional unit argument to the constructor and placed `Unit` at global scope. Moved `start`, `end`, `unit`, and `dist` into the private section. Confirmed that public constructors and member functions still provide the needed interface; no getters or setters were added.
6. **Correct addition behavior.** Review identified that independently adding stored distances could contradict the summed endpoints. Changed the result calculation to `abs(temp.end - temp.start)`. Also assigned the left operand's unit to the result instead of leaving the default inch label.
7. **Verify results and revise documentation.** Ran the completed test sequence, compared the console output with expected results, and corrected outdated comments, including the feet and mile results and the zero-distance cancellation case.

## 🧪 Testing and Results

The recorded console run contains 11 numbered tests and 13 displayed results. All listed outputs matched the expected behavior of the final endpoint-addition implementation.

> Caveat: My program assumes you are adding **like Distance units** (i.e., feet + feet, inch + inches — NEVER inch + foot, etc.), because adding unit conversion and validation and/or try-catch blocks seemed to be outside the scope of this lesson's focus. However, in a real-world program I would have ensured those types of defensive coding measures were in place.

| Test | Input or operation | Expected and observed result | Status |
| --- | --- | --- | --- |
| 1 | Default construction | 0.00 inches | Pass |
| 2 | Endpoints 2 and 10 | 8.00 inches | Pass |
| 3 | Endpoints 4 and 20 | 16.00 inches | Pass |
| 4 | Add objects from Tests 2 and 3 | Endpoints 6 and 30; 24.00 inches | Pass |
| 5 | Add Test 2 object and `Distance(3, 6)` | Endpoints 5 and 16; 11.00 inches | Pass |
| 6 | Add objects from Tests 2, 3, and 4 | Endpoints 12 and 60; 48.00 inches | Pass |
| 7 | Endpoints 2 and 1 | 1.00 inch | Pass |
| 8 | Endpoints 4 and -10, unit foot | 14.00 feet | Pass |
| 9 | Endpoints 3 and 2, unit mile | 1.00 mile | Pass |
| 10 | `Distance(2, 10) + Distance(10, 2)` | Endpoints 12 and 12; 0.00 inches | Pass |
| 11 | `Distance(0, 2, foot)` plus `Distance(0, 3, foot)` | Operands: 2.00 and 3.00 feet; sum: 5.00 feet | Pass |

The default and cancellation cases test zero distance. Reversed and negative endpoints test the absolute-difference calculation. Unit tests cover singular inches and miles, plural feet, and retention of feet during addition.

The final console output demonstrates successful execution. This log does not claim that every intermediate revision was compiled or that the final build was warning-free; intermediate build records and compiler diagnostics are not included here.

## 🔎 Design Decisions and Limits

- Addition combines corresponding endpoints, not the separate distance magnitudes. Opposite endpoint differences can therefore cancel.
- The result retains the left operand's unit. The program does not convert units or validate mixed-unit addition.
- Private members prevent direct access from `main()`; constructors and class member functions access them internally.
- Tests use hard-coded arguments rather than interactive input. Fractional endpoints, mixed units, singular foot, and plural miles were not covered by the recorded run.

## 🤖 AI Assistance and Independent Work

I developed the initial class and absolute-difference calculation. I used Perplexity to clarify scope and access rules, refine unit output, review operator behavior, identify targeted corrections, and organize documentation. AI provided explanations and example code. I incorporated refinements, compiled and ran the program, checked the reported results, and made the final implementation decisions.

## 📎 Documentation Basis

This concise, retrospective log was prepared from the development drafts and console results recorded in the chat. Its structure follows Dr. Rosalyn Warren's November 9, 2026 clarification: development notes, implementation order, testing, and corrections are sufficient; intermediate screenshots are optional. It does not replace the separate algorithm, source file, test table, or compilation/execution evidence required for submission.
