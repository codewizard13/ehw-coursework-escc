<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


> CIS 251 - C++ Programming | (Fall 2026 · *Dr. Rosalyn Warren*)   
> 📝 Eric Hepperle's Notes on — **Cisco Netacad C++ Essentials 2** course   
>
> 🧠 CPPE2: Module 4: Operators and Enumerated Types  

# 🧩 4.0.2 What do we want to achieve?

We’re going to show you how to add some new operators to an existing class, as this is the primary application of the operator overloading mechanism. We’ll try to give our stack some new ways access its functionalities. We don’t want to add any new operations to it – we just want to create a new method of invoking those already implemented.

We mentioned the “<<” and “\>>” operators a slide ago and now we want to overload them once again.

The snippet in the editor illustrates our plans. We want the “<<” to be a synonym of the push method invocation and we want the “\>>” to play the role of a pop member function. How do we do that?

  

```cpp
Stack stack(100);
int var;

stack << 200;     // push
stack >> var;   // pop
```

The C++ language **treats overloaded operators as very specific functions**. The number of parameters of these functions must correspond to the number of operator arguments, but it isn’t as simple as you may expect (e.g. a function implementing a new role of a binary operator must not have two arguments).

The name of such a specific function is also specific: it consists of a keyword “operator” glued to an operator symbol, e.g. a function implementing the “\>>” operator will be named:

  

```cpp
operator>>
```

  

You can’t name it in any other way.

An operator function may be implemented in two ways:

*   **as a member function of a class** – it’s implicitly assumed that an object of that class is one of the required operator’s arguments
*   **as a “standalone” function** – the function must explicitly specify the types of all its arguments

Let’s start with the first method.