
# W3Schools Notes

# 

C++ Operator Precedence

[❮ Previous](cpp_operators_logical.asp) [Next ❯](cpp_challenges_operators.asp)

- - -

ShareLink Copied

## Operator Precedence

When a calculation contains more than one operator, C++ follows **order of operations** rules to decide which part to calculate first.

For example, multiplication happens before addition:

### Example

```cpp
int result1 = 2 + 3 * 4;     // 2 + 12 = 14
int result2 = (2 + 3) * 4;   // 5 * 4 = 20

cout << result1 << "\n";
cout << result2 << "\n";
```

[Try it Yourself »](trycpp.asp?filename=demo_oper_precedence)

### Why Does This Happen?

In `2 + 3 * 4`, the multiplication is done first, so the answer is `14`.

If you want the addition to happen first, you must use parentheses: `(2 + 3) * 4`, which gives `20`.

**Tip:** Always use parentheses `( )` if you want to make sure the calculation is done in the order you expect. It also makes your code easier to read.

- - -

## Order of Operations

Here are some common operators in C++, from highest to lowest priority:

*   `()` - Parentheses
*   `*`, `/`, `%` - Multiplication, Division, Modulus
*   `+`, `-` - Addition, Subtraction
*   `>`, `<`, `>=`, `<=` - Comparison
*   `==`, `!=` - Equality
*   `&&` - Logical AND
*   `||` - Logical OR
*   `=` - Assignment

- - -

## Another Example

Subtraction and addition are done from left to right, unless you add parentheses:

### Example

```cpp
int result1 = 10 - 2 + 5;    // (10 - 2) + 5 = 13
int result2 = 10 - (2 + 5);  // 10 - 7 = 3

cout << result1 << "\n";
cout << result2 << "\n";
```

[Try it Yourself »](trycpp.asp?filename=demo_oper_precedence2)

**Remember:** Parentheses always come first. Use them to control the order of your calculations.

> - ⚠️ #GOTCHA: When dividing two integers in C++, the result will also be an integer. For example, `10 / 3` gives `3`. If you want a decimal result, use float or double values, like `10.0 / 3.0`.