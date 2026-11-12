# 🤖 AI Assistance Log:

I developed the safe-division program incrementally, adding numeric input validation, division-by-zero exception handling, and quotient calculation. I used **Perplexity** to:

- Interpret the assignment’s scope and suggest an initial solution and pseudocode plan.

- Refine my explanation of why division by zero should be handled, including the business reason for preventing misleading results.

- Explain the choice of `runtime_error` compared with a plain `exception` or a custom exception class.

- Review my reported test coverage and help select representative normal, edge-case, and invalid inputs for a concise test table.

- Clarify why `0 / 0` must still trigger the error. I initially questioned this because a number divided by itself equals one; the discussion clarified that this rule excludes zero.

I performed the code implementation and testing, reported the results, and made the final decisions about the program and documentation.