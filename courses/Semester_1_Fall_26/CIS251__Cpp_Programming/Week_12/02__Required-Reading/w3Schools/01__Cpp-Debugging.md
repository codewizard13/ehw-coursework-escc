# C++ Debugging

## Debugging

Debugging is the process of finding and fixing errors (bugs) in your program.

**Bugs** are mistakes that make your program crash, behave incorrectly, or give the wrong output.

Before you start debugging, make sure your code is clean and organized:

*   Use proper indentation to keep the structure clear.
*   Give your variables **clear, meaningful names** that describe what they store.

Clean code is easier to read - and easier to debug!

In the sections below, we'll introduce several common debugging techniques.

- - -

### 1. Print Debugging

Use `cout` to print values at different points in your code to see what's going wrong:

```cpp
int x = 10;  
int y = 0;  
cout << "Before division\n"; // Debug output  
int z = x / y; // Crashes!  
cout << "After division\n"; // Never runs
```

If you don't see "After division", the program crashed at `x / y`.

- - -

### 2. Check Variable Values

Print variables to see if they are what you expect:

```cpp
int x = 10;  
int y = 5;  
int result = x - y;  
cout << "Result: " << result << "\n"; // Result: 5
```

Expected 15? That means the logic is wrong: try using `x + y` instead.

- - -

### 3. Use a Debugger Tool

IDEs like Visual Studio, Code::Blocks, and VS Code have **debuggers** that let you:

*   Pause your program (breakpoints)
*   Step through code line by line
*   Watch variables and find unexpected values

**Tip:** Start with "1. Print Debugging". Use IDE tools as you get more comfortable.

- - -

### 4. Learn from Error Messages

The C++ compiler and runtime errors often tell you **what went wrong** and **where**. For example:

`error: expected ';' before 'return'`

**Easy solution:** Fix the missing semicolon!

- - -

## Exception Handling

**While debugging** is about finding and fixing errors in your code, **exception handling** is a way to deal with errors while the program is running - and run specific code when something goes wrong.

Learn about [Exception Handling](https://w3schools.com/cpp/cpp_exceptions.asp) in the next chapter.

---