/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=cbZhz4jcLVPb0Vga&t=15793

    **** NULL POINTERS ****

    Student: Eric Hepperle
    Created: 2026-10-06

    VERSION: 1.0

    STATUS: WIP

    Purpose:
    - Demonstrates basic nullptr assignment and dereferencing no-nos

    📝 Lessons Learned:
    - null value: a special value that means something has no value
    - null pointer: when a pointer is holding a null value, that pointer is not pointing at anything
    - nullptr: keyword representing a "null pointer" literal
    - nullptrs are helpful when determining if an address was successfully assigned to a pointer
    - #GOTCHA: If we create a pointer but dont assign it a value, we don't know where it is pointing to!
    - #GOTCHA ☠️: DEREFERENCING A NULL POINTER IS BAD! It can lead to 'UNDEFINED' behavior
    - #GOTCHA ☠️: DEREFERENCING an uninitialized value can also lead to undefined behavior

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

  // Unsafe/Undefined:
  //  - dereferencing a null pointer can lead to undefined behavior
  //
  // int *pointer = nullptr;
  // int x = 123;
  // *pointer; 

  // Unsafe/Undefined:
  //  - dereferencing a pointer not assigned a value (uninitialized)
  //
  // int *pointer;
  // int x = 123;
  // *pointer; 

  return 0;
}
