# C++ Exceptions

## Exceptions

As mentioned in the [C++ Errors](https://w3schools.com/cpp/cpp_errors.asp) chapter, different types of errors can occur while running a program - such as coding mistakes, invalid input, or unexpected situations.

When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an **exception** (throw an error).

- - -

## Exception Handling (try and catch)

Exception handling lets you **catch and handle errors** during runtime - so your program doesn't crash.

It uses three keywords:

*   `try` - defines the code to test
*   `throw` - triggers an exception
*   `catch` - handles the error

### Example

```cpp
try {  
  // Code that may throw an exception  
  throw 505;  
}  
catch (int errorCode) {  
  cout << "Error occurred: " << errorCode;  
}
```

Here, the program throws an exception with the value `505`, which is caught and handled in the `catch` block.

- - -

## Real-Life Example: Age Check

We can use exception handling to check if a user is old enough:

### Example

```cpp
try {  
  int age = 15;  
  if (age >= 18) {  
    cout << "Access granted - you are old enough.";  
  } else {  
    throw (age);  
  }  
}  
catch (int myNum) {  
  cout << "Access denied - You must be at least 18 years old.\n";  
  cout << "Age is: " << myNum;  
}
```

#### Example explained

We use the `try` block to test some code: If the `age` variable is less than `18`, we will `throw` an exception, and handle it in our `catch` block.

In the `catch` block, we catch the error and do something about it. The `catch` statement takes a **parameter**: in our example we use an `int` variable (`myNum`) (because we are throwing an exception of `int` type in the `try` block (`age`)), to output the value of `age`.

If no error occurs (e.g. if `age` is `20` instead of `15`, meaning it will be be greater than 18), the `catch` block is skipped:

### Example

```cpp
int age = 20;  
```

You can also use the `throw` keyword to output a reference number, like a custom error number/code for organizing purposes (`505` in our example):

### Example

```cpp
try {  
  int age = 15;  
  if (age >= 18) {  
    cout << "Access granted - you are old enough.";  
  } else {  
    throw 505;  
  }  
}  
catch (int myNum) {  
  cout << "Access denied - You must be at least 18 years old.\n";  
  cout << "Error number: " << myNum;  
}
```

- - -

## Handle Any Type of Exceptions (...)

If you do not know the `throw` **type** used in the `try` block, you can use the "three dots" syntax (`...`) inside the `catch` block, which will handle any type of exception:

### Example

```cpp
try {  
  int age = 15;  
  if (age >= 18) {  
    cout << "Access granted - you are old enough.";  
  } else {  
    throw 505;  
  }  
}  
catch (...) {  
  cout << "Access denied - You must be at least 18 years old.\n";  
}
```

- - -


[❮ Previous](https://w3schools.com/cpp/cpp_debugging.asp) [Next ❯](https://w3schools.com/cpp/cpp_input_validation.asp)
