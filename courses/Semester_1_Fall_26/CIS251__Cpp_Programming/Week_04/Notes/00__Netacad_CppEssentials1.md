<!-- 🔗 Custom Stylesheet -->
<link rel="stylesheet" href="../../../_css/main.css">

<!-- 🖼️ Site Logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

# NOTES: Week 4 (CIS 251 - C++ Programming)

# 🧩 CPPE1: Module 2: Control Structures and Data Types in C++


## 📖 2.0. If and Else: Enhancing Conditional Instructions in C++



---

### 🟣 2.0.1 The conditional statement – more conditional than before



---

### 🟣 2.0.2 LAB Essentials of if-else statement



---

### 🟣 2.0.3 LAB Some actual evaluations - taxes



---

### 🟣 2.0.4 LAB Some actual evaluations - converting measurement systems



---

### 🟣 2.0.5 LAB Some actual evaluations - finding day of week



---

### 🟣 2.0.6 LAB Some actual evaluations - finding date of Easter



---


## 📖 2.1. Additional Data Types and Their Applications


---

### 🟣 2.1.1 Not only the int is an int

It would seem that the developer’s life would be organized well enough if they had type int to operate with integers, type char to manipulate characters and type float for floating-point calculations.

However, this practice has shown that such a narrow repertoire of types may raise some problems.

Most of the computers currently in use store ints using **32 bits** (4 bytes); this means that we can operate the ints within the range of [-2147483648 .. 2147483647]. It may happen that:

*   we don’t need such big values; if we count sheep, it’s unlikely that we’ll need to count two billion of them, so why waste the majority of these 32 bits if we don’t need them;
*   we need much larger values; for example, we intend to calculate the exact number of humans living on Earth; in this case we need more than 32 bits to represent that number;
*   this brings us to another observation – after all, the number of inhabitants on Earth will never be a negative number; it seems like a real waste that up to half of the permissible range will never be used.

For these reasons, the C++ language provides some methods for defining precisely how we intend to store large/small numbers. This allows the compiler to allocate memory, either smaller than usual (e.g. 16 bits instead of 32) or larger than usual (e.g. 64 bits instead of 32). We can also declare that we guarantee that the value stored in the variable will be **non-negative**.

In this case the width of the variable’s **range does not change**, but is **shifted** toward the positive numbers. This means that instead of the range of -2,147,483,648 .. 2,147,483,647 we get the range of 0 .. 4294967295.

![alt text](image.png)

  

To specify our memory requirements, we can use some additional keywords called _modifiers_:

*   _long_ – is used to declare that we need a wider range of ints than the standard one;
*   _short_ – is used to determine that we need a narrower range of ints than the standard one;
*   _unsigned_ – used to declare that a variable will be used only for non-negative numbers; this might surprise you, but we can use this modifier together with the type char; we’ll explain it soon.

Let’s look at some examples.

  

The `counter` variable will use fewer bits than the standard `int` (e.g., it could be 16 bits long – in this case, the range of the variable will be suppressed to the range of [-32768 to 32767]):

```cpp
short int counter;
```

The word int may be omitted as all the declarations are considered to be specifying int by default, like this:

```cpp
short Counter;
```
The ants variable will occupy more bits than the standard int (e.g. 64 bits, so it can be used to store numbers from the range of [-9223372036854775808 .. 9223372036854775807] – can you read such huge numbers?

```cpp
long int ants;
```

Note – we can again omit the word int:

```cpp
long ants;
```

If we come to the conclusion that a variable will never be a negative value, we can use the unsigned modifier:


```cpp
unsigned int positive;
```

Of course, we can omit the int as usual:


```cpp
unsigned positive;
```

We can also mix some of the modifiers together – take a look:


```cpp
unsigned long int big_number;
```

We can remove the word int and the declaration will preserve its meaning:

```cpp
unsigned long big_number;
```

A more modest example is here:

```cpp
unsigned short int lambs;
```

Its equivalent form is:

```cpp
unsigned short lambs;
```

  

The _long_ and _short_ modifiers **must not be used** in conjunction with the type char (why?) and (for obvious reasons) must not be used simultaneously in a single declaration. But there’s nothing preventing us from using the _unsigned_ modifier with a variable of type char. What do we get from this declaration?

Don’t forget that we’re not allowed to omit the word char. Most of the compilers currently in use assume that the chars are stored using 8 bits (1 byte). That may be enough to store a small value such as the number of months or even the day of the month.

If we treat the char variable as a signed integer number, its range would be \[-128 .. 127\]. If we don’t need any signed value (as in the example below), its range shifts to \[0 .. 255\]. This may be sufficient for many applications and may also result in significant savings in memory usage.

```cpp
unsigned char little_counter;
```

But we need to add an important remark. So far we’ve used integer literals, assuming that all of them are of type int. This is generally the case, but there are some cases when the compiler recognizes literals of type long. This will happen if:

*   a literal value goes **beyond the acceptable** range of type int;
*   **letter L or l is appended** to the literal, such as 0L or 1981l – both of these literals are of type long.



---

### 🟣 2.1.2 Another float type


---

### 🟣 2.1.3 Floats and their traits


---

### 🟣 2.1.4 In memory of George Boole


---


## 📖 2.2. Looping Constructs: Iterating Through Code Blocks



---

### 🟣 2.2.1 Two simple programs



---

### 🟣 2.2.2 Some simple programs



---

### 🟣 2.2.3 The “while” loop



---

### 🟣 2.2.4 The “do” loop or do it at least once



---

### 🟣 2.2.5 “for” - the last loop



---

### 🟣 2.2.6 break and continue – the loop's spices



---

### 🟣 2.2.7 LAB Collatz's hypothesis



---

### 🟣 2.2.8 LAB Some actual evaluations – finding the value of π



---

### 🟣 2.2.9 LAB Finding positive powers of 2



---

### 🟣 2.2.10 LAB Finding negative powers of 2



---

### 🟣 2.2.11 LAB Drawing squares (actually: rectangles)



---

### 🟣 2.2.12 LAB Postcard from Gizah



---

### 🟣 2.2.13 LAB Do it yourself: Fibonacci sequence



---

### 🟣 2.2.14 LAB Do it yourself: factorials



---

### 🟣 2.2.15 LAB The riddle (a bit of a tricky one)



---
2.3. Algebra and Computer Logic



### 🟣 2.3.1 Computers and their logic



---

### 🟣 2.3.2 Pride && Prejudice



---

### 🟣 2.3.3 To be || not to be



---

### 🟣 2.3.4 Some logical expressions



---

### 🟣 2.3.5 How to deal with single bits



---

### 🟣 2.3.6 LAB Counting bits (the ones)



---

### 🟣 2.3.7 LAB Bitwise palindromes



---
2.4. Switch Statements: Another Perspective on Conditional Logic



### 🟣 2.4.1 Case and switch vs. if



---

### 🟣 2.4.2 LAB A real and usable calculator



---2.5. Arrays and Vectors: Why Are They Essential?



### 🟣 2.5.1 Arrays – why?



---



## 📖 2.6. Arrays: Simplifying Array Setup



---

### 🟣 2.6.1 Array initialization



---
2.7. Arrays of Arrays: Understanding Multidimensional Arrays



### 🟣 2.7.1 Not only ints



---

### 🟣 2.7.2 Not only vectors



---
2.8. Structures: Their Importance and Functionality



### 🟣 2.8.1 Structures – why do we need them?



---

### 🟣 2.8.2 Declaring the structures



---

### 🟣 2.8.3 Structures – how do we use them?



---

### 🟣 2.8.4 LAB Simple vector manipulations



---

### 🟣 2.8.5 LAB Collecting banknotes



---

### 🟣 2.8.6 LAB Palindromes once again



---

### 🟣 2.8.7 LAB Evaluating different kinds of means



---

### 🟣 2.8.8 LAB Two-dimensional square array – symmetric or not?



---2.9. Declaring and Initializing Structures: Fundamentals and Techniques



### 🟣 2.9.1 Structures – a few important rules



---

### 🟣 2.9.2 LAB Structure of time or time of structure



---

### 🟣 2.9.3 LAB Times and durations



---2.10. Module 2 Completion – Module Test
assignment
100 Pts



### 🟣 2.10.1 Congratulations! You have completed Module 2



---

### 🟣 2.10.2 Module 2 Test



---

