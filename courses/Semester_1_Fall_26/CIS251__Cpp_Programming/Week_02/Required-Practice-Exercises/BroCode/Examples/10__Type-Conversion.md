
# Bro Code Notes:  C++ Type Conversion

(Source: https://www.youtube.com/watch?v=Fj9HjbqHto8)

- implicit and explicit type conversion
- **type conversion:** converting a value of one data type to another
- **implicit type conversion:** done automatically; will truncate the decimal portion during double/float to int conversion
- **explicit type conversion:** converting on data type to another through casting

EX: Explicit type conversion using casting

```cpp
double x = (int) 3.14; // x now = 3

char x = 100; // ASCII letter d

std:cout << (char) 100;
```

- - -

**How is this Useful?**

#CASE_STUDY

Calculate the score of ints as a percentage