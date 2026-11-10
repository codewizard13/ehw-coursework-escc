# 🤖 AI Assistance Log:

I created the initial `Distance` class and chose to calculate distance as the absolute value of `end - start`, and added the + operator overload functionality. I used **Perplexity** to:

- Refine unit display using `switch` and singular/plural labels.

- Review `operator+` against the required `Box` example and identify corrections for recalculating distance from summed endpoints and preserving the left operand’s unit.

- Review assignment requirements, test coverage, and console results against expected output.

- Tighten code comments, correct expected-result descriptions, draft Git commit messages, and organize the pseudocode algorithm.

- Perplexity initially recommended endpoint-based addition, which produced an inappropriate zero-distance result for opposite-direction trips. I identified and challenged that mismatch with the intended travel-distance meaning. After reviewing alternatives, I selected magnitude addition with result endpoints from zero to the total.

I independently verified all results and performed all code implementation, compilation, testing, and final decisions.