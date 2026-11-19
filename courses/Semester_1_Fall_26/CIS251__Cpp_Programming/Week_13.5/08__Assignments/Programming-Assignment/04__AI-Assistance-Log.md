# 🤖 AI Assistance Log:

I used my Assignment 6 Score List Analyzer as the foundation and incrementally refactored it into a vector-based program with reusable reporting and a five-case test harness. I used **Perplexity** to:

- Review approaches for associating test titles and descriptions with score vectors, including a `TestCase` struct and a constant-reference range-based loop.

- Clarify accumulator initialization, output-formatting behavior, and array-versus-vector performance tradeoffs.

- Calculate expected test results and draft a five-case test table.

- Refine comments, add a concise Doxygen function header, draft conventional commit messages, and organize the development log and pseudocode algorithm.

I also used Google Gemini to explore joining strings with `accumulate()` and to suggest grouping test metadata and scores in a struct. I retained the simple comma-printing loop and incorporated the struct into the final harness.

I independently verified all results and performed all code implementation, compilation, testing, and final decisions.