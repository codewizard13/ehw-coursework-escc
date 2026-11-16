# C++ Iterator

[❮ Previous](https://w3schools.com/cpp/cpp_unordered_set.asp) [Next ❯](https://w3schools.com/cpp/cpp_algorithms.asp)

## C++ Iterators

Iterators are used to access and iterate through elements of data structures ([vectors](https://w3schools.com/cpp/cpp_vectors.asp), [sets](https://w3schools.com/cpp/cpp_sets.asp), etc.), by "[pointing](https://w3schools.com/cpp/cpp_pointers.asp)" to them.

It is called an "iterator" because "iterating" is the technical term for **looping**.

To iterate through a vector, look at the following example:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Create a vector iterator called it  
vector<string>::iterator it;  
  
// Loop through the vector with the iterator  
for (it = cars.begin(); it != cars.end(); ++it) {  
  cout << \*it << "\\n";  
}  
```

#### Example explained

1.  First we create a vector of strings to store the names of different car manufactures.
2.  Then we create a "vector iterator" called `it`, that we will use to loop through the vector.
3.  Next, we use a `for` loop to loop through the vector with the iterator. The iterator (`it`) points to the first element in the vector (`cars.begin()`) and the loop continues as long as `it` is not equal to `cars.end()`.
4.  The increment operator (`++it`) moves the iterator to the next element in the vector.
5.  The dereference operator (`*it`) accesses the element the iterator points to.

**Note:** The type of the iterator must match the type of the data structure it should iterate through (`string` in our example)

- - -

## What is `begin()` and `end()`?

`begin()` and `end()` are **functions** that **belong to data structures**, such as [vectors](https://w3schools.com/cpp/cpp_vectors.asp) and [lists](https://w3schools.com/cpp/cpp_list.asp). They **do not belong to the iterator** itself. Instead, they are used with iterators to access and iterate through the elements of these data structures.

*   `begin()` returns an iterator that points to the first element of the data structure.
*   `end()` returns an iterator that points to one position after the last element.

To understand how they work, let's continue to use vectors as an example:

```cpp
vector<string> cars \= {"Volvo", "BMW", "Ford", "Mazda"};  
  
vector<string>::iterator it;  
```

### Begin Examples

`begin()` points to the first element in the vector (index 0, which is "Volvo"):

### Example

```cpp
// Point to the first element in the vector  
it = cars.begin();  
```

To point to the second element (BMW), you can write `cars.begin() + 1`:

### Example

```cpp
// Point to the second element  
it = cars.begin() + 1;  
```

And of course, that also means you can point to the third element with `cars.begin() + 2`:

### Example

```cpp
// Point to the third element  
it = cars.begin() + 2;  
```

### End Example

`end()` points to one position **after** the last element in the vector (meaning it doesn't point to an actual element, but rather indicates that this is the end of the vector).

So, to use `end()` to point to the last element in the cars vector (Mazda), you can use `cars.end() - 1`:

### Example

```cpp
// Point to the last element  
it = cars.end() - 1;  
```

**Why do we say "point"?**

Iterators are like "[pointers](https://w3schools.com/cpp/cpp_pointers.asp)" in that they "point" to elements in a data structure rather than returning values from them. They refer to a specific position, providing a way to access and modify the value when needed, without making a copy of it. For example:

### Example

```cpp
// Point to the first element in the vector  
it = cars.begin();  
  
// Modify the value of the first element  
\*it = "Tesla";  
  
// Volvo is now Tesla  
```

- - -

## The `auto` Keyword

In C++ 11 and later versions, you can use the [`auto`](https://w3schools.com/cpp/cpp_auto.asp "Read More About The auto Keyword") keyword instead of explicitly declaring and specifying the type of the iterator.

The `auto` keyword allows the compiler to automatically determine the correct data type, which simplifies the code and makes it more readable:

Instead of this:

```cpp
vector<string>::iterator it = cars.begin();  
```

You can simply write this:

```cpp
auto it = cars.begin();  
```

In the example above, the compiler knows the type of `it` based on the return type of `cars.begin()`, which is `vector<string>::iterator`.

The `auto` keyword works in `for` loops as well:

```cpp
for (auto it = cars.begin(); it != cars.end(); ++it) {  
  cout << \*it << "\\n";  
}  
```


## For-Each Loop vs. Iterators

You can use a **for-each** loop to just loop through elements of a data structure, like this:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Print vector elements  
for (string car : cars) {  
  cout << car << "\\n";  
}  
```

When you are just reading the elements, and don't need to modify them, the for-each loop is much simpler and cleaner than iterators.

However, when you need to add, modify, or remove elements **during iteration**, iterate in reverse, or skip elements, you should use iterators:

### Example

```cpp
// Create a vector called cars that will store strings  
vector<string> cars \= {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Loop through vector elements  
for (auto it = cars.begin(); it != cars.end(); ) {  
  if (\*it == "BMW") {  
    it = cars.erase(it); // Remove the BMW element  
  } else {  
    ++it;  
  }  
}  
  
// Print vector elements  
for (const string& car : cars) {  
  cout << car << "\\n";  
}  
```

## Iterate in Reverse

To iterate in reverse order, you can use `rbegin()` and `rend()` instead of `begin()` and `end()`:

### Example

```cpp
// Iterate in reverse order  
for (auto it = cars.rbegin(); it != cars.rend(); ++it) {  
  cout << \*it << "\\n";  
}  
```

- - -

## Iterate Through other Data Structures

Iterators are great for code reusability since you can use the same syntax for iterating through vectors, lists, deques, sets and maps:

### List Example

```cpp
// Create a list called cars that will store strings  
list<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Loop through the list with an iterator  
for (auto it = cars.begin(); it != cars.end(); ++it) {  
  cout << \*it << "\\n";  
}  
```

### Deque Example

```cpp
// Create a deque called cars that will store strings  
deque<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Loop through the deque with an iterator  
for (auto it = cars.begin(); it != cars.end(); ++it) {  
  cout << \*it << "\\n";  
}  
```

### Set Example

```cpp
// Create a set called cars that will store strings  
set<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Loop through the set with an iterator  
for (auto it = cars.begin(); it != cars.end(); ++it) {  
  cout << \*it << "\\n";  
}  
```

### Map Example

```cpp
// Create a map that will store strings and integers  
map<string, int\> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };  
  
// Loop through the map with an iterator  
for (auto it = people.begin(); it != people.end(); ++it) {  
  cout << it->first << " is: " << it->second << "\\n";  
}  
```

#### Iterator Support

The examples above shows how to iterate through different data structures that support iterators ([vector](https://w3schools.com/cpp/cpp_vectors.asp), [list](https://w3schools.com/cpp/cpp_list.asp), [deque](https://w3schools.com/cpp/cpp_deque.asp), [map](https://w3schools.com/cpp/cpp_maps.asp) and [set](https://w3schools.com/cpp/cpp_sets.asp) support iterators, while **[stacks](https://w3schools.com/cpp/cpp_stacks.asp) and [queues](https://w3schools.com/cpp/cpp_queues.asp) do not**).

- - -

## Algorithms

Another important feature of iterators is that they are used with different algorithm functions, such as `sort()` and `find()` (found in the `<algorithm>` library), to sort and search for elements in a data structure.

For example, the `sort()` function takes iterators (typically returned by `begin()` and `end()`) as parameters to sort elements in a data structure from the beginning to the end.

In this example, the elements are sorted alphabetically since they are strings:

### Example

```cpp
#include <iostream>  
#include <vector>  
**#include <algorithm>**  // Include the <algorithm> library  
using namespace std;  
  
int main() {  
  // Create a vector called cars that will store strings  
  vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
  // Sort cars in alphabetical order  
  **sort(cars.begin(), cars.end());**  
  
  // Print cars in alphabetical order  
  for (string car : cars) {  
    cout << car << "\\n";  
  }  
  
  return 0;  
}  
```

And in this example, the elements are sorted numerically since they are integers:

### Example

```cpp
#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
int main() {  
  // Create a vector called numbers that will store integers  
  vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
  // Sort numbers numerically  
  sort(numbers.begin(), numbers.end());  
  
  for (int num : numbers) {  
    cout << num << "\\n";  
  }  
  
  return 0;  
}  
```

To reverse the order, you can use `rbegin()` and `rend()` instead of `begin()` and `end()`:

### Example

```cpp
#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
int main() {  
  // Create a vector called numbers that will store integers  
  vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
  // Sort numbers numerically in reverse order  
  sort(numbers**.rbegin()**, numbers**.rend()**);  
  
  for (int num : numbers) {  
    cout << num << "\\n";  
  }  
  
  return 0;  
}  
```

[❮ Previous](https://w3schools.com/cpp/cpp_unordered_set.asp) [Next ❯](https://w3schools.com/cpp/cpp_algorithms.asp)
