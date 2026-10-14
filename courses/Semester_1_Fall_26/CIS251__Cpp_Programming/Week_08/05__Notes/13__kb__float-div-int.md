# 📚 KB: Float ÷ Integer in C++

## 🎯 Quick answer

Dividing a `float` by an `int` in C++ performs **floating-point division**, not integer division. C++ promotes the integer operand to the floating-point type before dividing, so the decimal portion is preserved. [csd.uwo](https://www.csd.uwo.ca/courses/CS1027b/notes/CS1027-001b-OOP-W17.pdf)

```cpp
float a = 5.0f;
int b = 2;

auto result = a / b; // 2.5f
```

## ⚙️ How promotion works

When one operand is floating-point and the other is integral, C++ implicitly converts—“promotes”—the integer to the floating-point type before evaluating the operator. The division then occurs as floating-point ÷ floating-point. [csd.uwo](https://www.csd.uwo.ca/courses/CS1027b/notes/CS1027-001b-OOP-W17.pdf)

For `5.0f / 2`, the `int` value `2` becomes `2.0f`, and the result is `2.5f`.

## 🚨 When truncation happens

Integer division occurs only when **both operands are integer types**. The fractional part is discarded before the result is assigned, even if the destination variable is a `float` or `double`. [developer.mozilla](https://developer.mozilla.org/en-US/docs/Learn_web_development/Extensions/Advanced_JavaScript_objects/Object-oriented_programming)

```cpp
float result = 5 / 2; // 5 / 2 is integer division: 2
                      // result becomes 2.0f
```

The assignment to `float` happens **after** the division, so it cannot recover the lost `.5`.

## 🛠️ Avoiding unexpected truncation

Ensure at least one operand is a floating-point literal or floating-point variable:

| Expression | Operand types | Result |
|---|---|---|
| `5 / 2` | `int / int` | `2` |
| `5.0 / 2` | `double / int` | `2.5` |
| `5.0f / 2` | `float / int` | `2.5f` |
| `5 / 2.0` | `int / double` | `2.5` |
| `static_cast<double>(5) / 2` | `double / int` | `2.5` |

## 🧠 Rule of thumb

> **If either side of `/` is a floating-point type, the division is floating-point division. If both sides are integers, the division is integer division and truncates.**

## 🔗 Sources

- CodeChef: C++ float and integer division behavior 
- C++ forum discussion: mixed-type division and promotion [csd.uwo](https://www.csd.uwo.ca/courses/CS1027b/notes/CS1027-001b-OOP-W17.pdf)
- Microsoft C++ guidance: integer-float division warning [developer.mozilla](https://developer.mozilla.org/en-US/docs/Learn_web_development/Extensions/Advanced_JavaScript_objects/Object-oriented_programming)
- Birkbeck C++ introduction: integer division and truncation [book.vtk](https://book.vtk.org/en/latest/VTKBook/02Chapter2.html)