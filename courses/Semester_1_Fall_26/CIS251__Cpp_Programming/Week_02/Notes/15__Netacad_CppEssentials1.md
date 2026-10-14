[DELETE AFTER REFACTOR TO OTHER FILES]



### 🟢 1.3.15 Increment and decrement operators
  
```cpp
variable++

variable--
```

Return the original (unchanged) variable's value and then increment/decrement the variable by 1.

This behavior justifies the presence of the prefix _pre-_ (before) and _post-_ (after) in the operators’ names: _pre-_ because the variable is modified **first** and then its value is **used**; _post-_ because the variable's value is **used** and then **modified**.



---

### 🟢 1.3.16 Pre-and post-operators and their priorities

#ERIC_WEAK

```cpp
int i, j;

i = 1;
j = i++;
```

First, the variable i is set to 1. In the second statement, we’ll see the following steps:

*   the value of i will be taken (as we use the _post-incrementation_);
*   the variable i will be increased by 1.

In effect, j will receive the value of 1 and i the value of 2.

Things go a bit differently here.

```cpp
int i, j;

i = 1;
j = ++i;
```

  

The variable i is assigned with the value of 1; next, the i variable is incremented and is equal to 2; next, the increased value is assigned to the j variable.

In effect, both i and j will be equal to 2.


Look carefully at this program. Let’s trace its execution step by step.

```cpp
int i, j;

i = 4;
j = 2 * i++;
i = 2 * --j;
```

1.  The i variable is assigned the value of 4;
2.  We take the original value of i (4), multiply it by 2, assign the result (8) to j and eventually (post-)increment the i variable (it equals 5 now);
3.  We (pre-)decrement the value of j (it equals 7 now); this reduced value is taken and multiplied by 2 and the result (14) is assigned to the variable i.

What else do you need to know about the new operators? Firstly, their priority is quite high – higher than the "*", "/" and "%" operators. Secondly, their binding depends on whether you use the prefix or postfix version. The prefix version operators have a right-to-left binding, while the postfix operators bind from left to right.

Our priority table now reads as follows:

![alt text](1.3.16_cpp-priority-tbl.png)


---

### 🟢 1.3.17 Shortcut operators

![alt text](1.3.17_shortcut-ops.png)


---

### 🧪 1.3.18   LAB   Parentheses

## Level of difficulty

Easy

## Objectives

Familiarize the student with:

*   the order of operations;
*   the use of parentheses to change the order of operations.

## Scenario

Add some parentheses (none, one or two pairs) in the code below to get the expected results. Try to do this before you run the program.

```sh
result: 6 expected result : 6
result: 24 expected result : 24
result: 6 expected result : 6
result: 32 expected result : 32
result: 0 expected result : 0
```

**Starting Code:**

```cpp
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
  float v=2;
  float result = v + 1 * 2;
  std::cout << "result:  " << result <<  "  expected result :  6" << std::endl;
  result = v + 1 * v + 2 * 2;
  std::cout << "result: " << result <<  "  expected result : 24" << std::endl;
  result = v - 1 * 2 + 2 * 2;
  std::cout << "result:  " << result <<  "  expected result :  6" << std::endl;
  result = v + v * v + v * 2;
  std::cout << "result: " << result <<  "  expected result : 32" << std::endl;
  result = (int)v % 2 * v + 2 * 2;
  std::cout << "result:  " << result <<  "  expected result :  0" << std::endl;
}
```


**Eric's Answer:** #CORRECT

```cpp
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
  float v=2;
  float result = (v + 1) * 2;
  std::cout << "result:  " << result <<  "  expected result :  6" << std::endl;
  result = (v + 1) * (v + 2) * 2;
  std::cout << "result: " << result <<  "  expected result : 24" << std::endl;
  result = (v - 1) * 2 + (2 * 2);
  std::cout << "result:  " << result <<  "  expected result :  6" << std::endl;
  result = (v + v) * (v + v) * 2;
  std::cout << "result: " << result <<  "  expected result : 32" << std::endl;
  result = ((int)v % 2) * (v + 2 * 2);
  std::cout << "result:  " << result <<  "  expected result :  0" << std::endl;
}
```

---

### 🧪 1.3.19   LAB   Floats: operators and expressions

## Objectives

Familiarize the student with:

*   the concept of integers, floating-point numbers, operators and arithmetic operations in C++ programming;
*   understanding the precedence and associativity of C++ operators as well as the proper use of parentheses;
*   performing basic calculations.

## Scenario

Take a look at the code in the editor - it reads a float value, puts it into a variable named _x_ and prints the value of a variable named _y_. Your task is to complete the code in order to evaluate the following expression:

![alt text](1.3.19_lab_y-polynomial-eq.png)

We expect the result to be assigned to _y_.

Note: we've prepared a variable containing the value of π. Use it.

Be careful! Watch the operators and keep their priorities in mind. Remember that classical algebraic notation likes to omit the multiplication operator – you need to use it explicitly.

Don't hesitate to use as many parentheses as you need. Keep your code clean and readable – surround the operators with spaces.

Use additional variables to shorten the expression.

Hint: multiply _x_ by _x_ to get _x_ squared.

Test your code by using the data we've provided – don't be discouraged by any initial failures. Be persistent and inquisitive. Good luck!

![alt text](1.3.19_lab_sample-input.png)

**Starting Code:**

```cpp
#include <iostream>

using namespace std;

int main(void) {
	float pi = 3.14159265359;
	float x,y;

	cout << "Enter value for x: ";
	cin >> x;

	// put your code here
	
	cout << "y = " << y;
	return 0;
}
```

> Be persistent and inquisitive.

**Eric's Answer:**

```cpp
/* ************************************************************
    1.3.19 LAB Floats: operators and expressions
    Student: Eric Hepperle
    Created: 2026-08-29

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	float pi = 3.14159265359;
	float x,y;

	cout << "Enter value for x: ";
	cin >> x;
	
	float x_squared = x*x;
	float pi_squared = pi*pi;

	// put your code here
	float right_den = pi_squared * ((x_squared - (1.0f/2.0f))*(x_squared - (1.0f/2.0f)));
	float right = 1.0f + (x_squared/right_den);
	float left = x_squared / (pi_squared * (x_squared + (1.0f/2.0f)));

	y = left * right;
	
	cout << "y = " << y;

	return 0;
}
```

### #LESSONS_LEARNED 🧠:

> - ⚠️ #GOTCHA: Even though I declared all my variables as `floats`, when I just left the `1/2` as integers, the numbers didn't turn out right. I used Perplexity to help troubleshoot, and learned that you have to pseudo-cast literal ints as floats by adding the `f` prefix onto the end. I had read about that in a previous lesson, but didn't really fully understand the application until I ran into this issue.
>
> - Now I understand that whenever you have an int used in a float calculation, you must write the int as a decimal and append the `f` (ex: `1` should be `1.0f`)
(Ref: https://www.perplexity.ai/computer/tasks/94ca1dd6-4166-48b9-a790-7db3abd63769)

---

### 🧪 1.3.20   LAB   Ints: operators and expressions


## Level of difficulty

Easy

## Objectives

Familiarize the student with:

*   shortcut and pre/post increment/decrement operators;
*   building simple expressions;
*   translating verbal description into programming language;
*   testing code using known input and output data.

## Scenario

Take a look at the code below: it reads two integer values, manipulates them and finally outputs the _k_ variable. The problem is that the manipulations have been described using natural language, so the code is completely useless now.

We want you to act as an intelligent (naturally!) compiler and to translate the formula into real C++ notation. Try to use pre/post and short-cut operators – they fit perfectly into some of the steps.

Test your code using the data we've provided.

![alt text](1.3.20_lab_sample-input.png)


**Starting Code:**

```cpp
#include <iostream>

using namespace std;

int main(void) {
	int i, j, k;
	
	cout << "Enter i: ";
	cin >> i;
	cout << "Enter j: ";
	cin >> j;
	
	// increment i by 2
	// decrement j by i
	// divide i by j giving k
	// increment k by k
	// decrement k by 1
	// assign k modulo i to j
	// increment k by k added to i
	// increment k by k divided by j
	// assign k times k times k to k
	// increment k by i times j
	
	cout << k;
	return 0;
}
```


**Eric's Answer:**

```cpp
/* ************************************************************
    1.3.20 LAB Ints: operators and expressions
    Student: Eric Hepperle
    Created: 2026-08-29

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */
#include <iostream>
using namespace std;

int main(void) {
	int i, j, k;
	
	cout << "Enter i: ";
	cin >> i;
	cout << "Enter j: ";
	cin >> j;

    // // DEBUGGING: Fixed i, j values
    // i = 100;
    // j = 3;
	
	// increment i by 2
    i += 2;

    cout << "i += 2: " << i << endl;

	// decrement j by i
    j -= i;

    cout << "j -= i: " << j << endl;

	// divide i by j giving k
    k = i/j;

    cout << "k = i/j: " << k << endl;

	// increment k by k
    k += k;

	// decrement k by 1
    k--;

	// assign k modulo i to j
    j = k % i;

	// increment k by k added to i
    k += k + i;

	// increment k by k divided by j
    k += k/j;

	// assign k times k times k to k
    k = k * k * k;

	// increment k by i times j
    k += i * j;
	
	cout << "k = " << k << endl;
	return 0;
}
```

### #LESSONS_LEARNED 🧠:

> - ⚠️ #GOTCHA: By not putting `endl` or `\n` at the end of console out statement, it ended up "gluing" the correct 101 value i after the first increment to the incorrect value of k, but it was listing it as the `i` value. I cleared this issue up by adding the `endl` to the end of my debugging line outputting the `i` value. Then I added a label `k = ` to front of the k value for extra clarity and user-friendliness.
>
> - ⚠️ #GOTCHA: I was too eager to use shortcut operators as much as possible, I missed some important instruction discrepancies that skewed my k value by a lot. Eg, I interpreted the instruct5ion `increment k by k added to i` as `k += i`, but the correct **expression** was `k += k + i`. Once I knew that, I was able to understand and interpret what the code should be for the other two statements that I'd broken. BONUS: As a troubleshooting step I even created a truth table in Google Sheets and it was also producing wrong output, so at that point, I asked Perplexity for help. Once he located the first issue, I was able to solve the rest.


---


## 🟣 1.4 Characters: Handling Textual Data in C++

> - **word:** string of characters (letters, numbers, punctuation marks, etc.)


> - 📌 #TIP: in the C++ language **all strings are treated as arrays**.

> - **char:** the character (single) data type


---

### 🟢 1.4.2 ASCII code

**Computers store characters as numbers**. Every character used by a computer corresponds to a unique number, and vice versa. This system of assignments includes more characters than you would probably expect. Many of them are invisible to humans but essential for computers. Some of these characters are called **white spaces**, while others are named **control characters**, because their purpose is to **control** the input/output devices. An example of a white space that is completely invisible to the naked eye is a special code, or a pair of codes (different operating systems may treat this issue differently), which are used to mark the ends of lines inside text files. People don’t see this sign (or these signs), but they can see their effect where the lines are broken.

We can create virtually any number of assignments, but a world in which each computer type uses different character encoding would be extremely inconvenient. This has created a need to introduce a universal and widely accepted standard implemented by (almost) all computers and operating systems all over the world. **ASCII** (which is a short for _American Standard Code for Information Interchange_) is the most widely used system in the world, and it’s safe to assume that nearly all modern devices (like computers, printers, mobile phones, tablets, etc.) use this code. The code provides space for 256 different characters, but we’re only interested in the first 128. If you want to see how the code is constructed, go to the table on the right.

  

Look at it carefully – there are some interesting facts about it that you might notice. We'll show you one. Do you see what the code of the most common character is – the space? Yes – it’s 32. Now look at what the code of the lower-case letter “a” is. It’s 97, right? And now let's find the upper-case “A”. Its code is 65. What’s the difference between the code of “a” and “A”? It’s 32. Yes, that's the code of a space. We’ll use that interesting feature of the ASCII code soon.

Also, note that the letters are arranged in **the same order** as in the **Latin alphabet**.

By the way, ASCII code is being superseded (or rather extended) by a new international standard named UNICODE.

Fortunately, the ASCII set is a [UNICODE](https://en.wikipedia.org/wiki/Unicode "UNICODE") subset. UNICODE is able to represent virtually all characters used throughout the world. We’ll spend a little more time on this later.

  

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Character | Dec | Hex |     | Character | Dec | Hex |     | Character | Dec | Hex |     | Character | Dec | Hex |     |
| (NUL) | 0   | 0   |     | (space) | 32  | 20  |     | @   | 64  | 40  |     | \`  | 96  | 60  |
| (SOH) | 1   | 1   |     | !   | 33  | 21  |     | A   | 65  | 41  |     | a   | 97  | 61  |
| (STX) | 2   | 2   |     | "   | 34  | 22  |     | B   | 66  | 42  |     | b   | 98  | 62  |
| (ETX) | 3   | 3   |     | #   | 35  | 23  |     | C   | 67  | 43  |     | c   | 99  | 63  |
| (EOT) | 4   | 4   |     | ($) | 36  | 24  |     | D   | 68  | 44  |     | d   | 100 | 64  |
| (ENQ) | 5   | 5   |     | %   | 37  | 25  |     | E   | 69  | 45  |     | e   | 101 | 65  |
| (ACK) | 6   | 6   |     | &   | 38  | 26  |     | F   | 70  | 46  |     | f   | 102 | 66  |
| (BEL) | 7   | 7   |     | '   | 39  | 27  |     | G   | 71  | 47  |     | g   | 103 | 67  |
| (BS) | 8   | 8   |     | (   | 40  | 28  |     | H   | 72  | 48  |     | h   | 104 | 68  |
| (HT) | 9   | 9   |     | )   | 41  | 29  |     | I   | 73  | 49  |     | i   | 105 | 69  |
| (LF) | 10  | 0A  |     | \*  | 42  | 2A  |     | J   | 74  | 4A  |     | j   | 106 | 6A  |
| (VT) | 11  | 0B  |     | +   | 43  | 2B  |     | K   | 75  | 4B  |     | k   | 107 | 6B  |
| (FF) | 12  | 0C  |     | ,   | 44  | 2C  |     | L   | 76  | 4C  |     | l   | 108 | 6C  |
| (CR) | 13  | 0D  |     | \-  | 45  | 2D  |     | M   | 77  | 4D  |     | m   | 109 | 6D  |
| (SO) | 14  | 0E  |     | .   | 46  | 2E  |     | N   | 78  | 4E  |     | n   | 110 | 6E  |
| (SI) | 15  | 0F  |     | /   | 47  | 2F  |     | O   | 79  | 4F  |     | o   | 111 | 6F  |
| (DLE) | 16  | 10  |     | 0   | 48  | 30  |     | P   | 80  | 50  |     | p   | 112 | 70  |
| (DC1) | 17  | 11  |     | 1   | 49  | 31  |     | Q   | 81  | 51  |     | q   | 113 | 71  |
| (DC2) | 18  | 12  |     | 2   | 50  | 32  |     | R   | 82  | 52  |     | r   | 114 | 72  |
| (DC3) | 19  | 13  |     | 3   | 51  | 33  |     | S   | 83  | 53  |     | s   | 115 | 73  |
| (DC4) | 20  | 14  |     | 4   | 52  | 34  |     | T   | 84  | 54  |     | t   | 116 | 74  |
| (NAK) | 21  | 15  |     | 5   | 53  | 35  |     | U   | 85  | 55  |     | u   | 117 | 75  |
| (SYN) | 22  | 16  |     | 6   | 54  | 36  |     | V   | 86  | 56  |     | v   | 118 | 76  |
| (ETB) | 23  | 17  |     | 7   | 55  | 37  |     | W   | 87  | 57  |     | w   | 119 | 77  |
| (CAN) | 24  | 18  |     | 8   | 56  | 38  |     | X   | 88  | 58  |     | x   | 120 | 78  |
| (EM) | 25  | 19  |     | 9   | 57  | 39  |     | Y   | 89  | 59  |     | y   | 121 | 79  |
| (SUB) | 26  | 1A  |     | :   | 58  | 3A  |     | Z   | 90  | 5A  |     | z   | 122 | 7A  |
| (ESC) | 27  | 1B  |     | ;   | 59  | 3B  |     | \[  | 91  | 5B  |     | {   | 123 | 7B  |
| (FS) | 28  | 1C  |     | <   | 60  | 3C  |     | \\  | 92  | 5C  |     | \|  | 124 | 7C  |
| (GS) | 29  | 1D  |     | \=  | 61  | 3D  |     | \]  | 93  | 5D  |     | }   | 125 | 7D  |
| (RS) | 30  | 1E  |     | \>  | 62  | 3E  |     | ^   | 94  | 5E  |     | ~   | 126 | 7E  |
| (US) | 31  | 1F  |     | ?   | 63  | 3F  |     | \_  | 95  | 5F  |     |     | 127 | 7F  |


---

### 🟢 1.4.3 Character type values

How do we use the values of the char type in the C++ language? We can do it in two ways, which are not entirely equivalent.

The first way allows us to specify the character itself, but enclosed in single quotes (apostrophes). Let’s assume that we want the variable we declared a few slides earlier to be assigned the value of the upper-case letter “A”.

We do this as follows:

```cpp
character = 'A';
```

You’re not allowed to omit apostrophes under any circumstances.

Now let’s assign an asterisk to our variable. We do this as follows:


```cpp
character = '*';
```

The second method consists of assigning a **non-negative integer value** that is the code of the desired character. This means that the assignment below will put an “`A`” into the character variable.

```cpp
character = 65;
```

  

The second solution, however, is less recommended and if you can avoid it, you should. Why?

The second reason is more exotic, but still true. There’s a significant number of computers in the world which use codes **other than ASCII**. For example, many of the IBM mainframes use a code commonly called [EBCDIC](https://en.wikipedia.org/wiki/EBCDIC "EBCDIC") (_Extended Binary Coded Decimal Interchange Code_) which is very different from ASCII and is based on radically different concepts.


![alt text](1.4.3_ascii-ebcdic-hex-tbl.png)

---

### 🟢 ASCII vs EBCDIC


Now imagine that you’ve written a wonderful program and decided to compile and run it on a computer utilizing the EBCDIC code. If you wrote something like this, the compiler running on that computer would notice the question mark and use the appropriate EBCDIC code for that character.

```cpp
character = '?';
```

But if you wrote it like this:

```cpp
character = 63;
```

---

### 🟢 1.4.5 Literal

Now’s probably a good time to bring a new term into the mix: a **literal**. The literal is a symbol which **uniquely identifies its value**. Some prefer to use a different definition: the **literal means itself**. Choose the definition that you consider to be clearer and look at the following simple examples:

*   `character`: this is not a literal; it’s probably a variable name; when you look at it, you cannot guess what value is currently assigned to that variable;
*   `'A'`: this is a literal; when you look at it you can immediately guess its value; you even know that it’s a literal of the `char` type;
*   `100`: this is a literal, too (of the `int` type);
*   `100.0`: this is another literal, this time of a **floating point** type;
*   `i + 100`: this is a combination of a variable and a literal joined together with the `+` operator; this structure is called an **expression**.

If you’re an inquisitive person, you probably want to ask a question: if a literal of type char is given as the character enclosed in apostrophes, how do we code the apostrophe itself?

The C++ language uses a special convention that also extends to other characters, not only to apostrophes. Let's start with an apostrophe anyway. An apostrophe looks like this:

```cpp
character = '\'';
```

The `\` character (called _backslash_) acts as an **escape character**, because by using the `\` we can escape from the normal meaning of the character that follows the slash. In this example, we **escape** from the usual role of the apostrophe (i.e. delimiting the literals of type `char`).

You can also use the escape character to **escape from the escape character**. Yes, it does sound weird, but the example below should make it clear. This is how we put a backslash into a variable of type char.

```cpp
character = '\\';
```


---


> - 📌 #TIP: It appears that you only the NUMERATOR (top number) needs to have a decimal point for the result to be a decimal point (float).


#ERROR_ENCOUNTERED

![alt text](eh-scrn-cis-251-pract-ex_wk-2_01_err.png)



---

Guided Practice #4-5 PROOF:

![alt text](eh-scrn-cis-251-pract-ex_wk-2_02.png)


> - ⚠️ #GOTCHA: Integer division always ejects / truncates the decimal portion! Use casting on the denominator explicitly write the denominator as a decimal

---


Week 2 Assignment Results:

![alt text](eh-scrn-cis-251-pract-ex_wk-2_03_assmt-results.png)




















