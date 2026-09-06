Due Sep 6 11:59pm

# Discussion Topic: Week 3 Discussion - Decision Structures and Boolean LogicWeek 3 Discussion - Decision Structures and Boolean Logic

## Week 3 Discussion - Decision Structures and Boolean Logic

> How can AI-generated test cases help expose boundary-condition errors without becoming a substitute for your own reasoning?

**Requirements:** Post a substantive response of approximately 200-300 words by Thursday and reply constructively to at least two classmates by Sunday. When code is relevant, use a small code example and explain it in your own words. Cite/link any external source used.

**AI transparency:** If you use an AI assistant to brainstorm, disclose how you used it and identify at least one point you independently verified.

---

# MY ANSWER (ORIGINAL PARTIAL DRAFT):

Boundary condition errors are bugs that happen right at the edges of what your program allows (smallest, largest, negative, empty, wrong input type, etc.)

For example, if you know that you are using a switch statement that has options 1,2,3 mapped to "Green", "Yellow", "Red" (as in a stoplight simulator) and that those are the only valid values, then you can quickly determine some boundary values without using AI, since the allowed values are explicit. Nothing besides 1, 2, 3 are legal, so the only thing that might be obvious to test is if you've defined "light_value" as an int, but you put quotes around it making it a string.

Now, consider a different example that tests if a value is between x and y. In this case you are dealing with ranges, and you are liable to get into some off-by-one errors. Those can become a problem with memory addresses being wrong .... etc.

| value | description     | fail reason |
| ----- | --------------- | ----------- |
| 0     | the number zero | not in the legal set|
| -1     | negative values | not in the legal set|

## MY ANSWER (AFTER AI ASSISTANCE):

## ✅ Preserved Answer (with your correction applied)

Boundary condition errors occur at the edges of what a program accepts: the smallest and largest valid values, values just outside the allowed range, negative numbers, empty input, or wrong input types. These are exactly where off‑by‑one mistakes and invalid‑input bugs tend to hide.

AI‑generated test cases help by rapidly listing plausible edge cases you might overlook, especially when requirements are implicit rather than explicit. For example, in a stoplight simulator that only allows `1`, `2`, or `3`, the obvious boundaries are clear. But in a function that accepts “any integer between `min` and `max`,” it’s easy to forget to test `min‑1`, `max+1`, `INT_MIN`, or `INT_MAX`. An AI can quickly propose these, saving time and expanding coverage.

```cpp
// Example switch statement
    switch (light_value) {
        case 1:
            light_label = "Green";
            break;
        case 2:
            light_label = "Yellow";
            break;
        case 3:
            light_label = "Red";
            break;
        default:
            light_value_valid = false;
    }
```

However, AI suggestions must not replace your own reasoning. You still need to decide which boundaries are meaningful for your specific logic and data types, and to verify that the tests actually exercise the intended conditions.

```cpp
int light_value;
cin >> light_value;

// Valid: 1, 2, 3
// Important boundaries to test: 0, 4, -1, 999, and non‑numeric input
```

In my own work, I used an AI assistant to brainstorm boundary values for a `switch` on `light_value`. It suggested testing `0`, `4`, large positives/negatives, and non‑numeric input. I independently verified that string and non‑numeric input activates the `default` condition in the `switch`, with one weird quirk: entering only spaces and then pressing Enter keeps the input cursor waiting (repeated carriage returns) and never breaks out of the input prompt. That verification step ensured I understood the actual runtime behavior instead of just copying a list.

Used this way, AI becomes a force multiplier for testing, not a substitute for thinking.

***

## 🤖 AI Transparency (for your post)

- **How I used AI:** To brainstorm boundary values and help tighten wording.  
- **What I verified myself:** That string and non‑numeric input activates the `default` condition in the `switch`, all values in the allowed set work, and that entering only spaces followed by Enter leaves the input cursor waiting instead of completing the read.