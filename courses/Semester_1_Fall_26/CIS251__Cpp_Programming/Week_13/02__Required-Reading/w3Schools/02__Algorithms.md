# 

C++ Algorithm

[❮ Previous](cpp_iterators.asp) [Next ❯](cpp_namespaces.asp)

- - -

Share Link Copied

/\* One delegated listener for every bar on the page, bound once even if the include is pulled in twice. The markup above is static, so the bar is part of the cached HTML and needs no script to appear - this only wires the clicks. \*/ (function(){ if(window.wsShareBar)return; window.wsShareBar=1; function pageUrl(){return location.href.split('#')\[0\];} document.addEventListener('click',function(e){ var btn=e.target&&e.target.closest?e.target.closest('.ws-share-btn'):null; if(!btn)return; var net=btn.getAttribute('data-ws-net'); if(net==='copy'){ if(!navigator.clipboard)return; var toast=btn.querySelector('.ws-copied-toast'); navigator.clipboard.writeText(pageUrl()).then(function(){ btn.classList.add('copied'); if(toast)toast.classList.add('show'); clearTimeout(btn.\_wsT); btn.\_wsT=setTimeout(function(){ btn.classList.remove('copied'); if(toast)toast.classList.remove('show'); },1600); }); return; } var url=encodeURIComponent(pageUrl()),s=''; if(net==='x'){ var title=document.title.replace(/\\s\*\[-|\]\\s\*W3Schools.\*$/i,'').trim(); s='https://twitter.com/intent/tweet?url='+url+'&text='+encodeURIComponent(title+' - W3Schools'); } else if(net==='facebook')s='https://www.facebook.com/sharer/sharer.php?u='+url; else if(net==='linkedin')s='https://www.linkedin.com/sharing/share-offsite/?url='+url; if(s)window.open(s,'\_blank','noopener,width=600,height=540'); }); })();

## C++ Algorithms

In the previous chapters, you learned that data structures (like [vectors](cpp_vectors.asp), [lists](cpp_list.asp), etc) are used to store and organize data.

**Algorithms** are used to solve problems by sorting, searching, and manipulating data structures.

The `<algorithm>` library provides many useful functions to perform these tasks with [iterators](cpp_iterators.asp).

To use these functions, you must include the `<algorithm>` header file:

// Include the algorithm library  
#include <algorithm>  

- - -

## Sorting Algorithms

To sort elements in a data structure, you can use the `sort()` function.

The `sort()` function takes [iterators](cpp_iterators.asp) (typically a _start iterator_ returned by `begin()` and an _end iterator_ returned by `end()`) as parameters:

### Example

// Create a vector called cars that will store strings  
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};  
  
// Sort cars alphabetically  
sort(cars.begin(), cars.end());  

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_sort)

By default, the elements are sorted in ascending order. In the example above, the elements are sorted alphabetically since they are strings.

If we had a vector of integers, they would be sorted numerically:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort numbers numerically  
sort(numbers.begin(), numbers.end());  

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_sort2)

To reverse the order, you can use `rbegin()` and `rend()` instead of `begin()` and `end()`:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort numbers numerically in reverse order  
sort(numbers**.rbegin()**, numbers**.rend()**);  

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_sort3)

To only sort specific elements, you could write:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort numbers numerically, starting from the fourth element (only sort 5, 9, and 2)  
sort(numbers.**begin() \+ 3**, numbers.end());  

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_sort4)

- - -

Ad

[REMOVE ADS](https://order.w3schools.com/plans)

- - -

## Searching Algorithms

To search for specific elements in a vector, you can use the `find()` function.

It takes three parameters: `_start_iterator_, _end_iterator_, _value_`, where _value_ is the value to search for:

### Example

Seach for the number **3** in "numbers":

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Search for the number 3  
auto it = find(numbers.begin(), numbers.end(), 3);  

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_find)

To search for the first element that is **greater than** a specific value, you can use the `upper_bound()` function:

### Example

Find the first value greater than **5** in "numbers":

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Sort the vector in ascending order  
sort(numbers.begin(), numbers.end());  
  
// Find the first value that is greater than 5 in the sorted vector  
auto it = upper\_bound(numbers.begin(), numbers.end(), 5);  

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_upper_bound)

The `upper_bound()` function is typically used on sorted data structures. That's why we first sort the vector in the example above.

To find the smallest element in a vector, use the `min_element()` function:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Find the smallest number  
auto it = min\_element(numbers.begin(), numbers.end());

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_min)

To find the largest element, use the `max_element()` function:

### Example

// Create a vector called numbers that will store integers  
vector<int\> numbers = {1, 7, 3, 5, 9, 2};  
  
// Find the largest number  
auto it = max\_element(numbers.begin(), numbers.end());

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_max)

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

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_copy)

To fill all elements in a vector with a value, you can use the `fill()` function:

### Example

Fill all elements in the numbers vector with the value 35:

// Create a vector called numbers that will store 6 integers  
vector<int\> numbers(6);  
  
// Fill all elements in the numbers vector with the value 35  
fill(numbers.begin(), numbers.end(), 35);  

[Try it Yourself »](trycpp.asp?filename=demo_algorithms_fill)

- - -

## Exercise?**What is this?**  
Test your skills by answering a few questions about the topics of this page

What does the sort() function do?

  

Sorts elements in ascending order by default

Sorts elements in descending order by default

Searches for a specific element

Reverses the order of elements

  
Submit Answer »

[REMOVE ADS](https://order.w3schools.com/plans)

- - -

## Complete Algorithm Reference

For a complete reference of algorithm functions, go to our [C++ Algorithm Reference](cpp_ref_algorithm.asp).

- - -

  

[❮ Previous](cpp_iterators.asp) [Next ❯](cpp_namespaces.asp)

[★ +1](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_algorithms.asp "Your W3Schools Profile")

[Sign in to track progress](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fpathfinder.w3schools.com&origin=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_algorithms.asp "Sign in to track your progress")
