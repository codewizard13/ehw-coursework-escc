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

![alt text](image-1.png)

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

The _short_ modifier cannot be used alongside the `float`, but we may use the _long_ modifier here. It’s assumed that type `long float` is a synonym for another type named `double`. The variables of type `double` may differ from the variables of type `float`, not only in **range**, but also in **accuracy**.

> - #TIP: Long float is synonomy for `double`

What does this mean? The data stored in a floating-point variable has **finite precision** – in other words, only a certain number of digits are **precisely stored** in the variable.

For example, we expect that the value:


```cpp
1111111111111111111.111111111111111111111
```

will be stored by a specific type of computer as:

```cpp
1111111131851653120.000000
```

We say that the variable saves (only) **8 precise digits**. This is within the expected accuracy of 32-bit long `float`s. Using a `double` (which is usually 64 bits long) guarantees that the variable will save a more significant number of digits – about **15-17**. This is where the name `double` comes from – its accuracy is **doubled** compared to `float`.

---

### 🟣 2.1.3 Floats and their traits

We told you some time ago that computer addition is not always commutative. Do you know why? Imagine that you have to add a large number of floating-point values – some of them are very large, some very small (close to zero). If a very small float value is added to another that’s very large, the result can be quite surprising.

Let’s go back to the previous example – we’ll assume that our computer only saves 8 precise digits of any float. If we add these two floats, we’ll probably get:


```cpp
11111110656.000000
```

as the result. The lower value simply vanished without a trace.

We can’t avoid these effects when we add/subtract the numbers of type float (and of double as well, because they’re also affected by this issue). The phenomenon described here is what we call a **numerical anomaly**.

![alt text](image-2.png)

> - #GOTCHA:  ??? So what do we do about numerical anomalies?

---

### 🟣 2.1.4 In memory of George Boole

**George Boole** (1815 –1864) was an English mathematician, philosopher and logician and we’re talking about him for a very important reason. One of his most important achievements was **algebraic logic**, referred to by Boole himself as “the laws of thought”. Algebraic logic does not operate on numbers but only on **two truth values**, and doesn’t use standard arithmetic operations like addition and multiplication, but **conjunction, disjunction** and **negation**.

Taking into account the fact that virtually all modern computers are built using Boole’s theorems, we can say without exaggeration that Boole was actually one of the founders of IT.

There is a type in the C++ language whose name commemorates George Boole – **the type `bool`**.

It’s a very intriguing type. Variables of this type are able to store only two distinct values: `true` and `false`. Note: all these new words (`bool`, `true` and `false`) are keywords. Don’t forget that.

Take a look at the example below:


```cpp
bool developer_is_hungry = false;
```

We’ve declared a variable there. Neither its name nor its value requires additional comments. There are many contexts where this variable may be useful. One of the most spectacular is the following:

```cpp
if(developer_is_hungry) {
	have_lunch();
	developer_is_hungry = !developer_is_hungry;
}
```

The exclamation mark we’ve used in the assignment is a negation operator. It’s a **unary prefix operator** that changes the logical value of its arguments: because of the operator, true becomes false and vice versa. As you see, having lunch changes the logical state of one of the most important factors of a programmer’s well-being.

To be honest, the `bool` type is only a very special variant of the `int` type. It’s very short (variables of this type occupy only 8 bits, which is still too much, because one bit would be enough). It behaves like an int inside expressions (**true is equivalent to 1 while false is equivalent to `0`**).

We’ll return to this type and its values soon, and to George Boole’s algebra and logical operators, too.




---


## 📖 2.2. Looping Constructs: Iterating Through Code Blocks


```cpp

```


```cpp

```




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

