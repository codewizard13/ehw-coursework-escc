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

- **⏳ Metrics**: It took me about 10 minutes to add and test, and another 30 to document.

---

### 4. Refactoring the Unit Display

I needed to display the singular or plural unit label consistently. I first extracted the logic into a `Distance` member function named `printUnitText()` and called it from `display()`. That approach had three problems:

- It returned nothing. It printed the label directly with `cout`, so I could not store, reuse, or combine the label as a string.
- It split one output line across several statements in `display()`, which made the output order harder to follow.
- After I changed it to return a `string`, calling it without sending the result to `cout` printed no label.

I then refactored to a `setUnitText()` member function that sets a new private class variable, `unitTxt`. That fixed the compiler errors but introduced a logic error, described below.


Here is my code for the `printUnitText()`


```cpp
  // Return the unit text.
  void printUnitText()
  {
    switch (unit)
    {
    case inch:
      cout << (dist == 1.0 ? "inch" : "inches");
      break;
    case foot:
      cout << (dist == 1.0 ? "foot" : "feet");
      break;
    case mile:
      cout << (dist == 1.0 ? "mile" : "miles");
      break;
    }
  }

  // Display the endpoint calculation and singular/plural unit label.
  void display()
  {
    cout << "Distance: ABS (" << end << " - " << start << ") = ";
    cout << dist << " ";
    cout << this->printUnitText();
    cout << endl;
  }
```

That refactor worked, but it always printed the units as `inches` no matter what. Then I decided to try a slightly different approach: using a setter for a private member property `unitTxt`.


One compiler error showed that `setUnitText()` initially returned `bool` while `unitTxt` was declared as `string`. I corrected the return type to `string`.


```cpp
class Distance {

  // ...

  // Set the unit text
  string setUnitText()
  {
    switch (unit)
    {
    case inch:
      return (dist == 1.0 ? "inch" : "inches");
      break;
    case foot:
      return (dist == 1.0 ? "foot" : "feet");
      break;
    case mile:
      return (dist == 1.0 ? "mile" : "miles");
      break;
    }
    return "Error: unit unknown";
  }

  // Display the endpoint calculation and singular/plural unit label.
  void display()
  {
    cout << "Distance: ABS (" << end << " - " << start << ") = ";
    cout << dist << " " << unitTxt << endl;
  }

  // ...

  private:
    double start = 0.0;
    double end = 0.0;
    Unit unit = inch;
    string unitTxt = setUnitText();
    double dist = 0.0;
};
```

Test 8 exposed an initialization-order bug. `unitTxt` was initialized before the constructor stored the foot value and calculated the distance, so it incorrectly stayed `"inches"`. I moved `this->unitTxt = setUnitText();` into the constructor, after `unit`, `dist`, and the endpoints are set, so the label now matches the object. The private member now has the default `string unitTxt = "inches";`.

So, heres a code excerpt showing the main refactor states at this point:

```cpp
class Distance
{
public:
  Distance()
  {
    // Use the default member initializers.
  }

  // Constructor: Initialize endpoints, calculate distance, and select a unit.
  Distance(double start, double end, Unit unit = Unit::inch)
  {
    this->start = start;
    this->end = end;
    this->dist = abs(end - start);
    this->unit = unit;
    this->unitTxt = setUnitText(); // Unit text is set in the constructor
  }

  // Show the unit text
  string setUnitText()
  {
    switch (unit)
    {
    case inch:
      return (dist == 1.0 ? "inch" : "inches");
      break;
    case foot:
      return (dist == 1.0 ? "foot" : "feet");
      break;
    case mile:
      return (dist == 1.0 ? "mile" : "miles");
      break;
    }
    return "Error: unit unknown";
  }

  // Display the endpoint calculation and singular/plural unit label.
  void display()
  {
    cout << "Distance: ABS (" << end << " - " << start << ") = ";
    cout << dist << " " << unitTxt << endl;
  }

  // ...

private:
  double start = 0.0;
  double end = 0.0;
  Unit unit = Unit::inch;
  string unitTxt = "inches";
  double dist = 0.0;
};

// ...

int main()
{
  // ...

  // Define datasets
  vector<TestCase> testHarness = {
      {"TEST CASE: 1", "Default construction (0, 0)"},
      {"TEST CASE: 2", "Initialize two double endpoints; use default inches", 2.0, 10.0},
  };

  // Loop through test harness
  for (const auto &test : testHarness)
  {
    cout << "\n============ " << test.title << " =============\n";
    cout << "Decription: " << test.descr << endl;
    cout << "INPUTS" << endl;
    cout << "- Start:  " << test.start << endl;
    cout << "- End:    " << test.end << endl;
    cout << "- Unit:   " << test.myUnit << endl;
  }

  // TEST 1: Default construction with zero-valued endpoints.
  cout << "\n***************** TEST 1 ******************\n";
  Distance d1;
  d1.display(); // Expected distance: 0.00 inches

  // ...

  // TEST 8: Negative endpoint and the plural feet label.
  cout << "\n***************** TEST 8 ******************\n";
  Distance d8(4.0, -10.0, Unit::foot);
  d8.display(); // Expected distance: 14.00 feet

  // ...

  return 0;
}
```

And here's the output showing that it correctly registers "feet" with the `Unit::foot` enum value:

```sh
******** START DISTANCE CALC PROGRAM *****************************************

The current file is:    100__Main-WIP.cpp

============ TEST CASE: 1 =============
Decription: Default construction (0, 0)
INPUTS
- Start:  0.00
- End:    0.00
- Unit:   0

============ TEST CASE: 2 =============
Decription: Initialize two double endpoints; use default inches
INPUTS
- Start:  2.00
- End:    10.00
- Unit:   0

***************** TEST 1 ******************
Distance: ABS (0.00 - 0.00) = 0.00 inches

***************** TEST 8 ******************
Distance: ABS (-10.00 - 4.00) = 14.00 feet

******** END PROGRAM *******************************************
```

---

### 5. Reversing Course: Removing the test harness and opting for the manual tests again

After a minor test implementation of the test harness approach, I realized it was too complex for the scope of what I'm trying to do. Thus, I removed all the test-harness-ry but left the new `setUnitText()` member function.

> - #GOTCHA: Somehow my `enum class Unit` got reverted back to `enum Unit`! Ugh. Spent 5 miutes fixing that. I suspect it was code I copied from the Perplexity or Copilot that was referencing an earlier state.

I added self-documenting output for better user experience indicating `DESCRIPTION`, `INPUTS`, and `EXPECTED OUTPUT`. Enabled all tests through 11.

> - #GOTCHA: Test 11 takes in two feet measurement and silently returns inches, but it should also be feet. Will resolve that next


### ??. Implementing unit conversion

Suggestion addressed:

> Implementing unit conversion to **Avoid silent failure on mismatched units**

This is my code attempt:

```cpp

// ...

  bool convertUnit(Unit orig, Unit final) {
    return false;
  }

  // Display the endpoint calculation and singular/plural unit label.
  void display()
  {
    cout << "Distance: ABS (" << end << " - " << start << ") = ";
    cout << dist << " " << unitTxt << endl;
  }

  // Add travel distances and retain the left operand's unit.
  // Assumes both operands use the same unit.
  Distance operator+(const Distance &d)
  {
    Distance temp;

    // if the units for both operands are not the same,
    //  convert both units to inches
    if (this->unit != d.unit) {
      cout << this->unit << " is NOT THE SAME as " << d.unit << endl;
      // convertUnit(this->unit);
    }

    temp.dist = this->dist + d.dist;
    temp.start = 0.0;
    temp.end = temp.dist;
    temp.unit = this->unit;

    return temp;
  }

  // ...
  ```

refactor(courses/CIS251__Cpp): wk 14 assmt - Main.cpp - WIP - add convertUnit() stub and logic in Distance operator+() to determine if both operand units are equal or not; NOTE: This is a temporary debug cout, but it compile errors because of `<<`; Will fix that next


VSCODE copilot fusion, my prompt:

```md
#PROMPT

I'm trying to automatic unit conversion such that if two distances with different unit values are added, it automatically converts the units to match. If inches and feet are added, it should convert to inches, but, if after the addition there inches / 12 >=1, then it should display the result as feet. If feet and miles are added, similarly it should convert both measurements to the feet (the small unit), then if after the additon there is >=5280 feet, then it should display in miles, the the 2-decimal precision.

Here's the error I'm getting at compile time (partial). I can obviously see that the plus overload function doesn't know what to do with the `<<`. I'm not trying to overload inside an overload, but I am confused on how to handle this:

100__Main-WIP.cpp: In member function 'Distance Distance::operator+(const Distance&)':
100__Main-WIP.cpp:116:12: error: no match for 'operator<<' (operand types are 'std::ostream' {aka 'std::basic_ostream<char>'} and 'Unit')
  116 |       cout << this->unit << " is NOT THE SAME as " << d.unit << endl;
      |       ~~~~ ^~ ~~~~~~~~~~
      |       |             |
      |       |             Unit
      |       std::ostream {aka std::basic_ostream<char>}
  • there are 55 candidates
    100__Main-WIP.cpp:116:12:
      116 |       cout << this->unit << " is NOT THE SAME as " << d.unit << endl;
          |       ~~~~~^~~~~~~~~~~~~
In file included from C:/msys64/ucrt64/include/c++/16.1.0/ostream:42,
                 from C:/msys64/ucrt64/include/c++/16.1.0/iostream:43,
                 from 100__Main-WIP.cpp:44:
    • candidate 1: 'std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(__ostream_type& (*)(__ostream_type&)) [with _CharT = char; _Traits = std::char_traits<char>; __ostream_type = std::basic_ostream<char>]'
      C:/msys64/ucrt64/include/c++/16.1.0/bits/ostream.h:116:7:
        116 |       operator<<(__ostream_type& (*__pf)(__ostream_type&))
            |       ^~~~~~~~
      • no known conversion for argument 1 from 'Unit' to 'std::basic_ostream<char>::__ostream_type& (*)(std::basic_ostream<char>::__ostream_type&)' {aka 'std::basic_ostream<char>& (*)(std::basic_ostream<char>&)'}
```

```md
#RESPONSE

The compile error is just from this diagnostic line:

    ```cpp
    cout << this->unit << " is NOT THE SAME as " << d.unit << endl;
    ```

`Unit` is an `enum class`, so C++ doesn’t automatically know how to print it. You don’t need that diagnostic for addition; remove it rather than overloading `<<`.

For the conversion, make your helper take a numeric distance and return the converted value:

    ```cpp
    static double unitInches(Unit unit)
    {
      switch (unit)
      {
      case Unit::inch: return 1.0;
      case Unit::foot: return 12.0;
      case Unit::mile: return 63360.0;
          }
          return 1.0;
        }

    static double convertUnit(double value, Unit from, Unit to)
    {
      return value * unitInches(from) / unitInches(to);
    }
    ```

Then the simplest approach in `operator+` is:

1. If the units match, add the values and keep that unit.
2. Otherwise, convert both distances to inches and add them.
3. Choose the display unit: miles at 63,360 inches or more, feet at 12 inches or more, otherwise inches. This gives you feet for a mixed feet/miles sum below one mile, and miles once it reaches a mile.
4. After setting the result’s `dist` and `unit`, refresh `unitTxt` with `temp.unitTxt = temp.setUnitText();`. Otherwise, the result may keep its default `"inches"` label even when its unit is feet or miles.

Your existing `fixed << setprecision(2)` in `main` already handles the two-decimal display.
```





---








---



TESTING ...

