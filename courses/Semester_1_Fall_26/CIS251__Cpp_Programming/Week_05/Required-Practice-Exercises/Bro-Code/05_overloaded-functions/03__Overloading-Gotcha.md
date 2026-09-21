## ✅ Slightly imprecise

It is mostly correct, but “different parameter sets” could mistakenly imply that different **parameter names** are enough.

A more precise concise definition is:

> **Function overloading:** defining multiple functions with the same name in the same scope, with different numbers and/or types of parameters.

For example, this is **not** overloading because both signatures are `bakePizza(string, string, string)`:

```cpp
void bakePizza(string bread, string sauce, string cheese);
void bakePizza(string bread, string sauce, string topping);
```

The parameter names differ, but their number and types do not. [learn.microsoft](https://learn.microsoft.com/en-us/cpp/cpp/functions-cpp?view=msvc-170)