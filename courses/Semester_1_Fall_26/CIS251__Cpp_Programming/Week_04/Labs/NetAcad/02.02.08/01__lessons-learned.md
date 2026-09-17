
> 2.2.8 LAB  Some actual evaluations – finding the value of π

# 🎓 Lessons Learned

- The `%` operator returns a remainder and works with integer types—not `double`.
- If the divisor is larger than a positive numerator, the remainder is the numerator:
  ```cpp
  1 % 2  // 1
  ```
- `i % 2 == 0` means `i` is even; `i % 2 != 0` (or `== 1` for nonnegative values) means `i` is odd.

- Integer division happens when **both** operands are integers:
  ```cpp
  1 / 3  // 0
  ```
- Assigning an already-calculated integer result into a `double` does not restore the lost fraction:
  ```cpp
  double x = 1 / 3;  // x becomes 0.0
  ```
- Put a floating-point value in **either** operand to get floating-point division:
  ```cpp
  1.0 / 3   // 0.333333...
  1 / 3.0   // 0.333333...
  ```

## 🔁 Leibniz π logic

- The Leibniz formula is:
  \[
  \frac{\pi}{4} = \frac{1}{1} - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \cdots
  \]
- The denominators are positive odd numbers: `1, 3, 5, 7, ...`.
- The signs alternate: `+`, `-`, `+`, `-`, ...
- A loop starting at `i = 0` should:
  - Add on even indexes: `i = 0, 2, 4, ...`
  - Subtract on odd indexes: `i = 1, 3, 5, ...`
- `n` should represent the number of **terms/iterations**, so use:
  ```cpp
  for (long i = 0; i < n; ++i)
  ```

## 🔢 Sequence pattern

- For any integer `i`:
  ```cpp
  2 * i
  ```
  produces an even integer.

- For any integer `i`:
  ```cpp
  2 * i + 1
  ```
  produces an odd integer.

- If `i` increments by `1`, then `2 * i + 1` increments by `2`, producing consecutive odd values.

- Example:
  ```text
  i:          0, 1, 2, 3
  2 * i + 1:  1, 3, 5, 7
  ```

- The index does not have to start at `0`:
  ```text
  i:          12, 13, 14, 15
  2 * i + 1:  25, 27, 29, 31
  ```

- Starting at `0` matters only when you specifically need the output sequence to begin at `1`.

## 🛠️ Debugging takeaways

- Give each variable one clear job:
  - `i`: term/iteration counter
  - `denom`: denominator for the current fraction
  - `pi4`: running total for \(\pi / 4\)

- Trace the first few loop passes on paper or in comments before trusting the full result:

  ```text
  i = 0 → denom = 1 → +1/1
  i = 1 → denom = 3 → -1/3
  i = 2 → denom = 5 → +1/5
  i = 3 → denom = 7 → -1/7
  ```

- A mathematically correct formula can still produce a wrong program if:
  - The loop starts at the wrong index.
  - The condition’s add/subtract branches are reversed.
  - The denominator sequence is wrong.
  - Integer division removes fractional values.
  - The loop runs fewer or more times than intended.

- When a result has the correct digits but the opposite sign, check whether your add/subtract logic is reversed.

- Leibniz’s series converges slowly, so even a correct answer with 10,000 terms will be close to π but not perfectly equal to it.

---



