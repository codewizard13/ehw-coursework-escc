/* ************************************************************
    Course: ESCC, CIS-251 - C++ Programming
    Source: CISCO NETWORKING ACADEMY C++ Essentials 1
    Module 3.0: Pointers: Another Dimension of Data in C++
    Submodule: 3.0.4: sizeof operator

    **** SUGGESTED EXERCISE ****


    Student: Eric Hepperle
    Created: 2026-10-31

    VERSION: 1.0

    STATUS: Fully Working!

    Description:
    Can be used as a utility
    We think it would be a good exercise for you to compile and run the following program on your computer. By doing this, you’ll learn how your computer and compiler use the memory.

    The program is perhaps a bit simplistic, but its role is to identify interesting features of your environment, and it’s good enough for this.


    GitHub: https://github.com/codewizard13
 ************************************************************ */

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