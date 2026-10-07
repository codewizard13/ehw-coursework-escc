/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 7 PROGRAMMING ASSIGNMENT — Pointers, References, Memory, and C++ Essentials 1 Synthesis

    Student: Eric Hepperle
    Created: 2026-10-06

    VERSION: 1.0

    STATUS: Fully Working, but incomplete assignemnt!
      - NEXT: add small functions to modify values by reference (like in
        the tic-tac-toe program), inspect values through pointers, and
        include comments explaining &, *, and nullptr

    Instructions:
      Reference and Pointer Practice: write small, clearly labeled functions
      that modify values by reference, inspect values through pointers, and 
      demonstrate one safe new/delete pair. Include comments
      explaining &, *, nullptr, and why delete is required.

    Notes:
    - This is a complete program although it doesn't satisfy the assignment
      requirements yet.
    - Basic grocery list maker that gets number of foods to enter from user,
      stores the foods dynamically, prints out the grocery list, and
      deletes the dynamic array at the end.

    Lessons Learned:
    - #GOTCHA: Ensure you 'delete' 'new' variables otherwise you can have memory leaks
    - delete: keyword to free the memory
    - #GOTCHA: You cannot easily do a sanity check on whether a dynamically allocated
        array has loaded all the values without monitoring a separate counter variable
        and checking exit status.
    - #GOTCHA: - `pFoods` is a pointer (`string*`), so it has no `.size()`
        function. It holds the address of the first string, not the array’s count.
        Track successful entries separately
    - `pFoods[i].size()` counts characters in one food name, not the foods array.

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */


 /*
 ALGORITHM:

 0. Initialize a dynamic array foods
 1. Ask user how many foods they want to record
 2. Get input 'desired_quantiy' from user
 3. Add 'desired_quantity' foods to the array
 4. Loop over the array and print all the foods (grocery list)
 5. Delete dynamic array foods
 
 */


#include <iostream>
using namespace std;

int main () {

    string *pFoods = nullptr;
  int size;

  cout << "How many foods to enter in?: ";
  if (!(cin >> size)) {
    cout << "Invalid input: size must be an integer (1-10)\n";
    return 1;
  }

  pFoods = new string[size];

  // receive the requested quantity of foods
  for (int i=0; i < size; i++) {
    cout << "Enter the next grocery item # " << i + 1 << ": ";
    
    // Validate the current food item
    if (!getline(cin >> ws, pFoods[i])) {
      cout << "Input failed.\n";
      break;
    }
    
  }

  // Print out the stored foods
  cout << "******* GROCERY LIST ********\n";

  for (int i=0; i < size; i++) {
    cout << "Item # " << i+1 << ": " << pFoods[i] << '\n';
  }

  // Delete array to prevent memory leak
  delete[] pFoods;

  return 0;
}