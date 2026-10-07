/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    WEEK 7 PROGRAMMING ASSIGNMENT — Pointers, References, Memory, and C++ Essentials 1 Synthesis

    Student: Eric Hepperle
    Created: 2026-10-06
    Updated: 2026-10-07

    VERSION: 1.02

    STATUS: WIP

    Instructions:
      Reference and Pointer Practice: write small, clearly labeled functions
      that modify values by reference, inspect values through pointers, and
      demonstrate one safe new/delete pair. Include comments
      explaining &, *, nullptr, and why delete is required.

    Notes:
    - Replaces `size` in the printGroceryItems() function with `itemsAddedCount`

    Lessons Learned:
    -

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

/*
ALGORITHM:

1. Initialize the food pointer to nullptr and the entry counter to zero.
2. Ask how many grocery items the user wants to enter.
   Stop on failed integer input.
   Retry integer counts outside 1-10.
3. Allocate a string array of the requested size.
4. For each requested item:
   Read the food name.
   Stop collecting if input fails.
   Otherwise, update the entry counter through a reference parameter.
5. If collection failed, report how many items were stored.
6. Print successfully stored entries through a pointer function.
7. Release the array with delete[] and set its pointer to nullptr.
8. End the program.

*/

#include <iostream>
using namespace std;

bool getDesiredFoodsCount(int &size);
bool getGroceryItems(string *pFoods, int size, int &itemsAddedCount);
void printGroceryItems(string *foods, int size);

int main()
{

  string *pFoods = nullptr;
  int size;                // number of elements allocated
  int itemsAddedCount = 0; // actual number of elements added

  cout << "*****************************\n";
  cout << "*    Grocery List Program   *\n";
  cout << "*****************************\n\n";

  if (!getDesiredFoodsCount(size))
  {
    cout << "Unable to get desired grocery count from user.\n";
    cout << "*****************************\n";
    return 1;
  }

  // new[] creates an array and returns its starting address.
  pFoods = new string[size];

  if (!getGroceryItems(pFoods, size, itemsAddedCount))
  {
    cout << "Input stopped. Recorded " << itemsAddedCount
         << " of " << size << " items.\n";
    if (itemsAddedCount > 0)
    {
      printGroceryItems(pFoods, itemsAddedCount);
    }
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

  cout << "*****************************\n";

  return 0;
}

// & declares a reference to main's size variable.
// Changing size here changes the original variable, not a copy.
bool getDesiredFoodsCount(int &size)
{
  bool try_again = true;

  // Keep trying until they enter something valid
  do
  {
    cout << "How many foods to enter in?: ";
    if (!(cin >> size))
    {
      // Stop checking on non-numeric input
      cout << "Invalid input: size must be an integer (1-10)\n";
      return false;
    }
    if (size < 1 || size > 10)
    {
      // Loop around and check again if its and int but out of range
      cout << "Invalid input: size must be between 1 and 10.\n";
      continue;
    }
    cout << endl;

    try_again = false;

  } while (try_again);

  return true;
}

// * in string *pFoods declares a pointer to a string.
// pFoods[i] accesses an array entry through that pointer.
// & lets this function update main's itemsAddedCount.
bool getGroceryItems(string *pFoods, int size, int &itemsAddedCount)
{

  // nullptr means the pointer points to no object.
  // Check before attempting to access any foods, to help avoid a memory leaks.
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
    // - ws skips leftover newlines and leading whitespace.
    if (!getline(cin >> ws, pFoods[i]))
    {
      cout << "Input failed.\n";
      return false;
    }

    // Increment the items recored tally by 1, only after
    //  input succeeds.
    itemsAddedCount++;
  }
  cout << "-------------------------------\n";
  cout << "* Successfully added " << itemsAddedCount << " items! *\n";
  cout << "-------------------------------\n";

  return true;
}

// Inspect the grocery items through a pointer without changing them.
void printGroceryItems(string *pFoods, int itemsAddedCount)
{
  // Check for nullptr before dereferencing pFoods
  if (pFoods == nullptr)
  {
    cout << "Sorry, no grocery list is available.\n";
    return;
  }

  if (itemsAddedCount <= 0)
  {
    cout << "Sorry, no items were found!\n";
    return;
  }

  // Print out the stored foods
  cout << "******* GROCERY LIST ********\n";

  for (int i = 0; i < itemsAddedCount; i++)
  {
    cout << "Item # " << i + 1 << ": " << pFoods[i] << '\n';
  }
}
