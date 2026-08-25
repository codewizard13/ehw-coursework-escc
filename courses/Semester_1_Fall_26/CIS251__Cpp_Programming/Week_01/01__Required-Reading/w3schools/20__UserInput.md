# C++ User Input

You have already learned that `cout` is used to output (print) values. Now we will use `cin` to get user input.

`cin` is a predefined variable that reads data from the keyboard with the extraction operator (`>>`).

In the following example, the user can input a number, which is stored in the variable `x`. Then we print the value of `x`:

### Example

```cpp
int x;   
cout << "Type a number: "; // Type a number and press enter  
cin >> x; // Get user input from the keyboard  
cout << "Your number is: " << x; // Display the input value
```

#### Good To Know

`cout` is pronounced "see-out". Used for **output**, and uses the insertion operator (`<<`)

`cin` is pronounced "see-in". Used for **input**, and uses the extraction operator (`>>`)

- - -

## Creating a Simple Calculator

In this example, the user must input two numbers. Then we print the sum by calculating (adding) the two numbers:

### Example

```cpp
int x, y;  
int sum;  
cout << "Type a number: ";  
cin >> x;  
cout << "Type another number: ";  
cin >> y;  
sum = x + y;  
cout << "Sum is: " << sum;
```

There you go! You just built a basic calculator!

- - -


## Complete <iostream> Reference

**Tip:** Both `cin` and `cout` belongs to the `<iostream>` library, which is short for _standard_ **_i_**_nput /_ **_o_**_utput_ _**stream**s_. For a complete reference of <iostream> objects along with detailed information, go to our [C++ iostream Reference](cpp_ref_iostream.asp).

  