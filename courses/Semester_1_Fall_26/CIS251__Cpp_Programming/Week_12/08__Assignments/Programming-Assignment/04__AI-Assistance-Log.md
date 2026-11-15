# 🤖 AI Assistance Log:

I created the initial Persistent Contact List program to write hard-coded names and emails to a text file and read them back for display. I used **Perplexity** to:

> **NOTE:** The most difficult part of this assignment was determining a minimum baseline of tests to perform. AI helped somewhat, but it still felt like there were dozens of tests that should be done to harden the code, but I pruned that down to a representative 6 for times-sake.

- Review file-stream handling, helper-function organization, and error messages.

- Clarify the differences between checking whether a stream’s file is open, checking its failure state, and checking an operation’s result.

- Plan repeatable test cases covering writing, reading, closed-stream rejection, appending, backup creation, and reading an empty file.

- Obtain example code for selected improvements, including the `getYesNo()` input function and backup error checks.

- Tighten code comments, correct expected-result descriptions, draft Git commit messages, and organize the pseudocode algorithm.

I critically evaluated the AI’s recommendations, challenged misleading wording about “fake contacts,” questioned duplicated cleanup code, and rejected excessive error-handling blocks. I selected which suggestions to incorporate while keeping the design appropriate for an introductory C++ assignment. I independently verified all results and performed all code implementation, compilation, and testing, and made all final decisions.