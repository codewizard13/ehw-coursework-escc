# 🛠️ Incremental Development Log

## 📘 Assignment Information

- **Course:** CIS-251 — C++ Programming
- **Assignment:** Week 14 — AI-Assisted Software Engineering for C++: Prompting, Verification, and Responsible Use
- **Author:** Eric L. Hepperle
- **Program:** Distance class with AI-suggested updates, version 1.0 (WIP)

## 📋 Initial Design and Planning

I chose week 10's distance assignment because it was complex enough and I remembered I didn't set it up to do unit conversions because it was out of scope. I thought it would be a perfect opportunity for this assignemnt 14 ai assisted challenge.


## 🏗️ Incremental Implementation

### 1. Evaluate the code with Google AI studio

#### Inital Prompt:

I signed up for **Google Ai studio (Gemini)**, then based on this week's tutorial, posted the following prompt:


```md
#PROMPT:

I am a beginning C++ student. My program uses only concepts through classes,
vectors, file I/O, and exceptions. Do not introduce libraries or techniques
outside those topics.

Here is my requirement:

Give me (1) a plain-language explanation, (2) five test cases, and (3) a code
review limited to concepts already covered in CIS 251, based on the draft code
as context.

Here is my current code:

[full Week 10 final Main.cpp code here]

Identify two likely logic errors. Explain each error and suggest a small test
that would expose it. Do not rewrite the entire program.
```

> 📌 #TIP ? iF I was starting over, I would merge the very last paragraph under the "Here is my requirement" section, possibly renamed as "REQUIREMENTS" and as a concise bullet list

#### Results:



Gemini gave the required plain language explanation, five test cases, and the appropriately limited code review.

> - #GOTCHA: _While the programming task description says to submit a revised program and "reject/correct at least one questionable or unnecessary suggestion", it doesn't clearly say to what degree to revise the program. In other words, though it clearly says to reject at least one suggestion, it doesn't say whether to implement at least one suggestion, or whether it is required to implement ALL the non-questionalbe suggestions, or just one, or as many as I choose._
>
>   Therefore, I'm making an executive decision for time sake to only implement two suggestions, so as not to make this overly complex.

Full prompt response [here](./05__AI-Gen-Review.md)



### 2. Converting to Enum class for typesafty

Suggestion addressed:

> Using enum class instead of ...

I wanted more clarity, so I branched the response an asked the following followup prompt:

```md
#PROMPT:

ELI-NOVICE: Use heading emoji. Explain why enum class is more appropriate here. Give your rationale and include tradeoffs -- I am not a fan of having to write :: a whole bunch. Can I just use a namespace? Be detailed, yet concise. No more than 300 words.
```

- **Note:** ELI-Novice is a derivative of "explain like I'm 5" directives. It sets the tone and knowledge level to communicate on to the prompter on. Novice is the level after "explain like I'm 18" and before "Explain like I'm a college student". It's the right amount of simplicity and technical concept accuracy without academically complex sentence structures.

**Gemini Response**:

```md
#RESPONSE

🚦 Why enum class Wins Here

Your global enum Unit leaks inch, foot, and mile into the entire program. If you
later create a variable like double foot = 12.0;, your code will not compile
because the names collide. Worse, plain enums silently turn into integers (0, 1,
2), so C++ lets you write bugs like if (inch == 0) or foot + 10 without any
warning.

Switching to enum class Unit solves both problems:

  - Zero Name Clashes: Names stay locked inside Unit, so double foot works fine.
  - Type Safety: It refuses to mix with numbers, catching logic mistakes before
    the program runs.

⚖️ The Tradeoff: All That :: Typing

You trade a little convenience for safety. Writing Unit::inch, Unit::foot, and
Unit::mile in constructors, main(), and switch statements feels repetitive. In
small assignments, plain enum feels faster—until a name collision or sneaky
integer conversion wastes 20 minutes of debugging.

📦 Can You Just Use a namespace?

You can wrap a plain enum inside a namespace, like namespace Measure { enum Unit
{ inch, foot, mile }; }.

  - What it fixes: It prevents global name collisions (Measure::foot). If you
    dislike typing ::, you can write using namespace Measure; inside main() to
    drop the prefix locally.
  - What it misses: It is still a plain enum, meaning inch still secretly
    behaves like the integer 0. You get cleaner scoping, not type safety.

💡 Beginner Takeaway

Make enum class your default habit. Typing Unit:: a few extra times is a small
price for compiler protection against sneaky bugs.
```

Based on that advice, it seems safest to convert to enum class and use `::` a bunch (\*muffled-grumble\*)

So, I converted the enum to an enum class like this:

```cpp
enum class Unit
{
  inch,
  foot,
  mile
};
```

Pretty simple. Then I had to prefix all the references to `inch`, `foot`, and `mile` with `Unit::`, like this:

```cpp
switch (unit)
{
case Unit::inch:
    cout << (dist == 1.0 ? "inch" : "inches");
    break;
case Unit::foot:
    cout << (dist == 1.0 ? "foot" : "feet");
    break;
case Unit::mile:
    cout << (dist == 1.0 ? "mile" : "miles");
    break;
}
```

- **Note:** `unit` refers to the private member variable declared at the end of the class.

### 3. Comparing against Wk 10 assignment - attempting to break the original

I decided it would be a good idea to not just believe what AI told me, but to test it. First, I wanted to be able to quickly compare results between two different versions of the same file (Wk 10 Main.cpp, vs Wk 14). I knew from PHP and other languages that printing the name of the file that is running / being compiled / interpreted is a basic feature of many languages. I discovered from Perplexity that C++, like PHP, offers `__FILE__`. In PHP this is called a **magic constant**?

I next evaluated whether it would be worth it to convert this program to use a test harness.

I determined that I'd try it because I could use more practice in developing a test-harness loop approach. I found the example I build in Wk 13 and used that as a model. To Wk 14 Main.cpp I added `struct TestCase` like this:


```cpp
struct TestCase {
  string title;
  string descr;
  double start = 0.0;
  double end = 0.0;
  Unit myUnit = Unit::inch;
};
```

Note, I made sure to add the struct right before `main()` because it references the `Unit enum class` and could potentially carry a `Distance` object, so those need to be declared first.

I then commented out all the previous "manual" tests and began building my test harness like this:

```cpp
// Define datasets
vector<TestCase> testHarness = {
    {"TEST CASE: 1", "Default construction (0, 0)",0.0,0.0},
    {"TEST CASE: 2", "Initialize two double endpoints; use default inches",0.0,0.0},
};
```

Finally, I added a basic `foreach` loop with const ref to check if my 'plumbing' was correct, like this:

```cpp
// Loop through test harness
for (const auto &test : testHarness) {
    cout << "\n============ " << test.title << " =============\n";
}
```

This was the result:

```sh
******** START DISTANCE CALC PROGRAM *****************************************

The current file is:    100__Main-WIP.cpp

============ TEST CASE: 1 =============

============ TEST CASE: 2 =============

******** END PROGRAM *******************************************
```

As expected, good so far. Next — display more values from the two test cases, then do calculations with those numbers, then add the rest of the test cases.

---

### ??. Implementing unit conversion

Suggestion addressed:

> Implementing unit conversion to **Avoid silent failure on mismatched units**

---








---
