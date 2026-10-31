/* ==========================================================================
    Course:     ESCC, CIS-251 - C++ Programming
    Source:     CISCO NETWORKING ACADEMY C++ Essentials 1
    Module:     3.0: Pointers: Another Dimension of Data in C++
    Submodule:  3.0.4: sizeof operator

    **** SUGGESTED EXERCISE ****

    Student:    Eric Hepperle
    Created:    2026-10-31

    Version:    1.0
    
    Status:     Fully Working!

    Description:
    Simple utility to display the size in bytes of several C++ types and pointers on the
    current system. Compile and run it to see how the compiler and platform
    represent these types in memory.

    GitHub:     https://github.com/codewizard13
   ========================================================================== */

#include <iostream>

using namespace std;

int main(void)
{
    cout << "This computing environment uses:" << endl;
    cout << sizeof(char) << " bytes for chars" << endl;
    cout << sizeof(short int) << " bytes for shorts" << endl;
    cout << sizeof(int) << " bytes for ints" << endl;
    cout << sizeof(long int) << " bytes for longs" << endl;
    cout << sizeof(float) << " bytes for floats" << endl;
    cout << sizeof(double) << " bytes for doubles" << endl;
    cout << sizeof(bool) << " byte for bools" << endl;
    cout << sizeof(int *) << " bytes for pointers" << endl;
    return 0;
}