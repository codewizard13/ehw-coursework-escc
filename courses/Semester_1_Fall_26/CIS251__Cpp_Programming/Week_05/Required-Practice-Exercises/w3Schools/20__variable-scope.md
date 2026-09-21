# C++ Variable Scope


Now that you understand how functions work, it is important to learn how variables act inside and outside of functions.

In C++, variables are only accessible inside the region they are created. This is called **scope**.

## Local Scope

A variable created inside a function belongs to the _local scope_ of that function, and can only be used inside that function:

### Example

```cpp
void myFunction() {  
  // Local variable that belongs to myFunction  
  int x = 5;  
  
  // Print the variable x  
  cout << x;  
}  
  
int main() {  
  myFunction();  
  return 0;  
}  
```

A **local variable** cannot be used outside the function it belongs to.

If you try to access it outside the function, an error occurs:

### Example

```cpp
void myFunction() {  
  // Local variable that belongs to myFunction  
  int x = 5;  
}  
  
int main() {  
  myFunction();  
  
  // Print the variable x in the main function  
  cout << x;  
  return 0;  
}  
```

- - -

## Global Scope

A variable created outside of a function, is called a **global variable** and belongs to the _global scope_.

Global variables are available from within any scope, global and local:

### Example

A variable created outside of a function is global and can therefore be used by anyone:

```cpp
// Global variable x  
int x = 5;  
  
void myFunction() {  
  // We can use x here  
  cout << x << "\\n";  
}  
  
int main() {  
  myFunction();  
  
  // We can also use x here  
  cout << x;  
  return 0;  
}  
```

### Naming Variables

If you operate with the same variable name inside and outside of a function, C++ will treat them as two separate variables; One available in the global scope (outside the function) and one available in the local scope (inside the function):

### Example

The function will print the local `x`, and then the code will print the global `x`:

```cpp
// Global variable x  
int x = 5;  
  
void myFunction() {  
  // Local variable with the same name as the global variable (x)  
  int x \= 22;  
  cout << x << "\\n"; // Refers to the local variable x  
}  
  
int main() {  
  myFunction();  
  
  cout << x; // Refers to the global variable x  
  return 0;  
}  
```

However, you should avoid using the same variable name for both globally and locally variables as it can lead to errors and confusion.

In general, you should be careful with global variables, since they can be accessed and modified from any function:

### Example

Change the value of `x` from `myFunction`:

```cpp
// Global variable x  
int x = 5;  
  
void myFunction() {  
  cout << ++x << "\\n"; // Increment the value of x by 1 and print it  
}  
  
int main() {  
  myFunction();  
  
  cout << x; // Print the global variable x  
  return 0;  
}  
  
// The value of x is now 6 (no longer 5)  
```


## Conclusion

To sum up, use local variables (with good variable names) as much as you can. This will make your code easier to maintain and better to understand. However, you may find global variables when working on existing C++ programs or while collaborating with others. Therefore, it is good to understand how the scope works and how to use it effectively to make sure your code is clear and functional.
