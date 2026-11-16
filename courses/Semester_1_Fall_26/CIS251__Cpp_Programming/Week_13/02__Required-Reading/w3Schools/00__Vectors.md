# C++ Vectors

[❮ Previous](https://w3schools.com/cpp/cpp_data_structures.asp) [Next ❯](https://w3schools.com/cpp/cpp_list.asp)



## C++ Vector

A vector in C++ is like a resizable [array](https://w3schools.com/cpp/cpp_arrays.asp).

Both vectors and arrays are data structures used to store multiple elements of the same data **type**.

The difference between an array and a vector, is that the size of an array cannot be modified (you cannot add or remove elements from an array). A vector however, can grow or shrink in size as needed.

To use a vector, you have to include the `<vector>` header file:

```cpp
// Include the vector library  
#include <vector>  
```

## Create a Vector

To create a vector, use the `vector` keyword, and specify the **type** of values it should store within angle brackets `<>` and then the name of the vector, like: `vector<_type_> _vectorName_`.

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars;  
```

If you want to add elements at the time of declaration, place them in a comma-separated list, inside curly braces `{}`, just like with arrays:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Print vector elements  
for (string car : cars) {  
  cout << car << "\\n";  
}  
```

**Note:** The type of the vector (`string` in our example) cannot be changed after its been declared.

- - -

## Access a Vector

You can access a vector element by referring to the index number inside square brackets `[]`.

Vectors, like arrays, are 0-indexed, meaning that `[0]` is the first element, `[1]` is the second element, and so on:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Get the first element  
cout << cars\[0\];  // Outputs Volvo  
  
// Get the second element  
cout << cars\[1\];  // Outputs BMW  
```

One advantage of using the vector library, is that it includes many useful functions. For example, you can access the first or the last element of a vector with the `.front()` and `.back()` functions:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Get the first element  
cout << cars.front();  
  
// Get the last element  
cout << cars.back();  
```

To access an element at a specified index, you can use the `.at()` function and specify the index number:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Get the second element  
cout << cars.at(1);  
  
// Get the third element  
cout << cars.at(2);  
```

> **📌 #TIP:** The `.at()` function is often preferred over square brackets `[]` because it lets you know if an error occurs.

For example if the element is out of range:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars \= {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Try to access an element that does not exist (throws an error message)  
cout << cars.at(6);  
```

## Change a Vector Element

To change the value of a specific element, you can refer to the index number:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Change the value of the first element  
cars\[0\] = "Opel";  
  
cout << cars\[0\];  // Now outputs Opel instead of Volvo  
```

However, it is safer to use the `.at()` function:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Change the value of the first element  
cars.at(0) = "Opel";  
  
cout << cars.at(0);  // Now outputs Opel instead of Volvo  
```

## Add Vector Elements

The biggest difference between a vector and an array is that ***vectors can grow dynamically***. That means you can add or remove elements from the vector.

To add an element to the vector, you can use the `.push_back()` function, which will add an element at the end of the vector:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
cars.push\_back("Tesla");  
```

You can add as many elements as you want:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
cars.push\_back("Tesla");  
cars.push\_back("VW");  
cars.push\_back("Mitsubishi");  
cars.push\_back("Mini");  
```

- - -

## Remove Vector Elements

To remove an element from the vector, you can use the `.pop_back()` function, which removes an element from the end of the vector:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
cars.pop\_back();  
```

> **📌 #TIP:** Elements are usually only added and removed from the end of the vector. If you need to add or remove elements from both ends, it is often better to use a [deque](https://w3schools.com/cpp/cpp_deque.asp) instead of a vector.

- - -

## Vector Size

To find out how many elements a vector has, use the `.size()` function:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
cout << cars.size();  // Outputs 4  
```

- - -

## Check if a Vector is Empty

There is also a function to find out whether a vector is empty or not.

The `.empty()` function returns `1` (_true_) if the vector is empty and `0` (_false_) if it contains one or more elements:

### Example

```cpp
vector<string> cars;  
cout << cars.empty();  // Outputs 1 (The vector is empty)  
```

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
cout << cars.empty();  // Outputs 0 (not empty)  
```

- - -

## Loop Through a Vector

You can loop through the vector elements by using a `for` loop combined with the `.size()` function:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
for (int i = 0; i < cars.size(); i++) {  
  cout << cars\[i\] << "\\n";  
}  
```

You can also use a **for-each loop** (introduced in C++ version 11 (2011), which is cleaner and more readable:

### Example

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
for (string car : cars) {  
  cout << car << "\\n";  
}  
```

**Tip:** It is also possible to loop through vectors with an [iterator](https://w3schools.com/cpp/cpp_iterators.asp), which you will learn more about in a later chapter.

- - -

## Complete Vector Reference

For a complete reference of Vector functions, go to our [C++ Vector Reference](https://w3schools.com/cpp/cpp_ref_vector.asp).

- - -

  

[❮ Previous](https://w3schools.com/cpp/cpp_data_structures.asp) [Next ❯](https://w3schools.com/cpp/cpp_list.asp)
