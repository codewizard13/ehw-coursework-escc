/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 7 PROGRAMMING ASSIGNMENT — Pointers, References, Memory, and C++ Essentials 1 Synthesis

    Student: Eric Hepperle
    Created: 2026-10-06
    Updated: 2026-10-07

    VERSION: 1.01

    STATUS: WIP

    Instructions:
      Reference and Pointer Practice: write small, clearly labeled functions
      that modify values by reference, inspect values through pointers, and
      demonstrate one safe new/delete pair. Include comments
      explaining &, *, nullptr, and why delete is required.

    Notes:
    -

    Lessons Learned:
    -

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

/*
ALGORITHM:

1. Ask how many grocery items the user wants to enter.
2. Reject failed integer input or a count outside 1–10.
3. Allocate a string array of the requested size.

// COLLECT GROCERY ITEMS

4. Start the successful-entry counter at zero.
5. For each requested item:
  Read the food name.
  If input fails, stop collecting.
  Otherwise, update the counter through a reference function.

// PRINT OUT FORMATTED GROCERY LIST

6. Print the stored entries through a pointer function.
7. Release the array with delete[] and clear its pointer.
8. Report incomplete input if fewer items were stored than requested.

*/

#include <iostream>
using namespace std;

bool getGroceryItems(string *pFoods, int size);
void printGroceryItems(string *foods, int size);

int main()
{

  string *pFoods = nullptr;
  int size;

  cout << "*****************************\n";
  cout << "*    Grocery List Program   *\n";
  cout << "*****************************\n\n";

  cout << "How many foods to enter in?: ";
  if (!(cin >> size))
  {
    cout << "Invalid input: size must be an integer (1-10)\n";
    return 1;
  }

  pFoods = new string[size];

  if (!getGroceryItems(pFoods, size))
  {
    cout << "Sorry, failed to record any grocery items.\n";
  }
  else
  {
    printGroceryItems(pFoods, size);
  }

  // Delete array to prevent memory leak
  // new[] requires matching delete[] to release the array.
  // Without this, the allocated memory is not explicitly released.
  delete[] pFoods;

  // Clear the now-invalid address. This does not free memory;
  // delete[] above already did that.
  pFoods = nullptr;

  return 0;
}

bool getGroceryItems(string *pFoods, int size)
{

  // nullptr means the pointer points to no object.
  // Check before attempting to access any foods.
  if (pFoods == nullptr)
  {
    cout << "Sorry, no grocery list is available.\n";
    return false;
  }

  // receive the requested quantity of foods
  for (int i = 0; i < size; i++)
  {
    cout << "Enter the next grocery item # " << i + 1 << ": ";

    // Validate the current food item
    if (!getline(cin >> ws, pFoods[i]))
    {
      cout << "Input failed.\n";
      // break;
      return false;
    }
  }

  return true;
}

void printGroceryItems(string *pFoods, int size)
{
  // Print out the stored foods
  cout << "\n******* GROCERY LIST ********\n";

  for (int i = 0; i < size; i++)
  {
    cout << "Item # " << i + 1 << ": " << pFoods[i] << '\n';
  }

  cout << "*****************************\n";
}
