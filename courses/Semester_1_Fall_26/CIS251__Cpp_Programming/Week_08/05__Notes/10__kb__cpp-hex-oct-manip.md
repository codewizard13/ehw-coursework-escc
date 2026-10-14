# 📘 Sidebar: C++ `hex` and `oct` Stream Manipulators

## 🏷️ What they are

`hex` and `oct` are **stream manipulators**—special predefined C++ names used with `cin` and `cout` to control how integer values are formatted. They are not variable modifiers and not ordinary keywords; they are part of the input/output stream library. [en.cppreference](https://en.cppreference.com/cpp/io/manip)

- `dec` — display integers in decimal (base 10)
- `hex` — display integers in hexadecimal (base 16)
- `oct` — display integers in octal (base 8)

## 🧩 Basic syntax

```cpp
cout << i << hex << endl;
cout << i << oct << endl;
```

Read the statement left to right:

| Code | Meaning |
|---|---|
| `cout` | The standard output stream, usually the console |
| `<<` | Insertion operator; sends the right-side item into `cout` |
| `i` | The integer value to print |
| `hex` | Changes the stream’s integer base to hexadecimal |
| `oct` | Changes the stream’s integer base to octal |
| `endl` | Sends a newline and flushes the output buffer |

The `<<` operator can be chained, so `cout << i << hex << endl;` performs three actions in order: print `i`, apply `hex`, then print a newline. [en.cppreference](https://en.cppreference.com/cpp/io/manip)

## 🔄 Order matters

```cpp
cout << i << hex << endl;   // i prints in decimal; hex applies afterward
cout << hex << i << endl;   // i prints in hexadecimal
```

In the first statement, `i` is sent to `cout` before `hex`, so it appears in decimal. In the second statement, `hex` is applied before `i`, so `i` appears in hexadecimal. [learn.microsoft](https://learn.microsoft.com/en-us/cpp/standard-library/using-insertion-operators-and-controlling-format?view=msvc-170)

## 📌 Sticky behavior

`hex` and `oct` are **sticky**: once applied, they remain in effect for later integer output until changed by another base manipulator, usually `dec`. [learn.microsoft](https://learn.microsoft.com/en-us/cpp/standard-library/using-insertion-operators-and-controlling-format?view=msvc-170)

```cpp
cout << hex << 255 << endl;  // ff
cout << 255 << endl;         // ff — still hexadecimal
cout << dec << 255 << endl;  // 255 — back to decimal
```

## ✅ Example: input 8

```cpp
int i;
cin >> i;
cout << i << hex << endl;
cout << i << oct << endl;
```

If the user enters `8`, output is:

```text
8
8
10
```

- `8` — decimal
- `8` — hexadecimal; digits 0–9 look the same in both bases
- `10` — octal; \(8_{10} = 10_8\)

The value stored in `i` never changes. Only the way `cout` displays it changes. 

## 🧠 Mental model

Think of a manipulator as a **setting sent to the stream**:

```cpp
cout << value << setting;
```

- `value` says, “Print this.”
- `setting` says, “Change how future values are displayed.”

So `cout << i << oct << endl;` means: “Print `i` now, then make `cout` display future integers in octal.” [cs.fsu](https://www.cs.fsu.edu/~myers/c++/notes/formatting.html)

## ⚠️ Common quiz gotcha

Do not assume `cout << i << hex` prints `i` in hexadecimal. It prints `i` first, then changes the base for later output. To print `i` in hexadecimal, write:

```cpp
cout << hex << i << endl;
```