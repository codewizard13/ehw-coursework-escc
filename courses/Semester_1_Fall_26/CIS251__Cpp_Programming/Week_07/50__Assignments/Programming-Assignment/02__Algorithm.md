### 📊 Pseudocode Algorithm

# Week 7 Programming Assignment - Pointers, References, Memory, and C++ Essentials 1 Synthesis

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