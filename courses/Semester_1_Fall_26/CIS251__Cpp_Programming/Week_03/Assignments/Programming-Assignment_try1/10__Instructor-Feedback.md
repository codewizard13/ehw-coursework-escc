<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)

# Week 3 Programming Assignment — 

![](https://alabama.instructure.com/images/thumbnails/31162645/IzXRBvlUTUgjZiI8nERvp7stV4PpwU3RFzIk4Ych)

Rosalyn Warren at Tue Sep 8, 2026 11:16amat Tue Sep 8, 2026 11:16am9/8/2026

| Rubric Criterion | Points | Evaluation |
| --- | --- | --- |
| Program meets stated requirements and produces correct results | **35/40** | Program correctly accepts an order amount and shipping option, uses a `switch`, assigns the stated shipping charges, calculates the final amount, and rejects invalid shipping letters. However, the assignment specifically requires **boundary tests for every branch**, and the submitted tests do not demonstrate meaningful numeric boundary testing. |
| Correct use of C++ concepts taught this week | **24/25** | Appropriate use of `switch`, `if`, `bool`, variables, `cin`, `cout`, arithmetic, and formatting. The student appropriately avoids loops because they have not yet been covered. |
| Testing, validation, and correction of errors | **14/20** | Five tests were submitted and include all three shipping choices plus two invalid-character tests. All documented tests pass. However, the tests are primarily option-selection tests rather than boundary tests. There is also no validation of the **order amount**. A negative amount such as `-10` is accepted and produces `-$5.00`, and nonnumeric order input is not handled correctly. |
| Readability, organization, naming, comments | **8/10** | Code is readable, consistently formatted, and commented. Names such as `order_amount`, `shipping_amount`, and `valid_shipping_choice` are meaningful. The pseudocode is present but too general; it does not describe the actual decision logic or invalid-input branch. |
| Submission evidence / AI transparency | **4/5** | Source, test evidence, run screenshot, and AI log are included. AI use is disclosed. The AI log is very brief, but it satisfies the basic transparency requirement. |
| **Total** | **85/100** | **B** |

### Feedback

The program is well organized and demonstrates the Week 3 decision-structure concepts correctly. The `switch` statement is an appropriate solution for selecting among the three shipping options, and using the Boolean `valid_shipping_choice` to prevent calculation after an invalid selection is a good application of Boolean logic.

The largest weakness is **testing**. The assignment explicitly requires normal, boundary, and invalid testing. The submitted test table uses `$10.00` for every order amount, so it does not demonstrate boundary testing of the numeric input or any boundaries associated with the supplied decision rules. Testing `a`, `b`, `c`, `z`, and `A` verifies the shipping-option branches, but those are not sufficient to satisfy the boundary-testing requirement.

The program also accepts invalid monetary values. For example, entering an order amount of `-10` followed by shipping option `a` produces:

`Final Amount: $-5.00`

A negative order amount should be rejected if invalid-input handling is expected. Nonnumeric input also causes the input stream to fail and prevents meaningful processing. Since loops have not been taught, the program did **not** need to repeatedly prompt the user, but an `if` statement could have detected an invalid amount and displayed an appropriate error.

The pseudocode should also be more specific. Instead of only stating "Calculate final amount," it should document the actual decision process: read the amount, read the shipping choice, select the shipping charge according to the choice, reject an invalid choice, and calculate the final amount only when the choice is valid.

**Overall:** Good command of the Week 3 C++ material and a functional program, but incomplete boundary/invalid-input testing prevents full credit.

Rosalyn Warren, Sep 8 at 11:13 AM