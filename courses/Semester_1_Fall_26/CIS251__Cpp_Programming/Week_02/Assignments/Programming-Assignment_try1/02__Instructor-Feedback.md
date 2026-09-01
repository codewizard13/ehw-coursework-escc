<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)

# Week 2 Programming Assignment — Data Types, Constants, Operators, Expressions, and Numeric Calculations


![](https://alabama.instructure.com/images/thumbnails/31162645/IzXRBvlUTUgjZiI8nERvp7stV4PpwU3RFzIk4Ych)

Rosalyn Warren at Mon Aug 31, 2026 12:00pmat Mon Aug 31, 2026 12:00pm8/31/2026

This is a strong submission overall. Your program uses the required Week 2 concepts appropriately, and your testing goes well beyond the minimum requirement. I especially like that you tested product names containing spaces and recognized why `getline()` was useful.

There are two issues to correct.

First, remember that this is a purchase receipt calculator, so monetary output should be displayed consistently to two decimal places. Your calculations are mathematically correct, but output such as:

```
SALES TAX: $0.135
TOTAL:     $1.635
```

is not appropriate currency formatting. The receipt should display `$0.14` and `$1.64`.

Second, make sure your test evidence matches the final source code you submit. Your current source defines:

```
const double TAX_RATE = 0.10;
```

but several of your test cases and screenshots use a 9% tax rate. That suggests the program was changed after some of the testing was completed. After making a change like that, rerun the final test cases against the final version of the program.

Your nine-case test table is otherwise very good and demonstrates a serious effort to verify the calculations.