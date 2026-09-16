
> 2.0.5   LAB   Some actual evaluations - finding day of week
# Lessons Learned

---



## ⚠️ Be Careful about Shortcut Assignments with Complex Right Side Formulas

Your other shortcut assignments worked because their right-hand sides were a **single value** or an expression where early integer division did not change the intended order.

For example:

```cpp
month_num += day_num;
month_num += year_num;
month_num += year_num / 4;
month_num -= year_num / 100;
month_num += year_num / 400;
```

Each is effectively:

```cpp
month_num = month_num + day_num;
month_num = month_num + year_num;
month_num = month_num + (year_num / 4);
month_num = month_num - (year_num / 100);
month_num = month_num + (year_num / 400);
```

That grouping is exactly what Zeller’s formula requires: calculate `year_num / 4`, `year_num / 100`, or `year_num / 400` first, discard any fractional part, then add or subtract the whole-number result.

## ⚠️ Why the multiplication line differs

This line:

```cpp
month_num *= 83 / 32;
```

groups as:

```cpp
month_num = month_num * (83 / 32);
```

But Zeller’s rule requires:

```cpp
month_num = (month_num * 83) / 32;
```

The `month_num` must participate in the division calculation **before** the decimal portion gets discarded. In other words, you need the truncated whole-number result of:

```cpp
(month_num * 83) / 32
```

—not the truncated whole-number result of:

```cpp
83 / 32
```

## 📌 Rule of thumb

Use a compound-assignment shortcut safely when this is the calculation you mean:

```cpp
variable = variable OP (entire_right_side);
```

For your additions and subtractions, that is exactly right. For the month calculation, it is not.

Compare:

```cpp
month_num += year_num / 4;       // Correct: add the whole-number year/4
month_num *= 83 / 32;            // Wrong: multiply by the whole-number 83/32
month_num = (month_num * 83)/32; // Correct: divide after multiplying
```

The issue is not that `+=`, `-=`, or `*=` are unreliable; it is that `*=` places `month_num` **outside** the `/ 32` portion of the calculation.