# 📘 KB: C++ Prefix vs. Postfix Increment and Decrement

## 🧠 Plain English

`++` adds 1 to a variable; `--` subtracts 1. Both come in two forms:

- **Postfix**: `i++` or `i--`
- **Prefix**: `++i` or `--i`

The variable ends up changed by 1 either way. The difference is **which value is returned to the rest of the expression**: postfix returns the old value, while prefix returns the new value. [en.cppreference](https://en.cppreference.com/cpp/language/operator_incdec)

| Form | Name | Changes variable? | Value used in expression |
|---|---|---:|---|
| `i++` | Post-increment | Yes, adds 1 | Old value of `i` |
| `++i` | Pre-increment | Yes, adds 1 | New value of `i` |
| `i--` | Post-decrement | Yes, subtracts 1 | Old value of `i` |
| `--i` | Pre-decrement | Yes, subtracts 1 | New value of `i` |

## 🔍 Example code

```cpp
int i = 0, j = i++, k = --i;
```

Step-by-step:

| Statement | What happens | Values afterward |
|---|---|---|
| `int i = 0;` | `i` starts at 0 | `i = 0` |
| `j = i++;` | `j` receives the old value `0`; then `i` becomes 1 | `j = 0`, `i = 1` |
| `k = --i;` | `i` becomes 0 first; then `k` receives 0 | `k = 0`, `i = 0` |

Final result:

```cpp
i = 0
j = 0
k = 0
```

## 🧩 Memory trick

Look at where the operator sits:

```cpp
j = i++;   // Operator after i: hand over the old value, then change i.
k = --i;   // Operator before i: change i first, then hand over the new value.
```

- `i++` means: “Here is my current value; increase me afterward.”
- `++i` means: “Increase me first; here is my updated value.”
- `i--` means: “Here is my current value; decrease me afterward.”
- `--i` means: “Decrease me first; here is my updated value.” 

## ⚠️ When it matters

If the result is not being stored or used, both forms produce the same final variable value:

```cpp
i++;   // i becomes i + 1
++i;   // i becomes i + 1
```

The distinction matters only when the expression’s value is used, such as:

```cpp
int j = i++;
int k = ++i;
cout << i++;
```

In those cases, `i++` supplies the pre-change value, while `++i` supplies the post-change value. [codegenes](https://www.codegenes.net/blog/difference-between-pre-increment-and-post-increment-in-a-loop/)

## ✅ Quick check

```cpp
int x = 5;
int a = x++;   // a = 5, x = 6
int b = ++x;   // x = 7, b = 7
int c = x--;   // c = 7, x = 6
int d = --x;   // x = 5, d = 5
```

Final values:

```cpp
a = 5
b = 7
c = 7
d = 5
x = 5
```