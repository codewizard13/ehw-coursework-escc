## 📊 Pseudocode Algorithm

# WEEK 11 PROGRAMMING ASSIGNMENT — Exceptions, Error Handling, and Robust Programs

```
START

Declare numerator and denominator as real numbers.

Prompt for numerator.
If reading numerator fails:
    Display an input error.
    End with an error status.

Prompt for denominator.
If reading denominator fails:
    Display an input error.
    End with an error status.

TRY
    If denominator equals zero:
        THROW a division-by-zero error.

    Calculate numerator / denominator.
    Display the quotient.

CATCH the division-by-zero error
    Display an explanation.
    End with an error status.

End successfully.

STOP
```