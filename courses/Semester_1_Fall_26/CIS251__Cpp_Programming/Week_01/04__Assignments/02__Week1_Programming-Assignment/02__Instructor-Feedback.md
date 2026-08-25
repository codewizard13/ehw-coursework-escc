<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)

# Week 1 Programming Assignment - C++ Foundations: Problem Solving, Compilation, and Basic Syntax

Rosalyn Warren at Mon Aug 24, 2026 10:31amat Mon Aug 24, 2026 10:31am8/24/2026

Great job! The program is well organized, easy to follow, and successfully demonstrates input, variables, output, and an arithmetic calculation.

What you did well:

*   Correctly declares and uses variables.
*   Gets input from the user.
*   Produces clear, formatted output.
*   Performs an arithmetic calculation.
*   Includes helpful comments explaining the logic and a potential issue.

**One issue to address:**

double nums\_div = num\_1 / num\_2; performs integer division first, because both num\_1 and num\_2 are integers. For example, 5 / 2 will produce 2, not 2.5. You could fix this with:  

double nums\_div = **static\_cast<double>**(num\_1) / num\_2;

Also, division by zero should eventually be handled as you learn conditional statements.

Overall: Excellent work and a strong understanding of the basic C++ concepts.