# 📘 KB: C++ `fixed`, Scientific Notation, and Floating-Point Precision

## 🧠 What the code does

```cpp
#include <iostream>
using namespace std;

int main()
{
    double big = 1e15;
    double small = 1e-15;

    cout << fixed << big + small;

    return 0;
}
```

This program adds a very large number and a very tiny number, then prints the result using fixed decimal notation.

Output:

```text
1000000000000000.000000
```

## 🔢 Scientific notation

C++ uses `e` notation for powers of 10:

| Literal | Meaning | Decimal value |
|---|---|---|
| `1e15` | \(1 \times 10^{15}\) | `1000000000000000` |
| `1e-15` | \(1 \times 10^{-15}\) | `0.000000000000001` |

So `big + small` is mathematically:

```text
1000000000000000.000000000000001
```

## 🖨️ What `fixed` does

`fixed` is a **stream manipulator**: it tells `cout` to display floating-point numbers in normal decimal form rather than scientific notation such as `1e+15`. [cplusplus](https://cplusplus.com/reference/ios/fixed/)

With `fixed`, C++ uses a default precision of **6 digits after the decimal point** unless you change it with `setprecision()`. 

```cpp
cout << fixed << 1e15;
```

prints:

```text
1000000000000000.000000
```

## ⚠️ Why the tiny number disappears

The tiny value `1e-15` is much smaller than the six decimal places shown by default:

```text
0.000000000000001
```

Because `fixed` displays only six places after the decimal, the displayed result becomes:

```text
1000000000000000.000000
```

The tiny addition is effectively rounded out of the displayed output. [cplusplus](https://cplusplus.com/reference/ios/fixed/)

## 🧩 Show more decimal places

Use `setprecision()` from `<iomanip>`:

```cpp
#include <iomanip>
cout << fixed << setprecision(20) << big + small;
```

This asks `cout` to show 20 digits after the decimal point, making the tiny contribution more visible—subject to the limits of `double` precision. [geeksforgeeks](https://www.geeksforgeeks.org/cpp/print-a-double-value-with-full-precision-in-cpp/)

## 🧠 Key takeaway

`double` values have limited precision. Adding a very small number to a very large number may not visibly change the printed result, especially when `fixed` uses its default six decimal places. [geeksforgeeks](https://www.geeksforgeeks.org/cpp/print-a-double-value-with-full-precision-in-cpp/)