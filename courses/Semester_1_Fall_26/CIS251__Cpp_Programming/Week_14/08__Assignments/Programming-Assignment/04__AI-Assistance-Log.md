## 🤖 AI Assistance Log

I extended my Week 10 `Distance` class for Week 14, keeping the absolute-value distance calculation and the `+` operator overload. I used **Google AI Studio (Gemini)** as the primary reviewer, plus **VS Code Copilot Fusion** and **Perplexity** as secondary helpers.

I used **Google AI Studio** to:

- Explain the program in plain language, suggest five test cases, and review the code within CIS 251 concepts.
- Flag likely logic errors, including unchecked mixed-unit addition in `operator+`.
- propose Test 15, which uses `0.2 + 0.7 + 0.1` to expose a floating-point label problem.
- Recommend `enum class Unit` over a plain `enum`, with a follow-up on the trade-offs of typing `Unit::`.
- Explain the `const` fix: `operator+` is `const`, so the helpers it calls (`unitToInch()` and `convertUnit()`) must also be `const`.

I used **Copilot Fusion** to:

- Diagnose the `operator<<` compile error, which came from printing an `enum class` value with `cout`.
- Suggest unit-conversion helper functions.

I used **Perplexity** to:

- Summarize diffs and draft conventional commit messages.
- Explain terminology, such as self-documenting output and manual versus automated tests.
- Review `operator+` design choices, including why returning `Distance(0.0, sum, unit)` makes a manual `temp` object unnecessary.
- Review test coverage and expected output.
- Organize the dev log and the pseudocode algorithm.

I rejected or corrected several suggestions:

- **`static` helpers:** Copilot used `static`, which my course hasn't covered, so I rewrote the helpers as ordinary member functions.
- **Size-based display unit:** Copilot proposed switching the result to feet or miles by size. I considered it unnecessary, so I did not use it.
- **Inches-only conversion:** Perplexity and I discussed always converting mixed units to inches. The final design converts the right operand into the left operand's unit, so Tests 12 and 13 show that operand order can change the result unit.
- **"Out of scope" claim:** Perplexity first called the `dist == 1.0` floating-point check out of scope. I challenged that because it is a logic bug in my own code. I added a tolerance check, `abs(dist - 1.0) < 0.005`, and Test 15.
- **Reverted enum:** Pasted code temporarily reverted `enum class Unit` to a plain `enum`. I caught it and restored it.
- **Test description errors:** I corrected copied descriptions and comments in Tests 12-14.

I independently verified all results and performed all code implementation, compilation, testing, and final decisions.
