/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=ZVUAh3N2xDkpXaDz&t=15876

    **** NULL POINTERS ****

    Student: Eric Hepperle
    Created: 2026-10-06

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates how to safely dereference a nullptr

    📝 Lessons Learned:
    - Some programmers check to see if pointer is a nullptr before dereferencing it
    - this could come into play with dynamic memory
    - #GOTCHA: if we don't assign an address, the pointer will still be a null pointer
    - #GOTCHA ☠️: IT IS NEVER SAFE TO DEREFERENCE A NULL POINTER!
    - When using pointers, be careful that your code isn't dereferencing
      nullptr or pointing to free memory - this will cause underfined behavior

    Sample Output:

    address was assigned!
    123

    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

  // Correct:
  int *pointer = nullptr;
  int x = 123;

  pointer = &x;

  // Use conditional to safely deref pointer
  if (pointer == nullptr) {
    cout << "address wass not assigned!\n";
  } else {
    cout << "address was assigned!\n";
    cout << *pointer;
  }

  return 0;
}
