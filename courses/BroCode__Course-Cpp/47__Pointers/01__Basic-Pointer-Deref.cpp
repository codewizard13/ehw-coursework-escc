/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=JfR9VROdxpMw-WPE&t=15478

    **** POINTERS ****

    Student: Eric Hepperle
    Created: 2026-10-06

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Demonstrates printing STRING pointer address and getting pointer value with
      dereference operator.

    📝 Lessons Learned:
    - pointer - a variable that stores a memory address of another variable
    - we use pointers because sometimes its easier to work with an address
    - #REAL_LIFE: Tell people where the free pizza is rather than carrying around 20 pizzas with me
    - Use address-of operator (&) and dereference operator (*)
    - common naming convention for pointers: *p[VariableName]
    
    Sample Output:

    pName: 0xb71a5ffd30
    *pName: Bro

    References:
    - 
    
    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

int main() {

    string name = "Bro";

    string *pName = &name;

    // Print the pointer address
    cout << "pName: " << pName << '\n';

    // Use dereference operator to access the value at the address
    cout << "*pName: " << *pName << '\n';

    return 0;
}
