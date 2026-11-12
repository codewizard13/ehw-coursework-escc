Due Oct 18 11:59pm

20 points possible

# Discussion Topic: Week 11 Discussion - Exceptions, Error Handling, and Robust Programs

> Ask AI to propose an exception strategy, then critique whether each proposed exception is truly exceptional or should be normal validation.

**Requirements:** Post a substantive response of approximately 200-300 words by Thursday and reply constructively to at least two classmates by Sunday. When code is relevant, use a small code example and explain it in your own words. Cite/link any external source used.

**AI transparency:** If you use an AI assistant to brainstorm, disclose how you used it and identify at least one point you independently verified.


---

# MY ANSWER (DRAFT):

I provided the following prompt to perplexity:

> For a small C++ program that registers students for courses, propose an exception-handling strategy. Identify several possible errors and recommend which should throw exceptions and which should use normal validation. Explain each choice so I can critique it.

The result was this:

> I would use normal validation for expected mistakes and exceptions when the program cannot complete an operation.
> 
> - Normal validation: Invalid input, unknown student IDs, full courses, duplicate registrations, and missing prerequisites. These are expected problems, so display a clear message and let the student correct the request.
> - Exceptions: A required file cannot be opened, registration data is corrupted, or saving fails. These failures prevent the program from completing its task and should be handled by a higher-level `try`/`catch` block. [isocpp.github](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
> 
> If saving fails, the program should not report success or leave a partial registration. The main point to critique is the boundary: a full course is a normal rejection, while a failed save is a system failure.

My Critique:

Makes sense. Using normal validation on invalid data input and other predictable problems including various user errors that can be displayed to the user. Exceptions are appropriate when a failure prevents the program from completing its task.

# AI-ASSISTED DRAFT:

## 📝 Prompt and AI Recommendation

I asked Perplexity to propose an exception-handling strategy for a small C++ course-registration program and explain which errors should use exceptions versus normal validation.

Perplexity recommended normal validation for predictable problems, such as invalid input, unknown student IDs, full courses, duplicate registrations, and missing prerequisites. The program should explain the problem and allow the student to correct the request.

Exceptions would handle failures such as an unreadable required file, corrupted registration data, or an unsuccessful save. This approach follows the C++ Core Guidelines’ recommendation to use exceptions when a function cannot perform its assigned task. [isocpp.github](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

## 💻 Small Code Example

A short `enum class` could represent expected outcomes without throwing exceptions:

```cpp
enum class Result { Success, Full, Duplicate };

Result checkRegistration(bool full, bool enrolled) {
    if (enrolled) return Result::Duplicate;
    if (full) return Result::Full;
    return Result::Success;
}
```

Here, `Success` means the checks passed—not that registration was saved.

## 🔎 My Critique

I agree with this distinction because an unsuccessful request does not necessarily mean the program malfunctioned. A full course is an expected registration outcome, so throwing an exception would unnecessarily complicate ordinary decision-making.

However, the recommendation needs a clearer recovery plan. If saving fails, catching the exception and displaying a message is not enough. The program should avoid reporting success and preserve the previous valid registration state. A higher-level `try`/`catch` block should handle the failure, but the registration logic must prevent partial updates. This makes the strategy more reliable than simply separating user errors from system failures.

**🤖 AI transparency:** I used Perplexity to propose an exception-handling strategy, organize and condense my response, strengthen my critique, and create a short `enum class` example. I reviewed the distinction between normal validation and exceptions and explained why a failed save should not leave a partial registration.


### References:
-  

### #NOTES:
- 