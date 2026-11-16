# C++ Algorithm

[❮ Previous](https://w3schools.com/cpp/cpp_iterators.asp) [Next ❯](https://w3schools.com/cpp/cpp_namespaces.asp)

## C++ Algorithms

In the previous chapters, you learned that data structures (like [vectors](https://w3schools.com/cpp/cpp_vectors.asp), [lists](https://w3schools.com/cpp/cpp_list.asp), etc) are used to store and organize data.

**Algorithms** are used to solve problems by sorting, searching, and manipulating data structures.

The `<algorithm>` library provides many useful functions to perform these tasks with [iterators](https://w3schools.com/cpp/cpp_iterators.asp).

To use these functions, you must include the `<algorithm>` header file:

// Include the algorithm library  
#include <algorithm>  

- - -

## Sorting Algorithms

To sort elements in a data structure, you can use the `sort()` function.

The `sort()` function takes [iterators](https://w3schools.com/cpp/cpp_iterators.asp) (typically a _start iterator_ returned by `begin()` and an _end iterator_ returned by `end()`) as parameters:

### Example

// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Sort cars alphabetically  
sort(cars.begin(), cars.end());  
```

By default, the elements are sorted in ascending order. In the example above, the elements are sorted alphabetically since they are strings.

If we had a vector of integers, they would be sorted numerically:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort numbers numerically  
sort(numbers.begin(), numbers.end());  
```

To reverse the order, you can use `rbegin()` and `rend()` instead of `begin()` and `end()`:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort numbers numerically in reverse order  
sort(numbers**.rbegin()**, numbers**.rend()**);  
```

To only sort specific elements, you could write:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort numbers numerically, starting from the fourth element (only sort 5, 9, and 2)  
sort(numbers.**begin() \+ 3**, numbers.end());  
```

## Searching Algorithms

To search for specific elements in a vector, you can use the `find()` function.

It takes three parameters: `_start_iterator_, _end_iterator_, _value_`, where _value_ is the value to search for:

### Example

Seach for the number **3** in "numbers":

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Search for the number 3  
auto it = find(numbers.begin(), numbers.end(), 3);  
```

To search for the first element that is **greater than** a specific value, you can use the `upper_bound()` function:

### Example

Find the first value greater than **5** in "numbers":

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort the vector in ascending order  
sort(numbers.begin(), numbers.end());  
  
// Find the first value that is greater than 5 in the sorted vector  
auto it = upper\_bound(numbers.begin(), numbers.end(), 5);  
```

The `upper_bound()` function is typically used on sorted data structures. That's why we first sort the vector in the example above.

To find the smallest element in a vector, use the `min_element()` function:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Find the smallest number  
auto it = min\_element(numbers.begin(), numbers.end());
```

To find the largest element, use the `max_element()` function:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Find the largest number  
auto it = max\_element(numbers.begin(), numbers.end());
```

- - -

## Modifying Algorithms

To copy elements from one vector to another, you can use the `copy()` function:

### Example

Copy elements from one vector to another:

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Create a vector called copiedNumbers that should store 6 integers  
vector<int\> copiedNumbers(6);  
  
// Copy elements from numbers to copiedNumbers  
copy(numbers.begin(), numbers.end(), copiedNumbers.begin());  
```

To fill all elements in a vector with a value, you can use the `fill()` function:

### Example

Fill all elements in the numbers vector with the value 35:

// Create a vector called numbers that will store 6 integers  
vector<int\> numbers(6);  
  
// Fill all elements in the numbers vector with the value 35  
fill(numbers.begin(), numbers.end(), 35);  
```

## Complete Algorithm Reference

For a complete reference of algorithm functions, go to our [C++ Algorithm Reference](https://w3schools.com/cpp/cpp_ref_algorithm.asp).

- - -

[❮ Previous](https://w3schools.com/cpp/cpp_iterators.asp) [Next ❯](https://w3schools.com/cpp/cpp_namespaces.asp)
