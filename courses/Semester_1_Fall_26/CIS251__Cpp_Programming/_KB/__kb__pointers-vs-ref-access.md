# 📘 C++ Knowledge Base: Pointers, References, `.` and `->`

## 🎯 The big idea

Pointers and references can both let code access an existing object, but they are **not the same thing**. A pointer is a variable that stores an object’s memory address; a reference is an alias—another name—for an existing object. [en.cppreference](https://en.cppreference.com/cpp/language/reference)

## 📦 Object and dot operator

Use `.` when your variable **is the actual object**.

```cpp
Student s;
s.name = "Eric";
```

Here, `s` is a `Student` object, so use `s.name`.

## 🏷️ Reference and dot operator

A reference acts like another name for the original object. Because it behaves like the object, it also uses `.`.

```cpp
Student s;
Student& alias = s;

alias.name = "Eric";  // Changes s.name
```

`alias` does not store a separately usable address in your code; it refers to `s` and must be initialized when declared. It cannot later be changed to refer to a different object. [learn.microsoft](https://learn.microsoft.com/en-us/cpp/cpp/references-cpp?view=msvc-170)

## 📍 Pointer and arrow operator

A pointer is a separate variable that stores an address.

```cpp
Student s;
Student* ptr = &s;
```

Use `->` to access a member through that pointer:

```cpp
ptr->name = "Eric";
```

The arrow means “follow the address, then access the member.” Pointers to class objects can be used with `->`. [en.cppreference](https://en.cppreference.com/cpp/language/pointer)

## 🔁 Arrow translation

This code:

```cpp
ptr->name
```

is shorthand for:

```cpp
(*ptr).name
```

`*ptr` follows the address to reach the object; `.` accesses its member. Parentheses are necessary. [cs.nmsu](http://www.cs.nmsu.edu/~jcook/posts/cpp-pointersetc/)

## ⚖️ Quick rule

| Variable holds/represents | Use | Example |
|---|---|---|
| Actual object | `.` | `s.name` |
| Reference / alias to object | `.` | `alias.name` |
| Pointer / address of object | `->` | `ptr->name` |

## ⚠️ Pointer safety

A pointer can be changed to point at another object and may be `nullptr` (pointing to no object). Do not use `ptr->member` unless `ptr` points to a valid object. A reference must refer to a valid object when initialized. [en.cppreference](https://en.cppreference.com/cpp/language/reference)