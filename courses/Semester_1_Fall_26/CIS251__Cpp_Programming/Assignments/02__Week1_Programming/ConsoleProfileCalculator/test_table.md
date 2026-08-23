# TEST TABLE for: Week 1 Programming Assignment

| Num 1 | Num 2 |   Expected Result | Actual Result | Pass/Fail |
| ----- | ----- | ----------------: | ------------: | --------- |
| 3     | 1     |                 3 |             3 | Pass      |
| 9     | 3     |                 3 |             3 | Pass      |
| 3     | 9     |               .33 |             0 | Fail      |
| 3     | 7     |               .43 |             0 | Fail      |
| 3     | 0     | Div by Zero Error |         blank | Fail      |
| 9     | 7     |              1.29 |             1 | Fail      |

NOTES & CONCLUSIONS:

- Though I'm declaring the initial numbers as int, I am declaring the division results as double, which I expected to hold precision to 2 decimal places.
- It seems that declaring the arithmetic result as double still only results in an integer output.
